
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <stdio.h>
#include <stdlib.h>

/*Program to check inter-process communication -> Server Process*/	
int main()
{
	char c;
	int shmid;
	key_t key;

	/*Server Process*/
	char *shm, *s;
	key = 5678;
	int SHMSIZE = 100;

	/* * create the segment.* */
	if ((shmid = shmget(key, SHMSIZE, IPC_CREAT | 0666)) < 0)
	{
		perror("shmget"); exit(1);
	}
	/** Now we attach the segment to our data space.*/
	if ((shm = shmat(shmid, NULL, 0)) == (char *) -1)
	{
		perror("shmat");
		exit(1);
	}
	/** Now put some things into the memory for the other process to read. */
	s = shm;
	for (c = 'a'; c <= 'z'; c++)
		*s++ = c;

	*s = NULL;
	/** Finally, we wait until the other process
	* Changes the first character of our memory
	* to '*', indicating that it has read what
	* we put there.
	*/
	while (*shm != '*')
		sleep(1);
	exit(0);
}
