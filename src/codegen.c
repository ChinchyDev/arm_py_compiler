#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "codegen.h"

static int label_count = 0;

#define MAX_SYMBOLS 64

typedef struct
{
    char *name;
    int offset;
} Symbol;

static Symbol symtable[MAX_SYMBOLS];
static int symcount = 0;
static int next_offset = 224; // start stack at sp + 224

int get_offset(const char *name)
{
    for (int i = 0; i < symcount; i++)
    {
        if (strcmp(symtable[i].name, name) == 0)
            return symtable[i].offset;
    }

    if (symcount < MAX_SYMBOLS)
    {
        symtable[symcount].name = strdup(name);
        symtable[symcount].offset = next_offset;
        next_offset += 4;
        return symtable[symcount++].offset;
    }

    fprintf(stderr, "Symbol table full!\n");
    exit(1);
}

static char *new_label(const char *prefix)
{
    static char buffer[64];
    snprintf(buffer, sizeof(buffer), "%s_%d", prefix, label_count++);
    return buffer;
}

#define STACK_SIZE 256
#define WORD_SIZE 4

/*int get_offset(const char *name)
{
    unsigned long hash = 0;
    for (const char *p = name; *p; p++)
    {
        hash = (hash * 31 + *p) % STACK_SIZE;
    }
    return (hash * WORD_SIZE) % STACK_SIZE;
}*/

void codegen_expression(ASTNode *node);


void codegen(ASTNode *root)
{
    if (!root)
        return;
    
    print_symbol_table();

    printf(".section .text\n");
    printf(".global _start\n");
    printf("_start:\n");
    printf("  sub sp, sp, #%d  @ Allocate stack frame\n", STACK_SIZE);

    for (int i = 0; i < root->children_count; i++)
    {
        codegen_expression(root->children[i]);
    }

    printf("  mov r7, #1\n");
    printf("  mov r0, #0\n");
    printf("  svc #0\n");
}

