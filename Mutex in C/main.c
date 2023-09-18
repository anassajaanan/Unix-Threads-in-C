#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

pthread_mutex_t	mutex;

int mails = 0;

void	*routine()
{
	for (int i = 0; i < 1000000; i++)
	{
		pthread_mutex_lock(&mutex);
		mails++;
		pthread_mutex_unlock(&mutex);
	}
	return (NULL);
}


int main(void)
{
	pthread_t	thread1;
	pthread_t	thread2;
	pthread_t	thread3;

	pthread_mutex_init(&mutex, NULL);
	pthread_create(&thread1, NULL, &routine, NULL);
	pthread_create(&thread2, NULL, &routine, NULL);
	pthread_create(&thread3, NULL, &routine, NULL);
	pthread_join(thread1, NULL);
	pthread_join(thread2, NULL);
	pthread_join(thread3, NULL);
	pthread_mutex_destroy(&mutex);
	printf("The value of mails is %d\n", mails);
	return (0);
}