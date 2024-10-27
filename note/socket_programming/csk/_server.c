#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <sys/epoll.h>

#define BUF_SIZE   (1024)
#define EPOLL_SIZE (32)

int main(int argc, char **argv)
{
    int serv_sock, clnt_sock;
    struct sockaddr_in serv_addr, clnt_addr;
    socklen_t clnt_len;
    char buf[BUF_SIZE];

    // epoll 四件套
    struct epoll_event *ep_events;
    struct epoll_event event;
    int epfd, event_cnt;
    if (argc != 2)
    {
        printf("Usage : %s <port> \n", argv[0]);
        exit(1);
    }
    serv_sock = socket(PF_INET, SOCK_STREAM, 0);
    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = htonl(INADDR_ANY);
    serv_addr.sin_port = htons(atoi(argv[1]));

    bind(serv_sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr));
    listen(serv_sock, 5);

    
    epfd = epoll_create(EPOLL_SIZE);
    ep_events = malloc(sizeof(struct epoll_event) * EPOLL_SIZE);

    event.data.fd = serv_sock;
    event.events = EPOLLIN;    
    epoll_ctl(epfd, EPOLL_CTL_ADD, serv_sock, &event);

    while(1)
    {
        event_cnt = epoll_wait(epfd, ep_events, EPOLL_SIZE, -1);
        if(event_cnt == -1)
        {
            puts("epoll_wait() error!");
            exit(1);
        }
        for(int i = 0; i < event_cnt; i ++ )
        {
            // 如果是服务器，就给客户端创建监听事件
            if(ep_events[i].data.fd == serv_sock)
            {
                clnt_len = sizeof(clnt_addr);
                clnt_sock = accept(serv_sock, (struct sockaddr*)&clnt_addr, &clnt_len);
                event.data.fd = clnt_sock;
                event.events = EPOLLIN;
                epoll_ctl(epfd, EPOLL_CTL_ADD, clnt_sock, &event);
                printf("Connected connected: %d!\n", ep_events[i].data.fd);
            }
            // 如果是客户端的事件，有两种情况：
                // 1. 读入数据
                // 2. 结束链接
            else 
            {
                int str_len = read(ep_events[i].data.fd, buf, BUF_SIZE);
                if(str_len == 0)
                {
                    epoll_ctl(epfd, EPOLL_CTL_DEL, ep_events[i].data.fd, NULL);
                    close(ep_events[i].data.fd);
                    printf("Connected close: %d!\n", ep_events[i].data.fd);
                }
                else 
                {
                    write(ep_events[i].data.fd, buf, str_len);
                }
            }    
            
        }
    }

    close(serv_sock);
    close(epfd);
    return 0;
}