/* Using open followed by a dup call */
#include <stdio.h>
#include <string.h>
#include <fcntl.h>
int main(int argc,char **argv)
{
	int fd1,fd2;
	fd1=open("input.txt",O_RDWR);

	fd2=dup(fd1);

	printf("fd1 file offset before write: %d\n",lseek(fd1,0,1));
	write(fd1,"hello ",strlen("hello "));

	printf("fd2 file offset before write: %d\n",lseek(fd2,0,1));
	write(fd2,"wo",strlen("world "));

	return 0;
}
