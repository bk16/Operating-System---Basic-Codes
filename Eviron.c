# include<stdio.h>

extern char **environ;

int main(int argc, char *argv[])
{
	int i;
	printf("Arguments to this Program\n");
	for(i=0;i<argc;i++)
	{
		printf("%s\n",argv[i]);
	}

	printf("Environment Listing of this program\n");
	for(i=0;environ[i]!=NULL;i++)
	{
		printf("%s\n",environ[i]);
	}
	return 0;
}
