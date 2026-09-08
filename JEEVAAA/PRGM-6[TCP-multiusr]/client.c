//implement multi client program using tcp and fork system call
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <arpa/inet.h>
 
#define P 8080
#define B 100
 
int main() {
    int s;
    char b[B];
    struct sockaddr_in a;
 
    s = socket(AF_INET, SOCK_STREAM, 0);
 
    a.sin_family = AF_INET;
    a.sin_port = htons(P);
    a.sin_addr.s_addr = inet_addr("127.0.0.1");
 
    connect(s, (struct sockaddr *)&a, sizeof(a));
 
    while(1) {
        printf("Enter: ");
        fgets(b, B, stdin);
        send(s, b, strlen(b)+1, 0);
 
        recv(s, b, B, 0);
        printf("Received: %s\n", b);
    }
 
    close(s);
}



