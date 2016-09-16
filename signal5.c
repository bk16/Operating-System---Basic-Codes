

#include <signal.h> 
#include <stdio.h>
#include <stdlib.h>

void a_h(int sm)
{
	printf("BITS Pilani\n");
	//alarm(1);
//set a new alarm for 1 second
}
int main()
{
	signal(SIGALRM, a_h);	
	//set up alarm handler
	alarm(1);
	//schedule the first alarm
	while(1)
	{
		pause();
		alarm(1);
	//pause in a loop
	}
}
