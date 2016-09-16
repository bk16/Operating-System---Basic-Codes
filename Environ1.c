#include <stdio.h>

int main()
{
	char *s;
	s = getenv("LOGNAME");

	if(s==NULL)
		printf("Variable Not Found\n");
	else
		printf("Value is %s \n", s);

	return 0;
}
