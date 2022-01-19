#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <getopt.h>

#include "def.h"
#include "allfuncs.h"

int errflag;
FILE *infd;


int intcase = 1, arbcase = 0;
int exitsize = 0;		/* max number of nodes to be left in loop without iterating */
int maxnode = 400;		/* max number of nodes */
int maxhash = 347;		/* prime number = size of hash table */
int progress = 0;		/* if not 0, print line number every n lines, n = progress */
int labinit = 10;		/* labels generated starting with labinit */
int labinc = 10;		/* labels increase by labinc */
int inputform = 0;		/* = 0 if freeform input, 1 if standard form input */
int debug = 0;
int levbrk = 1;			/* true implies multilevel breaks; false implies single-level breaks only */
int levnxt = 1;			/* true implies multilevel nexts; false implies single-level nexts only */



void
getargs(int argc, char *argv[])
{
	int c;
	char str[2];

#define getval(var)	sscanf(optarg, "%d", &var)
	while ((c = getopt(argc, argv, "a:b:c:d:e:h:i:m:n:p:s:t:")) != -1) {
		switch (c) {
		case 'a':
			getval(arbcase);
			break;
		case 'b':
			getval(levbrk);
			break;
		case 'c':
			getval(labinc);
			break;
		case 'd':
			getval(debug);
			break;
		case 'e':
			getval(exitsize);
			break;
		case 'h':
			getval(maxhash);
			break;
		case 'i':
			getval(intcase);
			break;
		case 'm':
			getval(maxnode);
			break;
		case 'n':
			getval(levnxt);
			break;
		case 'p':
			getval(progress);
			break;
		case 's':
			getval(inputform);
			break;
		case 't':
			getval(labinit);
			break;
		default:
			str[0] = 'c';
			str[1] = '\0';
			error("invalid switch:", str, "");
			errflag = 1;
			break;
		}
	}
	if (errflag)
		exit(EXIT_FAILURE);

	if (optind >= argc)
		faterr("no input file", "", "");
	infd = fopen(argv[optind], "r");
	if (infd == NULL)
		faterr("can't open input file:", argv[optind], "");
}
