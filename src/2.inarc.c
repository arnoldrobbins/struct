#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/* find forward in-arcs for each node, pretending that arcs which jump into a loop 
	jump to the head of the largest such loop instead, based on the
	depth first search tree */
#include "def.h"
#include "2.def.h"
#include "allfuncs.h"

void
getinarc(struct list **inarc, VERT *head)		/* construct array "inarc" containing in arcs for each node */
{
	VERT v, adj, x;
	int i, j;

	for (v = 0; v < nodenum; ++v)
		inarc[v] = 0;

	/* fill in inarc nodes */

	for (i = 0; i < accessnum; ++i) {
		v = after[i];
		for (j = 0; j < ARCNUM(v); ++j) {
			adj = ARC(v, j);
			if (!DEFINED(adj))
				continue;
			if (ntoaft[adj] > ntoaft[v]) {	/* not a back edge */
				/* if edge jumps into loop, pretend jumps to head of
				   largest loop jumped into */
				x = maxentry(v, adj, head);
				if (!DEFINED(x))
					x = adj;
				else
					x = FATH(x);

				inarc[x] = consls(v, inarc[x]);	/* insert v in list inarc[x] */
			}
		}
	}
}



VERT
maxentry(VERT x, VERT y, VERT *head)		/* return z if z is ITERVX of largest loop containing y but not x, UNDEFINED otherwise */
{
	if (head[y] == UNDEFINED)
		return UNDEFINED;
	if (loomem(x, head[y], head))
		return UNDEFINED;
	y = head[y];
	while (head[y] != UNDEFINED) {
		if (loomem(x, head[y], head))
			return y;
		y = head[y];
	}
	return y;
}



bool
loomem(VERT x, VERT y, VERT *head)		/* return true if x is in loop headed by y, false otherwise */
{
	VERT w;

	if (!DEFINED(y))
		return true;
	ASSERT(NTYPE(y) == ITERVX, loomem);
	for (w = (NTYPE(x) == ITERVX) ? x : head[x]; DEFINED(w);
	     w = head[w])
		if (w == y)
			return true;
	return false;
}
