#include <stdio.h>
#include <stdlib.h>
#include "1.incl.h"
#include "1.defs.h"
#include "def.h"
#include "allfuncs.h"

extern int match[], symclass[], action[], newstate[];
extern char symbol[];
long *hashtab;
int *value;
intptr_t *chain;

extern FILE *infd;

int
parse(void)
{
	int i, j, found, current, someread;
	char c;

	hash_init();
	routinit();
	line_init();

	someread = 0;		/* indicates haven't read part of a routine */

	empseek(0);
	endbuf = get_a_line(&endline, &endchar, &endcom, &comchar);
	if (progress && endbuf != -1)
		fprintf(stderr, "parsing\n");
	while (endbuf != -1) {	/* get_a_line returns -1 when no more input */
		someread = 1;
		if (progress > 0) {
			for (i = begline; i <= endline; i++)
				if (!(i % progress))
					fprintf(stderr,
						"parsing line %d\n", i);
		}
		current = 0;
		for (i = 0; i < endbuf; i++) {

			c = buffer[i];
			if (c != '~') {
				found = 0;
				if ((current < 0 || current >= snum)
				    && current != ABORT) {
					strerr("in parsing:", "", "");
					fprintf(stderr,
						"line %d of file, parser in invalid state %d ",
						begline, current);
					fprintf(stderr,
						"treating it as straight line code\n");
					current = ABORT;
				} else
					for (j = match[current];
					     j < match[current + 1]; j++) {
						if ((symclass[j] == 0
						     && c == symbol[j])
						    || (symclass[j] != 0
							&& classmatch(c,
								      symclass
								      [j])))
						{
							found = 1;
							break;
						}
					}
				if (!found) {
					error("in syntax:", "", "");
					fprintf(stderr,
						"between lines %d and %d of file\n",
						begline, endline);
					if (debug)
						fprintf(stderr,
							"symbol '%c' does not match entries for state %d\n",
							c, current);
					fprintf(stderr,
						"treating it as straight line code\n");
					current = ABORT;
				} else if (!action[j])
					current = newstate[j];
				else {
					current = act(action[j], c, i);
					if (current == nulls)
						current = newstate[j];
				}
				if (current == ABORT)
					break;
				if (current == endrt) {
					return 1;
				}
			}
		}
		line_init();
		endbuf = get_a_line(&endline, &endchar, &endcom, &comchar);
	}
	if (someread)
		return 1;
	else
		return 0;
}

void
hash_init(void)
{
	int i;

	hashtab = challoc(sizeof(*hashtab) * maxhash);
	chain = challoc(sizeof(*chain) * maxhash);
	value = challoc(sizeof(*value) * maxhash);
	for (i = 0; i < maxhash; i++) {
		hashtab[i] = -1L;
		value[i] = -2;
		chain[i] = 0;
	}
}

void
hash_check(void)
{
	int i;

	for (i = 0; i < maxhash; ++i)
		if (value[i] == -2 && hashtab[i] != -1L) {
			error
			    ("in syntax; label used but does not appear as statement label:",
			     "", "");
			fprintf(stderr, "%ld\n", hashtab[i]);
			routerr = 1;
		}
}

void
hash_free(void)
{
	chfree(hashtab, sizeof(*hashtab) * maxhash);
	hashtab = 0;
	chfree(chain, sizeof(*chain) * maxhash);
	chain = 0;
	chfree(value, sizeof(*value) * maxhash);
	value = 0;
}

int
hash(long x)
{
	int quo, rem, hcount, temp;

	ASSERT(x >= 0L, hash);
	quo = x / maxhash;
	rem = x - (quo * maxhash);
	if (quo == 0)
		quo = 1;

	temp = rem;
	for (hcount = 0;
	     (hashtab[temp] != -1L) && (hashtab[temp] != x)
	     && (hcount < maxhash); hcount++)
		temp = (temp + quo) % maxhash;
	if (hcount >= maxhash)
		faterr("hash table overflow - too many labels", "", "");
	hashtab[temp] = x;
	return temp;
}

void
addref(long x, intptr_t *ptr)	/* put ptr in chain for x or assign value of x to *ptr */
{
	int index;

	index = hash(x);

	if (value[index] == -1) {	/* x already assigned value */
		*ptr = chain[index];
		return;
	}

	/* add ptr to chain */

	if (chain[index] == 0)
		*ptr = 0;
	else
		*ptr = chain[index];
	chain[index] = (intptr_t)ptr;
}

void
fixvalue(long x, intptr_t ptr)
{
	intptr_t *temp1, temp2;
	int index, temp0;

	index = hash(x);

	while (index != -2) {	/* trace chain of linked labels */

		if (value[index] == -1) {
			error("in syntax:  ", "", "");
			fprintf(stderr,
				"attempt to redefine value of label %ld between lines %d and %d\n",
				x, begline, endline);
			routerr = 1;
			return;
		}

		temp1 = &chain[index];	/* trace chain for each label */
		while (temp1 != 0) {
			temp2 = *temp1;
			*temp1 = ptr;
			temp1 = (intptr_t *)temp2;
		}
		temp0 = index;
		index = value[index];
		value[temp0] = -1;
	}
}

void
connect(long x, long y)
{
	intptr_t *temp;
	int index, temp2;

	index = hash(x);

	if (value[index] == -1)
		fixvalue(y, chain[index]);
	else {
		if (y == implicit) {	/* attach implicit chain to x chain */
			temp = &chain[index];

			while (*temp != 0)
				temp = (intptr_t *)*temp;

			*temp = chain[hash(y)];
		}
		temp2 = index;	/* attach y linked labels to x linked labels */
		while (value[temp2] >= 0)
			temp2 = value[temp2];
		if (y == implicit)
			value[temp2] = value[hash(y)];
		else
			value[temp2] = hash(y);
	}
	if (y == implicit)
		clear(y);
}


void
clear(long x)
{
	int index;

	index = hash(x);
	value[index] = -2;
	chain[index] = 0;
	hashtab[index] = -1L;
}
