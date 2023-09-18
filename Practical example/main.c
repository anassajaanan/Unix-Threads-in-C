#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>


void	*func1(void *array)
{
	int	*res;

	res = malloc(sizeof(int));
	*res = 0;
	for (int i = 0; i < 5; i++)
		*res += ((int *)array)[i];
	return ((void *)res);
}


void	*func2(void *array)
{
	int	*res;

	res = malloc(sizeof(int));
	*res = 0;
	for (int i = 5; i < 10; i++)
		*res += ((int *)array)[i];
	return ((void *)res);
}


int main(void)
{
	int			*res1;
	int			*res2;
	pthread_t	thread1;
	pthread_t	thread2;
	int	array[10] = {2, 12, 45, 8, 77, 23, 96, 45, 18, 47};


	pthread_create(&thread1, NULL, &func1, &array);
	pthread_create(&thread2, NULL, &func2, &array);
	pthread_join(thread1, (void **)&res1);
	pthread_join(thread2, (void **)&res2);
	printf("The sum of the array is : %d\n", *res1 + *res2);
	free(res1);
	free(res2);
	return (0);
}