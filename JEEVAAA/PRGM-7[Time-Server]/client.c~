#include<stdio.h>
#include<string.h>
#include<time.h>
#include<unistd.h>
#include<arpa/inet.h>

int main(){
int s=socket(AF_INET,SOCK_DGRAM,0);
struct sockaddr_in server;
socklen_t len=sizeof(server);
char buf[100]="TIME";

server.sin_family=AF_INET;
server.sin_port=htons(8080);
server.sin_addr.s_addr=inet_addr("127.0.0.1");

sendto(s,buf,strlen(buf),0,(struct sockaddr * )&server,len);

printf("Request send to server....\n");

recvfrom(s,buf,sizeof(buf),0,(struct sockaddr * )&server,&len);
printf("Server Time : %s",buf);

close(s);
return 0;
}
