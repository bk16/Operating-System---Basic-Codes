#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<string.h>
#include<sys/types.h>
#include<sys/uio.h>

int main(int argc, char **argv)
{
	int read_bytes,n,fd,fd1;
	char buf[128];
	char * pathname="input.txt";

	/* In the open call permissions are not mandatory */
	fd=open(pathname,O_RDONLY);
	if(fd== -1)
	{
		printf("Error opening %s\n",pathname);
		return 1;
	}

	while(1)
	{
		read_bytes=read(fd,buf,sizeof(buf));
		if(!read_bytes)
			break;
		if(read_bytes==-1) 
		{
			printf("Error reading file %s\n",pathname);
			return 2;
		}
		/* The permissions in creat call can be set either
		using octal or symbolic representation*/

		fd1=creat("new.txt",777);
		n=write(fd1,buf,read_bytes);
		if(n== -1) 
		{
			printf("Error writing to stdout\n");
			return 3;
		}		
	}
	close(fd);
	close(fd1);
	return 0;
}
