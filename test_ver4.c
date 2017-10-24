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
    pthread_t tid;

    for (i = 0; i < 3; i++)
        pthread_create(&tid, NULL, myThreadFun, (int *)i);
    pthread_exit(NULL);
    return 0;
}
