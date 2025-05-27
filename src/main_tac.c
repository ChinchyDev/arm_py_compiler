#include <stdio.h>
#include <stdlib.h>
#include "ast.h"
#include "tac.h"
#include "codegen_tac.h"

// External parser function
extern int yyparse();
extern ASTNode *ast_root;
extern FILE *yyin;

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        fprintf(stderr, "Usage: %s <input_file>\n", argv[0]);
        return 1;
    }

    // Open input file
    yyin = fopen(argv[1], "r");
    if (!yyin)
    {
        fprintf(stderr, "Error: Cannot open file %s\n", argv[1]);
        return 1;
    }

    // Parse the input file
    printf("; Parsing input file: %s\n", argv[1]);
    if (yyparse() != 0)
    {
        fprintf(stderr, "Parsing failed\n");
        fclose(yyin);
        return 1;
    }
    fclose(yyin);

    if (!ast_root)
    {
        fprintf(stderr, "No AST generated\n");
        return 1;
    }

    printf("; Parsing successful, generating TAC...\n");

    // Debug: Print AST
    printf("; --- AST Structure ---\n");
    print_ast(ast_root, 0);

    // Generate TAC from AST
    printf("; Generating Three Address Code...\n");
    generate_tac_from_ast(ast_root);

    // Debug: Print generated TAC
    print_tac();

    // Generate ARM assembly from TAC
    printf("; Generated TAC\n");
    printf("; --- ARM Assembly (via TAC) ---\n");
    tac_to_arm(tac_head);

    // Cleanup
    free_ast(ast_root);
    free_tac();

    return 0;
}