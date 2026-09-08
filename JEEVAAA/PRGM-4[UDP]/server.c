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
int server_sock,client_sock;
struct sockaddr_in server_addr,client_addr;
socklen_t len=sizeof(client_addr);
char buffer[BUFFER_SIZE];
server_sock=socket(AF_INET,SOCK_DGRAM,0);
if(server_sock<0)
{
perror("[-] socket error");
exit(1);}
printf("[+] UTP  server socket created\n");
server_addr.sin_family=AF_INET;
server_addr.sin_addr.s_addr=INADDR_ANY;
server_addr.sin_port=htons(PORT);

if(bind(server_sock,(struct sockaddr*)&server_addr,sizeof(server_addr))<0){
 perror("Bind failed ...");
 close(server_sock);
 exit(EXIT_FAILURE);
}
printf("UDP Server is running..........\n");
while(1){
recvfrom(server_sock,buffer,BUFFER_SIZE,0,(struct sockaddr*)&client_addr,&len);
buffer[strcspn(buffer,"\n")]='\0';
printf("Client : %s\n",buffer);
char reply[]="Message Recieved by server";
sendto(server_sock,reply,strlen(reply),0,(struct sockaddr*)&client_addr,len);
}
close(server_sock);
return 0;
}
