#include<stdio.h>
#include<string.h>
#include<fcntl.h>
#include<unistd.h>
#include<arpa/inet.h>`
#include<sys/socket.h>

#define PORT 8080

int main(){
int s,c,fd,n;
char file[100],buff[1024];
struct sockaddr_in server;

s=socket(AF_INET,SOCK_STREAM,0);


server.sin_family=AF_INET;
server.sin_port=htons(PORT);
server.sin_addr.s_addr=inet_addr("127.0.0.1");

connect(s,(struct sockaddr *)&server,sizeof(server));
printf("Enter filename : ");
scanf("%99s",file);
send(s,file,strlen(file)+1,0);
while((n=recv(s,buf,1023,0))>0)
        printf("%.*s",n,buff);
close(s);
}
 

