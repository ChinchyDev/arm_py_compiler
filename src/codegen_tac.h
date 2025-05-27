#ifndef CODEGEN_TAC_H
#define CODEGEN_TAC_H

#include "tac.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

// Forward declaration for TACInstr
typedef struct TACInstr TACInstr;

// === Symbol Table for TAC backend ===
#define MAX_TAC_SYMBOLS 64

typedef struct
{
    char *name;
    int offset;
} TacSymbol;

static TacSymbol tac_symtable[MAX_TAC_SYMBOLS];
static int tac_symcount = 0;
static int tac_next_offset = 224;

static int get_offset(const char *name)
{
    for (int i = 0; i < tac_symcount; i++)
    {
        if (strcmp(tac_symtable[i].name, name) == 0)
            return tac_symtable[i].offset;
    }

    if (tac_symcount < MAX_TAC_SYMBOLS)
    {
        tac_symtable[tac_symcount].name = strdup(name);
        tac_symtable[tac_symcount].offset = tac_next_offset;
        tac_next_offset += 4;
        return tac_symtable[tac_symcount++].offset;
    }

    fprintf(stderr, "[TAC] Symbol table full!\n");
    exit(1);
}

static void print_symbol_table()
{
    printf("\n; TAC Symbol Table (Variable -> Stack Offset)\n");
    for (int i = 0; i < tac_symcount; i++)
    {
        printf("; %-10s -> [sp, #%d]\n", tac_symtable[i].name, tac_symtable[i].offset);
    }
}

// Codegen interface
void tac_to_arm(TAC *code);

#endif
