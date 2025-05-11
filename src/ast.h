/* ast.h */
#ifndef AST_H
#define AST_H

typedef enum {
    NODE_PROGRAM,
    NODE_STATEMENT_LIST,
    NODE_EXPRESSION_STMT,
    NODE_ASSIGNMENT,
    NODE_COMPOUND_ASSIGNMENT,
    NODE_IF,
    NODE_WHILE,
    NODE_FOR,
    NODE_FUNCTION_DEF,
    NODE_RETURN,
    NODE_IMPORT,
    NODE_BINARY_OP,
    NODE_UNARY_OP,
    NODE_CALL,
    NODE_IDENTIFIER,
    NODE_NUMBER,
    NODE_STRING,
    NODE_BOOLEAN,
    NODE_NONE,
    NODE_LIST,
    NODE_DICT
} NodeType;

typedef struct ASTNode {
    NodeType type;
    union {
        // For numbers
        double number_value;
        
        // For strings and identifiers
        char *string_value;
        
        // For boolean values
        int boolean_value;
        
        // For binary operations
        struct {
            int operator;
            struct ASTNode *left;
            struct ASTNode *right;
        } binary_op;
        
        // For unary operations
        struct {
            int operator;
            struct ASTNode *operand;
        } unary_op;
        
        // For if statements
        struct {
            struct ASTNode *condition;
            struct ASTNode *then_body;
            struct ASTNode *else_body;
        } if_stmt;
        
        // For while loops
        struct {
            struct ASTNode *condition;
            struct ASTNode *body;
        } while_loop;
        
        // For function definitions
        struct {
            char *name;
            struct ASTNode *params;
            struct ASTNode *body;
        } function_def;
        
        // Other node types...
    } data;
} ASTNode;

// Function declarations for creating AST nodes
ASTNode *create_statement_list(ASTNode *stmt, ASTNode *next);
ASTNode *create_expression_stmt(ASTNode *expr);
ASTNode *create_assignment(char *id, ASTNode *expr);
ASTNode *create_compound_assignment(int op, char *id, ASTNode *expr);
// More node creation functions...

extern ASTNode *program_root;

#endif