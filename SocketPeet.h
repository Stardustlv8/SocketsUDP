#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<sys/socket.h>
#include<arpa/inet.h>
#include<unistd.h>
struct sockaddr_in echoServerAddr;    
struct sockaddr_in echoClientAddr;
char Buffer [256];
unsigned short echoServerPort = atoi(argv[1]);

void startSocket(){
    int sock;
    
    sock = socket(PF_INET, SOCK_DGRAM, IPPROTO_UDP);
    if(sock == -1) return -1;

    echoServerAddr.sin_family = AF_INET;
    echoServerAddr.sin_addr.s_addr = htonl(INADDR_ANY);
    echoServerAddr.sin_port = htons(echoServerPort);
    bzero( &(echoServerAddr.sin_zero), 8);
    int bin = bind(sock, (struct sockaddr *) &echoServerAddr, sizeof(echoServerAddr));
}
void sendMessage(char * msg){

}
void receiveMessage(char *msg){
    int clientStructLen = sizeof(echoClientAddr);
    int recive = recvfrom(sock, Buffer, 256, 0,(struct sockaddr *) &echoClientAddr, &clientStructLen);
}