#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <pthread.h>
#include <time.h>


void	*get_random_number()
{
	int	*value;

	value = (int *)malloc(sizeof(int));
	*value = rand() % 100 + 1;
	return (value);
}

int main(void)
{
	int			*res;
	pthread_t	threads[8];

	srand(time(NULL));
	
	for (int i = 0; i < 8; i++)
		pthread_create(threads + i, NULL, &get_random_number, NULL);
	for (int i = 0; i < 8; i++)
	{
		pthread_join(threads[i], (void **)&res);
		printf("The value of the thread is %d\n", *res);
		free(res);
	}


	return (0);
}