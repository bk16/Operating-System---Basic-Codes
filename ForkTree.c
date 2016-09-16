#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <unistd.h>

int main()
{
	pid_t B,C,A,whichone;

	int status;
	A = getpid();

	B = fork();
	if( B == -1)
	{
		printf("Process creation B failed\n");
	}

	C = fork();
	if( C == -1)
	{
		printf("Process creation C failed\n");
	}
	whichone = wait(&status);
	
	printf("Done waiting for %d\n",(int)whichone);
	if( B == 0)
	{
		pid_t D;
		printf("I am B, My pid is %d. My parent's pid is %d\n",(int)getpid(),(int)getppid());

		D = fork();

		if( D == 0 )	
		{
			printf("I am D, My pid is %d. My parent's pid is %d\n",(int)getpid(),(int)getppid());
		}
	}
	if( C == 0 )
	{
		pid_t E;
		pid_t F;

		printf("I am C, My pid is %d. My parent's pid is %d\n",(int)getpid(),(int)getppid());

		E = fork();
		F = fork();

		if( E == 0 )
		{
			printf("I am E, My pid is %d. My parent's pid is %d\n",(int)getpid(),(int)getppid());
		}
		
		if( F == 0 )
		{
			printf("I am F, My pid is %d. My parent's pid is %d\n",(int)getpid(),(int)getppid());
		}
	}

	if( B != 0 && C != 0)
	{
		printf("this is the root parent with pid %d and parent pid %d\n",getpid(),getppid());
	}
	return 0;
}
		
