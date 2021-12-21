/* A Bison parser, made by GNU Bison 3.8.  */

/* Bison implementation for Yacc-like parsers in C

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

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output, and Bison version.  */
#define YYBISON 30800

/* Bison version string.  */
#define YYBISON_VERSION "3.8"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 16 "beauty.y"

#include "b.h"
#include <stdio.h>

struct node *t;
void error(char *mess1, char *mess2, char *mess3);

#line 79 "y.tab.c"

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

/* Use api.header.include to #include this header
   instead of duplicating it here.  */
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
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_xxif = 3,                       /* xxif  */
  YYSYMBOL_xxelse = 4,                     /* xxelse  */
  YYSYMBOL_xxwhile = 5,                    /* xxwhile  */
  YYSYMBOL_xxrept = 6,                     /* xxrept  */
  YYSYMBOL_xxdo = 7,                       /* xxdo  */
  YYSYMBOL_xxrb = 8,                       /* xxrb  */
  YYSYMBOL_xxpred = 9,                     /* xxpred  */
  YYSYMBOL_xxident = 10,                   /* xxident  */
  YYSYMBOL_xxle = 11,                      /* xxle  */
  YYSYMBOL_xxge = 12,                      /* xxge  */
  YYSYMBOL_xxne = 13,                      /* xxne  */
  YYSYMBOL_xxnum = 14,                     /* xxnum  */
  YYSYMBOL_xxcom = 15,                     /* xxcom  */
  YYSYMBOL_xxstring = 16,                  /* xxstring  */
  YYSYMBOL_xxexplist = 17,                 /* xxexplist  */
  YYSYMBOL_xxidpar = 18,                   /* xxidpar  */
  YYSYMBOL_xxelseif = 19,                  /* xxelseif  */
  YYSYMBOL_xxlb = 20,                      /* xxlb  */
  YYSYMBOL_xxend = 21,                     /* xxend  */
  YYSYMBOL_xxcase = 22,                    /* xxcase  */
  YYSYMBOL_xxswitch = 23,                  /* xxswitch  */
  YYSYMBOL_xxuntil = 24,                   /* xxuntil  */
  YYSYMBOL_xxdefault = 25,                 /* xxdefault  */
  YYSYMBOL_xxeq = 26,                      /* xxeq  */
  YYSYMBOL_27_ = 27,                       /* '|'  */
  YYSYMBOL_28_ = 28,                       /* '&'  */
  YYSYMBOL_29_ = 29,                       /* '!'  */
  YYSYMBOL_30_ = 30,                       /* '<'  */
  YYSYMBOL_31_ = 31,                       /* '>'  */
  YYSYMBOL_32_ = 32,                       /* '+'  */
  YYSYMBOL_33_ = 33,                       /* '-'  */
  YYSYMBOL_34_ = 34,                       /* '*'  */
  YYSYMBOL_35_ = 35,                       /* '/'  */
  YYSYMBOL_xxuminus = 36,                  /* xxuminus  */
  YYSYMBOL_37_ = 37,                       /* '^'  */
  YYSYMBOL_38_ = 38,                       /* ':'  */
  YYSYMBOL_39_ = 39,                       /* '('  */
  YYSYMBOL_40_ = 40,                       /* ')'  */
  YYSYMBOL_41_ = 41,                       /* ','  */
  YYSYMBOL_42_ = 42,                       /* '='  */
  YYSYMBOL_43_ = 43,                       /* '{'  */
  YYSYMBOL_44_ = 44,                       /* '}'  */
  YYSYMBOL_YYACCEPT = 45,                  /* $accept  */
  YYSYMBOL_allprog = 46,                   /* allprog  */
  YYSYMBOL_prog = 47,                      /* prog  */
  YYSYMBOL_stat = 48,                      /* stat  */
  YYSYMBOL_xxtab = 49,                     /* xxtab  */
  YYSYMBOL_xxnl = 50,                      /* xxnl  */
  YYSYMBOL_xxnew = 51,                     /* xxnew  */
  YYSYMBOL_nlevel = 52,                    /* nlevel  */
  YYSYMBOL_pindent = 53,                   /* pindent  */
  YYSYMBOL_mindent = 54,                   /* mindent  */
  YYSYMBOL_caseseq = 55,                   /* caseseq  */
  YYSYMBOL_casetok = 56,                   /* casetok  */
  YYSYMBOL_xxctok = 57,                    /* xxctok  */
  YYSYMBOL_deftok = 58,                    /* deftok  */
  YYSYMBOL_swtok = 59,                     /* swtok  */
  YYSYMBOL_fstok = 60,                     /* fstok  */
  YYSYMBOL_identtok = 61,                  /* identtok  */
  YYSYMBOL_predlist = 62,                  /* predlist  */
  YYSYMBOL_explist = 63,                   /* explist  */
  YYSYMBOL_oppred = 64,                    /* oppred  */
  YYSYMBOL_pred = 65,                      /* pred  */
  YYSYMBOL_expr = 66,                      /* expr  */
  YYSYMBOL_iftok = 67,                     /* iftok  */
  YYSYMBOL_elsetok = 68,                   /* elsetok  */
  YYSYMBOL_whtok = 69,                     /* whtok  */
  YYSYMBOL_rpttok = 70,                    /* rpttok  */
  YYSYMBOL_optuntil = 71,                  /* optuntil  */
  YYSYMBOL_unttok = 72,                    /* unttok  */
  YYSYMBOL_dotok = 73,                     /* dotok  */
  YYSYMBOL_dopart = 74,                    /* dopart  */
  YYSYMBOL_opdotok = 75,                   /* opdotok  */
  YYSYMBOL_lbtok = 76,                     /* lbtok  */
  YYSYMBOL_rbtok = 77,                     /* rbtok  */
  YYSYMBOL_labtok = 78,                    /* labtok  */
  YYSYMBOL_comtok = 79                     /* comtok  */
};
typedef enum yysymbol_kind_t yysymbol_kind_t;




