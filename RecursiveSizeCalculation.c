#include <stdio.h>
#include <sys/types.h>
#include <fcntl.h>
#include <dirent.h>
#include <string.h>
#include <sys/stat.h>
#include <errno.h>
#include <stdlib.h>

long recursiveCalculate(char * name);

int main(int argc,char *argv[])
{
	struct dirent * direntp;
	DIR * dir;

	dir = opendir(".");
	
	long totalSize = 0;

	while( (direntp = readdir(dir)) != NULL )
	{
		char * name = direntp->d_name;
		int status;
	
		struct stat stat_buf;

		status = stat(name, &stat_buf);
		
		printf("Working on %s\n",name);

		if(direntp->d_type == DT_REG) 
		{
        		//remove(name);
			int fd = open(name,O_RDONLY);
			long size = (long)lseek(fd,0,SEEK_END);
			totalSize += size;
			close(fd);
    		}
		else if(direntp->d_type == DT_DIR)
		{
			//printf("I am in directory removal\n");
			char fullpath[256];
			if( name[0] !='.')
			{
				strcpy(fullpath,".");
				strcat(fullpath,"/");
				strcat(fullpath,name);
				//printf("I am in directory size calculation.\n");
				totalSize += recursiveCalculate(fullpath);
			}
		}	
	}
	printf("Total size is %ld\n",totalSize);
    	return 0;
}

long recursiveCalculate(char * dirname)
{
	struct dirent * direntp;
	DIR * dir;

	dir = opendir(dirname);
	//printf("i am in directory %s\n",dirname);
	
	long totalSize = 0;
	
	while( (direntp = readdir(dir)) )
	{
		char * name = direntp->d_name;
		int status;
		struct stat stat_buf;

		status = stat(name, &stat_buf);
	
		//printf("ready to remove %s\n",name);
		//printf("I am in directory removal function\n");
		if(direntp->d_type == DT_REG) 
		{
        		//remove(name);
			int fd = open(name,O_RDONLY);
			long size = (long)lseek(fd,0,SEEK_END);
			totalSize += size;
			close(fd);
    		}
		else if(direntp->d_type == DT_DIR)
		{
			//printf("I am in directory removal\n");
			char fullpath[256];
			if( name[0] !='.')
			{
				strcpy(fullpath,dirname	);
				strcat(fullpath,"/");
				strcat(fullpath,name);
				//printf("I am in directory size calculation.\n");
				totalSize += recursiveCalculate(fullpath);
			}
		}
	}

	closedir(dir);	
	return totalSize;
}
	
