#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>


int mails = 0;

void	*routine()
{
	for (int i = 0; i < 10000; i++)
	{
		mails++;
	}
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
	printf("The expected value of mails is 20000\n");
	printf("The value of mails is %d\n", mails);
	return (0);
}