#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

/* Work around bug in HP-UX 11.23, which defines these macros
   incorrectly for preprocessor constants.  This workaround can likely
   be removed in 2023, as HPE has promised support for HP-UX 11.23
   (aka HP-UX 11i v2) only through the end of 2022; see Table 2 of
   <https://h20195.www2.hpe.com/V2/getpdf.aspx/4AA4-7673ENW.pdf>.  */
#ifdef __hpux
# undef UINT_LEAST8_MAX
# undef UINT_LEAST16_MAX
# define UINT_LEAST8_MAX 255
# define UINT_LEAST16_MAX 65535
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))


/* Stored state numbers (used for stacks). */
typedef yytype_uint8 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif


#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YY_USE(E) ((void) (E))
#else
# define YY_USE(E) /* empty */
#endif

/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
#if defined __GNUC__ && ! defined __ICC && 406 <= __GNUC__ * 100 + __GNUC_MINOR__
# if __GNUC__ * 100 + __GNUC_MINOR__ < 407
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")
# else
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# endif
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

#if !defined yyoverflow

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* !defined yyoverflow */

#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  13
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   418

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  45
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  35
/* YYNRULES -- Number of rules.  */
#define YYNRULES  77
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  140

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   326


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK                     \
   ? YY_CAST (yysymbol_kind_t, yytranslate[YYX])        \
   : YYSYMBOL_YYUNDEF)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    29,     2,     2,     2,     2,    28,     2,
      39,    40,    34,    32,    41,    33,     2,    35,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    38,     2,
      30,    42,    31,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,    37,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    43,    27,    44,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       3,     4,     5,     6,     7,     8,     9,    10,    11,    12,
      13,    14,    15,    16,    17,    18,    19,     2,    20,    21,
      22,    23,    24,    25,    26,     2,    36
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,    27,    27,    30,    31,    34,    35,    36,    37,    38,
      39,    40,    41,    42,    43,    44,    45,    49,    54,    55,
      56,    58,    63,    67,    68,    71,    72,    73,    74,    77,
      80,    87,    89,    96,   106,   111,   114,   119,   120,   124,
     125,   128,   131,   132,   133,   134,   135,   136,   137,   138,
     139,   140,   141,   142,   143,   144,   145,   146,   147,   148,
     149,   150,   153,   171,   178,   183,   188,   189,   192,   197,
     199,   211,   215,   216,   220,   221,   227,   228
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if YYDEBUG || 0
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "xxif", "xxelse",
  "xxwhile", "xxrept", "xxdo", "xxrb", "xxpred", "xxident", "xxle", "xxge",
  "xxne", "xxnum", "xxcom", "xxstring", "xxexplist", "xxidpar", "xxelseif",
  "xxlb", "xxend", "xxcase", "xxswitch", "xxuntil", "xxdefault", "xxeq",
  "'|'", "'&'", "'!'", "'<'", "'>'", "'+'", "'-'", "'*'", "'/'",
  "xxuminus", "'^'", "':'", "'('", "')'", "','", "'='", "'{'", "'}'",
  "$accept", "allprog", "prog", "stat", "xxtab", "xxnl", "xxnew", "nlevel",
  "pindent", "mindent", "caseseq", "casetok", "xxctok", "deftok", "swtok",
  "fstok", "identtok", "predlist", "explist", "oppred", "pred", "expr",
  "iftok", "elsetok", "whtok", "rpttok", "optuntil", "unttok", "dotok",
  "dopart", "opdotok", "lbtok", "rbtok", "labtok", "comtok", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-103)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-25)

