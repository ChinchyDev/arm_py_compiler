#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "ast.h"

ASTNode *create_node(ASTNodeType type, char *value)
{
    ASTNode *node = (ASTNode *)malloc(sizeof(ASTNode));
    node->type = type;
    node->value = value ? strdup(value) : NULL;
    node->intValue = 0;
    node->floatValue = 0.0;
    node->boolValue = 0;
    node->children = NULL;
    node->children_count = 0;
    return node;
}
ASTNode *create_int_node(int val)
{
    char buf[32];
    snprintf(buf, sizeof(buf), "%d", val);
    ASTNode *node = create_node(AST_INT, buf);
    node->intValue = val;
    return node;
}
ASTNode *create_float_node(double val)
{
    char buf[64];
    snprintf(buf, sizeof(buf), "%f", val);
    ASTNode *node = create_node(AST_FLOAT, buf);
    node->floatValue = val;
    return node;
}
ASTNode *create_bool_node(int val)
{
    ASTNode *node = create_node(AST_BOOL, val ? "True" : "False");
    node->boolValue = val ? 1 : 0;
    return node;
}

void add_child(ASTNode *parent, ASTNode *child)
{
    if (!parent || !child)
        return;
    parent->children = (ASTNode **)realloc(parent->children, sizeof(ASTNode *) * (parent->children_count + 1));
    parent->children[parent->children_count++] = child;
}

void free_ast(ASTNode *node)
{
    if (!node)
        return;
    for (int i = 0; i < node->children_count; i++)
    {
        free_ast(node->children[i]);
    }
    free(node->children);
    free(node->value);
    free(node);
}

static void print_indent(int indent)
{
    for (int i = 0; i < indent; i++)
        printf("  ");
}
void print_ast(ASTNode *node, int indent)
{
    if (!node)
        return;
    print_indent(indent);
    printf("Type: %d", node->type);
    if (node->value)
        printf("  val:%s", node->value);
    if (node->type == AST_INT)
        printf(" (intValue: %d)", node->intValue);
    if (node->type == AST_FLOAT)
        printf(" (floatValue: %f)", node->floatValue);
    if (node->type == AST_BOOL)
        printf(" (boolValue: %d)", node->boolValue);
    printf("\n");
    for (int i = 0; i < node->children_count; i++)
    {
        print_ast(node->children[i], indent + 1);
    }
}

// This file contains the implementation of the AST (Abstract Syntax Tree) for the Python compiler.
