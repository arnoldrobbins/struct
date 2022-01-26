#include <stdio.h>
#include <stdbool.h>
#include "def.h"
#include "4.def.h"
#include "allfuncs.h"

extern int linechars;
extern void (*rline[])();
extern int (*comment[])();
extern void (*getlabel[])();
extern int (*chkcont[])();

void
null(int c)
{
	return;
}


int
comprint(void)
{
	int c, blank, first, count;

	(void)blank;
	(void)first;
	blank = 1;
	first = 1;
	count = 0;
	while ((c = (*comment[inputform]) (0)) || blankline()) {
		++count;
		if (c) {
			(*comment[inputform]) (1);	/* move head past comment signifier */
			blank = blankline();
			/* if (first && !blank)
			   OUTSTR("#\n"); */
			prline("#");
			first = 0;
		} else
			(*rline[inputform]) (null);
	}
	/* if (!blank) 
	   OUTSTR("#\n"); */
	return count;
}



void
prcode(int linecount, int tab)
{
	bool someout;

	someout = false;
	while (linecount) {
		if ((*comment[inputform]) (0)) {
			linecount -= comprint();
			someout = true;
			continue;
		} else if (blankline())
			(*rline[inputform]) (null);
		else if ((*chkcont[inputform])()) {
			TABOVER(tab);
			prline("&");
			someout = true;
		} else {
			if (someout)
				TABOVER(tab);
			(*getlabel[inputform]) (null);
			prline("");
			someout = true;
		}
		--linecount;
	}
}


void
charout(int c)
{
	putc(c, outfd);
}



void
prline(char *str)
{
	fprintf(outfd, "%s", str);
	(*rline[inputform]) (charout);
	putc('\n', outfd);
}


int
input2(void)
{
	static int c;

	c = inchar();
	if (c == '\n')
		linechars = 0;
	else
		++linechars;
	return c;
}


int
unput2(int c)
{
	unchar(c);
	--linechars;
	return c;
}