#define yytable_value_is_error(Yyn) \
  ((Yyn) == YYTABLE_NINF)

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     205,  -103,  -103,  -103,  -103,    11,   138,  -103,   119,     1,
     -21,   157,   205,  -103,  -103,  -103,  -103,  -103,    14,  -103,
    -103,  -103,   -21,  -103,   -21,  -103,  -103,   -16,  -103,   226,
     117,  -103,  -103,   181,  -103,  -103,   -13,    -3,  -103,  -103,
    -103,    21,   205,  -103,   117,  -103,  -103,  -103,  -103,  -103,
     117,   117,   117,   117,  -103,   274,    29,     7,   117,   117,
       5,  -103,    22,  -103,  -103,   334,   371,    12,    12,   304,
     117,   117,   117,   117,   117,   117,   117,   117,   117,   117,
     117,   117,   117,  -103,  -103,  -103,  -103,    17,   231,   262,
      37,  -103,   -21,  -103,  -103,   381,   381,   381,   381,   344,
     371,   381,   381,     3,     3,    12,    12,    12,  -103,  -103,
     117,   117,     9,     1,  -103,   -12,  -103,  -103,   334,  -103,
      39,   117,  -103,    45,    34,  -103,  -103,  -103,    41,   205,
    -103,  -103,    93,  -103,    93,  -103,    93,  -103,  -103,  -103
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,    16,    62,    75,    73,     0,     0,     3,     0,     0,
       0,     0,     0,     1,     4,     2,    64,    65,     0,    33,
      32,    31,    40,    11,     0,    21,    21,    72,    76,     0,
       0,    21,    74,     0,    13,    14,    35,     0,    21,    39,
      21,    67,     0,     9,     0,    69,    77,    15,    60,    61,
       0,     0,     0,     0,    59,     0,     6,     0,     0,     0,
       0,     7,     0,     8,    22,    71,    45,    44,    43,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    41,    63,    21,    12,     0,    38,     0,
      17,    68,     0,    20,    42,    56,    57,    58,    55,    51,
      52,    54,    53,    46,    47,    48,    49,    50,     5,    34,
       0,     0,     0,     0,    17,    17,    66,    37,    70,    29,
       0,     0,    21,    17,     0,    23,    30,    21,     0,     0,
      28,    22,     0,    36,     0,    10,     0,    26,    27,    25
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
    -103,  -103,   -10,    -6,   -31,   -68,  -103,   -11,   -34,   -78,
     -35,   -42,  -103,  -103,  -103,  -103,    64,  -103,  -102,  -103,
     -17,    -9,  -103,  -103,  -103,  -103,  -103,  -103,  -103,  -103,
    -103,    25,   -48,  -103,   -27
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
       0,     5,     6,     7,     8,     9,    15,    41,    42,    93,
     114,   115,   121,   122,    22,    23,    54,   127,    87,    38,
      31,    88,    10,    85,    24,    25,    63,    92,    26,    27,
      45,    11,    34,    12,    29
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      14,    33,    57,   -18,    60,    39,    35,    40,   117,    86,
      62,    13,    16,    17,    18,    43,    28,    19,    30,   128,
      56,    55,   113,    47,    36,    44,    58,    14,    20,    61,
      21,   119,   -24,    84,   120,    65,    64,    80,    81,    59,
      82,    66,    67,    68,    69,   -17,    91,   113,     4,    82,
      89,    32,   -18,   135,   137,   113,   138,   109,   139,   112,
      46,    95,    96,    97,    98,    99,   100,   101,   102,   103,
     104,   105,   106,   107,   108,   116,   131,   126,    32,   133,
     125,   130,    37,   124,   112,    90,   123,     0,   129,     0,
       0,     0,   112,   132,     1,     0,     2,     0,   -17,   -17,
     -17,     0,   118,   -17,     0,     0,     0,     3,   -18,     0,
       0,     0,     0,     0,   -17,   -22,   -17,     0,   -22,   134,
       0,     0,   136,     0,    16,    17,    18,    36,    14,    19,
      14,    48,     0,    49,     0,     0,     4,   -22,   -19,     1,
      20,     2,    21,   -17,   -17,   -17,    50,     0,   -17,    51,
      52,     0,     3,   -18,     0,     0,    53,     0,     1,   -17,
       2,   -17,   -17,   -17,   -17,     0,     0,   -17,     0,     0,
       0,     3,   -18,     0,     0,     0,     0,     0,   -17,     0,
     -17,     4,     1,     0,     2,     0,   -17,   -17,   -17,     0,
       0,   -17,     0,     0,     0,     3,   -18,     0,     0,     0,
       4,    32,   -17,     0,   -17,     0,     1,     0,     2,     0,
     -17,   -17,   -17,     0,     0,   -17,     0,     0,     0,     3,
     -18,     0,     0,     0,     4,   -17,   -17,     1,   -17,     2,
       0,   -17,   -17,   -17,     0,     0,   -17,     0,     0,     0,
       3,    46,    70,    71,    72,     0,     0,   -17,     4,   -17,
       0,     0,     0,     0,     0,     0,     0,    73,    74,    75,
       0,    76,    77,    78,    79,    80,    81,     0,    82,     4,
       0,     0,   110,    70,    71,    72,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    70,    71,    72,    73,    74,
      75,     0,    76,    77,    78,    79,    80,    81,     0,    82,
      73,    74,    75,   111,    76,    77,    78,    79,    80,    81,
       0,    82,     0,     0,    83,    70,    71,    72,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      73,    74,    75,     0,    76,    77,    78,    79,    80,    81,
       0,    82,     0,     0,    94,    70,    71,    72,     0,     0,
       0,     0,     0,     0,     0,    70,    71,    72,     0,     0,
      73,    74,    75,     0,    76,    77,    78,    79,    80,    81,
      73,    82,    75,     0,    76,    77,    78,    79,    80,    81,
       0,    82,    70,    71,    72,     0,     0,     0,     0,     0,
       0,     0,   -25,   -25,   -25,     0,     0,    73,     0,     0,
       0,    76,    77,    78,    79,    80,    81,   -25,    82,     0,
       0,   -25,   -25,    78,    79,    80,    81,     0,    82
};

