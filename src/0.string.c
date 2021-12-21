#include <stdio.h>
#include <string.h>

#include "def.h"
#include "1.defs.h"
#include "allfuncs.h"

int
str_copy(char *s, char *ptr, int length)	/* copy s at ptr, return length of s */
{
	int i;

	for (i = 0; i < length; i++) {
		ptr[i] = s[i];
		if (ptr[i] == '\0')
			return (i + 1);
	}
	faterr("string too long to be copied at given address:\n", s, "");
}


int
find(char *s, char *ar[], int size)
{
	int i;

	for (i = 0; i < size; i++) {
		if (str_eq(s, ar[i]))
			return (i);
	}
	return (-1);
}


int
str_eq(char s[], char t[])
{
	int j;

	for (j = 0; s[j] == t[j]; j++) {
		if (s[j] == '\0')
			return (1);
	}
	return (0);
}


int
classmatch(char c, int i)
{
	switch (i) {
	case _digit:
		if ('0' <= c && c <= '9')
			return (1);
		else
			return (0);

	case _letter:
		if (('A' <= c && c <= 'Z') || ('a' <= c && c <= 'z'))
			return (1);
		else
			return (0);

	case _diglet:
		return (classmatch(c, _digit) || classmatch(c, _letter));

	case _arith:
		return strchr("()*+,-./", c) != NULL;
	case _nl:
		return (c == '\n');
	case _other:
		return (1);
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


int
slength(char *s)			/* return number of chars in s, not counting '\0' */
{
	int i;

	if (!s)
		return (-1);
	for (i = 0; s[i] != '\0'; i++)
		continue;
	return (i);
}


char *
concat(char *x, char *y)		/* allocate space, return xy */
{
	char *temp;
	int i, j;

	i = slength(x);
	j = slength(y);
	temp = (char *) galloc(i + j + 1);
	sprintf(temp, "%s", x);
	sprintf(&temp[i], "%s", y);
	return (temp);
}
