// epoll IO 复用服务器
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <sys/epoll.h>

#define BUF_SIZE   (1024)
#define EPOLL_SIZE (64)

int main(int argc, char **argv)
{
    int serv_sock, clnt_sock;
    struct sockaddr_in serv_addr, clnt_addr;
    socklen_t clnt_len;
    
    char buf[BUF_SIZE];

    struct epoll_event event;
    struct epoll_event *ep_events;
    int epfd, event_cnt;

    serv_sock = socket(PF_INET, SOCK_STREAM, 0);
    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = htonl(INADDR_ANY);
    serv_addr.sin_port = htons(atoi(argv[1]));

    clnt_len = sizeof(clnt_addr);

    bind(serv_sock, (struct sockaddr*)&serv_addr, sizeof(serv_addr));
    listen(serv_sock, 3);

    epfd = epoll_create(EPOLL_SIZE);
    ep_events = malloc(sizeof(struct epoll_event) * EPOLL_SIZE);

    // create event for serv_sock
    event.data.fd = serv_sock;
    event.events = EPOLLIN;
    epoll_ctl(epfd, EPOLL_CTL_ADD, serv_sock, &event);

    while(1)
    {
        event_cnt = epoll_wait(epfd, ep_events, EPOLL_SIZE, -1);
        if(event_cnt == -1)
        {
            printf("epoll_wait() error!");
            exit(1);
        }
        printf("events cnt: %d\n", event_cnt);
        for(int i = 0; i < event_cnt; i ++ )
        {
            int fd = ep_events[i].data.fd;
            if(fd == serv_sock)
            {
                printf("server event\n");
                // read a new client
                clnt_sock = accept(fd, (struct sockaddr*)&clnt_addr, &clnt_len);
                // add epoll event
                event.data.fd = clnt_sock;
                event.events = EPOLLIN;
                epoll_ctl(epfd, EPOLL_CTL_ADD, clnt_sock, &event);              
                printf("New connected : %d\n", clnt_sock);
            }
            else 
            {
                printf("clnt event\n");
                // clnt write data or write EOF
                int str_len = read(fd, buf, BUF_SIZE);
                if(str_len == 0)
                {
                    // read eof
                    // remove epoll event
                    epoll_ctl(epfd, EPOLL_CTL_DEL, fd, NULL);
                    close(fd);
                    printf("Close connected: %d\n", fd);
                }
                else 
                {   
                    buf[str_len] = 0;
                    printf("Message from client: %s", buf);
                    write(fd, buf, strlen(buf));
                }
            }
        }
    }

    close(epfd);
    close(serv_sock);
    return 0;
}