static const yytype_int16 yycheck[] =
{
       6,    11,    33,    15,    38,    22,    12,    24,   110,    57,
      41,     0,     5,     6,     7,    26,    15,    10,    39,   121,
      31,    30,    90,    29,    10,    41,    39,    33,    21,    40,
      23,    22,    44,     4,    25,    44,    42,    34,    35,    42,
      37,    50,    51,    52,    53,    24,    24,   115,    43,    37,
      59,    44,    15,   131,   132,   123,   134,    40,   136,    90,
      15,    70,    71,    72,    73,    74,    75,    76,    77,    78,
      79,    80,    81,    82,    85,    92,   124,    38,    44,    38,
     115,   123,    18,   114,   115,    60,   113,    -1,   122,    -1,
      -1,    -1,   123,   127,     1,    -1,     3,    -1,     5,     6,
       7,    -1,   111,    10,    -1,    -1,    -1,    14,    15,    -1,
      -1,    -1,    -1,    -1,    21,    22,    23,    -1,    25,   129,
      -1,    -1,   132,    -1,     5,     6,     7,    10,   134,    10,
     136,    14,    -1,    16,    -1,    -1,    43,    44,     0,     1,
      21,     3,    23,     5,     6,     7,    29,    -1,    10,    32,
      33,    -1,    14,    15,    -1,    -1,    39,    -1,     1,    21,
       3,    23,     5,     6,     7,    -1,    -1,    10,    -1,    -1,
      -1,    14,    15,    -1,    -1,    -1,    -1,    -1,    21,    -1,
      23,    43,     1,    -1,     3,    -1,     5,     6,     7,    -1,
      -1,    10,    -1,    -1,    -1,    14,    15,    -1,    -1,    -1,
      43,    44,    21,    -1,    23,    -1,     1,    -1,     3,    -1,
       5,     6,     7,    -1,    -1,    10,    -1,    -1,    -1,    14,
      15,    -1,    -1,    -1,    43,    44,    21,     1,    23,     3,
      -1,     5,     6,     7,    -1,    -1,    10,    -1,    -1,    -1,
      14,    15,    11,    12,    13,    -1,    -1,    21,    43,    23,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    26,    27,    28,
      -1,    30,    31,    32,    33,    34,    35,    -1,    37,    43,
      -1,    -1,    41,    11,    12,    13,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    11,    12,    13,    26,    27,
      28,    -1,    30,    31,    32,    33,    34,    35,    -1,    37,
      26,    27,    28,    41,    30,    31,    32,    33,    34,    35,
      -1,    37,    -1,    -1,    40,    11,    12,    13,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      26,    27,    28,    -1,    30,    31,    32,    33,    34,    35,
      -1,    37,    -1,    -1,    40,    11,    12,    13,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    11,    12,    13,    -1,    -1,
      26,    27,    28,    -1,    30,    31,    32,    33,    34,    35,
      26,    37,    28,    -1,    30,    31,    32,    33,    34,    35,
      -1,    37,    11,    12,    13,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    11,    12,    13,    -1,    -1,    26,    -1,    -1,
      -1,    30,    31,    32,    33,    34,    35,    26,    37,    -1,
      -1,    30,    31,    32,    33,    34,    35,    -1,    37
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     1,     3,    14,    43,    46,    47,    48,    49,    50,
      67,    76,    78,     0,    48,    51,     5,     6,     7,    10,
      21,    23,    59,    60,    69,    70,    73,    74,    15,    79,
      39,    65,    44,    47,    77,    48,    10,    61,    64,    65,
      65,    52,    53,    52,    41,    75,    15,    48,    14,    16,
      29,    32,    33,    39,    61,    66,    52,    49,    39,    42,
      53,    52,    49,    71,    48,    66,    66,    66,    66,    66,
      11,    12,    13,    26,    27,    28,    30,    31,    32,    33,
      34,    35,    37,    40,     4,    68,    77,    63,    66,    66,
      76,    24,    72,    54,    40,    66,    66,    66,    66,    66,
      66,    66,    66,    66,    66,    66,    66,    66,    52,    40,
      41,    41,    49,    50,    55,    56,    65,    63,    66,    22,
      25,    57,    58,    79,    49,    55,    38,    62,    63,    53,
      56,    77,    53,    38,    47,    54,    47,    54,    54,    54
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    45,    46,    47,    47,    48,    48,    48,    48,    48,
      48,    48,    48,    48,    48,    48,    48,    49,    50,    51,
      52,    53,    54,    55,    55,    56,    56,    56,    56,    57,
      58,    59,    60,    60,    61,    61,    62,    63,    63,    64,
      64,    65,    66,    66,    66,    66,    66,    66,    66,    66,
      66,    66,    66,    66,    66,    66,    66,    66,    66,    66,
      66,    66,    67,    68,    69,    70,    71,    71,    72,    73,
      74,    75,    75,    76,    77,    78,    79,    79
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     2,     1,     2,     5,     3,     4,     4,     3,
       9,     2,     4,     2,     2,     3,     1,     0,     0,     0,
       3,     0,     0,     2,     1,     6,     5,     5,     3,     1,
       2,     1,     1,     1,     4,     1,     2,     3,     1,     1,
       0,     3,     3,     2,     2,     2,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     1,
       1,     1,     1,     1,     1,     1,     3,     0,     1,     2,
       6,     2,     0,     1,     1,     1,     1,     2
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYNOMEM         goto yyexhaustedlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
  do                                                              \
    if (yychar == YYEMPTY)                                        \
      {                                                           \
        yychar = (Token);                                         \
        yylval = (Value);                                         \
        YYPOPSTACK (yylen);                                       \
        yystate = *yyssp;                                         \
        goto yybackup;                                            \
      }                                                           \
    else                                                          \
      {                                                           \
        yyerror (YY_("syntax error: cannot back up")); \
        YYERROR;                                                  \
      }                                                           \
  while (0)

/* Backward compatibility with an undocumented macro.
   Use YYerror or YYUNDEF. */
#define YYERRCODE YYUNDEF


/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)




# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YY_USE (yyoutput);
  if (!yyvaluep)
    return;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo,
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  yy_symbol_value_print (yyo, yykind, yyvaluep);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp,
                 int yyrule)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       YY_ACCESSING_SYMBOL (+yyssp[yyi + 1 - yynrhs]),
                       &yyvsp[(yyi + 1) - (yynrhs)]);
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args) ((void) 0)
# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif






/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg,
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep)
{
  YY_USE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/* Lookahead token kind.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;




/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    yy_state_fast_t yystate = 0;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus = 0;

    /* Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* Their size.  */
    YYPTRDIFF_T yystacksize = YYINITDEPTH;

    /* The state stack: array, bottom, top.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss = yyssa;
    yy_state_t *yyssp = yyss;

    /* The semantic value stack: array, bottom, top.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs = yyvsa;
    YYSTYPE *yyvsp = yyvs;

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yychar = YYEMPTY; /* Cause a token to be read.  */

  goto yysetstate;


/*------------------------------------------------------------.
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END
  YY_STACK_PRINT (yyss, yyssp);

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    YYNOMEM;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        YYNOMEM;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          YYNOMEM;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */


  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;


/*-----------.
| yybackup.  |
`-----------*/
yybackup:
  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either empty, or end-of-input, or a valid lookahead.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token\n"));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = YYEOF;
      yytoken = YYSYMBOL_YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else if (yychar == YYerror)
    {
      /* The scanner already issued an error message, process directly
         to error recovery.  But do not keep the error token as
         lookahead, it is too special and may lead us to an endless
         loop in error recovery. */
      yychar = YYUNDEF;
      yytoken = YYSYMBOL_YYerror;
      goto yyerrlab1;
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
  case 17: /* xxtab: %empty  */
#line 49 "beauty.y"
                        {
			if (!xxlablast) tab(xxindent);
			xxlablast = 0;
			}
#line 1398 "y.tab.c"
    break;

  case 18: /* xxnl: %empty  */
#line 54 "beauty.y"
                { newline(); }
#line 1404 "y.tab.c"
    break;

  case 19: /* xxnew: %empty  */
#line 55 "beauty.y"
                { putout('\n',"\n"); }
#line 1410 "y.tab.c"
    break;

  case 21: /* pindent: %empty  */
#line 58 "beauty.y"
                                {
				if (xxstack[xxstind] != xxlb)
					++xxindent;
				}
#line 1419 "y.tab.c"
    break;

  case 22: /* mindent: %empty  */
#line 63 "beauty.y"
                                {if (xxstack[xxstind] != xxlb && xxstack[xxstind] != xxelseif)
					--xxindent;
				pop();
				}
#line 1428 "y.tab.c"
    break;

  case 29: /* xxctok: xxcase  */
#line 77 "beauty.y"
                                {putout(xxcase,"case "); free (yyvsp[0]); push(xxcase); }
#line 1434 "y.tab.c"
    break;

  case 30: /* deftok: xxdefault ':'  */
#line 80 "beauty.y"
                                                {
						putout(xxcase,"default");
						free(yyvsp[-1]);
						putout(':',":");
						free(yyvsp[0]);
						push(xxcase);
						}
#line 1446 "y.tab.c"
    break;

  case 31: /* swtok: xxswitch  */
#line 87 "beauty.y"
                                                {putout(xxswitch,"switch"); free(yyvsp[0]); push(xxswitch); }
#line 1452 "y.tab.c"
    break;

  case 32: /* fstok: xxend  */
#line 89 "beauty.y"
                                {
				free(yyvsp[0]);
				putout(xxident,"end");
				putout('\n',"\n");
				putout('\n',"\n");
				putout('\n',"\n");
				}
#line 1464 "y.tab.c"
    break;

  case 33: /* fstok: xxident  */
#line 96 "beauty.y"
                                {
				putout(xxident,yyvsp[0]);
				free(yyvsp[0]);
				newflag = 1;
				forst();
				newflag = 0;
				}
#line 1476 "y.tab.c"
    break;

  case 34: /* identtok: xxident '(' explist ')'  */
#line 106 "beauty.y"
                                                {
				xxt = addroot(yyvsp[-3],xxident,0,0);
				yyval = addroot("",xxidpar,xxt,yyvsp[-1]);
				}
#line 1485 "y.tab.c"
    break;

  case 35: /* identtok: xxident  */
#line 111 "beauty.y"
                                        {yyval = addroot(yyvsp[0],xxident,0,0);}
#line 1491 "y.tab.c"
    break;

  case 36: /* predlist: explist ':'  */
#line 114 "beauty.y"
                                {
				yield(yyvsp[-1],0);
				putout(':',":");
				freetree(yyvsp[-1]);
				}
#line 1501 "y.tab.c"
    break;

  case 37: /* explist: expr ',' explist  */
#line 119 "beauty.y"
                                                        { yyval = addroot(yyvsp[-1],xxexplist,checkneg(yyvsp[-2],0),yyvsp[0]); }
#line 1507 "y.tab.c"
    break;

  case 38: /* explist: expr  */
#line 120 "beauty.y"
                                                        { yyval = checkneg(yyvsp[0],0); }
#line 1513 "y.tab.c"
    break;

  case 41: /* pred: '(' expr ')'  */
#line 128 "beauty.y"
                                { t = checkneg(yyvsp[-1],0);
				yield(t,100);  freetree(t);	}
#line 1520 "y.tab.c"
    break;

  case 42: /* expr: '(' expr ')'  */
#line 131 "beauty.y"
                                        { yyval = yyvsp[-1]; }
#line 1526 "y.tab.c"
    break;

  case 43: /* expr: '-' expr  */
#line 132 "beauty.y"
                                                        { yyval = addroot(yyvsp[-1],xxuminus,yyvsp[0],0); }
#line 1532 "y.tab.c"
    break;

  case 44: /* expr: '+' expr  */
#line 133 "beauty.y"
                                                        { yyval = yyvsp[0]; }
#line 1538 "y.tab.c"
    break;

  case 45: /* expr: '!' expr  */
#line 134 "beauty.y"
                                        { yyval = addroot(yyvsp[-1],'!',yyvsp[0],0); }
#line 1544 "y.tab.c"
    break;

  case 46: /* expr: expr '+' expr  */
#line 135 "beauty.y"
                                        { yyval = addroot(yyvsp[-1],'+',yyvsp[-2],yyvsp[0]); }
#line 1550 "y.tab.c"
    break;

  case 47: /* expr: expr '-' expr  */
#line 136 "beauty.y"
                                        { yyval = addroot(yyvsp[-1],'-',yyvsp[-2],yyvsp[0]); }
#line 1556 "y.tab.c"
    break;

  case 48: /* expr: expr '*' expr  */
#line 137 "beauty.y"
                                        { yyval = addroot(yyvsp[-1],'*',yyvsp[-2],yyvsp[0]); }
#line 1562 "y.tab.c"
    break;

  case 49: /* expr: expr '/' expr  */
#line 138 "beauty.y"
                                        { yyval = addroot(yyvsp[-1],'/',yyvsp[-2],yyvsp[0]); }
#line 1568 "y.tab.c"
    break;

  case 50: /* expr: expr '^' expr  */
#line 139 "beauty.y"
                                        { yyval = addroot(yyvsp[-1],'^',yyvsp[-2],yyvsp[0]); }
#line 1574 "y.tab.c"
    break;

  case 51: /* expr: expr '|' expr  */
#line 140 "beauty.y"
                                        { yyval = addroot(yyvsp[-1],'|',yyvsp[-2],yyvsp[0]); }
#line 1580 "y.tab.c"
    break;

  case 52: /* expr: expr '&' expr  */
#line 141 "beauty.y"
                                        { yyval = addroot(yyvsp[-1],'&',yyvsp[-2],yyvsp[0]); }
#line 1586 "y.tab.c"
    break;

  case 53: /* expr: expr '>' expr  */
#line 142 "beauty.y"
                                        { yyval = addroot(yyvsp[-1],'>',yyvsp[-2],yyvsp[0]); }
#line 1592 "y.tab.c"
    break;

  case 54: /* expr: expr '<' expr  */
#line 143 "beauty.y"
                                        { yyval = addroot(yyvsp[-1],'<',yyvsp[-2],yyvsp[0]); }
#line 1598 "y.tab.c"
    break;

  case 55: /* expr: expr xxeq expr  */
#line 144 "beauty.y"
                                        { yyval = addroot(yyvsp[-1],xxeq,yyvsp[-2],yyvsp[0]); }
#line 1604 "y.tab.c"
    break;

  case 56: /* expr: expr xxle expr  */
#line 145 "beauty.y"
                                        { yyval = addroot(yyvsp[-1],xxle,yyvsp[-2],yyvsp[0]); }
#line 1610 "y.tab.c"
    break;

  case 57: /* expr: expr xxge expr  */
#line 146 "beauty.y"
                                        { yyval = addroot(yyvsp[-1],xxge,yyvsp[-2],yyvsp[0]); }
#line 1616 "y.tab.c"
    break;

  case 58: /* expr: expr xxne expr  */
#line 147 "beauty.y"
                                        { yyval = addroot(yyvsp[-1],xxne,yyvsp[-2],yyvsp[0]); }
#line 1622 "y.tab.c"
    break;

  case 59: /* expr: identtok  */
#line 148 "beauty.y"
                                        { yyval = yyvsp[0]; }
#line 1628 "y.tab.c"
    break;

  case 60: /* expr: xxnum  */
#line 149 "beauty.y"
                                        { yyval = addroot(yyvsp[0],xxnum,0,0); }
#line 1634 "y.tab.c"
    break;

  case 61: /* expr: xxstring  */
#line 150 "beauty.y"
                                        { yyval = addroot(yyvsp[0],xxstring,0,0); }
#line 1640 "y.tab.c"
    break;

  case 62: /* iftok: xxif  */
#line 154 "beauty.y"
                                {
				if (xxstack[xxstind] == xxelse && !xxlablast)
					{
					--xxindent;
					xxstack[xxstind] = xxelseif;
					putout(' '," ");
					}
				else
					{
					if (!xxlablast)
						tab(xxindent);
					xxlablast = 0;
					}
				putout(xxif,"if");
				free(yyvsp[0]);
				push(xxif);
				}
#line 1662 "y.tab.c"
    break;

  case 63: /* elsetok: xxelse  */
#line 172 "beauty.y"
                                {
				tab(xxindent);
				putout(xxelse,"else");
				free(yyvsp[0]);
				push(xxelse);
				}
#line 1673 "y.tab.c"
    break;

  case 64: /* whtok: xxwhile  */
#line 178 "beauty.y"
                                {
				putout(xxwhile,"while");
				free(yyvsp[0]);
				push(xxwhile);
				}
#line 1683 "y.tab.c"
    break;

  case 65: /* rpttok: xxrept  */
#line 183 "beauty.y"
                                        {
					putout(xxrept,"repeat");
					free(yyvsp[0]);
					push(xxrept);
					}
#line 1693 "y.tab.c"
    break;

  case 68: /* unttok: xxuntil  */
#line 192 "beauty.y"
                        {
			putout('\t',"\t");
			putout(xxuntil,"until");
			free(yyvsp[0]);
			}
#line 1703 "y.tab.c"
    break;

  case 70: /* dopart: xxdo identtok '=' expr ',' expr  */
#line 200 "beauty.y"
                                        {push(xxdo);
					putout(xxdo,"do");
					free(yyvsp[-5]);
					puttree(yyvsp[-4]);
					putout('=',"=");
					free(yyvsp[-3]);
					puttree(yyvsp[-2]);
					putout(',',",");
					free(yyvsp[-1]);
					puttree(yyvsp[0]);
					}
#line 1719 "y.tab.c"
    break;

  case 71: /* opdotok: ',' expr  */
#line 211 "beauty.y"
                                                {
						putout(',',",");
						puttree(yyvsp[0]);
						}
#line 1728 "y.tab.c"
    break;

  case 73: /* lbtok: '{'  */
#line 216 "beauty.y"
                                {
				putout('{'," {");
				push(xxlb);
				}
#line 1737 "y.tab.c"
    break;

  case 74: /* rbtok: '}'  */
#line 220 "beauty.y"
                                        { putout('}',"}");  pop();   }
#line 1743 "y.tab.c"
    break;

  case 75: /* labtok: xxnum  */
#line 221 "beauty.y"
                                {
				tab(xxindent);
				putout(xxnum,yyvsp[0]);
				putout(' ',"  ");
				xxlablast = 1;
				}
#line 1754 "y.tab.c"
    break;

  case 76: /* comtok: xxcom  */
#line 227 "beauty.y"
                                { putout(xxcom,yyvsp[0]);  free(yyvsp[0]);  xxlablast = 0; }
#line 1760 "y.tab.c"
    break;

  case 77: /* comtok: comtok xxcom  */
#line 228 "beauty.y"
                                        { putout ('\n',"\n"); putout(xxcom,yyvsp[0]);  free(yyvsp[0]);  xxlablast = 0; }
#line 1766 "y.tab.c"
    break;


#line 1770 "y.tab.c"

      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", YY_CAST (yysymbol_kind_t, yyr1[yyn]), &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYSYMBOL_YYEMPTY : YYTRANSLATE (yychar);
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
      yyerror (YY_("syntax error"));
    }

  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;
  ++yynerrs;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  /* Pop stack until we find a state that shifts the error token.  */
  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYSYMBOL_YYerror;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYSYMBOL_YYerror)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;


      yydestruct ("Error: popping",
                  YY_ACCESSING_SYMBOL (yystate), yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", YY_ACCESSING_SYMBOL (yyn), yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturnlab;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturnlab;


/*-----------------------------------------------------------.
| yyexhaustedlab -- YYNOMEM (memory exhaustion) comes here.  |
`-----------------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturnlab;


/*----------------------------------------------------------.
| yyreturnlab -- parsing is finished, clean up and return.  |
`----------------------------------------------------------*/
yyreturnlab:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif

  return yyresult;
}

