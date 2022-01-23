#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "def.h"
#include "3.def.h"
#include "allfuncs.h"

#define ARCCOUNT(v)	REACH(v)

void
fixhd(VERT v, VERT hd, VERT *head)
{
	VERT w, newhd;
	int i;

	head[v] = hd;
	newhd = (NTYPE(v) == ITERVX) ? v : hd;
	for (i = 0; i < CHILDNUM(v); ++i)
		for (w = LCHILD(v, i); DEFINED(w); w = RSIB(w))
			fixhd(w, newhd, head);
}

void
getloop(void)
{
	cntarcs();
	fixloop(START);
}


void
cntarcs(void)
{				/* count arcs entering each node */
	VERT w, v;
	int i;

	for (v = 0; v < nodenum; ++v)
		ARCCOUNT(v) = 0;
	for (v = 0; v < nodenum; ++v)
		for (i = 0; i < ARCNUM(v); ++i) {
			w = ARC(v, i);
			if (!DEFINED(w))
				continue;
			++ARCCOUNT(w);
		}
}


void
fixloop(VERT v)			/* find WHILE loops  */
{
	int recvar;

	if (NTYPE(v) == LOOPVX) {
		ASSERT(DEFINED(ARC(v, 0)), fixloop);
		NXT(ARC(v, 0)) = ARC(v, 0);
		if (!getwh(v))
			getun(v);
	} else if (NTYPE(v) == IFVX && arbcase)
		getswitch(v);
	else if (NTYPE(v) == DOVX) {
		ASSERT(DEFINED(ARC(v, 0)), fixloop);
		NXT(ARC(v, 0)) = ARC(v, 0);
	}
	RECURSE(fixloop, v, recvar);
}


int
getwh(VERT v)
{
	VERT vchild, vgrand, vgreat;

	ASSERT(NTYPE(v) == LOOPVX, getwh);
	vchild = LCHILD(v, 0);
	ASSERT(DEFINED(vchild), getwh);
	ASSERT(NTYPE(vchild) == ITERVX, getwh);
	vgrand = LCHILD(vchild, 0);
	if (!DEFINED(vgrand) || !IFTHEN(vgrand))
		return (false);
	vgreat = LCHILD(vgrand, THEN);
	if (DEFINED(vgreat) && NTYPE(vgreat) == GOVX
	    && ARC(vgreat, 0) == BRK(vchild)) {
		/* turn into WHILE */
		NTYPE(v) = WHIVX;
		NEG(vgrand) = !NEG(vgrand);
		LPRED(vchild) = vgrand;
		LCHILD(vchild, 0) = RSIB(vgrand);
		RSIB(vgrand) = UNDEFINED;
		return (true);
	}
	return (false);
}


int
getun(VERT v)			/* change loop to REPEAT UNTIL if possible */
{
	VERT vchild, vgrand, vgreat, before, ch;

	ASSERT(NTYPE(v) == LOOPVX, getun);
	vchild = LCHILD(v, 0);
	ASSERT(DEFINED(vchild), getun);
	if (ARCCOUNT(vchild) > 2)
		return (false);	/* loop can be iterated without passing through predicate of UNTIL */
	vgrand = ARC(vchild, 0);
	if (!DEFINED(vgrand))
		return (false);
	for (ch = vgrand, before = UNDEFINED; DEFINED(RSIB(ch));
	     ch = RSIB(ch))
		before = ch;
	if (!IFTHEN(ch))
		return (false);
	vgreat = LCHILD(ch, THEN);
	if (DEFINED(vgreat) && NTYPE(vgreat) == GOVX
	    && ARC(vgreat, 0) == BRK(vchild)) {
		/* create  UNTIL node */
		NTYPE(v) = UNTVX;
		NXT(vchild) = ch;
		LPRED(vchild) = ch;
		RSIB(before) = UNDEFINED;
		return (true);
	}
	return (false);
}


#define FORMCASE(w)	(DEFINED(w) && !DEFINED(RSIB(w)) && NTYPE(w) == IFVX && ARCCOUNT(w) == 1)

bool
getswitch(VERT v)
{
	VERT ch, grand, temp;

	/* must be of form if ... else if ... else if ... */
	if (NTYPE(v) != IFVX)
		return (false);
	ch = LCHILD(v, ELSE);
	if (!FORMCASE(ch))
		return (false);
	grand = LCHILD(ch, ELSE);
	if (!FORMCASE(grand))
		return (false);

	temp = create(SWCHVX, 0);
	exchange(&graph[temp], &graph[v]);	/* want arcs to enter switch, not first case */
	BEGCOM(v) = UNDEFINED;
	RSIB(v) = RSIB(temp);	/* statements which followed IFVX should follow switch */
	EXP(v) = UNDEFINED;
	LCHILD(v, 0) = temp;
	NTYPE(temp) = ACASVX;
	for (ch = LCHILD(temp, ELSE); FORMCASE(ch);) {
		LCHILD(temp, ELSE) = UNDEFINED;
		RSIB(temp) = ch;
		NTYPE(ch) = ACASVX;
		temp = ch;
		ch = LCHILD(temp, ELSE);
	}
	ASSERT(!DEFINED(RSIB(temp)), getswitch);
	return (true);
}
