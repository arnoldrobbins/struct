#include <stdio.h>
#
#include "def.h"
#include "4.def.h"
extern int linechars;
extern int rdfree(), comfree(), labfree(), contfree();
extern int rdstand(), comstand(), labstand(), contstand();
extern int (*rline[])();
extern int (*comment[])();
extern int (*getlabel[])();
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
	return (count);
}



void
prcode(int linecount, int tab)
{
	int someout;

	someout = FALSE;
	while (linecount) {
		if ((*comment[inputform]) (0)) {
			linecount -= comprint();
			someout = TRUE;
			continue;
		} else if (blankline())
			(*rline[inputform]) (null);
		else if ((*chkcont[inputform]) ()) {
			TABOVER(tab);
			prline("&");
			someout = TRUE;
		} else {
			if (someout)
				TABOVER(tab);
			(*getlabel[inputform]) (null);
			prline("");
			someout = TRUE;
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
	return (c);
}


int
unput2(int c)
{
	unchar(c);
	--linechars;
	return (c);
}
