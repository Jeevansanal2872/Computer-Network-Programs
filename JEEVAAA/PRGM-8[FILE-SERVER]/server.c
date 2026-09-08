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
server.sin_addr.s_addr=INADDR_ANY;

bind(s,(struct sockaddr * )&server,sizeof(server));
listen(s,5);

printf("Server listening on port %d...\n",PORT);

while(1){
c=accept(s,NULL,NULL);

if(fork()==0){
close(s);
n=recv(c,file,sizeof(file)-1,0);
file[n]='\0';

printf("Client Requested %s\n",file);

fd=open(file,O_RDONLY);

if(fd<0){
sprintf(buff,"file not found \n server pid : %d\n",getpid());
}
else{
sprintf(buff,"Server PID : %d\n\n",getpid());
n=read(fd,buff+strlen(buff),sizeof(buff)-strlen(buff)-1);
buf[strlen(buff)+n]='\0';
close(fd);
}
send(c,buff,strlen(buff),0);

close(c);
exit(0);}
close(c)} 
close(s);
return 0;
}
}
