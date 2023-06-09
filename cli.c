#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <string.h>
#include <arpa/inet.h>

#define PORT 9600
#define BUF_SIZE 128

int main(int argc, char *argv[]) {
	//socket
	int client_fd = socket(PF_INET, SOCK_DGRAM, 0);
	if (client_fd < 0) {
		fprintf(stderr, "Cannot create socket\n");
		return 1;
	}

	//set values
	struct sockaddr_in server_addr;
	server_addr.sin_family = AF_INET;
	server_addr.sin_port = htons(PORT);
	int ok = inet_pton(AF_INET, "127.0.0.1", &server_addr.sin_addr);
	if (!ok) {
		fprintf(stderr, "Cannot parse IP address\n");
		return 1;
	}

	//connect
	int err = connect(client_fd, (struct sockaddr *) &server_addr, sizeof(server_addr));
	if (err != 0) {
		fprintf(stderr, "Cannot connect to server\n");
		return 1;
	}

	printf("Type messages to send to the server. End with Ctrl+D.\n");

	//loop
	while (1) {
		char buf[BUF_SIZE];
		memset(*buf, 0, sizeof(buf));

		buf = getchar();

		//write
		ssize_t written = write(client_fd, myInput, 1);
		if (written < 0) {
			fprintf(stderr, "Cannot write data\n");
			return 1;
		}

		//recieve
		

	}
	
	//close
	printf("Closing connection\n");
	err = close(client_fd);
	if (err != 0) {
		fprintf(stderr, "Error while closing connection\n");
		return 1;
	}

	return 0;
}
