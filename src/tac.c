#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tac.h"
#include "ast.h"

// Global TAC instruction list
TAC *tac_head = NULL;
TAC *tac_tail = NULL;

// Counters
int temp_count = 0;
int label_count = 0;

// Create a new TAC instruction
TAC *create_tac(const char *op, const char *arg1, const char *arg2, const char *result) {
    TAC *instr = (TAC *)malloc(sizeof(TAC));
    instr->op = op ? strdup(op) : NULL;
    instr->arg1 = arg1 ? strdup(arg1) : NULL;
    instr->arg2 = arg2 ? strdup(arg2) : NULL;
    instr->result = result ? strdup(result) : NULL;
    instr->next = NULL;
    return instr;
}

// Add TAC instruction to the global list
void add_tac(TAC *instr) {
    if (!tac_head) {
        tac_head = tac_tail = instr;
    } else {
        tac_tail->next = instr;
        tac_tail = instr;
    }
}

// Generate new temporary variable
char *new_temp() {
    char *temp = (char *)malloc(16);
    snprintf(temp, 16, "t%d", temp_count++);
    return temp;
}

// Generate new label
char *new_label() {
    char *label = (char *)malloc(16);
    snprintf(label, 16, "L%d", label_count++);
    return label;
}

// Print all TAC instructions
void print_tac() {
    printf("; --- TAC Instructions ---\n");
    TAC *curr = tac_head;
    while (curr) {
        printf("(%s, %s, %s, %s)\n", 
               curr->op ? curr->op : "NULL",
               curr->arg1 ? curr->arg1 : "NULL", 
               curr->arg2 ? curr->arg2 : "NULL",
               curr->result ? curr->result : "NULL");
        curr = curr->next;
    }
}

// Free TAC instruction list
void free_tac() {
    TAC *curr = tac_head;
    while (curr) {
        TAC *temp = curr;
        curr = curr->next;
        free(temp->op);
        free(temp->arg1);
        free(temp->arg2);
        free(temp->result);
        free(temp);
    }
    tac_head = tac_tail = NULL;
}

// Convert AST to TAC - returns the result variable/temp for expressions
char *generate_tac_from_ast(ASTNode *node) {
    if (!node) return NULL;
    
    switch (node->type) {
        case AST_STATEMENT_LIST: {
            // Process each statement
            for (int i = 0; i < node->children_count; i++) {
                generate_tac_from_ast(node->children[i]);
            }
            return NULL;
        }
        
        case AST_ASSIGNMENT: {
            // var = expr
            char *expr_result = generate_tac_from_ast(node->children[0]);
            add_tac(create_tac("=", expr_result, NULL, node->value));
            return NULL;
        }
        
        case AST_EXPR_STMT: {
            // Expression statement (just evaluate the expression)
            generate_tac_from_ast(node->children[0]);
            return NULL;
        }
        
        case AST_PRINT: {
            // print(expr)
            char *expr_result = generate_tac_from_ast(node->children[0]);
            add_tac(create_tac("print", expr_result, NULL, NULL));
            return NULL;
        }
        
        case AST_IF: {
            // if condition: body [else_part]
            char *cond_result = generate_tac_from_ast(node->children[0]);
            char *false_label = new_label();
            char *end_label = new_label();
            
            // Jump to false_label if condition is false (0)
            add_tac(create_tac("ifgoto0", cond_result, NULL, false_label));
            
            // Generate code for if body
            generate_tac_from_ast(node->children[1]);
            
            // Jump to end if we have an else part
            if (node->children_count > 2) {
                add_tac(create_tac("goto", NULL, NULL, end_label));
            }
            
            // False label (for else part)
            add_tac(create_tac("label", NULL, NULL, false_label));
            
            // Generate else part if it exists
            if (node->children_count > 2) {
                generate_tac_from_ast(node->children[2]);
                add_tac(create_tac("label", NULL, NULL, end_label));
            }
            
            return NULL;
        }
        
        case AST_ELSE: {
            // Process else body
            generate_tac_from_ast(node->children[0]);
            return NULL;
        }
        
        case AST_GT: {
            // expr1 > expr2
            char *left = generate_tac_from_ast(node->children[0]);
            char *right = generate_tac_from_ast(node->children[1]);
            char *result = new_temp();
            add_tac(create_tac(">", left, right, result));
            return result;
        }
        
        case AST_LT: {
            // expr1 < expr2
            char *left = generate_tac_from_ast(node->children[0]);
            char *right = generate_tac_from_ast(node->children[1]);
            char *result = new_temp();
            add_tac(create_tac("<", left, right, result));
            return result;
        }
        
        case AST_EQ: {
            // expr1 == expr2
            char *left = generate_tac_from_ast(node->children[0]);
            char *right = generate_tac_from_ast(node->children[1]);
            char *result = new_temp();
            add_tac(create_tac("==", left, right, result));
            return result;
        }
        
        case AST_NEQ: {
            // expr1 != expr2
            char *left = generate_tac_from_ast(node->children[0]);
            char *right = generate_tac_from_ast(node->children[1]);
            char *result = new_temp();
            add_tac(create_tac("!=", left, right, result));
            return result;
        }
        
        case AST_ADD: {
            // expr1 + expr2
            char *left = generate_tac_from_ast(node->children[0]);
            char *right = generate_tac_from_ast(node->children[1]);
            char *result = new_temp();
            add_tac(create_tac("+", left, right, result));
            return result;
        }
        
        case AST_SUB: {
            // expr1 - expr2
            char *left = generate_tac_from_ast(node->children[0]);
            char *right = generate_tac_from_ast(node->children[1]);
            char *result = new_temp();
            add_tac(create_tac("-", left, right, result));
            return result;
        }
        
        case AST_MUL: {
            // expr1 * expr2
            char *left = generate_tac_from_ast(node->children[0]);
            char *right = generate_tac_from_ast(node->children[1]);
            char *result = new_temp();
            add_tac(create_tac("*", left, right, result));
            return result;
        }
        
        case AST_DIV: {
            // expr1 / expr2
            char *left = generate_tac_from_ast(node->children[0]);
            char *right = generate_tac_from_ast(node->children[1]);
            char *result = new_temp();
            add_tac(create_tac("/", left, right, result));
            return result;
        }
        
        case AST_INT: {
            // Integer literal - return the value as string
            return strdup(node->value);
        }
        
        case AST_FLOAT: {
            // Float literal - return the value as string
            return strdup(node->value);
        }
        
        case AST_IDENTIFIER: {
            // Variable reference - return the variable name
            return strdup(node->value);
        }
        
        case AST_BOOL: {
            // Boolean literal
            return strdup(node->boolValue ? "1" : "0");
        }
        
        default:
            printf("Warning: Unhandled AST node type %d in TAC generation\n", node->type);
            return NULL;
    }
}