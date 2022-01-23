#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "def.h"
#include "allfuncs.h"

int routbeg;

extern int debug;
struct coreblk {
	struct coreblk *nxtblk;
	int blksize;
	int nxtfree;
	struct coreblk *blk;
};

long space;

void *
challoc(int n)
{
	void *p;

	p = malloc(n);
	if (p) {
		memset(p, 0, n);
		space += n;
		return (p);
	}
	fprintf(stderr, "alloc out of space\n");
	fprintf(stderr, "total space alloc'ed = %ld\n", space);
	fprintf(stderr, "%d more bytes requested\n", n);
	exit(EXIT_FAILURE);
}


void
chfree(void *p, int n)
{
	ASSERT(p, chfree);
	space -= n;
	free(p);
}


struct coreblk *tcore, *gcore;
int tblksize = 12, gblksize = 300;

/* allocate n bytes from coreblk *p */
/* use specifies where called */

void *
balloc(int n, struct coreblk **p, int size)
{
	int i;
	struct coreblk *q;

	n = (n + sizeof(intptr_t) - 1) / sizeof(intptr_t);	/* convert bytes to wds to ensure ints always at wd boundaries */
	for (q = *p;; q = q->nxtblk) {
		if (!q) {
			q = morespace(n, p, size);
			break;
		}
		if (q->blksize - q->nxtfree >= n)
			break;
	}
	i = q->nxtfree;
	q->nxtfree += n;
	return (&(q->blk)[i]);
}

void *
talloc(int n)			/* allocate from line-by-line storage area */
{
	return (balloc(n, &tcore, tblksize));
}

void *
galloc(int n)			/* allocate from graph storage area */
{
	return (balloc(n, &gcore, gblksize));
}

void
reuse(struct coreblk *p)	/* set nxtfree so coreblk can be reused */
{
	for (; p; p = p->nxtblk)
		p->nxtfree = 0;
}

void
bfree(struct coreblk *p)	/* free coreblk p */
{
	if (!p)
		return;
	bfree(p->nxtblk);
	p->nxtblk = 0;
	free(p);
}


struct coreblk *
morespace(int n, struct coreblk **p, int size)	/* get at least n more wds for coreblk *p */
{
	struct coreblk *q;
	int t, i;

	t = n < size ? size : n;
	q = malloc(i = t * sizeof(*(q->blk)) + sizeof(*q));
	if (!q) {
		error(": alloc out of space", "", "");
		fprintf(stderr, "space = %ld\n", space);
		fprintf(stderr, "%d more bytes requested\n", n);
		exit(1);
	}
	space += i;
	q->nxtblk = *p;
	*p = q;
	q->blksize = t;
	q->nxtfree = 0;
	q->blk = q + 1;
	return (q);
}


void
freegraf(void)
{
	bfree(gcore);
	gcore = 0;
}


void
error(char *mess1, char *mess2, char *mess3)
{
	static int lastbeg;

	if (lastbeg != routbeg) {
		fprintf(stderr, "routine beginning on line %d:\n",
			routbeg);
		lastbeg = routbeg;
	}
	fprintf(stderr, "error %s %s %s\n", mess1, mess2, mess3);
}


void
faterr(char *mess1, char *mess2, char *mess3)
{
	error(mess1, mess2, mess3);
	exit(EXIT_FAILURE);
}


void
strerr(char *mess1, char *mess2, char *mess3)
{
	error("struct error: ", mess1, mess2);
}
