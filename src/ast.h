#ifndef AST_H
#define AST_H

typedef enum
{
    AST_STATEMENT_LIST,
    AST_EXPR_STMT,
    AST_ASSIGNMENT,
    AST_PLUS_ASSIGN,
    AST_MINUS_ASSIGN,
    AST_TIMES_ASSIGN,
    AST_DIVIDE_ASSIGN,
    AST_IF,
    AST_IF_ELIF,
    AST_IF_ELSE,
    AST_IF_ELIF_ELSE,
    AST_ELIF,
    AST_WHILE,
    AST_FOR,
    AST_FOR_RANGE,
    AST_FUNCTION_DEF,
    AST_RETURN,
    AST_IMPORT,
    AST_PRINT, // Added for print statement
    AST_PARAMETERS,
    AST_ARGUMENTS,
    AST_CALL,
    AST_OR,
    AST_AND,
    AST_EQ,
    AST_NEQ,
    AST_LT,
    AST_GT,
    AST_LE,
    AST_GE,
    AST_ADD,
    AST_SUB,
    AST_MUL,
    AST_DIV,
    AST_MOD,
    AST_NEG,
    AST_NOT,
    AST_INT,
    AST_FLOAT,
    AST_STRING,
    AST_BOOL,
    AST_NONE,
    AST_IDENTIFIER,
    AST_LIST,
    AST_DICT
} ASTNodeType;

typedef struct ASTNode
{
    ASTNodeType type;
    char *value;
    int intValue;
    double floatValue;
    int boolValue;
    struct ASTNode **children;
    int children_count;
} ASTNode;

ASTNode *create_node(ASTNodeType type, char *value);
ASTNode *create_int_node(int val);
ASTNode *create_float_node(double val);
ASTNode *create_bool_node(int val);
void add_child(ASTNode *parent, ASTNode *child);
void free_ast(ASTNode *node);
void print_ast(ASTNode *node, int indent);

#endif