#include <stdio.h>
#
/* for testing only */
#include "def.h"

void
testreach(void)
{
	VERT v;

	for (v = 0; v < nodenum; ++v)
		fprintf(stderr, "REACH(%d) = %d\n", v, REACH(v));
}
