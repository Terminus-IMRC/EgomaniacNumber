#include "defs.h"
#include <stdio.h>

_Bool isthetime_came()
{
	if((clock()-startc)/CLOCKS_PER_SEC>60*60*23.5){
		puts("Saba-ga-tonda.");
		return 1;
	}

	return 0;
}
