#include <stdio.h>
#include <signal.h>
#include <stdlib.h>
#include <stdbool.h>

#include "1.defs.h"
#include "def.h"
#include "allfuncs.h"


int (*input)(void), (*unput)(int c);
FILE *outfd;


static void dexit(int signum);

int
main(int argc, char *argv[])
{
	bool anyoutput;

	outfd = stdout;
	anyoutput = false;
	getargs(argc, argv);
	if (debug == 2)
		debfd = stderr;
	else if (debug)
		debfd = fopen("debug1", "w");

	if (signal(SIGINT, SIG_IGN) != SIG_IGN)
		signal(SIGINT, dexit);
	prog_init();

	for (;;) {
		++routnum;
		routerr = 0;

		input = input1;
		unput = unput1;
		if (!mkgraph())
			break;
		if (debug)
			prgraph();
		if (routerr)
			continue;

		if (progress)
			fprintf(stderr, "build:\n");
		build();
		if (debug)
			prtree();
		if (routerr)
			continue;

		if (progress)
			fprintf(stderr, "structure:\n");
		structure();
		if (debug)
			prtree();
		if (routerr)
			continue;
		input = input2;
		unput = unput2;

		if (progress)
			fprintf(stderr, "output:\n");
		output();
		if (routerr)
			continue;
		anyoutput = true;
		freegraf();
	}
	if (anyoutput)
		exit(EXIT_SUCCESS);
	else
		exit(EXIT_FAILURE);
}


static void
dexit(int signum_unused)
{
	exit(EXIT_FAILURE);
}
