#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<sys/socket.h>
#include<arpa/inet.h>
#include<unistd.h>
int main(int argc, char * argv[]){
 int sock;		/*Socket Emitido*/
 struct sockaddr_in echoServerAddr;    /*Estrutura para el server*/
 struct sockaddr_in echoClientAddr;
 char Buffer [256];
 unsigned short echoServerPort = atoi(argv[1]);
 int reciveMessageSize;

 sock = socket(PF_INET, SOCK_DGRAM, IPPROTO_UDP);
 if(sock == -1) return -1;

 echoServerAddr.sin_family = AF_INET;
 echoServerAddr.sin_addr.s_addr = htonl(INADDR_ANY);
 echoServerAddr.sin_port = htons(echoServerPort);
 bzero( &(echoServerAddr.sin_zero), 8);

 int bin = bind(sock, (struct sockaddr *) &echoServerAddr, sizeof(echoServerAddr));

 int clientStructLen = sizeof(echoClientAddr);
 int recive = recvfrom(sock, Buffer, 256, 0,(struct sockaddr *) &echoClientAddr, &clientStructLen);
 if(recive == -1) return -1;
 printf("Mensaje recibido: %s\n", Buffer);
}
