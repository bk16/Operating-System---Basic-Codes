#include <stdio.h>
#include <unistd.h>
int main()
{
	execl ("./temp", /* program to run - give full path */
		"temp", /* name of program sent to argv[0] */	
		NULL); /* terminate arg list */

	printf ("EXEC Failed\n") ;
	/* This above line will be printed only on error and not otherwise */
}
