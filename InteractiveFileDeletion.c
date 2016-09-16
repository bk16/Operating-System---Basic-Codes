#include <stdio.h>
#include <sys/types.h>
#include <fcntl.h>
#include <dirent.h>
#include <string.h>

int main()
{
	struct dirent * direntp;
	DIR * dir;

	dir = opendir(".");

	while( (direntp = readdir(dir)) != NULL )
	{
		char * temp = direntp->d_name;
		int len = strlen(temp);
		int fd = open(temp,O_RDONLY);

		if( temp[len-1]== 't' && temp[len-2]== 'x' && temp[len-3]== 't' && temp[len-4]=='.')
		{
			off_t size;
			size = lseek(fd,0,SEEK_END);
			
			printf("%s is a txt file!\n",temp);
			if( (int)size > 1024 )
			{
				printf("Do you want to delete the file %s, having size %d?\n 'Y' : yes. 'N' : no.",temp,(int)size);
				char input;
				scanf("%c",&input);

				if( input ==  'Y')
				{
					printf("File %s removed\n",temp);
					remove(temp);
				}
			}
		}
		//printf("%s\n",direntp->d_name);
	}
	closedir(dir);

	return 0;
}
