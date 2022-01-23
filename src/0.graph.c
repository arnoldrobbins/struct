#include <stdio.h>
#include <stdlib.h>
#include "def.h"
#include "allfuncs.h"

#define TABOVER(n)	tabover(n, stderr)

void
prgraph(void)
{
	VERT v;
	int i;

	if (progress)
		fprintf(stderr, "prgraph():\n");
	for (v = 0; v < nodenum; ++v) {
		fprintf(stderr, "%" PRIdPTR " %s:", v, typename[NTYPE(v)]);
		for (i = 0; i < ARCNUM(v); ++i) {
			fprintf(stderr, "%" PRIdPTR " ", ARC(v, i));
			ASSERT(UNDEFINED <= ARC(v, i)
			       && ARC(v, i) < nodenum, prgraph);
		}
		fprintf(stderr, "\n");
	}
	fprintf(stderr, "\n\n");
}

void
prtree(void)
{
	prtr(START, 1);
}

void
prtr(VERT v, int tab)
{				/* print tree in form of program indenting by tab */
	int i;

	TABOVER(tab);
	fprintf(stderr, "%" PRIdPTR " %s:", v, typename[NTYPE(v)]);
	for (i = 0; i < ARCNUM(v); ++i)
		fprintf(stderr, " %" PRIdPTR, ARC(v, i));
	fprintf(stderr, "\n");
	for (i = 0; i < CHILDNUM(v); ++i) {
		TABOVER(tab + 1);
		fprintf(stderr, "{\n");
		if (DEFINED(LCHILD(v, i)))
			prtr(LCHILD(v, i), tab + 1);
		TABOVER(tab + 1);
		fprintf(stderr, "}\n");
	}
	if (DEFINED(RSIB(v)))
		prtr(RSIB(v), tab);
}


void
tabover(int n, FILE * fd)
{				/* tab n times */
	int i;

	for (i = 0; i < n; ++i)
		putc('\t', fd);
}
