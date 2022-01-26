#include <stdio.h>
#include <stdbool.h>
#include "def.h"
#include "allfuncs.h"

int endbuf;

int
mkgraph(void)
{
	if (!parse())
		return false;

	hash_check();
	hash_free();
	fingraph();

	return true;
}
