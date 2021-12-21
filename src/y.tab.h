/* A Bison parser, made by GNU Bison 3.8.  */

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

#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
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
    YYUNDEF = 325,                 /* "invalid token"  */
    xxif = 300,                    /* xxif  */
    xxelse = 301,                  /* xxelse  */
    xxwhile = 302,                 /* xxwhile  */
    xxrept = 303,                  /* xxrept  */
    xxdo = 304,                    /* xxdo  */
    xxrb = 305,                    /* xxrb  */
    xxpred = 306,                  /* xxpred  */
    xxident = 307,                 /* xxident  */
    xxle = 308,                    /* xxle  */
    xxge = 309,                    /* xxge  */
    xxne = 310,                    /* xxne  */
    xxnum = 311,                   /* xxnum  */
    xxcom = 312,                   /* xxcom  */
    xxstring = 313,                /* xxstring  */
    xxexplist = 314,               /* xxexplist  */
    xxidpar = 315,                 /* xxidpar  */
    xxelseif = 316,                /* xxelseif  */
    xxlb = 318,                    /* xxlb  */
    xxend = 319,                   /* xxend  */
    xxcase = 320,                  /* xxcase  */
    xxswitch = 321,                /* xxswitch  */
    xxuntil = 322,                 /* xxuntil  */
    xxdefault = 323,               /* xxdefault  */
    xxeq = 324,                    /* xxeq  */
    xxuminus = 326                 /* xxuminus  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif
/* Token kinds.  */
#define YYEMPTY -2
#define YYEOF 0
#define YYerror 256
#define YYUNDEF 325
#define xxif 300
#define xxelse 301
#define xxwhile 302
#define xxrept 303
#define xxdo 304
#define xxrb 305
#define xxpred 306
#define xxident 307
#define xxle 308
#define xxge 309
#define xxne 310
#define xxnum 311
#define xxcom 312
#define xxstring 313
#define xxexplist 314
#define xxidpar 315
#define xxelseif 316
#define xxlb 318
#define xxend 319
#define xxcase 320
#define xxswitch 321
#define xxuntil 322
#define xxdefault 323
#define xxeq 324
#define xxuminus 326

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

#if !defined yyerror && !defined YYERROR_IS_DECLARED
void yyerror (const char *msg);
#endif
#if !defined yylex && !defined YYLEX_IS_DECLARED
int yylex (void);
#endif

int yyparse (void);


#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
