#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

int	x = 5;

void	*routine()
{
	x++;
	sleep(2);
	printf("The value of x is %d\n", x);
	return (NULL);
}

void	*routine2()
{
	x--;
	sleep(2);
	printf("The value of x is %d\n", x);
	return (NULL);
}

int main(void)
{
	pthread_t	thread1;
	pthread_t	thread2;

	pthread_create(&thread1, NULL, &routine, NULL);
	pthread_create(&thread2, NULL, &routine2, NULL);
	pthread_join(thread1, NULL);
	pthread_join(thread2, NULL);
	printf("The value of x is %d\n", x);
	return (0);
}