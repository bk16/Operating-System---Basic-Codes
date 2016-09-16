#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <stdlib.h>

/*How to catch a signal*/

void signalHandler(int signum)
{
	printf("\n Interrupt signal %d received \n", signum);
	exit(signum);
}

int main()
{
	signal(SIGINT, signalHandler);
	while(1)
	{
		printf("\n Going to sleep....\n");
		sleep(1);
	}
	return 0;
}
