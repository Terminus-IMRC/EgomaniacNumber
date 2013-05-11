#include <stdio.h>
#include <stdlib.h>

#ifndef PROJNAME
#error "Specify PROJNAME in compile."
#endif

void will_and_die(char* str, int exitno)
{
	fprintf(stderr, "%s called perror. So exiting.\nDetails: ", PROJNAME);
	 perror(str);
	 exit(exitno);
}