void codegen_expression(ASTNode *node)
{
    if (!node)
        return;

    switch (node->type)
    {
    case AST_STATEMENT_LIST:
        for (int i = 0; i < node->children_count; i++)
        {
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
    case AST_DIVIDE_ASSIGN:
    {
        printf("  @ Assignment to variable '%s'\n", node->value);
        codegen_expression(node->children[0]);
        int offset = get_offset(node->value);
        printf("  str r0, [sp, #%d]  @ Store to variable '%s'\n", offset, node->value);
        break;
    }

    case AST_IF:
    {
        char *else_label = new_label("else");
        char *end_label = new_label("ifend");
        printf("  @ If condition\n");
        codegen_expression(node->children[0]);
        printf("  cmp r0, #0\n");
        printf("  beq %s\n", else_label);
        codegen_expression(node->children[1]);
        printf("  b %s\n", end_label);
        printf("%s:\n", else_label);
        if (node->children_count > 2 && node->children[2])
        {
            codegen_expression(node->children[2]);
        }
        printf("%s:\n", end_label);
        break;
    }

    case AST_IF_ELIF:
    case AST_IF_ELIF_ELSE:
    {
        printf("  @ Complex if-elif[-else] chain\n");
        for (int i = 0; i < node->children_count; i++)
        {
            codegen_expression(node->children[i]);
        }
        break;
    }

    case AST_IF_ELSE:
    case AST_ELIF:
        printf("  @ Simplified if-elif-else stub\n");
        for (int i = 0; i < node->children_count; i++)
        {
            codegen_expression(node->children[i]);
        }
        break;

    case AST_ELSE:
        printf("  @ Else block\n");
        for (int i = 0; i < node->children_count; i++)
        {
            codegen_expression(node->children[i]);
        }
        break;

    case AST_WHILE:
    {
        char *start_label = new_label("while_start");
        char *end_label = new_label("while_end");
        printf("%s:\n", start_label);
        codegen_expression(node->children[0]);
        printf("  cmp r0, #0\n");
        printf("  beq %s\n", end_label);
        codegen_expression(node->children[1]);
        printf("  b %s\n", start_label);
        printf("%s:\n", end_label);
        break;
    }

    case AST_FOR:
    {
        char *start_label = new_label("for_start");
        char *end_label = new_label("for_end");
        printf("  @ For loop variable '%s'\n", node->value);
        codegen_expression(node->children[0]);
        printf("%s:\n", start_label);
        codegen_expression(node->children[1]);
        printf("  @ For-loop continues (placeholder)\n");
        printf("  b %s\n", start_label);
        printf("%s:\n", end_label);
        break;
    }

    case AST_PRINT:
    {
        printf("  @ Print statement\n");
        codegen_expression(node->children[0]);
        printf("  mov r1, r0\n");
        printf("  ldr r0, =msg\n");
        printf("  mov r2, #4\n");
        printf("  mov r7, #4  @ syscall write\n");
        printf("  svc #0\n");
        break;
    }

    case AST_IDENTIFIER:
    {
        int offset = get_offset(node->value);
        printf("  ldr r0, [sp, #%d]  @ Load identifier '%s'\n", offset, node->value);
        break;
    }

    case AST_INT:
        printf("  mov r0, #%s\n", node->value);
        break;

    default:
        printf("  @ Unhandled AST node type %d\n", node->type);
        break;
    case AST_ADD:
    case AST_SUB:
    case AST_MUL:
    case AST_DIV:
    {
        ASTNode *left = node->children[0];
        ASTNode *right = node->children[1];

        if (left->type == AST_IDENTIFIER && right->type == AST_IDENTIFIER)
        {
            int left_offset = get_offset(left->value);
            int right_offset = get_offset(right->value);

            printf("  ldr r1, [sp, #%d]  @ Load '%s'\n", left_offset, left->value);
            printf("  ldr r2, [sp, #%d]  @ Load '%s'\n", right_offset, right->value);

            switch (node->type)
            {
            case AST_ADD:
                printf("  add r0, r1, r2\n");
                break;
            case AST_SUB:
                printf("  sub r0, r1, r2\n");
                break;
            case AST_MUL:
                printf("  mul r0, r1, r2\n");
                break;
            case AST_DIV:
                printf("  @ Integer division not implemented yet\n");
                break;
            default:
                break;
            }
        }
        else
        {
            // fallback for mixed expressions
            codegen_expression(left);
            printf("  push {r0}\n");
            codegen_expression(right);
            printf("  pop {r1}\n");

            switch (node->type)
            {
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
                printf("  @ Integer division not implemented yet\n");
                break;
            default:
                break;
            }
        }
        break;
    }
        case AST_GT:
    case AST_LT:
    case AST_EQ:
    case AST_NEQ:
    {
        codegen_expression(node->children[0]); // left operand
        printf("  push {r0}\n");
        codegen_expression(node->children[1]); // right operand
        printf("  pop {r1}\n");
        printf("  cmp r1, r0\n");

        switch (node->type)
        {
        case AST_GT:
            printf("  movgt r0, #1\n");
            printf("  movle r0, #0\n");
            break;
        case AST_LT:
            printf("  movlt r0, #1\n");
            printf("  movge r0, #0\n");
            break;
        case AST_EQ:
            printf("  moveq r0, #1\n");
            printf("  movne r0, #0\n");
            break;
        case AST_NEQ:
            printf("  movne r0, #1\n");
            printf("  moveq r0, #0\n");
            break;
        default:
            break;
        }
        break;
    }

        case AST_AND:
    case AST_OR:
    {
        char *short_circuit = new_label(node->type == AST_AND ? "false_result" : "true_result");
        char *end_label = new_label("end_logic");

        codegen_expression(node->children[0]); // left operand
        printf("  cmp r0, #0\n");

        if (node->type == AST_AND) {
            printf("  beq %s\n", short_circuit);  // If left is 0 (false), skip and return false
        } else {
            printf("  bne %s\n", short_circuit);  // If left is 1 (true), skip and return true
        }

        codegen_expression(node->children[1]); // right operand
        printf("  b %s\n", end_label);          // Done, jump to end

        printf("%s:\n", short_circuit);
        printf("  mov r0, #%d\n", node->type == AST_AND ? 0 : 1); // Set short-circuit result

        printf("%s:\n", end_label);
        break;
    }

    }
}

void print_symbol_table(void) {
    printf("\n; Symbol Table (Variable -> Stack Offset)\n");
    for (int i = 0; i < symcount; i++) {
        printf("; %s -> [sp, #%d]\n", symtable[i].name, symtable[i].offset);
    }
    printf("\n");
}

