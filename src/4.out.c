#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "def.h"
#include "4.def.h"
#include "3.def.h"
#include "allfuncs.h"

void
outrat(
VERT v,
int tab,			/* number of tabs to indent */
bool tabfirst)		/* false if doing IF of ELSE IF */
{
	bool ndcomma;
	VERT w;
	int type, i;

	type = NTYPE(v);
	if (hascom[type])
		prcom(v);
	if (!LABEL(v) && type == FMTVX) {
		OUTSTR
		    ("#following unreferenced format statement commented out\n");
		OUTSTR("#");
	}
	if (LABEL(v) && type != ITERVX) {
		ASSERT(tabfirst, outrat);
		prlab(LABEL(v), tab);
	} else if (tabfirst && type != DUMVX && type != ITERVX)
		TABOVER(tab);

	switch (type) {
	case DUMVX:
		newlevel(v, 0, tab, YESTAB);
		break;
	case GOVX:
		OUTSTR("go to ");
		OUTNUM(LABEL(ARC(v, 0)));
		OUTSTR("\n");
		break;
	case STOPVX:
		if (progtype != blockdata)
			OUTSTR("stop\n");
		break;
	case RETVX:
		OUTSTR("return\n");
		break;
	case BRKVX:
		if (!levbrk) {
			ASSERT(LEVEL(v) == 1, outrat);
			OUTSTR("break\n");
		} else {
			OUTSTR("break ");
			OUTNUM(LEVEL(v));
			OUTSTR("\n");
		}
		break;
	case NXTVX:
		if (!levnxt) {
			ASSERT(LEVEL(v) == 1, outrat);
			OUTSTR("next\n");
		} else {
			OUTSTR("next ");
			OUTNUM(LEVEL(v));
			OUTSTR("\n");
		}
		break;
	case ASGOVX:
	case COMPVX:
		OUTSTR("goto ");
		if (type == ASGOVX) {
			OUTSTR((char *)EXP(v));
			OUTSTR(",");
		}
		OUTSTR("(");
		for (i = ARCNUM(v) - 1; i >= 0; --i) {	/* arcs were stored backward */
			OUTNUM(LABEL(ARC(v, i)));
			if (i > 0)
				OUTSTR(",");
		}
		OUTSTR(")");
		if (type == COMPVX) {
			OUTSTR(",");
			OUTSTR((char *)EXP(v));
		}
		OUTSTR("\n");
		break;
	case ASVX:
		OUTSTR("assign ");
		OUTNUM(LABEL(LABREF(v)));
		OUTSTR(" to ");
		OUTSTR((char *)EXP(v));
		OUTSTR("\n");
		break;
	case IFVX:
		OUTSTR("IF");
		prpred(v, true);
		if (IFTHEN(v))
			newlevel(v, THEN, tab + 1, YESTAB);
		else {
			newlevel(v, THEN, tab + 1, YESTAB);
			TABOVER(tab);
			OUTSTR("ELSE ");
			w = LCHILD(v, ELSE);
			ASSERT(DEFINED(w), outrat);
			if (NTYPE(w) == IFVX && !LABEL(w)
			    && !DEFINED(RSIB(w)) && !HASBRACE(v, ELSE))
				newlevel(v, ELSE, tab, NOTAB);
			else
				newlevel(v, ELSE, tab + 1, YESTAB);
		}
		break;
	case ITERVX:
		newlevel(v, 0, tab, YESTAB);
		ASSERT(DEFINED(NXT(v)), outrat);
		if (LABEL(NXT(v))) {
			prlab(LABEL(NXT(v)), tab);
			OUTSTR("continue\n");
		}
		break;
	case DOVX:
		OUTSTR("DO ");
		OUTSTR((char *)INC(v));
		newlevel(v, 0, tab + 1, YESTAB);
		break;
	case LOOPVX:
	case UNTVX:
		OUTSTR("REPEAT");
		newlevel(v, 0, tab + 1, YESTAB);
		if (type == UNTVX) {
			TABOVER(tab + 1);
			OUTSTR("UNTIL");
			ASSERT(DEFINED(ARC(v, 0)), outrat);
			prpred(LPRED(ARC(v, 0)), true);
			OUTSTR("\n");
		}
		break;
	case WHIVX:
		OUTSTR("WHILE");
		ASSERT(DEFINED(ARC(v, 0)), outrat);
		ASSERT(DEFINED(LPRED(ARC(v, 0))), outrat);
		prpred(LPRED(ARC(v, 0)), true);
		newlevel(v, 0, tab + 1, YESTAB);
		break;
	case STLNVX:
	case FMTVX:
		prstln(v, tab);
		break;
	case SWCHVX:
		OUTSTR("SWITCH");
		if (DEFINED(EXP(v))) {
			OUTSTR("(");
			OUTSTR((char *)EXP(v));
			OUTSTR(")");
		}
		newlevel(v, 0, tab + 1, YESTAB);
		break;
	case ICASVX:
	case ACASVX:
		OUTSTR("CASE ");
		if (type == ACASVX)
			prpred(v, false);
		else
			OUTSTR((char *)EXP(v));
		OUTSTR(":\n");
		newlevel(v, 0, tab + 1, YESTAB);
		if (type == ACASVX && DEFINED(LCHILD(v, ELSE))) {
			TABOVER(tab);
			OUTSTR("DEFAULT:\n");
			newlevel(v, 1, tab + 1, YESTAB);
		}
		break;
	case IOVX:
		OUTSTR((char *)PRERW(v));
		ndcomma = false;
		if (DEFINED(FMTREF(v))) {
			OUTNUM(LABEL(FMTREF(v)));
			ndcomma = true;
		}
		if (DEFINED(ARC(v, ENDEQ))) {
			if (ndcomma)
				OUTSTR(",");
			OUTSTR("end = ");
			OUTNUM(LABEL(ARC(v, ENDEQ)));
			ndcomma = true;
		}
		if (DEFINED(ARC(v, ERREQ))) {
			if (ndcomma)
				OUTSTR(",");
			OUTSTR("err = ");
			OUTNUM(LABEL(ARC(v, ERREQ)));
			ndcomma = true;
		}
		OUTSTR((char *)POSTRW(v));
		OUTSTR("\n");
		break;
	}
}


