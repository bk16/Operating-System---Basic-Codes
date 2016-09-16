/*shmdt (shm_ptr), it will detached the shared memory.
• shm_ptr is the pointer to the shared memory, returned
by shmat() during shared memory attachment.
• If shmdt() fails, the returned value is non-zero.
• To remove a shared memory segment, use the following
shmctl (shm_id, IPC_RMID, NULL).
• shm_id is the shared memory ID.
• IPC_RMID indicates this is a remove operation.*/

#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <stdio.h>
#include <stdlib.h>

/*to check shmdt() [detach], and shmctl() [remove] */

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

	int randomValue = 20;
	int * randomPtr = &randomValue;
	printf("Return value from shmdt : %d\n",shmdt( shm_ptr ));
	printf("Return value from randomPtr : %d\n",shmdt( randomPtr ));

}
