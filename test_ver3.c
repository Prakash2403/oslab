#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

// A normal C function that is executed as a thread
// when its name is specified in pthread_create()
void *myThreadFun(void *vargp)
{
    printf("Thread is running\n");
    return NULL;
}

int main()
{
    pthread_t tid;
    printf("Before Thread\n");
    pthread_create(&tid, NULL, myThreadFun, NULL);
//    pthread_join(tid, NULL);
    sleep(1);
    printf("After Thread\n");
    exit(0);
}
