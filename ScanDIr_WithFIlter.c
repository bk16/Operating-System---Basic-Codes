#include <dirent.h>
#include <stdio.h>
#include <string.h>

int filter(const struct dirent *entry);

int main(void)
{
	struct dirent **namelist;
	int n;
	n = scandir(".", &namelist, filter , alphasort);
	if (n < 0)
		printf("scandir error");
	else 
	{
		while(n--) 
		{
			printf("%s\n", namelist[n]->d_name);
		}
	}
	return 0;
}

int filter(const struct dirent *entry)
{
	char *name=entry->d_name;
	if(name[strlen(name)-1]=='c' && name[strlen(name)-2]=='.')
		return 1;
	else
		return 0;
}