#line 229 "beauty.y"

#define ASSERT(X,Y)	if (!(X)) error("struct bug: assertion 'X' invalid in routine Y","","");

yyerror(s)
char *s;
	{
	extern int yychar;
	fprintf(stderr,"\n%s",s);
	fprintf(stderr," in beautifying, output line %d,",xxlineno + 1);
	fprintf(stderr," on input: ");
		switch (yychar) {
			case '\t': fprintf(stderr,"\\t\n"); return;
			case '\n': fprintf(stderr,"\\n\n"); return;
			case '\0': fprintf(stderr,"$end\n"); return;
			default: fprintf(stderr,"%c\n",yychar); return;
			}
	}

yyinit(argc, argv)			/* initialize pushdown store */
int argc;
char *argv[];
	{
	xxindent = 0;
	xxbpertab = 8;
	xxmaxchars = 120;
	}


#include <signal.h>
main()
	{
	int exit();
	if ( signal(SIGINT, SIG_IGN) != SIG_IGN)
		signal(SIGINT, exit);
	yyinit();
	yyparse();
	}


putout(type,string)			/* output string with proper indentation */
int type;
char *string;
	{
	static int lasttype;
	if ( (lasttype != 0) && (lasttype != '\n') && (lasttype != ' ') && (lasttype != '\t') && (type == xxcom))
		accum("\t");
	else if (lasttype == xxcom && type != '\n')
		tab(xxindent);
	else
		if (lasttype == xxif	||
			lasttype == xxwhile	||
			lasttype == xxdo	||
			type == '='	||
			lasttype == '='	||
			(lasttype == xxident && (type == xxident || type == xxnum) )	||
			(lasttype == xxnum && type == xxnum) )
			accum(" ");
	accum(string);
	lasttype = type;
	}


