#include <stdio.h>
#include <stdbool.h>
#include "1.defs.h"
#include "1.incl.h"
#include "def.h"
#include "allfuncs.h"


void
prog_init(void)
{
	endline = endcom = 0;
	endchar = -1;
	comchar = -1;
	graph = challoc(sizeof(*graph) * maxnode);
}

void
routinit(void)
{
	graf_init();
	progtype = !sub;
	routbeg = endline + 1;
	rtnbeg = endchar + 1;
	nameline = 0;
	stflag = UNDEFINED;
}

void
line_init(void)
{
	struct lablist *makelab();

	freelabs();
	newlab = linelabs = makelab(0L);
	flag = counter = nlabs = lswnum = swptr = p1 = 0;
	p3 = 5;
	endcom = endline;
	comchar = endchar;
	begline = endline + 1;
	begchar = endchar + 1;
	reflab = endlab = errlab = 0;
	r1 = r2 = 0;
}

void
graf_init(void)
{
	int arctype[3];
	long arclab[3];

	nodenum = 0;
	doptr = UNDEFINED;
	retvert = stopvert = UNDEFINED;
	ENTLST = FMTLST = 0;


	arctype[0] = -2;
	arclab[0] = implicit;
	START =
	    makenode(DUMVX, false, false, implicit, 1, arctype, arclab);
}
