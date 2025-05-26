%{
#include <stdio.h>
#include <string.h>
#include "parser.tab.h"

int line_num = 1;
int indent_level = 0;
int indent_stack[100] = {0};  // Stack to track indentation levels, initialized with 0
int stack_top = 1;            // Start with one element (0) in the stack

// For handling indentation
int pending_token = 0;
int pending_dedent_count = 0;

void update_indentation(int new_indent);
%}

%option noyywrap

DIGIT       [0-9]
NUMBER      {DIGIT}+|{DIGIT}+\.{DIGIT}*
IDENTIFIER  [a-zA-Z_][a-zA-Z0-9_]*
STRING      \"[^\"]*\"|\'[^\']*\'
WHITESPACE  [ \t]
NEWLINE     \n
INDENT      ^[ \t]+

%%

{NEWLINE}[ \t]+   { 
                      line_num++; 
                      // Get the indentation level
                      char *indent_text = yytext + 1; // Skip the newline
                      int i, new_indent = 0;
                      
                      for (i = 0; indent_text[i] != '\0'; i++) {
                          if (indent_text[i] == ' ')
                              new_indent++;
                          else if (indent_text[i] == '\t')
                              new_indent += 8; // Standard tab width
                      }
                      
                      // Update indentation state
                      update_indentation(new_indent);
                      
                      // Return NEWLINE, INDENT or DEDENT will be handled later
                      return NEWLINE;
                    }
{NEWLINE}           { 
                      line_num++;
                      // Zero indentation after newline
                      update_indentation(0);
                      return NEWLINE; 
                    }

"if"                { return IF; }
"else"              { return ELSE; }
"elif"              { return ELIF; }
"while"             { return WHILE; }
"for"               { return FOR; }
"in"                { return IN; }
"def"               { return DEF; }
"return"            { return RETURN; }
"import"            { return IMPORT; }
"print"             { return PRINT; }
"True"              { yylval.bval = 1; return BOOL; }
"False"             { yylval.bval = 0; return BOOL; }
"None"              { return NONE; }
"and"               { return AND; }
"or"                { return OR; }
"not"               { return NOT; }
"range"             { return RANGE; }

"+"                 { return PLUS; }
"-"                 { return MINUS; }
"*"                 { return TIMES; }
"/"                 { return DIVIDE; }
"%"                 { return MODULO; }
"="                 { return ASSIGN; }
"+="                { return PLUS_ASSIGN; }
"-="                { return MINUS_ASSIGN; }
"*="                { return TIMES_ASSIGN; }
"/="                { return DIVIDE_ASSIGN; }
"=="                { return EQ; }
"!="                { return NEQ; }
"<"                 { return LT; }
">"                 { return GT; }
"<="                { return LE; }
">="                { return GE; }
"("                 { return LPAREN; }
")"                 { return RPAREN; }
"["                 { return LBRACKET; }
"]"                 { return RBRACKET; }
"{"                 { return LBRACE; }

"}"                 { return RBRACE; }
":"                 { return COLON; }
","                 { return COMMA; }

{NUMBER}            { 
                      if (strchr(yytext, '.') != NULL) {
                          yylval.fval = atof(yytext); 
                          return FLOAT_NUM;
                      } else {
                          yylval.ival = atoi(yytext); 
                          return INT_NUM;
                      }
                    }
{IDENTIFIER}        { 
                      yylval.sval = strdup(yytext); 
                      return IDENTIFIER; 
                    }
{STRING}            { 
                      // Remove the quotes
                      yytext[strlen(yytext)-1] = '\0';
                      yylval.sval = strdup(yytext+1); 
                      return STRING; 
                    }
{WHITESPACE}        { /* ignore whitespace */ }

.                   { printf("Unknown character: %s\n", yytext); }
<<EOF>> {
    while (stack_top > 1) {
        stack_top--;
        pending_dedent_count++;
    }
    if (pending_dedent_count > 0) {
        pending_dedent_count--;
        return DEDENT;
    }
    return 0;
}


. { 
    printf("[debug raw char] '%s' at line %d\n", yytext, line_num); 
    printf("Unknown character: %s\n", yytext); 
}

%%

// Function to handle indentation tracking and queuing INDENT/DEDENT tokens
void update_indentation(int new_indent) {
    int current_indent = indent_stack[stack_top - 1];
    printf("[debug] line %d: current_indent=%d, new_indent=%d, stack_top=%d\n", line_num, current_indent, new_indent, stack_top);
    
    if (new_indent > current_indent) {
        indent_stack[stack_top++] = new_indent;
        pending_token = INDENT;
    } else if (new_indent < current_indent) {
        while (stack_top > 1 && new_indent < indent_stack[stack_top - 1]) {
            stack_top--;
            pending_dedent_count++;
        }

        if (indent_stack[stack_top - 1] != new_indent) {
            printf("Error: Inconsistent indentation at line %d\n", line_num);
        }

        // Emit only one DEDENT now, leave the rest for later
        if (pending_dedent_count > 0 && pending_token == 0) {
            pending_token = DEDENT;
            pending_dedent_count--;
        }
    }
}

const char* tokname(int tok) {
    switch (tok) {
        case IF: return "IF";
        case ELSE: return "ELSE";
        case ELIF: return "ELIF";
        case INDENT: return "INDENT";
        case DEDENT: return "DEDENT";
        case NEWLINE: return "NEWLINE";
        case IDENTIFIER: return "IDENTIFIER";
        case INT_NUM: return "INT_NUM";
        case ASSIGN: return "ASSIGN";
        case PLUS: return "PLUS";
        case TIMES: return "TIMES";
        case GT: return "GT";
        case PRINT: return "PRINT";
        case COLON: return "COLON";
        default: return "OTHER";
    }
}



// This is the function that the parser will call to get tokens
int get_token() {
    if (pending_token != 0) {
        int token = pending_token;
        pending_token = 0;
        printf("[token] %s\n", tokname(token));
        return token;
    }

    if (pending_dedent_count > 0) {
        pending_dedent_count--;
        printf("[token] DEDENT\n");
        return DEDENT;
    }

    int tok = yylex();
    printf("[token] %s\n", tokname(tok));
    return tok;
}



