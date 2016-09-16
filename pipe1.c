#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <unistd.h>
int main()
{
	int pfd[2];
	char buf[30];

	
	if( pipe(pfd) == -1 )
	{
		printf("Error creating pipe!\n");
		exit(1);
	}

	printf("Writing to pipe....");
	
	write( pfd[1], "Hello", 5);

	printf("Reading from pipe....");
	
	read( pfd[0], buf, 3);
	
	buf[3] = 0;

	printf("%s\n",buf);
	return 0;
}
