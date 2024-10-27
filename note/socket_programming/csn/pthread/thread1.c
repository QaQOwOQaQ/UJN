#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
void *thread_main(void *arg);

int main()
{
    pthread_t t_id;
    int thread_param = 5;

    if(pthread_create(&t_id, NULL, thread_main, (void*)&thread_param) != 0)
    {
        puts("pthread_create() error!\n");
        exit(1);
    }
    sleep(3);
    puts("end of main!");
    return 0;
}

void *thread_main(void *arg)
{
    int cnt = *((int*)arg);
    for(int i = 0; i < cnt; i ++ )
    {
        sleep(1);
        puts("running thread");
    }    
    return NULL;
}
