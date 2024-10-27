.PHONY:server
server:
	gcc web_server.c -o server -g -lpthread -D_REENTRANT
	./server 9190

.PHONY:client
client:
	gcc _client.c -o client -Wall -Werror -g -D_REENTRANT
	./client 127.0.0.1 5500

.PHONY:clean
clean:
	rm -rf client server *.o a.out