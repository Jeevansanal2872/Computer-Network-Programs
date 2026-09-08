#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <arpa/inet.h>
 
#define P 8080
#define B 100
 
int main() {
    int s, c1, c2;
    char b[B];
    struct sockaddr_in a;
 
    s = socket(AF_INET, SOCK_STREAM, 0);
 
    a.sin_family = AF_INET;
    a.sin_addr.s_addr = INADDR_ANY;
    a.sin_port = htons(P);
 
    bind(s, (struct sockaddr *)&a, sizeof(a));
    listen(s, 2);
 
    printf("Waiting for Client 1...\n");
    c1 = accept(s, NULL, NULL);
    printf("Client 1 Connected\n");
 
    printf("Waiting for Client 2...\n");
    c2 = accept(s, NULL, NULL);
    printf("Client 2 Connected\n");
 
    while(1) {
        recv(c1, b, B, 0);
        send(c2, b, strlen(b)+1, 0);
 
        recv(c2, b, B, 0);
        send(c1, b, strlen(b)+1, 0);
    }
 
    close(c1);
    close(c2);
    close(s);
}
