#include <stdio.h>
#
/* for testing only */
#include "def.h"
#include "2.def.h"

void
testaft(void)
{
	int i;

	for (i = 0; i < nodenum; ++i)
		fprintf(stderr, "ntoaft[%d] = %d, ntobef[%d] = %d\n", i,
			ntoaft[i], i, ntobef[i]);
	fprintf(stderr, "\n");
	for (i = 0; i < accessnum; ++i)
		fprintf(stderr, "after[%d] = %d\n", i, after[i]);
}

void
testhead(VERT *head)
{
	VERT v;

	for (v = 0; v < nodenum; ++v)
		fprintf(stderr, "head[%d] = %d\n", v, head[v]);
}

void
testdom(VERT *dom)
{
	VERT v;

	for (v = 0; v < nodenum; ++v)
		fprintf(stderr, "dom[%d] = %d\n", v, dom[v]);
}


void
testtree(void)
{
	VERT v;
	int i;

	for (v = 0; v < nodenum; ++v) {
		fprintf(stderr, "%d: RSIB %d, ", v, RSIB(v));
		for (i = 0; i < CHILDNUM(v); ++i)
			fprintf(stderr, " %d", LCHILD(v, i));
		fprintf(stderr, "\n");
	}
}
