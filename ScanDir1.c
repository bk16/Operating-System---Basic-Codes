#include <stdio.h>
#include <sys/types.h>
#include <fcntl.h>
#include <dirent.h>
#include <string.h>
#include <sys/stat.h>
#include <errno.h>
#include <stdlib.h>

int filter(struct dirent * direntp);

int main(int argc,char *argv[])
{
	struct dirent * direntp;
	struct dirent **namelist;
	DIR * dir;

	dir = opendir(".");
	
	long totalSize = 0;

	int n = scandir(".",&namelist,NULL,alphasort);

	if( n< 0 )
	{
		printf("Error openeing directory\n");
		return 1;
	}
	else
	{
		while(n--)
		{
			printf("Name : %s\n",namelist[n]->d_name);
		}
	}

	n = scandir(".",&namelist,filter,alphasort);

	if( n< 0 )
	{
		printf("Error openeing directory\n");
		return 1;
	}
	else
	{
		while(n--)
		{
			printf("Name : %s\n",namelist[n]->d_name);
		}
	}
    	return 0;
}

int filter(struct dirent * direntp)
{
	char * name = direntp->d_name;

	if(name[0] =='c' || name[0] =='C')
		return 1;
	else
		return 0;
}

	
