#include <stdio.h>
#include "def.h"
#include "allfuncs.h"

#define bufsize 1601
char buffer[bufsize];
int bufcount;
extern int errflag;
long stchars;			/* counts number of chars at most recent \n read */

int newline;			/* counts number of lines read so far in file */
extern void (*rline[])();
extern int (*comment[])();
extern int (*getlabel[])();
extern int (*chkcont[])();


void
flush(void)
{
	bufcount = 0;
}

void
addchar(int c)
{
	buffer[bufcount++] = c;
}

// not getline, to avoid conflict with <stdio.h> function of that name.
int
get_a_line(int *lastline, long *lastchar, int *linecom, long *charcom)

		/* set *lastline to number of last line of statement,
		   set *lastchar to number of last char of statement,
		   set *linecom to number of last line of comment preceding statement */
{

	int i;

	flush();
	while (unput1(input1()) != EOF) {
		while ((*comment[inputform]) (0) || blankline()) {
			(*rline[inputform]) (addchar);
			flush();
		}
		*linecom = newline;
		/* set charcom to number of last char of comment, starting at 0
		   if at start of file and no comment, will be -1  */
		*charcom = stchars - 1;
		if (unput1(input1()) == EOF)
			break;
		(*getlabel[inputform]) (addchar);
		(*rline[inputform]) (addchar);

		while (blankline()
		       || (!(*comment[inputform]) (0)
			   && (*chkcont[inputform])()))
			(*rline[inputform])(addchar);

		addchar('\0');
		*lastline = newline;
		*lastchar = stchars - 1;
		if (debug == 40)
			fprintf(stderr, "line %d; bufcount: %d\n", newline,
				bufcount);

		for (i = 5; i < bufcount; ++i)
			if (buffer[i] == ' ' || buffer[i] == '\t'
			    || buffer[i] == '\n')
				buffer[i] = '~';
		return bufcount;
	}
	return -1;
}


int linechars;			/* counts number of chars read so far in current line */
long newchar;			/* counts number of chars read so far in file */


int
input1(void)
{
	static int c;

	if (c == '\n')
		linechars = 0;
	c = inchar();
	++linechars;
	++newchar;
	if (c == '\n') {
		++newline;
		stchars = newchar;
	}
	return c;
}

int
unput1(int c)
{
	--linechars;
	--newchar;
	unchar(c);
	if (c == '\n') {
		stchars = newchar;
		--newline;
	}
	return c;
}
