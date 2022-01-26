#include <stdio.h>
#include <stdlib.h>
#include "def.h"
#include "allfuncs.h"

char *typename[TYPENUM] = {
	"STLNVX", "IFVX", "DOVX", "IOVX", "FMTVX",
	"COMPVX", "ASVX", "ASGOVX", "LOOPVX", "WHIVX",
	"UNTVX", "ITERVX", "THENVX", "STOPVX", "RETVX",
	"DUMVX", "GOVX", "BRKVX", "NXTVX", "SWCHVX",
	"ACASVX", "ICASVX"
};

int hascom[TYPENUM] = {
	2, 2, 2, 2, 2,
	2, 2, 2, 0, 0,
	0, 0, 2, 0, 0,
	0, 0, 0, 0, 2,
	2, 0
};

int nonarcs[TYPENUM] = {
	FIXED + 3, FIXED + 4, FIXED + 2, FIXED + 3, FIXED + 2,
	FIXED + 2, FIXED + 2, FIXED + 2, FIXED + 1, FIXED + 1,
	FIXED + 1, FIXED + 4, FIXED + 3, FIXED, FIXED,
	FIXED + 2, FIXED + 1, FIXED + 1, FIXED + 1, FIXED + 3,
	FIXED + 4, FIXED + 2
};

int childper[TYPENUM] = {
	0, 2, 1, 0, 0,
	0, 0, 0, 1, 1,
	1, 1, 1, 0, 0,
	1, 0, 0, 0, 1,
	2, 1
};

intptr_t arcsper[TYPENUM] = {
	1, 2, 2, 3, 0,
	-(FIXED + 1), 1, -(FIXED + 1), 1, 1,
	1, 1, 2, 0, 0,
	-FIXED, 1, 1, 1, -(FIXED + 1),
	2, 1
};

VERT *
arc(VERT v, int i)
{
	ASSERT(DEFINED(v), arc);
	ASSERT(0 <= i && i < ARCNUM(v), arc);
	return &graph[v][nonarcs[NTYPE(v)] + i];
}

VERT *
lchild(VERT v, int i)
{
	ASSERT(DEFINED(v), lchild);
	ASSERT(0 <= i && i < childper[NTYPE(v)], lchild);
	return &graph[v][nonarcs[NTYPE(v)] - i - 1];
}

intptr_t *
vxpart(VERT v, int type, int j)
{
	ASSERT((NTYPE(v) == type) && (0 <= j)
	       && (j < nonarcs[type] - FIXED), vxpart);
	return &graph[v][FIXED + j];
}

intptr_t *
expres(VERT v)
{
	int ty;

	ty = NTYPE(v);
	ASSERT(ty == COMPVX || ty == ASGOVX || ty == ASVX || ty == SWCHVX
	       || ty == ICASVX, expres);
	return &graph[v][FIXED];
}

intptr_t *
negpart(VERT v)
{
	ASSERT(NTYPE(v) == IFVX || NTYPE(v) == ACASVX, negpart);
	return &graph[v][FIXED + 1];
}

intptr_t *
predic(VERT v)
{
	ASSERT(NTYPE(v) == IFVX || NTYPE(v) == ACASVX, predic);
	return &graph[v][FIXED];
}

intptr_t *
level(VERT v)
{
	ASSERT(NTYPE(v) == GOVX || NTYPE(v) == BRKVX
	       || NTYPE(v) == NXTVX, level);
	return &graph[v][FIXED];
}

intptr_t *
stlfmt(VERT v, int n)
{
	ASSERT(NTYPE(v) == STLNVX || NTYPE(v) == FMTVX, stlfmt);
	return &graph[v][FIXED + n];
}

int
create(int type, int arcnum)
{
	int i, wds;

	if (nodenum >= maxnode) {
		maxnode += 100;
		graph = realloc(graph, maxnode * sizeof(*graph));
	}
	wds = nonarcs[type] + arcnum;
	graph[nodenum] = galloc(sizeof(*graph) * wds);
	for (i = 0; i < wds; i++)
		graph[nodenum][i] = 0;
	NTYPE(nodenum) = type;
	if (arcsper[type] < 0)
		ARCNUM(nodenum) = arcnum;

	return nodenum++;
}
