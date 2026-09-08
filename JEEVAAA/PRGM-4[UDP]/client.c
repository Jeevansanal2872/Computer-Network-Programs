#include<stdio.h>

#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<arpa/inet.h>
#define PORT 8080
#define BUFFER_SIZE 1024
int main()
{
char *ip="127.0.0.1";
int port=5566;

int sock;
struct sockaddr_in addr;
char buffer[BUFFER_SIZE];
struct sockaddr_in server_addr;
socklen_t len=sizeof(server_addr);
sock=socket(AF_INET,SOCK_DGRAM,0);

if(sock<0)
{
perror("[-] socket error");
exit(1);}

printf("[+] UTP client socket created\n");


server_addr.sin_family=AF_INET;
server_addr.sin_port=htons(port);
server_addr.sin_addr.s_addr=inet_addr(ip);

printf("connected to the server.\n");
printf("Enter the message : ");
fgets(buffer,BUFFER_SIZE,stdin);

sendto(sock,buffer,strlen(buffer),0,(struct sockaddr*)&server_addr,len);
recvfrom(sock,buffer,BUFFER_SIZE,0,(struct sockaddr*)&server_addr,&len);
buffer[strcspn(buffer,"\n")] = '\0';
printf("Server : %s\n",buffer);
close(sock);
return 0;
}

