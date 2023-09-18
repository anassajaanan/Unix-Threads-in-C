#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>


// When we use pthread_mutex_lock, one thread will be executed at a time, and the others will wait
// When we use


pthread_mutex_t	mutex;

void	*lock()
{
	pthread_mutex_lock(&mutex);
	printf("Got Lock\n");
	sleep(1);
	pthread_mutex_unlock(&mutex);
	return (NULL);
}

void	*trylock()
{
	if (pthread_mutex_trylock(&mutex) == 0)
	{
		printf("Got Lock\n");
		sleep(1);
		pthread_mutex_unlock(&mutex);
	}
	else
	{
		printf("Didn't get lock\n");
	}
	return (NULL);
}

int main(void)
{
	pthread_t	threads[4];
	
	pthread_mutex_init(&mutex, NULL);
	for (int i = 0; i < 4; i++)
		pthread_create(&threads[i], NULL, &trylock, NULL);
	for (int i = 0; i < 4; i++)
		pthread_join(threads[i], NULL);
	pthread_mutex_destroy(&mutex);
	return (0);
}