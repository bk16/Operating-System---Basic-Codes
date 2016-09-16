#include <stdio.h>
#include <unistd.h>
int main(void) 
{
	int x;
	x = 0;
	pid_t = fork();
	x = 1;
	printf("I am process %ld, with parent %ld & my x is %d\n", (long)getpid(),(long)getppid(), x);
	
	return 0;
}
