#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <time.h>

int	primes[10] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29};

void	swap(int *a, int *b)
{
	int	temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

void	shuffle_array(int *array, int length)
{
	int	random_index;

	for (int i = 0; i < length; i++)
	{
		random_index = rand() % 10;
		swap(&array[i], &array[random_index]);
	}
}

void	*get_unique_prime(void	*val)
{
	int	*res;

	res = (int *)malloc(sizeof(int));
	*res = *(int *)val;
	return (res);
	
}

int main(void)
{
	int			*res;
	pthread_t	threads[10];

	srand(time(NULL));
	shuffle_array(primes, 10);
	for (int i = 0; i < 10; i++)
		pthread_create(&threads[i], NULL, &get_unique_prime, (void *)&primes[i]);
	for (int i = 0; i < 10; i++)
	{
		pthread_join(threads[i], (void **)&res);
		printf("The number is : %d\n", *res);
		free(res);
	}

}