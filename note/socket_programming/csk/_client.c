// 基于 fork 的 I/O 分流客户端
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>

#define BUF_SIZE (32)

// 建立 I/O 处理例程
void read_routine(int fd, char buf[]);
void write_routine(int fd, char buf[]);

int main(int argc, char **argv)
{
    int sock;
    struct sockaddr_in serv_addr;   
    char buf[BUF_SIZE];

    pid_t pid;

    sock = socket(PF_INET, SOCK_STREAM, 0);
    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_addr.s_addr = inet_addr(argv[1]);
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(atoi(argv[2]));
    if(connect(sock, (struct sockaddr*)&serv_addr, sizeof(serv_addr)) == -1)
    {
        printf("connect() error!");
        exit(1);
    }

    pid = fork();
    if(pid == 0)
        write_routine(sock, buf);
    else
        read_routine(sock, buf);

    close(sock);
    return 0;
}

void write_routine(int sock, char buf[])
{   
    while(1)
    {
        fputs("Input you message(q to quit):", stdout);
        fgets(buf, BUF_SIZE, stdin);
        if(!strcmp("q\n", buf) || !strcmp("Q\n", buf))
        {
            shutdown(sock, SHUT_WR);
            break;
        }
        write(sock, buf, strlen(buf));
    }
}

void read_routine(int sock, char buf[])
{
    int str_len;
    while(1)
    {
        str_len = read(sock, buf, BUF_SIZE);
        if(str_len == 0)
            break;
        buf[str_len] = 0;
        printf("Message From Server: %s", buf);
    }
}