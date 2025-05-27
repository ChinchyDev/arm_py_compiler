#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include "codegen_tac.h"

// Check if a string is a number
int is_number(const char *str)
{
    if (!str)
        return 0;
    if (*str == '-' || *str == '+')
        str++; // Skip sign
    while (*str)
    {
        if (!isdigit(*str) && *str != '.')
            return 0;
        str++;
    }
    return 1;
}

// Get value (either from variable or immediate)
void load_value(const char *value, const char *reg)
{
    if (is_number(value))
    {
        printf("  mov %s, #%s\n", reg, value);
    }
    else
    {
        printf("  ldr %s, [sp, #%d]  @ %s\n", reg, get_offset(value), value);
    }
}

void tac_to_arm(TAC *code)
{
    printf(".section .text\n.global _start\n_start:\n");
    printf("  sub sp, sp, #256  @ Allocate stack space\n");

    while (code)
    {
        if (strcmp(code->op, "=") == 0)
        {
            // Assignment: result = arg1
            if (is_number(code->arg1))
            {
                printf("  mov r0, #%s\n", code->arg1);
            }
            else
            {
                printf("  ldr r0, [sp, #%d]  @ %s\n", get_offset(code->arg1), code->arg1);
            }
            printf("  str r0, [sp, #%d]  @ %s\n", get_offset(code->result), code->result);
        }
        else if (strcmp(code->op, "+") == 0)
        {
            // Addition: result = arg1 + arg2
            load_value(code->arg1, "r1");
            load_value(code->arg2, "r2");
            printf("  add r0, r1, r2\n");
            printf("  str r0, [sp, #%d]  @ %s\n", get_offset(code->result), code->result);
        }
        else if (strcmp(code->op, "-") == 0)
        {
            // Subtraction: result = arg1 - arg2
            load_value(code->arg1, "r1");
            load_value(code->arg2, "r2");
            printf("  sub r0, r1, r2\n");
            printf("  str r0, [sp, #%d]  @ %s\n", get_offset(code->result), code->result);
        }
        else if (strcmp(code->op, "*") == 0)
        {
            // Multiplication: result = arg1 * arg2
            load_value(code->arg1, "r1");
            load_value(code->arg2, "r2");
            printf("  mul r0, r1, r2\n");
            printf("  str r0, [sp, #%d]  @ %s\n", get_offset(code->result), code->result);
        }
        else if (strcmp(code->op, "/") == 0)
        {
            // Division: result = arg1 / arg2 (simplified)
            load_value(code->arg1, "r1");
            load_value(code->arg2, "r2");
            printf("  @ Division operation (simplified)\n");
            printf("  mov r0, r1  @ Store result as arg1 for now\n");
            printf("  str r0, [sp, #%d]  @ %s\n", get_offset(code->result), code->result);
        }
        else if (strcmp(code->op, ">") == 0)
        {
            // Greater than: result = (arg1 > arg2) ? 1 : 0
            load_value(code->arg1, "r1");
            load_value(code->arg2, "r2");
            printf("  cmp r1, r2\n");
            printf("  mov r0, #0\n");   // Default to false
            printf("  movgt r0, #1\n"); // Set to true if greater
            printf("  str r0, [sp, #%d]  @ %s\n", get_offset(code->result), code->result);
        }
        else if (strcmp(code->op, "<") == 0)
        {
            // Less than: result = (arg1 < arg2) ? 1 : 0
            load_value(code->arg1, "r1");
            load_value(code->arg2, "r2");
            printf("  cmp r1, r2\n");
            printf("  mov r0, #0\n");   // Default to false
            printf("  movlt r0, #1\n"); // Set to true if less than
            printf("  str r0, [sp, #%d]  @ %s\n", get_offset(code->result), code->result);
        }
        else if (strcmp(code->op, "==") == 0)
        {
            // Equal: result = (arg1 == arg2) ? 1 : 0
            load_value(code->arg1, "r1");
            load_value(code->arg2, "r2");
            printf("  cmp r1, r2\n");
            printf("  mov r0, #0\n");   // Default to false
            printf("  moveq r0, #1\n"); // Set to true if equal
            printf("  str r0, [sp, #%d]  @ %s\n", get_offset(code->result), code->result);
        }
        else if (strcmp(code->op, "!=") == 0)
        {
            // Not equal: result = (arg1 != arg2) ? 1 : 0
            load_value(code->arg1, "r1");
            load_value(code->arg2, "r2");
            printf("  cmp r1, r2\n");
            printf("  mov r0, #0\n");   // Default to false
            printf("  movne r0, #1\n"); // Set to true if not equal
            printf("  str r0, [sp, #%d]  @ %s\n", get_offset(code->result), code->result);
        }
        else if (strcmp(code->op, "ifgoto0") == 0)
        {
            // Conditional jump: if arg1 == 0 goto result
            load_value(code->arg1, "r0");
            printf("  cmp r0, #0\n");
            printf("  beq %s\n", code->result);
        }
        else if (strcmp(code->op, "goto") == 0)
        {
            // Unconditional jump
            printf("  b %s\n", code->result);
        }
        else if (strcmp(code->op, "label") == 0)
        {
            // Label definition
            printf("%s:\n", code->result);
        }
        else if (strcmp(code->op, "print") == 0)
        {
            // Print statement - simplified (just store value in r0 for now)
            printf("  @ Print statement\n");
            load_value(code->arg1, "r0");
            printf("  @ Value to print is in r0\n");
        }
        else
        {
            printf("  @ Unknown TAC operation: %s\n", code->op);
        }

        code = code->next;
    }

    // Exit program
    printf("  mov r7, #1\n");
    printf("  mov r0, #0\n");
    printf("  svc #0\n");

    // Print symbol table for debugging
    print_symbol_table();
}