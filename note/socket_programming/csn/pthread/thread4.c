// 利用 锁 实现线程安全
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <pthread.h>

#define NUM_THREAD (100)
#define MAX_NUM    (5000000)

void *thread_inc(void *arg);
void *thread_dec(void *arg);

long long num = 0;
pthread_mutex_t mutex;

int main()
{
    pthread_t thread_id[NUM_THREAD];
    pthread_mutex_init(&mutex, NULL);

    for(int i = 0; i < NUM_THREAD; i ++ )
    {
        if(i & 1)
            pthread_create(&(thread_id[i]), NULL, thread_inc, NULL);
        else 
            pthread_create(&(thread_id[i]), NULL, thread_dec, NULL);
    }

    for(int i = 0; i < NUM_THREAD; i ++ )
        pthread_join(thread_id[i], NULL);
    
    printf("result: %lld\n", num);
    pthread_mutex_destroy(&mutex);
}

void *thread_inc(void *arg)
{
    pthread_mutex_lock(&mutex);
    for(int i = 0; i < MAX_NUM; i ++ )
        num ++ ;
    pthread_mutex_unlock(&mutex);
    return NULL;
}

void *thread_dec(void *arg)
{
    pthread_mutex_lock(&mutex);
    for(int i = 0; i < MAX_NUM; i ++ )
        num -- ;
    pthread_mutex_unlock(&mutex);
    return NULL;
}