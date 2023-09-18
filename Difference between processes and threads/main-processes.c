#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <sys/types.h>


int main(void)
{
	int	x = 5;

	int pid = fork();

	if (pid == 0)
	{
		x++;
	}
	sleep(2);
	printf("The value of x is %d\n", x);
	if (pid != 0)
		wait(NULL);
	return (0);
}