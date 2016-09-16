#include <stdio.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/types.h>

/*to attach the shared memory to a process, shmat is used*/

/*void *shmat(int shmid, const void *shmaddr, int shmflg);*/

int main()
{
	int shm_id = shmget( IPC_PRIVATE, 14, IPC_CREAT | 0666 );
	/*IPC_PRIVATE (i.e., a private key).*/
	key_t k;
	k = 23;
	printf("%d\n",k);
	/*k = ftok();	/*how does ftok work*/
	k = ftok("Hello",'a');
	printf("k : %d\n",k);
	k = ftok("Hello",'b');
	printf("k : %d\n",k);
	printf("shm_d : %d\n",shm_id);

	/*Moreover, the place where a key is required accepts a special parameter, IPC_PRIVATE.*/
	key_t someKey;
	someKey = ftok(".",'a');
	printf("Some key : %d\n",k);
	/* IPC_PRIVATE creates a unique key, and gurantess that that particular key is not used anywhere*/
	return 0;
}
