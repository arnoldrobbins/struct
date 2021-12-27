#include <stdio.h>
#include "def.h"
#include "allfuncs.h"

struct list *
consls(VERT v, struct list *ls)			/* make list */
{
	struct list *temp;

	temp = challoc(sizeof(*temp));
	temp->elt = v;
	temp->nxtlist = ls;
	return (temp);
}

struct list *
append(VERT v, struct list *ls)			/* return ls . v */
{
	struct list *temp;

	if (!ls)
		return (consls(v, 0));
	for (temp = ls; temp->nxtlist; temp = temp->nxtlist)
		continue;
	temp->nxtlist = consls(v, 0);
	return (ls);
}


void
freelst(struct list *ls)
{
	if (!ls)
		return;
	if (ls->nxtlist)
		freelst(ls->nxtlist);
	chfree(ls, sizeof(*ls));
}


VERT
oneelt(struct list *ls)		/* return w if w is only elt of ls, UNDEFINED otherwise */
{
	if (!ls)
		return (UNDEFINED);
	if (ls->nxtlist)
		return (UNDEFINED);
	return (ls->elt);
}


int
lslen(struct list *ls)			/* return number of elements in list ls */
{
	int count;
	struct list *lp;

	count = 0;
	for (lp = ls; lp; lp = lp->nxtlist)
		++count;
	return (count);
}


void
prlst(struct list *ls)
{
	struct list *lp;

	for (lp = ls; lp; lp = lp->nxtlist)
		fprintf(stderr, "%d,", lp->elt);
	fprintf(stderr, "\n");
}
