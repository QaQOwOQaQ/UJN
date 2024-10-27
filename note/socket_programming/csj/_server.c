#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>

#define SIZE (1024)

int main(int argc, char **argv)
{
    if(argc != 2)
    {
        printf("Usage : <Port>\n");
        exit(1);
    }

    int clnt_sock, serv_sock;
    struct sockaddr_in serv_addr, clnt_addr;
    socklen_t clnt_len;
    char buf[SIZE] = {0};

    FILE *readfp;
    FILE *writefp;

    serv_sock = socket(PF_INET, SOCK_STREAM, 0);
    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_addr.s_addr = htonl(INADDR_ANY);
    serv_addr.sin_port = htons(atoi(argv[1]));
    serv_addr.sin_family = AF_INET;
    
    bind(serv_sock, (struct sockaddr*)&serv_addr, sizeof(serv_addr));
    listen(serv_sock, 5);
    clnt_len = sizeof(clnt_addr);
    clnt_sock = accept(serv_sock, (struct sockaddr*)&clnt_addr, &clnt_len);
    if(clnt_sock == -1)
    {
        printf("accept() error!\n");
        exit(1);
    }
    readfp = fdopen(clnt_sock, "r");
    // 产生一份新的 write fd
    writefp = fdopen(dup(clnt_sock), "w");

    fputs("From Server: Hi~ Client? \n", writefp);
    fputs("I love all of the world!\n", writefp);
    fputs("You are awesome!\n", writefp);
    fflush(writefp);    // 使用标准输入输出有缓冲，需要刷新一下确保数据全发送过去了

    // 半关闭
    shutdown(fileno(writefp), SHUT_WR);
    fclose(writefp);

    fgets(buf, SIZE, readfp);
    fputs(buf, stdout);
    fclose(readfp);
    
    return 0;
}