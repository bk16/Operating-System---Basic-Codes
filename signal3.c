#include <signal.h> 
#include <stdio.h>
#include <stdlib.h>

int alarmFlag = 0 ;

void alarmHandler() ; /* signal handler */
/*not neccessary that signal number is passed along*/
/*Here two signals can arrive. If I press ctrl+C before 5 seconds, SIGINT is called, else SIGALRM is called*/
void signalHandler(int signum)
{
	printf("\n Interrupt signal %d received \n", signum);
	exit(signum);
}

int main ()
{
	signal(SIGALRM, alarmHandler) ; /*Install signal Handler*/
	signal(SIGINT, signalHandler);
	alarm (5) ;
	printf ("Looping ...\n") ;
	while (!alarmFlag)
	{
		pause ( ) ; /* wait for a signal */
	}
	printf ("Loop ends due to alarm signal\n") ;
}
void alarmHandler ( )
{
	printf ("An ALARM clock signal was received\n") ;
	alarmFlag = 1 ;
}
