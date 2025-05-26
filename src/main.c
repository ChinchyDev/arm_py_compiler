#include <stdio.h>
#include <stdlib.h>
#include "parser.tab.h"
#include "ast.h"
#include "codegen.h"

extern FILE *yyin;
extern int yyparse(void);
extern ASTNode *ast_root;

extern void yyerror(const char *s);

int main(int argc, char **argv)
{
    if (argc < 2)
    {
        fprintf(stderr, "Usage: %s <input.py>\n", argv[0]);
        return 1;
    }

    yyin = fopen(argv[1], "r");
    if (!yyin)
    {
        perror("Failed to open input file");
        return 1;
    }

    if (yyparse() == 0 && ast_root != NULL)
    {
        printf("; Parsing successful, generating code...\n");
        printf("; Generated AST:\n");
        // Print the AST for debugging
        print_ast(ast_root, 0);// Print the AST for debugging
        printf("; Generated symbol table\n");
        print_symbol_table();// Print the symbol table for debugging 
        // ast_root should be a AST_STATEMENT_LIST node as expected by new codegen
        printf("; Generated ARM assembly\n");
        codegen(ast_root); // Pass AST_STATEMENT_LIST as root node.
        free_ast(ast_root);
    }
    else
    {
        fprintf(stderr, "Parsing failed.\n");
    }

    fclose(yyin);
    return 0;
}

/*void yyerror(const char *s)
{
    fprintf(stderr, "Error: %s\n", s);
}*/