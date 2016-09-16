#include<sys/types.h>
#include<sys/uio.h>
#include <unistd.h>
#include <errno.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/socket.h>
#define BUFFSIZE 4096
int main()
{
int n;
char buf[BUFFSIZE];
while ((n = read(STDIN_FILENO, buf, BUFFSIZE)) > 0)
if (write(STDOUT_FILENO, buf, n) != n)
printf("write error");
if (n < 0)
printf("read error");
exit(0);
}
