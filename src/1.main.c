#include <stdio.h>
#include "def.h"
#include "allfuncs.h"

int endbuf;

int
mkgraph(void)
{
	if (!parse())
		return (FALSE);

	hash_check();
	hash_free();
	fingraph();

	return (TRUE);
}
