#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>

#define SIZE (1024)

int main(int argc, char **argv)
{
    if(argc != 3)
    {
        printf("Usage : <IP> <Port> \n");
        exit(1);
    }
    
    int sock;
    struct sockaddr_in serv_addr;
    char buf[SIZE];

    FILE *writefp;
    FILE *readfp;

    sock = socket(PF_INET, SOCK_STREAM, 0);
    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_addr.s_addr = inet_addr(argv[1]);
    serv_addr.sin_port = htons(atoi(argv[2]));
    serv_addr.sin_family = AF_INET;

    connect(sock, (struct sockaddr*)&serv_addr, sizeof(serv_addr));
    
    writefp = fdopen(sock, "w");
    readfp = fdopen(sock, "r");

    // 从服务器接受数据，打印到终端，最后输出 thank you！
    while(1)
    {
        if(fgets(buf, SIZE, readfp) == NULL)
            break;
        fputs(buf, stdout);
        fflush(stdout);
    }
    fputs("From Client: Thank you!\n", writefp);
    fflush(writefp);

    fclose(writefp);
    fclose(readfp);


    return 0;
}