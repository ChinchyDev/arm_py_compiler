#ifndef TAC_H
#define TAC_H
#include "ast.h"

// Three Address Code instruction structure
typedef struct TAC
{
    char *op;         // Operation: =, +, -, *, /, <, >, ==, !=, etc.
    char *arg1;       // First argument
    char *arg2;       // Second argument (NULL for unary ops)
    char *result;     // Result variable or label
    struct TAC *next; // Next instruction
} TAC;

// Global TAC instruction list
extern TAC *tac_head;
extern TAC *tac_tail;

// Temporary variable counter
extern int temp_count;

// Label counter
extern int label_count;

// Function declarations
TAC *create_tac(const char *op, const char *arg1, const char *arg2, const char *result);
void add_tac(TAC *instr);
char *new_temp();
char *new_label();
void print_tac();
void free_tac();

// AST to TAC conversion
char *generate_tac_from_ast(ASTNode *node);

#endif