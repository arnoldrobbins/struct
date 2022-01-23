#include <stdio.h>
#include <stdbool.h>
#include "def.h"
#include "4.def.h"
#include "allfuncs.h"

bool *brace;

void
output(void)
{
	VERT w;
	int i;

	brace = challoc(nodenum * sizeof(*brace));
	for (i = 0; i < nodenum; ++i)
		brace[i] = false;
	if (progress)
		fprintf(stderr, "ndbrace:\n");
	for (w = START; DEFINED(w); w = RSIB(w))
		ndbrace(w);
	if (progress)
		fprintf(stderr, "outrat:\n");
	for (w = START; DEFINED(w); w = RSIB(w))
		outrat(w, 0, YESTAB);
	OUTSTR("END\n");
	chfree(brace, nodenum * sizeof(*brace));
	brace = 0;
}
