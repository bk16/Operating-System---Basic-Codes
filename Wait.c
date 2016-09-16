#include <sys/wait.h>
#include <stdlib.h>
#include <stdio.h>

int main(void)
{
	pid_t childpid;
	fork();

	int ptr;
	childpid = wait(&ptr);
	if(childpid != -1)	
	{
		printf("Waited for child with pid %ld\n", (long) childpid);
	}
	else
	{
		printf("No child to wait for\n");
		exit(1);
	}

	printf("Child process returned with status %d\n",ptr);
}
