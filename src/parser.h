/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2021 Free Software Foundation,
   Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <https://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

#ifndef YY_YY_SRC_PARSER_H_INCLUDED
# define YY_YY_SRC_PARSER_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token kinds.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    YYEMPTY = -2,
    YYEOF = 0,                     /* "end of file"  */
    YYerror = 256,                 /* error  */
    YYUNDEF = 257,                 /* "invalid token"  */
    INT_NUM = 258,                 /* INT_NUM  */
    FLOAT_NUM = 259,               /* FLOAT_NUM  */
    BOOL = 260,                    /* BOOL  */
    IDENTIFIER = 261,              /* IDENTIFIER  */
    STRING = 262,                  /* STRING  */
    NEWLINE = 263,                 /* NEWLINE  */
    INDENT = 264,                  /* INDENT  */
    DEDENT = 265,                  /* DEDENT  */
    IF = 266,                      /* IF  */
    ELSE = 267,                    /* ELSE  */
    ELIF = 268,                    /* ELIF  */
    WHILE = 269,                   /* WHILE  */
    FOR = 270,                     /* FOR  */
    IN = 271,                      /* IN  */
    DEF = 272,                     /* DEF  */
    RETURN = 273,                  /* RETURN  */
    IMPORT = 274,                  /* IMPORT  */
    NONE = 275,                    /* NONE  */
    RANGE = 276,                   /* RANGE  */
    AND = 277,                     /* AND  */
    OR = 278,                      /* OR  */
    NOT = 279,                     /* NOT  */
    PLUS = 280,                    /* PLUS  */
    MINUS = 281,                   /* MINUS  */
    TIMES = 282,                   /* TIMES  */
    DIVIDE = 283,                  /* DIVIDE  */
    MODULO = 284,                  /* MODULO  */
    ASSIGN = 285,                  /* ASSIGN  */
    PLUS_ASSIGN = 286,             /* PLUS_ASSIGN  */
    MINUS_ASSIGN = 287,            /* MINUS_ASSIGN  */
    TIMES_ASSIGN = 288,            /* TIMES_ASSIGN  */
    DIVIDE_ASSIGN = 289,           /* DIVIDE_ASSIGN  */
    EQ = 290,                      /* EQ  */
    NEQ = 291,                     /* NEQ  */
    LT = 292,                      /* LT  */
    GT = 293,                      /* GT  */
    LE = 294,                      /* LE  */
    GE = 295,                      /* GE  */
    LPAREN = 296,                  /* LPAREN  */
    RPAREN = 297,                  /* RPAREN  */
    LBRACKET = 298,                /* LBRACKET  */
    RBRACKET = 299,                /* RBRACKET  */
    LBRACE = 300,                  /* LBRACE  */
    RBRACE = 301,                  /* RBRACE  */
    COLON = 302,                   /* COLON  */
    COMMA = 303                    /* COMMA  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 17 "src/parser.y"

    int ival;
    float fval;
    int bval;  // Boolean
    char *sval;
    struct ASTNode *node;

#line 120 "src/parser.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_SRC_PARSER_H_INCLUDED  */
