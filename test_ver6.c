#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>



// The function to be executed by all threads
void *myThreadFun(void *vargp)
{
    printf("Thread ID: %d\n ", vargp);
}

int main()
{
    int i;
    pthread_t tid[3];
    for (i = 0; i < 3; i++)
        pthread_create(&tid[i], NULL, myThreadFun, (int *)i);
    for (i=0; i < 3; i++)
	{
		pthread_join(tid[i], NULL);
	}
    return 0;
}
