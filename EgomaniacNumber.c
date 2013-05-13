#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <errno.h>
#include <time.h>

#include "defs.h"

#ifndef X
#error "Specify X in compile."
#endif

#if ! X%2
#error "X must be odd number."
#endif

#ifndef ELEM
#error "Specify ELLEM in compile."
#endif

#define Ceilings (X*X)
#define OneLine (X*(Ceilings+1)/2)

char* advance_till_space(char* buf);

double startc;

int main()
{
	int i;
	long long j;
	int res[Ceilings];
	int n;
	char* buf, *bufdef;
	FILE* fp;

	bufdef=buf=(char*)malloc(sizeof(char)*0xff);

	for(i=0; i<Ceilings; i++)
		res[i]=0;

	sprintf(buf, "ms%d.txt", X);
	fp=fopen(buf, "r");
	if(errno)
		will_and_die(buf, 1);

	startc=clock();

	for(j=0; j<ELEM; j++){
		fgets(buf, 0xff, fp);
		if(*buf=='-')
			fgets(buf, 0xff, fp);
		for(i=0; i<X/2; i++){
			fgets(buf, 0xff, fp);
		}

		while(*buf++ == ' ')
			;

		for(i=0; i<X/2; i++){
			buf=advance_till_space(buf);
			while(!isdigit((unsigned char)*buf))
				buf++;
		}

		n=atoi(buf);
		res[n-1]++;

		for(i=0; i<X/2; i++)
			fgets(buf, 0xff, fp);

		buf=bufdef;

		if(isthetime_came())
			break;
	}

	fclose(fp);

	fp=fopen("out.txt", "w");
	for(i=0; i<Ceilings; i++)
		fprintf(fp, "%d %d\n", i+1, res[i]);

	fclose(fp);

	free(buf);

	return 0;
}

char* advance_till_space(char* buf)
{
	while(*buf++ != ' ')
		;
	return buf;
}
