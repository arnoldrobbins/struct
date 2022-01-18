#include <stdio.h>
#include <stdlib.h>
#include "def.h"
#include "3.def.h"
#include "allfuncs.h"

#define BRANCHTYPE(t)	(t == STOPVX || t == RETVX || t == BRKVX || t == NXTVX || t == GOVX)
#define MAXCHUNK	20
		/* if else clause smaller than MAXCHUNK and smaller than then clause,
		   and there is no reason not to negate the if, negate the if */

void
getthen(VERT v)			/* turn IFVX into THEN when appropriate, create else ifs where possible  */
{
	VERT tch, fch;
	int tn, fn;
	int recvar;

	if (NTYPE(v) == IFVX) {
		tch = LCHILD(v, THEN);
		fch = LCHILD(v, ELSE);
		if (!DEFINED(fch))
			mkthen(v);
		else if (!DEFINED(tch)) {
			negate(v);
			mkthen(v);
		} else if (BRANCHTYPE(NTYPE(tch)))
			mkthen(v);
		else if (BRANCHTYPE(NTYPE(fch))) {
			negate(v);
			mkthen(v);
		} else if (NTYPE(fch) != IFVX || DEFINED(RSIB(fch))) {	/* not an else if */
			if (NTYPE(tch) == IFVX && !DEFINED(RSIB(tch)))
				/* invert into else if */
				negate(v);
			else {
				/* asoc(v,n) returns number of statements associated with v
				   if <= n, -1 otherwise */
				tn = asoc(tch, MAXCHUNK);
				fn = asoc(fch, MAXCHUNK);
				if (fn >= 0 && (tn < 0 || fn < tn))
					/* else clause smaller */
					negate(v);
			}
		}
	}
	RECURSE(getthen, v, recvar);
}

void
mkthen(VERT v)
{
	VERT w, tc;

	w = LCHILD(v, ELSE);
	tc = LCHILD(v, THEN);
	ASSERT(!DEFINED(w)
	       || (DEFINED(tc) && BRANCHTYPE(NTYPE(tc))), mkthen);
	if (DEFINED(w)) {
		insib(v, w);
		LCHILD(v, ELSE) = UNDEFINED;
	}
	ASSERT(IFTHEN(v), mkthen);
}


void
negate(VERT v)
{
	ASSERT(NTYPE(v) == IFVX, negate);
	exchange2(&LCHILD(v, THEN), &LCHILD(v, ELSE));
	NEG(v) = !NEG(v);
}
