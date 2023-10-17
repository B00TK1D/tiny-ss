/*
    Tiny SS
    Author: B00TK1D
    Attempt to open a socket listening on all TCP ports from 1 to 65535 (or provided max_port).
    Print out any ports that fail to bind (meaning they are currently in use)
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>

#define MAX_PORT 65535

int main(int argc, char **argv) {
    int sock;
    struct sockaddr_in addr;
    int port;
    int ret;

    int max_port = MAX_PORT;

    if (argc > 1) {
        max_port = atoi(argv[argc - 1]);
    }

    for (port = 1; port <= max_port; port++) {
        sock = socket(AF_INET, SOCK_STREAM, 0);
        if (sock < 0) {
            exit(1);
        }

        memset(&addr, 0, sizeof(addr));
        addr.sin_family = AF_INET;
        addr.sin_port = htons(port);
        addr.sin_addr.s_addr = INADDR_ANY;

        ret = bind(sock, (struct sockaddr *)&addr, sizeof(addr));
        if (ret < 0) {
            printf("%d,", port);
        }

        close(sock);
    }

    return 0;
}