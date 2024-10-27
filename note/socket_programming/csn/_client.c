// 多线程客户端
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <pthread.h> 

#define BUF_SIZE   (1024)
#define NAME_SIZE  (20)

void *send_main(void *arg);
void *recv_main(void *arg);

char name[NAME_SIZE] = "[DEFAULT]";
char message[BUF_SIZE];

int main(int argc, char **argv)
{
    int sock;
    struct sockaddr_in serv_addr;
    pthread_t send_thread, recv_thread;
    void *thread_return;
    
    if(argc != 4)
    {
        printf("Usage : <IP> <Port> <Name>: %d\n", argc);
        exit(1);
    }

    sprintf(name, "[%s]", argv[3]);
    sock = socket(PF_INET, SOCK_STREAM, 0);

    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_addr.s_addr = inet_addr(argv[1]);
    serv_addr.sin_port = htons(atoi(argv[2]));
    serv_addr.sin_family = AF_INET;

    connect(sock, (struct sockaddr*)&serv_addr, sizeof(serv_addr));

    pthread_create(&send_thread, NULL, send_main, (void*)&sock);
    pthread_create(&recv_thread, NULL, recv_main, (void*)&sock);

    pthread_join(send_thread, &thread_return);
    pthread_join(recv_thread, &thread_return);
    close(sock);
    return 0;
}

void *send_main(void *arg)
{
    int sock = *(int*)arg;
    char name_message[NAME_SIZE + BUF_SIZE];
    int has_quit = 0;
    while(1)
    {
        if(has_quit == -1)
        {
            close(sock);
            exit(0);
        }
        fgets(message, BUF_SIZE, stdin);
        if(!strcmp("q\n", message) || !strcmp("Q\n", message))
        {
            has_quit = -1;
            // [WARNING]: you must add '\n' at the ending of the name_message
            // else client doesn't konw you readin is done
            sprintf(name_message, "%s Bye! I will leval this char room\n", name);
            write(sock, name_message, strlen(name_message));
        }
        else 
        {
            sprintf(name_message, "%s %s", name, message);
            write(sock, name_message, strlen(name_message));
        }
    }
    return NULL;
}

void *recv_main(void *arg)
{
    int sock = *(int*)arg;
    char name_message[NAME_SIZE + BUF_SIZE];
    int str_len;
    while(1)
    {
        str_len = read(sock, name_message, NAME_SIZE + BUF_SIZE - 1);
        if(str_len == -1)
            return (void*)-1;
        name_message[str_len] = 0;
        fputs(name_message, stdout);
    }
    return NULL;
}


