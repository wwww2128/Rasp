#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <asm-generic/socket.h>
#include <asm-generic/types.h>
#include <unistd.h>
#include <netinet/in.h>

#define PORT 1000

int main()
{
	struct sockaddr_in sad,cad;
	memset(&sad, 0, sizeof(sad));
	memset(&cad, 0, sizeof(cad));
	
	sad.sin_family = AF_INET;
	sad.sin_port = htons(PORT);
	sad.sin_addr.s_addr = htonl(INADDR_ANY);
	//printf("LE: %d	BE: %d\r\n",PORT, sad.sin_port);
	int fd = socket(AF_INET, SOCK_STREAM, 0);
}

