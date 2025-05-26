%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ast.h"

// Use get_token instead of yylex
extern int get_token();
#define yylex get_token

extern int line_num;
void yyerror(const char *s);

ASTNode *ast_root = NULL;
%}

%union {
    int ival;
    float fval;
    int bval;  // Boolean
    char *sval;
    struct ASTNode *node;
}

%token <ival> INT_NUM
%token <fval> FLOAT_NUM
%token <bval> BOOL
%token <sval> IDENTIFIER STRING
%token NEWLINE INDENT DEDENT
%token IF ELSE ELIF WHILE FOR IN DEF RETURN IMPORT NONE RANGE PRINT
%token AND OR NOT
%token PLUS MINUS TIMES DIVIDE MODULO
%token ASSIGN PLUS_ASSIGN MINUS_ASSIGN TIMES_ASSIGN DIVIDE_ASSIGN
%token EQ NEQ LT GT LE GE
%token LPAREN RPAREN LBRACKET RBRACKET LBRACE RBRACE COLON COMMA

%type <node> program statement_list statement expression_stmt assignment_stmt
%type <node> if_stmt while_stmt for_stmt function_def return_stmt import_stmt print_stmt
%type <node> expression logical_or logical_and equality comparison term factor
%type <node> unary call primary list_expr dict_expr arguments parameters
%type <node> elif_clauses else_clause suite

%start program

%%

program: statement_list          { ast_root = $1; }
       | %empty                  { ast_root = create_node(AST_STATEMENT_LIST, NULL); }
       ;

statement_list: statement        { 
                                   $$ = create_node(AST_STATEMENT_LIST, NULL); 
                                   if ($1) add_child($$, $1); 
                                 }
              | statement_list statement { 
                                   $$ = $1; 
                                   if ($2) add_child($$, $2); 
                                 }
              ;

statement: expression_stmt       { $$ = $1; }
         | assignment_stmt       { $$ = $1; }
         | if_stmt               { $$ = $1; }
         | while_stmt            { $$ = $1; }
         | for_stmt              { $$ = $1; }
         | function_def          { $$ = $1; }
         | return_stmt           { $$ = $1; }
         | import_stmt           { $$ = $1; }
         | print_stmt            { $$ = $1; }
         | NEWLINE               { $$ = NULL; } /* Handle empty lines */
         ;

expression_stmt: expression NEWLINE { $$ = create_node(AST_EXPR_STMT, NULL); add_child($$, $1); }
                ;

assignment_stmt: IDENTIFIER ASSIGN expression NEWLINE { 
                    $$ = create_node(AST_ASSIGNMENT, $1); 
                    add_child($$, $3); 
                }
               | IDENTIFIER PLUS_ASSIGN expression NEWLINE {
                    $$ = create_node(AST_PLUS_ASSIGN, $1);
                    add_child($$, $3);
                }
               | IDENTIFIER MINUS_ASSIGN expression NEWLINE {
                    $$ = create_node(AST_MINUS_ASSIGN, $1);
                    add_child($$, $3);
                }
               | IDENTIFIER TIMES_ASSIGN expression NEWLINE {
                    $$ = create_node(AST_TIMES_ASSIGN, $1);
                    add_child($$, $3);
                }
               | IDENTIFIER DIVIDE_ASSIGN expression NEWLINE {
                    $$ = create_node(AST_DIVIDE_ASSIGN, $1);
                    add_child($$, $3);
                }
               ;

print_stmt: PRINT expression NEWLINE {
             $$ = create_node(AST_PRINT, NULL);
             add_child($$, $2);
           }
          | PRINT IDENTIFIER NEWLINE {
             $$ = create_node(AST_PRINT, NULL);
             add_child($$, create_node(AST_IDENTIFIER, $2));
           }
          ;

/* Suite represents an indented block of code */
suite: NEWLINE INDENT statement_list DEDENT { $$ = $3; }
     ;

