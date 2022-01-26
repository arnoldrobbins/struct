#include <stdio.h>
#include <string.h>
#include <ctype.h>

#include "def.h"
#include "1.defs.h"
#include "allfuncs.h"



int
classmatch(char c, int i)
{
	switch (i) {
	case _digit:
		if (isdigit(c))
			return 1;
		else
			return 0;

	case _letter:
		if (isupper(c) || islower(c))
			return 1;
		else
			return 0;

	case _diglet:
		return classmatch(c, _digit) || classmatch(c, _letter);

	case _arith:
		return strchr("()*+,-./", c) != NULL;
	case _nl:
		return c == '\n';
	case _other:
	default:
		return 1;
	}
}


void
copychars(char *cbeg, char *target, int n)	/* copy n chars from cbeg to target */
{
	int i;

	for (i = 0; i < n; i++)
		target[i] = cbeg[i];
}



void
copycs(char *cbeg, char *target, int n)	/* copy n chars from cbeg to target, add '\0' */
{
	copychars(cbeg, target, n);
	target[n] = '\0';
}



char *
concat(char *x, char *y)		/* allocate space, return xy */
{
	char *temp;
	int i, j;

	i = strlen(x);
	j = strlen(y);
	temp = (char *) galloc(i + j + 1);
	sprintf(temp, "%s", x);
	sprintf(&temp[i], "%s", y);
	return temp;
}
