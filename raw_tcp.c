#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#include "custom.h"

int main(void)
{
	int i, recv_length, socket_fd;
	u_char buffer[9000];
	if((socket_fd = socket(PF_INET, SOCK_RAW, IPPROTO_TCP)) == -1)
		fatal_error("in socket");
	for(i=0; i<3; i++){
		recv_length = recv(socket_fd, buffer, 8000, 0);
		printf("Got a %d byte packet\n", recv_length);
		raw_dump(buffer, recv_length);
	}

   return 0;
}