/* if statement with optional elif and else clauses */
if_stmt: IF expression COLON suite { 
           $$ = create_node(AST_IF, NULL);
           add_child($$, $2); // condition
           add_child($$, $4); // body
         }
       | IF expression COLON suite elif_clauses {
           $$ = create_node(AST_IF_ELIF, NULL);
           add_child($$, $2); // if condition
           add_child($$, $4); // if body
           add_child($$, $5); // elif chain
         }
       | IF expression COLON suite else_clause {
           $$ = create_node(AST_IF_ELSE, NULL);
           add_child($$, $2); // condition
           add_child($$, $4); // if body
           add_child($$, $5); // else body
         }
       | IF expression COLON suite elif_clauses else_clause {
           $$ = create_node(AST_IF_ELIF_ELSE, NULL);
           add_child($$, $2); // if condition
           add_child($$, $4); // if body
           add_child($$, $5); // elif chain
           add_child($$, $6); // else body
         }
       ;

elif_clauses: ELIF expression COLON suite {
               $$ = create_node(AST_ELIF, NULL);
               add_child($$, $2); // condition
               add_child($$, $4); // body
             }
           | elif_clauses ELIF expression COLON suite {
               $$ = $1;
               ASTNode *elif_node = create_node(AST_ELIF, NULL);
               add_child(elif_node, $3); // condition
               add_child(elif_node, $5); // body
               add_child($$, elif_node);
             }
           ;

else_clause: ELSE COLON suite {
              $$ = $3; // Just return the statements in the else block
            }
          ;

while_stmt: WHILE expression COLON suite {
             $$ = create_node(AST_WHILE, NULL);
             add_child($$, $2); // condition
             add_child($$, $4); // body
           }
          ;

for_stmt: FOR IDENTIFIER IN expression COLON suite {
            $$ = create_node(AST_FOR, $2);
            add_child($$, $4); // iterable
            add_child($$, $6); // body
          }
        | FOR IDENTIFIER IN RANGE LPAREN expression RPAREN COLON suite {
            $$ = create_node(AST_FOR_RANGE, $2);
            add_child($$, $6); // range expression
            add_child($$, $9); // body
          }
        | FOR IDENTIFIER IN RANGE LPAREN expression COMMA expression RPAREN COLON suite {
            $$ = create_node(AST_FOR_RANGE, $2);
            add_child($$, $6); // start
            add_child($$, $8); // end
            add_child($$, $11); // body
          }
        ;

function_def: DEF IDENTIFIER LPAREN parameters RPAREN COLON suite {
               $$ = create_node(AST_FUNCTION_DEF, $2);
               add_child($$, $4); // parameters
               add_child($$, $7); // body
             }
           | DEF IDENTIFIER LPAREN RPAREN COLON suite {
               $$ = create_node(AST_FUNCTION_DEF, $2);
               add_child($$, create_node(AST_PARAMETERS, NULL)); // empty parameters
               add_child($$, $6); // body
             }
           ;

return_stmt: RETURN expression NEWLINE {
              $$ = create_node(AST_RETURN, NULL);
              add_child($$, $2);
            }
          | RETURN NEWLINE {
              $$ = create_node(AST_RETURN, NULL);
            }
          ;

import_stmt: IMPORT IDENTIFIER NEWLINE {
              $$ = create_node(AST_IMPORT, $2);
            }
          ;

parameters: IDENTIFIER {
              $$ = create_node(AST_PARAMETERS, NULL);
              add_child($$, create_node(AST_IDENTIFIER, $1));
            }
          | parameters COMMA IDENTIFIER {
              $$ = $1;
              add_child($$, create_node(AST_IDENTIFIER, $3));
            }
          ;

/* Expression grammar */
expression: logical_or { $$ = $1; }
          ;

logical_or: logical_and { $$ = $1; }
          | logical_or OR logical_and {
              $$ = create_node(AST_OR, NULL);
              add_child($$, $1);
              add_child($$, $3);
            }
          ;

logical_and: equality { $$ = $1; }
           | logical_and AND equality {
              $$ = create_node(AST_AND, NULL);
              add_child($$, $1);
              add_child($$, $3);
            }
           ;

