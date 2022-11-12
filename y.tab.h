/* A Bison parser, made by GNU Bison 3.5.1.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2020 Free Software Foundation,
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

/* Undocumented macros, especially those whose name start with YY_,
   are private implementation details.  Do not rely on them.  */

#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 1
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    WHILE = 258,
    TRUE = 259,
    FALSE = 260,
    EQ = 261,
    NEQ = 262,
    LOR = 263,
    LAND = 264,
    LNOT = 265,
    LTEQ = 266,
    GTEQ = 267,
    LT = 268,
    GT = 269,
    XOR = 270,
    BOR = 271,
    BAND = 272,
    AEQ = 273,
    INC = 274,
    DEC = 275,
    NUM = 276,
    ID = 277,
    IF = 278,
    ELSE = 279,
    STRUCT = 280,
    INT = 281,
    FLOAT = 282,
    LONG = 283,
    POINTER = 284,
    CHAR = 285,
    ARROP = 286,
    ARRCL = 287,
    CRLOP = 288,
    CRLCL = 289,
    ROP = 290,
    RCL = 291,
    UMINUS = 292
  };
#endif
/* Tokens.  */
#define WHILE 258
#define TRUE 259
#define FALSE 260
#define EQ 261
#define NEQ 262
#define LOR 263
#define LAND 264
#define LNOT 265
#define LTEQ 266
#define GTEQ 267
#define LT 268
#define GT 269
#define XOR 270
#define BOR 271
#define BAND 272
#define AEQ 273
#define INC 274
#define DEC 275
#define NUM 276
#define ID 277
#define IF 278
#define ELSE 279
#define STRUCT 280
#define INT 281
#define FLOAT 282
#define LONG 283
#define POINTER 284
#define CHAR 285
#define ARROP 286
#define ARRCL 287
#define CRLOP 288
#define CRLCL 289
#define ROP 290
#define RCL 291
#define UMINUS 292

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 81 "prob1.y"

	char string[100];

#line 135 "y.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
