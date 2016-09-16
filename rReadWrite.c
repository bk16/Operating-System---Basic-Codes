#include <sys/types.h>
#include <sys/uio.h>
#include <unistd.h>
#include <stdio.h>
#define BUFFSIZE 4096

int main()
{
	int n;
	char buf[BUFFSIZE];
	
	while( (n = read(STDIN_FILENO, buf, BUFFSIZE)) > 0 )
	{
		if( write(STDOUT_FILENO, buf, n) != n )
		{
			printf("Write error\n");
		}
		if( n < 0 )
			printf("Read error\n");

	}
	return 0;
	//exit(0);
}
			
