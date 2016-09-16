#include <sys/wait.h>
#include <stdio.h>

int main(void)
{
	pid_t childpid;
	int * p;
	childpid = fork();
	//printf("Childpid is : %ld\n", (long) childpid);
	childpid = wait(p);
	printf("Childpid is : %ld\n", (long) childpid);
	if(childpid != -1)	
		printf("Waited for child with pid %ld\n", (long) childpid);
	else
		printf("No child to wait for\n");
}
