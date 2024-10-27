// 生产者-消费者 模型
#include <semaphore.h>
#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>

static sem_t sem_one;
static sem_t sem_two;
static int num;

void *read_routine(void *arg)
{
    for(int i = 0; i < 5; i ++ )
    {
        fputs("Input num: ", stdout);
        sem_wait(&sem_two);
        scanf("%d", &num);
        sem_post(&sem_one);
        // 此时该线程被阻塞， 执行另外一个线程
    }
    return NULL;
}

void *accu_routine(void *arg)
{
    int sum = 0;
    for(int i = 0; i < 5; i ++ )
    {
        sem_wait(&sem_one);
        sum += num;
        sem_post(&sem_two);
    }
    printf("sum = %d\n", sum);
    return NULL;
}

int main()
{
    pthread_t id1, id2;
    sem_init(&sem_one, 0, 0);
    sem_init(&sem_two, 0, 1);

    pthread_create(&id1, NULL, read_routine, NULL);
    pthread_create(&id2, NULL, accu_routine, NULL);

    pthread_join(id1, NULL);
    pthread_join(id2, NULL);

    sem_destroy(&sem_one);
    sem_destroy(&sem_two);

    return 0;   
}