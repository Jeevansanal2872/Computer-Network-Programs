#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#define PORT 8080
#define BUFFER_SIZE 1024

int main()
{
    int sock;
    struct sockaddr_in server_addr;
    char buffer[BUFFER_SIZE];
    socklen_t len = sizeof(server_addr);

    sock = socket(AF_INET, SOCK_DGRAM, 0);

    if (sock < 0)
    {
        perror("Socket creation failed");
        exit(1);
    }

    printf("UDP Client Socket Created\n");

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);
    server_addr.sin_addr.s_addr = inet_addr("127.0.0.1");

    printf("Enter new generation English sentence:\n");
    fgets(buffer, BUFFER_SIZE, stdin);

    sendto(sock, buffer, strlen(buffer), 0,
           (struct sockaddr *)&server_addr, len);

    recvfrom(sock, buffer, BUFFER_SIZE, 0,
             (struct sockaddr *)&server_addr, &len);

    printf("\nFormal English:\n%s\n", buffer);

    close(sock);
    return 0;
}
