// epoll 条件触发

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <sys/epoll.h>
#include <unistd.h>
#include <fcntl.h>

#define BUF_SIZE   (2)
#define EPOLL_SIZE (64)

void setnoblockingmode(int fd)
{
    int flag = fcntl(fd, F_GETFL, 0);
    fcntl(fd, F_SETFL, flag | O_NONBLOCK);
}

int main(int argc, char **argv)
{
    int serv_sock, clnt_sock;
    struct sockaddr_in serv_addr, clnt_addr;
    socklen_t clnt_len;
    char buf[BUF_SIZE];
    int str_len;

    struct epoll_event event;
    struct epoll_event *ep_events;
    int epfd, event_cnt;

    serv_sock = socket(AF_INET, SOCK_STREAM, 0);
    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = htonl(INADDR_ANY);
    serv_addr.sin_port = htons(atoi(argv[1]));

    bind(serv_sock, (struct sockaddr*)&serv_addr, sizeof(serv_addr));
    listen(serv_sock, 3);

    epfd = epoll_create(EPOLL_SIZE);
    ep_events = malloc(sizeof(struct epoll_event) * EPOLL_SIZE);

    setnoblockingmode(serv_sock);
    event.data.fd = serv_sock;
    event.events = EPOLLIN;
    epoll_ctl(epfd, EPOLL_CTL_ADD, serv_sock, &event);

    while(1)
    {
        event_cnt = epoll_wait(epfd, ep_events, EPOLL_SIZE, -1);
        printf("return epoll wait!\n");
        for(int i = 0; i < event_cnt; i ++ )
        {
            int fd = ep_events[i].data.fd;
            if(fd == serv_sock)
            {
                clnt_len = sizeof(clnt_addr);
                clnt_sock = accept(fd, (struct sockaddr*)&serv_addr, &clnt_len);
                printf("New connected: %d\n", clnt_sock);
                event.data.fd = clnt_sock;
                event.events = EPOLLIN;
                setnoblockingmode(clnt_sock);
                epoll_ctl(epfd, EPOLL_CTL_ADD, clnt_sock, &event);
            }   
            else 
            {
                str_len = read(fd, buf, BUF_SIZE);
                if(str_len == 0)
                {
                    epoll_ctl(epfd, EPOLL_CTL_DEL, fd, NULL);
                    printf("Close connected: %d\n", fd);
                    close(fd);
                }
                else 
                {
                    write(fd, buf, strlen(buf));
                }
            }
        }
        sleep(2);
    }
    close(epfd);
    close(serv_sock);
    return 0;
}