%option nounput

%{
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <ctype.h>
#include "y.tab.h"
#include "b.h"

#undef	input
#define input(x)	(x = ninput())

#undef YY_INPUT
#define YY_INPUT(buf, result, max_size) \
	{ \
		buf[0] = ninput(); \
		result = (buf[0] != 0); \
	}

#define xxunmax	200
char xxunbuf[xxunmax + 2];
int xxunbp = -1;

#define YY_NO_INPUT 1
%}

D	[0-9]
A	[0-9a-z]
L	[a-z]
SP	[^0-9a-z]

%%

%{
char *xxtbuff;
int xxj, xxn, xxk;
char *xxp;
%}
[=/,(]{D}+[h]		{
				sscanf(&yytext[1], "%d", &xxn);
				xxtbuff = malloc(2 * xxn + 3);
				for (xxj = xxk = 1; xxj <= xxn; ++xxj) {
					xxtbuff[xxk] = ninput();
					if (xxtbuff[xxk] == '"')
						xxtbuff[++xxk] = '"';
					++xxk;
				}
				xxtbuff[0] = xxtbuff[xxk++] = '"';
				xxtbuff[xxk] = '\0';
				putback(xxtbuff);
				free(xxtbuff);

				backup(yytext[0]);
			}
IF			{ fixval(); return(xxif);}
ELSE			{ fixval(); return(xxelse);}
REPEAT			{ fixval(); return(xxrept); }
WHILE			{ fixval(); return(xxwhile); }
UNTIL			{ fixval(); return(xxuntil); }
DO			{ fixval(); return(xxdo); }
SWITCH			{ fixval(); return(xxswitch); }
CASE			{ fixval(); return(xxcase); }
DEFAULT			{ fixval(); return(xxdefault); }
END			{ fixval(); return(xxend); }

".true."		|
".false."		|

{L}{A}*			{ fixval(); return(xxident); }
~{D}+			{ fixval(); return(xxnum); }
{D}+/"."(ge|gt|le|lt|eq|ne|not|or|and)"."	|
{D}+\.?				|
{D}+\.?[de][+-]?{D}+		|
{D}*\.{D}+[de][+-]?{D}+		|
{D}*\.{D}+			{ fixval(); return(xxnum); }

".gt."			{ putback(">"); }
".ge."			{ putback(">=");}
".lt."			{ putback("<"); }
".le."			{ putback("<="); }
".eq."			{ putback("=="); }
".ne."			{ putback("!="); }
".not."			{ putback("!"); }
".or."			{ putback("||"); }
".and."			{ putback("&&"); }
">="			{ fixval(); return(xxge);  }
"<="			{ fixval(); return(xxle); }
==			{ fixval(); return(xxeq); }
!=			{ fixval(); return(xxne); }
"||"			{ fixval(); return('|'); }
"&&"			{ fixval(); return('&'); }
"**"			{ fixval(); return('^'); }

#.*			{ fixval(); return(xxcom); }
\"([^"]|\"\")*\"	{ fixval(); return(xxstring); }
'([^']|'')*'			{
					fixval();
					xxp = yylval.strval;
					xxn = slength(xxp);
					xxtbuff = malloc(2*xxn+1);
					xxtbuff[0] = '"';
					for (xxj = xxk = 1; xxj < xxn-1; ++xxj) {
						if (xxp[xxj] == '\'' && xxp[++xxj] == '\'')
							xxtbuff[xxk++] = '\'';
						else if (xxp[xxj] == '"') {
							xxtbuff[xxk++] = '"';
							xxtbuff[xxk++] = '"';
						} else
							xxtbuff[xxk++] = xxp[xxj];
					}
					xxtbuff[xxk++] = '"';
					xxtbuff[xxk] = '\0';
					free(xxp);
					yylval.strval = xxtbuff;
					return(xxstring);
				}

[ \t]		{ if (newflag) { fixval(); return(yytext[0]); } }
^\n		{ /* do nothing */ }
\n		{ if (newflag) { fixval(); return('\n'); }  }
{SP}		{ fixval(); return(yytext[0]); }

%%

int
rdchar(void)
{
	int c;

	if (xxunbp >= 0)
		return (xxunbuf[xxunbp--]);
	c = getchar();
	if (c == EOF)
		return ('\0');
	else
		return (c);
}

void
backup(int c)
{
	if (++xxunbp > xxunmax) {
		xxunbuf[xxunmax + 1] = '\0';
		error("RATFOR beautifying; input backed up too far during lex:\n",
			xxunbuf, "\n");
	}
	xxunbuf[xxunbp] = c;
}


int
ninput(void)
{
	int c, d;

	c = rdchar();
	if (c != '\n')
		return (c);
	while ((d = rdchar()) == ' ' || d == '\t')
		continue;
	if (d == '&')
		return (ninput());
	backup(d);
	return ('\n');
}


void
fixval(void)
{
	int i, j;

	if (yytext[0] == '~' && isdigit(yytext[1])) {
		j = strlen(yytext);
		for (i = 1; i <= j; i++)
			yytext[i-1] = yytext[i];
	}
	yylval.strval = (char *) malloc(strlen(yytext) + 1);
	strcpy(yylval.strval, yytext);
}

void
putback(char *str)
{
	int i;

	for (i = 0; str[i] != '\0'; ++i)
		continue;
	for (--i; i >= 0; --i)
		backup(str[i]);
}

int
yywrap(void)
{
	return 1;
}
