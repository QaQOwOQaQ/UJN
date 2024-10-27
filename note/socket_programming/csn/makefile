.PHONY:server
server:
	gcc _server.c -o server -Wall -Werror -g -lpthread -D_REENTRANT
	./server 9190

.PHONY:client
client:
	gcc _client.c -o client -Wall -Werror -g -lpthread -D_REENTRANT
	./client 127.0.0.1 9190 Ruiwen


.PHONY:app
app:
	gcc pthread/thread.c -lpthread -o app -g -Werror -Wall
	./app

.PHONY:clean
clean:
	rm -rf client server *.o a.out app