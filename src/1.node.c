#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "def.h"
#include "1.incl.h"
#include "allfuncs.h"

VERT
makenode(int type, bool addimp, bool addcom, long labe, int arcnum, int arctype[], long arclab[])
{
	int i;
	VERT num;

	ASSERT(arcsper[type] < 0 || arcnum == arcsper[type], makenode);
	num = create(type, arcnum);

	if (addimp)
		fiximp(num, labe);

	for (i = 0; i < arcnum; ++i) {
		if (arctype[i] == -2)
			addref(arclab[i], &ARC(num, i));
		else
			ARC(num, i) = arctype[i];
	}


	if (hascom[type]) {
		if (!addcom || endcom < begline)
			BEGCOM(num) = UNDEFINED;
		else {
			BEGCOM(num) = begchar - rtnbeg;
			if ((unsigned) (BEGCOM(num)) != begchar - rtnbeg)
				faterr("program too long", "", "");
		}
	}
	return (num);
}

void
fiximp(VERT num, long labe)		/* fix implicit links, check nesting */
{
	fixvalue(implicit, num);	/* set implicit links to this node */
	clear(implicit);
	if (labe != implicit)
		fixvalue(labe, num);
}
