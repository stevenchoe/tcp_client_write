CC = gcc
CFLAGS = -W -Wall -O2
LDFLAGS = -lm

all : tcp_client_write

tcp_client_write : tcp_client_write.c
	$(CC) $(CFLAGS) -o $@ $^ $(LDFLAGS)

clean :
	rm -rf *.o
