#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <sys/socket.h>

#define BUFSIZE 1024

void error_exit(char *message);

int main(int argc, char *argv[])
{
	int fd, ret;
	char message[50];
	struct sockaddr_in server_addr;

	if (argc != 3) {
		printf("Usage : %s <IP> <port>\n", argv[0]);
	}

	fd = socket(AF_INET, SOCK_STREAM, 0);
	if (fd == -1) {
		error_exit("socket() error");
	}

	memset(&server_addr, 0, sizeof(server_addr));
	server_addr.sin_family = AF_INET;
	server_addr.sin_addr.s_addr = inet_addr(argv[1]);
	server_addr.sin_port = htons(atoi(argv[2]));

    printf("sin_addr.s_addr = %x\n", server_addr.sin_addr.s_addr);

	ret = connect(fd, (struct sockaddr*) &server_addr, sizeof(server_addr));
	if (ret == -1) {
		error_exit("connect() error");
	}

	fputs("write message : ", stdout);
	fgets(message, BUFSIZE, stdin);

	printf("strlen(message) : %d\n", strlen(message));
	write(fd, message, strlen(message)-1);

	close(fd);

	return 0;
}

void error_exit(char *message) {
	fputs(message, stderr);
	fputc('\n', stderr);
	exit(1);
}
