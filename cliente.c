#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<sys/socket.h>
#include<arpa/inet.h>
#include<unistd.h>
int main(int argc, char * argv[]){
 int sock;		/*Socket Emitido*/
 struct sockaddr_in echoServerAddr;    /*Estrutura para el server*/
 struct sockaddr_in fromaddr;

 unsigned short echoServerPort = atoi(argv[3]);
 char * serverIP = argv[1];
 char * echoString = argv[2];

 sock = socket(PF_INET, SOCK_DGRAM, IPPROTO_UDP);
 if(sock == -1) return -1;
 echoServerAddr.sin_family = AF_INET;
 echoServerAddr.sin_addr.s_addr = inet_addr(serverIP);
 echoServerAddr.sin_port = htons(echoServerPort);
 bzero( &(echoServerAddr.sin_zero), 8);

 sendto(sock, echoString, sizeof(echoString), 0, (struct sockaddr *) &echoServerAddr, sizeof(echoServerAddr));
}
