#include <stdio.h>
#include <sys/types.h>
#include <fcntl.h>
#include <dirent.h>
#include <string.h>
#include <sys/stat.h>
#include <errno.h>
#include <stdlib.h>

int main()
{
	struct stat buf;
	DIR *dptr;
	struct dirent *sdir;
	int size=0;
	char str[100];

	char * folder = "/home/bali161616/OS";

	dptr=opendir(folder);
	int totalSize = 0;

	while(sdir=readdir(dptr))
	{
		if(sdir->d_type==4)
    		{		
        		if(sdir->d_name[0]!='.')
        		{		
            			stat(sdir->d_name,&buf);
            			size=buf.st_size;
            			printf("size=%d\n",size);
				totalSize += size;
       			 }
    		} /*For finding folder use d_type = 4 for dirent structure pointer. For recursive action put all in one separate function and call it recursively until folder search completes.*/
    		else
    		{
        		strcpy(str,folder);
        		strcat(str,"/");
        		strcat(str,sdir->d_name);
        		stat(str,&buf);
        		size+=buf.st_size;
        		printf("size=%d\n",size);
			totalSize += buf.st_size;
    		}
	}
	printf("Total Size is %d\n",totalSize);
}
