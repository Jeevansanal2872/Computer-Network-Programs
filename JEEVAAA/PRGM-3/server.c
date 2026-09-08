#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<arpa/inet.h>
int main()
{
char *ip="127.0.0.1";
int port=5566;
int server_sock,client_sock;
struct sockaddr_in server_addr,client_addr;
socklen_t addr_size;
char buffer[1024];
server_sock=socket(AF_INET,SOCK_STREAM,0);
if(server_sock<0)
{
perror("[-] socket error");
exit(1);}

printf("[+] tcp server socket created\n");

memset(&server_addr,'\0',sizeof(server_addr));
server_addr.sin_family=AF_INET;
server_addr.sin_port=htons(port);
server_addr.sin_addr.s_addr=inet_addr(ip);
if(bind(server_sock,(struct sockaddr *)&server_addr,sizeof(server_addr))<0)
{
perror("[-] bind error");
exit(1);}
printf("[+]bind to the port no:%d\n",port);
listen(server_sock,10);
printf("listening..\n");
addr_size=sizeof(client_addr);
client_sock=accept(server_sock,(struct sockaddr *)&client_addr,&addr_size);
printf("[+] client connected.\n");

int n;
recv(client_sock,&n,sizeof(n),0);
int matrix[n][n];
recv(client_sock,matrix,sizeof(matrux),0);
printf("Recieved Matrix : \n);
for(int i=0;i<n;i++){
for(int j=0;j<n;j++){
printf("%d",matrix[i][j]);
}
printf("\n");
}
char message[]="matrix recieved";
send(client_sock,message,sizeod(message),0);

send(client_sock,buffer,strlen(buffer),0);
close(client_sock);
printf("[+] client disconnected.\n");}
return 0;
}
