// IO流分离客户端
// 省略错误处理
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <unistd.h>

#define BUF_SIZE (1024)

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
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = inet_addr(argv[1]);
    serv_addr.sin_port = htons(atoi(argv[2]));
    if(connect(sock, (struct sockaddr*)&serv_addr, sizeof(serv_addr)) == -1)
    {
        printf("connect() error!\n");
        exit(1);
    }

    pid = fork();
    if(pid == 0)
        write_routine(sock, buf);
    else 
        read_routine(sock, buf);

    close(sock);
}

void write_routine(int fd, char buf[])
{
    // read from client
    while(1)
    {
        fgets(buf, BUF_SIZE, stdin);
        if(!strcmp("q\n", buf) || !strcmp("Q\n", buf))  
        {
            shutdown(fd, SHUT_WR); // half close
            break;
        }
        write(fd, buf, strlen(buf));
    }
}

void read_routine(int fd, char buf[])
{
    int str_len;
    while(1)
    {
        str_len = read(fd, buf, BUF_SIZE);
        if(str_len == 0)
            break;
        buf[str_len] = 0;
        printf("Message from server: %s", buf);
    }
}