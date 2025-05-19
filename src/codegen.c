#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "codegen.h"

/* This is a full code generator implementation skeleton for ARM assembly output,
 * handling all AST nodes defined in ast.h and parser.y,
 * reflecting the expected nodes and constructs from lexer and parser phases.
 *
 * The code generator outputs simple ARM assembly examples
 * and comments to illustrate the handling of different nodes.
 * Extend or replace with actual register allocation and instruction generation
 * as you develop further.
 */

static int label_count = 0;

static char *new_label(const char *prefix) {
    static char buffer[64];
    snprintf(buffer, sizeof(buffer), "%s_%d", prefix, label_count++);
    return buffer;
}

void codegen_expression(ASTNode *node);

void codegen(ASTNode *root) {
    if (!root) return;

    // Entry point label
    printf(".section .text\n");
    printf(".global _start\n");
    printf("_start:\n");

    // Generate code for the entire program (statement list)
    for (int i = 0; i < root->children_count; i++) {
        codegen_expression(root->children[i]);
    }

    // Exit system call
    printf("  mov r7, #1\n");
    printf("  mov r0, #0\n");
    printf("  svc #0\n"); // Exit syscall
}

void codegen_expression(ASTNode *node) {
    if (!node) return;

    switch (node->type) {
        case AST_STATEMENT_LIST:
            for (int i = 0; i < node->children_count; i++) {
                codegen_expression(node->children[i]);
            }
            break;

        case AST_EXPR_STMT:
            codegen_expression(node->children[0]);
            break;

        case AST_ASSIGNMENT:
        case AST_PLUS_ASSIGN:
        case AST_MINUS_ASSIGN:
        case AST_TIMES_ASSIGN:
        case AST_DIVIDE_ASSIGN: {
            // Assignment lhs variable name: node->value
            // rhs expression node->children[0]
            printf("  @ Assignment to variable '%s'\n", node->value);
            codegen_expression(node->children[0]);
            // For demonstration, assume result in r0 and store it to variable symbol storage (not implemented)
            printf("  @ (Storing r0 to variable '%s')\n", node->value);
            break;
        }

        case AST_IF: {
            char *else_label = new_label("else");
            char *end_label = new_label("ifend");
            // if condition
            printf("  @ If condition\n");
            codegen_expression(node->children[0]);
            printf("  cmp r0, #0\n");
            printf("  beq %s\n", else_label);
            // if body
            codegen_expression(node->children[1]);
            printf("  b %s\n", end_label);
            // else label (may be null)
            printf("%s:\n", else_label);
            if (node->children_count > 2 && node->children[2]) {
                codegen_expression(node->children[2]);
            }
            printf("%s:\n", end_label);
            break;
        }

        case AST_IF_ELIF:
        case AST_IF_ELSE:
        case AST_IF_ELIF_ELSE:
        case AST_ELIF:
            // Complex if-elif-else chain - can expand similar to AST_IF with chaining
            printf("  @ Complex if-elif-else - expand accordingly\n");
            // Simplified stub:
            for (int i = 0; i < node->children_count; i++) {
                codegen_expression(node->children[i]);
            }
            break;

        case AST_WHILE: {
            char *start_label = new_label("while_start");
            char *end_label = new_label("while_end");
            printf("%s:\n", start_label);
            codegen_expression(node->children[0]); // condition
            printf("  cmp r0, #0\n");
            printf("  beq %s\n", end_label);
            codegen_expression(node->children[1]); // body
            printf("  b %s\n", start_label);
            printf("%s:\n", end_label);
            break;
        }

        case AST_FOR: {
            char *start_label = new_label("for_start");
            char *end_label = new_label("for_end");
            // For loop over iterable (simplified)
            printf("  @ For loop variable '%s'\n", node->value);
            // codegen_expression for iterable
            codegen_expression(node->children[0]);
            printf("%s:\n", start_label);
            // simplified: no real iterator, just placeholder
            codegen_expression(node->children[1]); // body
            printf("  @ For-loop continues (placeholder)\n");
            printf("  b %s\n", start_label);
            printf("%s:\n", end_label);
            break;
        }

        case AST_FOR_RANGE: {
            char *start_label = new_label("forrange_start");
            char *end_label = new_label("forrange_end");
            printf("  @ For-range loop variable '%s'\n", node->value);
            // for-range can have 1 or 2 children for start/end
            if (node->children_count < 2) {
                printf("  @ Error: for-range missing start/end\n");
                return;
            }
            // Load start and end (for simplicity, assume literals or registers here)
            codegen_expression(node->children[0]); // start
            printf("  mov r1, r0  @ move start to r1 (counter)\n");
            codegen_expression(node->children[1]); // end
            printf("  mov r2, r0  @ move end to r2\n");
            printf("%s:\n", start_label);
            printf("  cmp r1, r2\n");
            printf("  bge %s\n", end_label);
            // Body with loop var in r1 (simplification)
            codegen_expression(node->children[2]);
            printf("  add r1, r1, #1\n");
            printf("  b %s\n", start_label);
            printf("%s:\n", end_label);
            break;
        }

        case AST_FUNCTION_DEF: {
            printf("%s:\n", node->value ? node->value : "function");
            // Parameters (node->children[0]) and body (node->children[1])
            if (node->children_count > 0) codegen_expression(node->children[0]);
            if (node->children_count > 1) codegen_expression(node->children[1]);
            printf("  @ Function return (placeholder)\n");
            break;
        }

        case AST_RETURN: {
            printf("  @ Return statement\n");
            if (node->children_count > 0) {
                codegen_expression(node->children[0]);
            }
            printf("  bx lr\n");
            break;
        }

        case AST_IMPORT: {
            printf("  @ Import statement for '%s' (no code generated)\n", node->value);
            break;
        }

        case AST_PARAMETERS:
        case AST_ARGUMENTS: {
            // Generate code for each parameter or argument expression
            for (int i = 0; i < node->children_count; i++) {
                codegen_expression(node->children[i]);
            }
            break;
        }

        case AST_CALL: {
            printf("  @ Function call to '%s'\n", node->value);
            // arguments as children
            if (node->children_count > 0) {
                codegen_expression(node->children[0]);
            }
            // In real codegen, push arguments and call function
            printf("  bl %s\n", node->value);
            break;
        }

        case AST_OR:
        case AST_AND:
        case AST_EQ:
        case AST_NEQ:
        case AST_LT:
        case AST_GT:
        case AST_LE:
        case AST_GE:
        case AST_ADD:
        case AST_SUB:
        case AST_MUL:
        case AST_DIV:
        case AST_MOD: {
            // Binary operators
            codegen_expression(node->children[0]);
            printf("  push {r0}\n");
            codegen_expression(node->children[1]);
            printf("  pop {r1}\n");
            switch (node->type) {
                case AST_OR:
                    printf("  @ Logical OR (simplified)\n");
                    printf("  orr r0, r1, r0\n");
                    break;
                case AST_AND:
                    printf("  @ Logical AND (simplified)\n");
                    printf("  and r0, r1, r0\n");
                    break;
                case AST_EQ:
                    printf("  cmp r1, r0\n");
                    printf("  moveq r0, #1\n");
                    printf("  movne r0, #0\n");
                    break;
                case AST_NEQ:
                    printf("  cmp r1, r0\n");
                    printf("  movne r0, #1\n");
                    printf("  moveq r0, #0\n");
                    break;
                case AST_LT:
                    printf("  cmp r1, r0\n");
                    printf("  movlt r0, #1\n");
                    printf("  movge r0, #0\n");
                    break;
                case AST_GT:
                    printf("  cmp r1, r0\n");
                    printf("  movgt r0, #1\n");
                    printf("  movle r0, #0\n");
                    break;
                case AST_LE:
                    printf("  cmp r1, r0\n");
                    printf("  movle r0, #1\n");
                    printf("  movgt r0, #0\n");
                    break;
                case AST_GE:
                    printf("  cmp r1, r0\n");
                    printf("  movge r0, #1\n");
                    printf("  movlt r0, #0\n");
                    break;
                case AST_ADD:
                    printf("  add r0, r1, r0\n");
                    break;
                case AST_SUB:
                    printf("  sub r0, r1, r0\n");
                    break;
                case AST_MUL:
                    printf("  mul r0, r1, r0\n");
                    break;
                case AST_DIV:
                    printf("  @ Division requires special handling (not implemented)\n");
                    break;
                case AST_MOD:
                    printf("  @ Modulus requires special handling (not implemented)\n");
                    break;
                default:
                    break;
            }
            break;
        }

        case AST_NEG:
        case AST_NOT: {
            codegen_expression(node->children[0]);
            switch (node->type) {
                case AST_NEG:
                    printf("  rsb r0, r0, #0\n");
                    break;
                case AST_NOT:
                    printf("  cmp r0, #0\n");
                    printf("  moveq r0, #1\n");
                    printf("  movne r0, #0\n");
                    break;
                default:
                    break;
            }
            break;
        }

        case AST_INT:
            printf("  mov r0, #%s\n", node->value);
            break;

        case AST_FLOAT:
            printf("  @ Float literal %s (not fully implemented)\n", node->value);
            break;

        case AST_STRING:
            printf("  @ String literal '%s' (not implemented)\n", node->value);
            break;

        case AST_BOOL:
            printf("  mov r0, #%d  @ Boolean literal %s\n", node->boolValue, node->value ? node->value : "");
            break;

        case AST_NONE:
            printf("  mov r0, #0  @ None\n");
            break;

        case AST_IDENTIFIER:
            printf("  @ Load identifier '%s' (not implemented)\n", node->value);
            break;

        case AST_LIST:
            printf("  @ List literal (not implemented)\n");
            break;

        case AST_DICT:
            printf("  @ Dict literal (not implemented)\n");
            break;

        default:
            printf("  @ Unhandled AST node type %d\n", node->type);
            break;
    }
}

