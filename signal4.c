#include <signal.h> 
#include <stdio.h>
#include <stdlib.h>

void alarm_handler(int signum)
{
	printf("BITS Pilani\n");
}
int main()
{
	signal(SIGALRM, alarm_handler);
	alarm(1);
	/*If no pause, the main exists and no alarm!*/
		
	pause();
}
