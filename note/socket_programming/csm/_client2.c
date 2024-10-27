#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#define BUF_SIZE 10

int main(int argc, char *argv[])
{
    int sock;
    char buf[BUF_SIZE];
    struct sockaddr_in serv_addr;

    FILE *readfp;
    FILE *writefp;

    sock = socket(PF_INET, SOCK_STREAM, 0);
    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = inet_addr(argv[1]);
    serv_addr.sin_port = htons(atoi(argv[2]));

    connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr));
    readfp = fdopen(sock, "r");
    writefp = fdopen(sock, "w");
    printf("Debug!\n");
    while (1)
    {
        printf("debug!\n");
        if (fgets(buf, BUF_SIZE, readfp) == NULL)
        {
            printf("deont1");
            break;
        }
        fputs(buf, stdout);
        fflush(stdout);
    }

    fputs("FROM CLIENT: Thank you \n", writefp);
    fflush(writefp);
    fclose(writefp);
    fclose(readfp);

    return 0;
}