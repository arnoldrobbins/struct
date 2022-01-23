#include <stdio.h>
#include <stdbool.h>
#include "def.h"

int routnum;
FILE *debfd;
bool routerr;
int nodenum, accessnum;
intptr_t **graph;
int progtype;
VERT stopvert, retvert;
VERT START;
