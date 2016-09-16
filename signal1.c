/*
prototype of a signal handling function :
• void <signal handler func name> (int sig)
• Eg: void my_handler (int signo);
*/

/*
• To get the signal handler function registered to
the kernel, the signal handler function pointer
is passed as second argument to the ‘signal’
function.
• The prototype of the signal function is :
void (*signal(int signo, void (*func )(int)))(int);
*/

#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <stdlib.h>

static void sigint_handler (int signo) 
{
	printf ("Caught SIGINT!\n");
	exit (EXIT_SUCCESS);
}

int main (void)
{
	/*
	* Register sigint_handler as our signal handler for SIGINT.

	*/
	if (signal (SIGINT, sigint_handler) == SIG_ERR)
	{
		fprintf (stderr, "Cannot handle SIGINT!\n");
		exit (EXIT_FAILURE);
	}
	for (;;)
		pause ();
	//while(1);
	return 0;
}
/* handler for SIGINT 
int main()
How to catch
{
signal(SIGINT, signalHandler);
while(1)
{
printf("\n Going to sleep....\n");
sleep(1);
}
return 0;
}*/
