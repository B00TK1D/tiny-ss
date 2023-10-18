/*
    Tiny SS
    Author: B00TK1D
    Attempt to open a socket listening on all TCP ports from 1 to 65535 (or provided max_port).
    Print out any ports that fail to bind (meaning they are currently in use)
*/

#include <stdio.h>
#include <stdlib.h>
#include <netinet/in.h>
#include <unistd.h>

#define MAX_PORT 65535

void scan(int sock_type, int max_port) {
    int sock;
    int ret;
    struct sockaddr_in addr;
    char first = 1;
    for (int port = 1; port <= max_port; port++) {
        sock = socket(AF_INET, sock_type, 0);
        if (sock < 0) {
            exit(1);
        }

        addr.sin_family = AF_INET;
        addr.sin_port = htons(port);
        addr.sin_addr.s_addr = INADDR_ANY;

        ret = bind(sock, (struct sockaddr *)&addr, sizeof(addr));
        if (ret < 0) {
            if (first) {
                first = 0;
            } else {
                printf(",");
            }
            printf("%d", port);
        }

        close(sock);
    }
}

int main(int argc, char **argv) {
    int sock;
    int ret;

    int max_port = MAX_PORT;

    if (argc > 1 && atoi(argv[argc - 1]) > 0 && atoi(argv[argc - 1]) <= MAX_PORT) {
        max_port = atoi(argv[argc - 1]);
    }

    if (argc > 1 && argv[1][0] == '-' && argv[1][1] == 'j') {
        printf("{tcp:[");
        scan(SOCK_STREAM, max_port);
        printf("],udp:[");
        scan(SOCK_DGRAM, max_port);
        printf("]}");
    } else {
        scan(SOCK_STREAM, max_port);
        printf(";");
        scan(SOCK_DGRAM, max_port);
    }

    

    return 0;
}