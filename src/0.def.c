#include <stdio.h>
#include "def.h"

int routnum;
FILE *debfd;
LOGICAL routerr;
int nodenum, accessnum;
intptr_t **graph;
int progtype;
VERT stopvert, retvert;
VERT START;