void
newlevel(
VERT v,
int ch,				/* number of lchild of v being processed */
int tab,			/* number of tabs to indent */
bool tabfirst)			/* same as for outrat */
{
	bool addbrace;
	VERT w;

	if (NTYPE(v) == ACASVX || NTYPE(v) == ICASVX)
		addbrace = false;
	else if (NTYPE(v) == SWCHVX)
		addbrace = true;
	else
		addbrace = HASBRACE(v, ch);
	ASSERT(tabfirst || !addbrace, newlevel);
	if (addbrace)
		OUTSTR(" {");
	if (tabfirst && NTYPE(v) != ITERVX && NTYPE(v) != DUMVX)
		OUTSTR("\n");
	for (w = LCHILD(v, ch); DEFINED(w); w = RSIB(w))
		outrat(w, tab, tabfirst);
	if (addbrace) {
		TABOVER(tab);
		OUTSTR("}\n");
	}
}




void
prpred(VERT v, bool addpar)
{
	if (addpar)
		OUTSTR("(");
	if (NEG(v))
		OUTSTR("!(");
	OUTSTR((char *)PRED(v));
	if (NEG(v))
		OUTSTR(")");
	if (addpar)
		OUTSTR(")");
}

void
prlab(int n, int tab)
{
	TABOVER(tab);
	OUTSTR("~");
	OUTNUM((intptr_t)n);
	OUTSTR(" ");
}

void
prstln(VERT v, int tab)
{
	ASSERT(NTYPE(v) == STLNVX || NTYPE(v) == FMTVX, prstln);
	if (!ONDISK(v)) {
		OUTSTR((char *)BEGCODE(v));
		OUTSTR("\n");
	} else {
		empseek(BEGCODE(v));
		prcode(ONDISK(v), tab);
	}
}

void
prcom(VERT v)
{
	if (DEFINED(BEGCOM(v))) {
		empseek(BEGCOM(v));
		comprint();
	}
}