accum(token)		/* fill output buffer, generate continuation lines */
char *token;
	{
	static char *buffer;
	static int lstatus,llen,bufind;
	int tstatus,tlen,i;

#define NEW	0
#define MID	1
#define CONT	2

	if (buffer == 0)
		{
		buffer = malloc(xxmaxchars);
		if (buffer == 0) error("malloc out of space","","");
		}
	tlen = slength(token);
	if (tlen == 0) return;
	for (i = 0; i < tlen; ++i)
		ASSERT(token[i] != '\n' || tlen == 1,accum);
	switch(token[tlen-1])
		{
		case '\n':	tstatus = NEW;
				break;
		case '+':
		case '-':
		case '*':
		case ',':
		case '|':
		case '&':
		case '(':	tstatus = CONT;
				break;
		default:	tstatus = MID;
		}
	if (llen + bufind + tlen > xxmaxchars && lstatus == CONT && tstatus != NEW)
		{
		putchar('\n');
		++xxlineno;
		for (i = 0; i < xxindent; ++i)
			putchar('\t');
		putchar(' ');putchar(' ');
		llen = 2 + xxindent * xxbpertab;
		lstatus = NEW;
		}
	if (lstatus == CONT && tstatus == MID)
		{			/* store in buffer in case need \n after last CONT char */
		ASSERT(bufind + tlen < xxmaxchars,accum);
		for (i = 0; i < tlen; ++i)
			buffer[bufind++] = token[i];
		}
	else
		{
		for (i = 0; i < bufind; ++i)
			putchar(buffer[i]);
		llen += bufind;
		bufind = 0;
		for (i = 0; i < tlen; ++i)
			putchar(token[i]);
		if (tstatus == NEW) ++xxlineno;
		llen = (tstatus == NEW) ? 0 : llen + tlen;
		lstatus = tstatus;
		}
	}

tab(n)
int n;
	{
	int i;
	newline();
	for ( i = 0;  i < n; ++i)
		putout('\t',"\t");
	}

newline()
	{
	static int already;
	if (already)
		putout('\n',"\n");
	else
		already = 1;
	}

void
error(char *mess1, char *mess2, char *mess3)
	{
	fprintf(stderr,"\nerror in beautifying, output line %d: %s %s %s \n",
		xxlineno, mess1, mess2, mess3);
	exit(1);
	}







push(type)
int type;
	{
	if (++xxstind > xxtop)
		error("nesting too deep, stack overflow","","");
	xxstack[xxstind] = type;
	}

pop()
	{
	if (xxstind <= 0)
		error("stack exhausted, can't be popped as requested","","");
	--xxstind;
	}


forst()
	{
	while( (xxval = yylex()) != '\n')
		{
		putout(xxval, yylval);
		free(yylval);
		}
	free(yylval);
	}
