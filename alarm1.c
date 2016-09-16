#include <stdio.h>
int main ( )
{
	alarm (5) ; /* schedule an alarm signal in 5 seconds */
	printf ("Looping forever ...\n") ;
	printf("Return value from alarm : %d\n",alarm());
	while ( 1 )	/*This infinite loop runs till next fie seconds, till the alarm clock goes off*/
		printf("Return value from alarm : %d\n",alarm()) ;	
	printf ("This line should never be executed.\n") ;
}

/*
Syntax: int alarm (int count)
• alarm () instructs the kernel to send the SIGALRM
signal to the calling process after count seconds. If an
alarm had already been scheduled, it is overwritten. If
count is 0, any pending alarm requests are cancelled.
• alarm () returns the number of seconds that remain
until the alarm signal is sent.
*/
