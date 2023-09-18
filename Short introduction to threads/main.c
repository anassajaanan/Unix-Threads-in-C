#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>



void	*routine()
{
	printf("Hello from thread\n");
	sleep(3);
	printf("Bye from thread\n");
	return (NULL);
}

int main(void)
{
	pthread_t	thread1;
	pthread_t	thread2;

	pthread_create(&thread1, NULL, &routine, NULL);
	pthread_create(&thread2, NULL, &routine, NULL);
	pthread_join(thread1, NULL);
	pthread_join(thread2, NULL);
	printf("Hello from main\n");
	return (0);
}