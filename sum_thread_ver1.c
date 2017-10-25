# include <stdio.h>
# include <pthread.h>

void * thread_sum(void *);
int TotalSumThread=0;
int TotalSumMain=0;

int main()
{
    int iNumber,iCount;
    pthread_t tid;
    printf("Enter Number Up to Which You want to Sum :");
    scanf("%d",&iNumber);
    pthread_create(&tid,NULL,thread_sum,(void *)&iNumber);
    pthread_join(tid,NULL);
    for(iCount=1;iCount<=iNumber;iCount=iCount+2)
    {
        TotalSumMain=TotalSumMain + iCount;
    }
    int total_sum = TotalSumMain + TotalSumThread;
    printf("Final Sum is : %d \n",total_sum);
    return 0;
}

void *thread_sum(void *no)
{
    int *iNumber,iCount;
    iNumber=(int*)no;
    for(iCount=2;iCount<=*iNumber;iCount=iCount+2)
        TotalSumThread=TotalSumThread + iCount;
    pthread_exit(NULL);
}
