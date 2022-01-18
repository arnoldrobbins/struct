#include <stdio.h>
#include <ctype.h>
#include "1.defs.h"
#include "def.h"
#include "allfuncs.h"

extern int linechar, errflag, debug;
extern int (*input)(),(*unput)();


int
uptolow(int c)			/*translates upper to lower case */
{
	if (isupper(c))
		return tolower(c);
	else
		return (c);
}

void
rdfree( int (*func)() )
{
	int c;

	while ((c = (*input)()) != '\n') {
		(*func)(c);
	}
}

void
rdstand( int (*func)() )
{
	int c;

	while ((c = (*input)()) != '\n') {
		(*func)(c);
	}
}

void
labfree( int (*func)() )	/* labels in freeform input */
{
	int c;
	int temp[6];
	int j;

	(void)temp;
	for (j = 0; j < 5; ++j) {
		while ((c = (*input)()) == ' ' || c == '\t');
		if (c == '\n') {
			if (j != 0) {
				temp[j] = '\0';
				error("label without code - ignored:", "",
				      "");
			}
		}
		if (! isdigit(c)) {
			(*unput)(c);
			break;
		} else {
			temp[j] = c;
			(*func)(c);
		}
	}
	for (; j < 5; ++j)
		(*func)(' ');
}

void
labstand( int (*func)() )	/* labels in standard form input */
{
	int c;
	int j;

	for (j = 0; j < 5; ++j) {
		c = (*input)();
		if (c == '\n') {
			error("line shorter than 5 characters", "", "");
			errflag = 1;
			(*unput)('\n');
		}
		if (c == '\t' || c == '\n') {
			for (; j < 5; ++j)
				(*func)(' ');
			return;
		}
		(*func)(c);
	}
	(*input)();		/* throw away continuation char */
}



int
contfree(void)		/* identify continuation lines in free-form input */
{
	return (nonblchar(_diglet, 0));	/* any non-alpha non-digit */
}


int
nonblchar(int class, int yesno)
{
#define CARDSIZE	121
	int temp[CARDSIZE];
	int j;

	for (j = 0; (temp[j] = (*input) ()) == ' ' || temp[j] == '\t'; ++j)
		if (j >= CARDSIZE - 1) {
			temp[CARDSIZE - 1] = '\0';
			error("line unexpectedly long", "", "");
			break;
		}
	if (temp[j] != EOF && classmatch(temp[j], class) == yesno)
		return (1);
	else {
		for (; j >= 0; --j)
			(*unput) (temp[j]);
		return (0);
	}
}


int
contstand(void)		/* continuation lines in standard form input */
{
	int temp[6];
	int i;

	for (i = 0; i < 6; ++i) {
		temp[i] = (*input) ();
		if (temp[i] == '\t' || temp[i] == '\n' || temp[i] == '\0'
		    || temp[i] == EOF) {
			for (; i >= 0; --i)
				(*unput)(temp[i]);
			return (0);
		}
	}
	if (temp[5] != '0' && temp[5] != ' ')
		return (1);
	else {
		for (i = 5; i >= 0; --i)
			(*unput)(temp[i]);
		return (0);
	}
}


int
comstand(int posafter)		/* standard form comments */
{
	int c;

	c = (*input)();
	if (!posafter)
		(*unput)(c);
	if (c == 'c' || c == '*' || c == '#')
		return (1);
	else
		return (0);
}


int
comfree(int posafter)
{
	return (comstand(posafter));
}

void (*rline[])() = { rdfree, rdstand };
int (*comment[])() = { comfree, comstand };
void (*getlabel[])() = { labfree, labstand };
int (*chkcont[])() = { contfree, contstand };

int
blankline(void)
{
	if (nonblchar(_nl, 1)) {	/* first non-blank is nl */
		(*unput)('\n');
		return (1);
	} else
		return (0);
}

#define maxunbp	80
char unbuf[maxunbp + 1];
int unbp;

void
empseek(unsigned int linebeg)
{
	unbp = 0;
	if (fseek(infd, (long) (linebeg + rtnbeg), 0) == -1)
		faterr("in disk seek", "", "");
}

int
inchar(void)
{
	if (unbp > 0)
		return (unbuf[--unbp]);
	else {
		return (uptolow(getc(infd)));
	}
}


void
unchar(int c)
{
	if (unbp >= maxunbp)
		faterr("dec.rat: unbuf size exceeded", "", "");
	if (c != EOF)
		unbuf[unbp++] = c;
}
