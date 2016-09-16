#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <stdio.h>
#include <stdlib.h>

/*server Program*/

int main()
{
	int shm_id;
	key_t mem_key;
	int *shm_ptr;

	mem_key = ftok(".", 'a');
	if( mem_key < 0 )
	{	
		printf("Negative memory key created!\n");
	}
	
	printf("Mem_key : %d\n",mem_key);

	/*to attach the shared memory to a process, shmat is used*/
	/*void *shmat(int shmid, const void *shmaddr, int shmflg);*/

	shm_id = shmget(mem_key,4*sizeof(int), IPC_CREAT | 0666);
	/*Now, if we give IPC_PRIVATE in place of mem_key, how do we know about mem_key?*/
	if (shm_id < 0) 
	{
		printf("*** shmget error (server) ***\n");
		exit(1);
	}
	shm_ptr = (int *) shmat(shm_id, NULL, 0);
	/* attach */
	if ( *shm_ptr == -1) 
	{
		printf("*** shmat error (server) ***\n");
		exit(1);
	}
}
