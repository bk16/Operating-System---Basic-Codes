#include <stdio.h>
#include <sys/types.h>
#include <fcntl.h>
#include <dirent.h>
#include <string.h>
#include <sys/stat.h>
#include <errno.h>
#include <stdlib.h>


int main(int argc,char *argv[])
{
	struct dirent * direntp;
	DIR * dir;

	dir = opendir(".");
	
	while( (direntp = readdir(dir)) != NULL )
	{
		char * name = direntp->d_name;
		int status;
	
		printf("Working on %s\n",name);	
	}
    	return 0;
}

