#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "def.h"
#include "4.def.h"
#include "3.def.h"
#include "allfuncs.h"

bool
ndbrace(VERT v)			/* determine whether braces needed around subparts of v */
    /* return true if v ends with IF THEN not in braces */
{
	VERT w;
	int i;
	bool endif;

	endif = false;
	for (i = 0; i < CHILDNUM(v); ++i) {
		endif = false;
		for (w = LCHILD(v, i); DEFINED(w); w = RSIB(w))
			endif = ndbrace(w);
		if (NTYPE(v) != DUMVX && NTYPE(v) != ITERVX &&
		    (!DEFINED(LCHILD(v, i)) || compound(v, i) ||
		     (endif && NTYPE(v) == IFVX && !IFTHEN(v)
		      && i == THEN)))
			/* DUMVX doesn't nest, ITERVX doen't nest since
			   nesting is done at LOOPNODE, etc., must
			   check for IFTHEN followed by unrelated ELSE */
		{
			YESBRACE(v, i);
			endif = false;
		}
	}
	return (endif || IFTHEN(v));
}


int
compound(VERT v, int ch)	/* return true iff subpart ch of v has multiple statements */
{
	VERT w;

	w = LCHILD(v, ch);
	if (!DEFINED(w))
		return (false);
	if (NTYPE(w) == ITERVX) {
		ASSERT(DEFINED(NXT(w)), compound);
		if (LABEL(NXT(w)))
			return (true);	/* loop ends with labeled CONTINUE statement */
		else
			return (compound(w, 0));
	} else if (DEFINED(RSIB(w)))
		return (true);
	else if (NTYPE(w) == STLNVX && CODELINES(w) > 1)
		return (true);
	else
		return (false);
}
