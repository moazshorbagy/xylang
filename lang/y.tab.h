/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015 Free Software Foundation, Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

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

#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    STRING_VAL = 258,
    IDENTIFIER = 259,
    BOOL_VAL = 260,
    INT = 261,
    FLOAT = 262,
    BOOL = 263,
    STRING = 264,
    CONST = 265,
    INT_VAL = 266,
    FLOAT_VAL = 267,
    COND_EQ = 268,
    COND_GREQ = 269,
    COND_LSEQ = 270,
    COND_NEQ = 271,
    WHILE = 272,
    IF = 273,
    ELSE = 274,
    DO = 275,
    FOR = 276,
    SWITCH = 277,
    CASE = 278,
    DEFAULT = 279
  };
#endif
/* Tokens.  */
#define STRING_VAL 258
#define IDENTIFIER 259
#define BOOL_VAL 260
#define INT 261
#define FLOAT 262
#define BOOL 263
#define STRING 264
#define CONST 265
#define INT_VAL 266
#define FLOAT_VAL 267
#define COND_EQ 268
#define COND_GREQ 269
#define COND_LSEQ 270
#define COND_NEQ 271
#define WHILE 272
#define IF 273
#define ELSE 274
#define DO 275
#define FOR 276
#define SWITCH 277
#define CASE 278
#define DEFAULT 279

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 15 "x.y" /* yacc.c:1909  */

	//nodeType* nodeTypeE;
    char* strVal;
    int intVal;
    //TODO
	char* boolVal;
    float floatVal;
    

#line 112 "y.tab.h" /* yacc.c:1909  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
