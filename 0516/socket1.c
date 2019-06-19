#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <sys/types.h>
#include <sys/un.h>
#include <unistd.h>

#define SOCK_PATH "echo_socket"

int main()
{
	int s, s2, len;
	unsigned t;
	struct sockaddr_un local, remote;
	char str[100];

	if((s = socket(AF_UNIX, SOCK_STREAM, 0)) == -1)
	{
		perror("socket");
		exit(1);
	}

