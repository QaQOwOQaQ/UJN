// 多线程服务器端
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <pthread.h>
#include <netinet/in.h>    // ???

#define BUF_SIZE  (1024)
#define MAX_CLNT  (3)

void send_message(char *message, int len);
void *handler_clnt(void *arg);

/* === cirtical section === */
int clnt_cnt;
int clnt_socks[MAX_CLNT];
/* === cirtical section === */

pthread_mutex_t mutex;

int main(int argc, char **argv)
{
    int serv_sock, clnt_sock;
    struct sockaddr_in serv_addr, clnt_addr;
    socklen_t clnt_len;
    pthread_t t_id;

    pthread_mutex_init(&mutex, NULL);
    serv_sock = socket(PF_INET, SOCK_STREAM, 0);

    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = htonl(INADDR_ANY);
    serv_addr.sin_port = htons(atoi(argv[1]));

    bind(serv_sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr));
    listen(serv_sock, 5);

    while(1)
    {
        clnt_len = sizeof(clnt_addr);
        clnt_sock = accept(serv_sock, (struct sockaddr*)&clnt_addr, &clnt_len);

        // 写入新的客户端
        pthread_mutex_lock(&mutex);
        if(clnt_cnt == MAX_CLNT)
        {
            printf("Cant add more client!\n");
            continue;
        }
        clnt_socks[clnt_cnt ++ ] = clnt_sock;
        pthread_mutex_unlock(&mutex);

        pthread_create(&t_id, NULL, handler_clnt, (void *)&clnt_sock);       //创建线程为新客户端服务，并且把clnt_sock作为参数传递
        pthread_detach(t_id);                                               //引导线程销毁，不阻塞
        printf("Connected client IP: %s \n", inet_ntoa(clnt_addr.sin_addr)); //客户端连接的ip地址
    }
    close(serv_sock);
    return 0;
}

// create a new thread for new client
void *handler_clnt(void *arg)
{
    int clnt_sock = *(int*)arg;
    int str_len = 0;
    char message[BUF_SIZE];
    while(1)
    {
        str_len = read(clnt_sock, message, BUF_SIZE - 1);
        if(str_len == 0)
        {
            break;
        }
        message[str_len] = 0;
        send_message(message, str_len);
    }

    // if str_len == 0, means client send close signal
    for(int i = 0; i < clnt_cnt; i ++ )
    {
        if(clnt_socks[i] == clnt_sock)
        {
            while(i + 1 < clnt_cnt)
            {
                clnt_socks[i] = clnt_socks[i + 1];
                i ++ ;
            }
            break;
        }
    }
    clnt_cnt -- ;
    pthread_mutex_unlock(&mutex);
    close(clnt_sock);
    return NULL;
}

// send message for all clients
void send_message(char *message, int len)
{
    pthread_mutex_lock(&mutex);
    for(int i = 0; i < clnt_cnt; i ++ )
    {
        write(clnt_socks[i], message, len);
    }
    pthread_mutex_unlock(&mutex);
}