equality: comparison { $$ = $1; }
        | equality EQ comparison {
            $$ = create_node(AST_EQ, NULL);
            add_child($$, $1);
            add_child($$, $3);
          }
        | equality NEQ comparison {
            $$ = create_node(AST_NEQ, NULL);
            add_child($$, $1);
            add_child($$, $3);
          }
        ;

comparison: term { $$ = $1; }
          | comparison LT term {
              $$ = create_node(AST_LT, NULL);
              add_child($$, $1);
              add_child($$, $3);
            }
          | comparison GT term {
              $$ = create_node(AST_GT, NULL);
              add_child($$, $1);
              add_child($$, $3);
            }
          | comparison LE term {
              $$ = create_node(AST_LE, NULL);
              add_child($$, $1);
              add_child($$, $3);
            }
          | comparison GE term {
              $$ = create_node(AST_GE, NULL);
              add_child($$, $1);
              add_child($$, $3);
            }
          ;

term: factor { $$ = $1; }
    | term PLUS factor {
        $$ = create_node(AST_ADD, NULL);
        add_child($$, $1);
        add_child($$, $3);
      }
    | term MINUS factor {
        $$ = create_node(AST_SUB, NULL);
        add_child($$, $1);
        add_child($$, $3);
      }
    ;

factor: unary { $$ = $1; }
      | factor TIMES unary {
          $$ = create_node(AST_MUL, NULL);
          add_child($$, $1);
          add_child($$, $3);
        }
      | factor DIVIDE unary {
          $$ = create_node(AST_DIV, NULL);
          add_child($$, $1);
          add_child($$, $3);
        }
      | factor MODULO unary {
          $$ = create_node(AST_MOD, NULL);
          add_child($$, $1);
          add_child($$, $3);
        }
      ;

unary: call { $$ = $1; }
     | MINUS unary {
         $$ = create_node(AST_NEG, NULL);
         add_child($$, $2);
       }
     | NOT unary {
         $$ = create_node(AST_NOT, NULL);
         add_child($$, $2);
       }
     ;

call: primary { $$ = $1; }
    | IDENTIFIER LPAREN arguments RPAREN {
        $$ = create_node(AST_CALL, $1);
        add_child($$, $3);
      }
    | IDENTIFIER LPAREN RPAREN {
        $$ = create_node(AST_CALL, $1);
        add_child($$, create_node(AST_ARGUMENTS, NULL)); // empty args
      }
    ;

arguments: expression {
            $$ = create_node(AST_ARGUMENTS, NULL);
            add_child($$, $1);
          }
         | arguments COMMA expression {
            $$ = $1;
            add_child($$, $3);
          }
         ;

primary: INT_NUM {
          char str[32];
          sprintf(str, "%d", $1);
          $$ = create_node(AST_INT, strdup(str));
        }
       | FLOAT_NUM {
          char str[32];
          sprintf(str, "%f", $1);
          $$ = create_node(AST_FLOAT, strdup(str));
        }
       | STRING {
          $$ = create_node(AST_STRING, $1);
        }
       | BOOL {
          $$ = create_node(AST_BOOL, $1 ? "True" : "False");
        }
       | NONE {
          $$ = create_node(AST_NONE, "None");
        }
       | IDENTIFIER {
          $$ = create_node(AST_IDENTIFIER, $1);
        }
       | LPAREN expression RPAREN {
          $$ = $2;
        }
       | list_expr {
          $$ = $1;
        }
       | dict_expr {
          $$ = $1;
        }
       ;

list_expr: LBRACKET arguments RBRACKET {
            $$ = create_node(AST_LIST, NULL);
            add_child($$, $2);
          }
         | LBRACKET RBRACKET {
            $$ = create_node(AST_LIST, NULL);
          }
         ;

dict_expr: LBRACE RBRACE {
            $$ = create_node(AST_DICT, NULL);
          }
         ;

%%

void yyerror(const char *s) {
    fprintf(stderr, "Error at line %d: %s\n", line_num, s);
}