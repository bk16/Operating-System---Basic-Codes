
#include <signal.h> 
#include <stdio.h>
#include <stdlib.h>

void sigint_handler(int signum)
{
	printf("Snoozing!\n");
	alarm(5); //schedule next alarm for 5 seconds
}
void alarm_handler(int signum)
{
	printf("Buzz Buzz Buzz\n"); //set a new alarm for 1 second
	alarm(1);
}
int main()
{
	signal(SIGALRM, alarm_handler); //set up alarm handler
	signal(SIGINT, sigint_handler); //set up signint handler
	alarm(1); //schedule the first alarm
	while(1)
	{
	pause(); //pause in a loop
	}
}
