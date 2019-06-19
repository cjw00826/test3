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
	int s, s2, len;		// s = Sever s2 = Client
	unsigned t;
	struct sockaddr_un local, remote;		// un = unix, addr = address  loac = server, remote , client
	char str[100];

	if((s = socket(AF_UNIX, SOCK_STREAM, 0)) == -1)	// 통째로 외울것, 이해X error
	{
		perror("socket");
		exit(1);
	}

	local.sun_family = AF_UNIX;
	strcpy(local.sun_path, SOCK_PATH);
	unlink(local.sun_path);
	len = strlen(local, sun_path) + sizeof(local.sun_family);

	if(bind(s, (struct sockaddr *)&local, len) == -1)
	{
		perror("bind");
		exit(1);
	}

	if(listen(s, 5) == -1)
	{
		perror("listen");
		exit(1);
	}

	for(;;)
	{
		int done, n;
		printf("Waiting for a connection...\n");
		t = sizeof(remote);

		if ((s2 = accept(s, (struct sockaddr *)&remote, &t)) == -1)
		{
			perror("accept");
			exit(1);
		}

		printf("Connected.\n");

		done = 0;

		do
		{
			n = recv(s2, str, 100, 0);
			if(n <= 0)
			{
				if(n < 0) perror("recv");
				done = 1;
			}

			if(!done)
				if(send(s2, str, n, 0) < 0)
				{
					perror("send");
					done = 1;
				}
		} while(!done);

		close(s2);
	}

	return 0;
}

