#include <pthread.h>
#include "stdio.h"
#include "stdlib.h"
#include "unistd.h"
void *funcionThread (void *parametro);
int contador = 0;
int main()
{
	pthread_t idHilo;
	int error;
	error = pthread_create (&idHilo, NULL, funcionThread, NULL);
	if (error != 0)
	{
		perror ("No puedo crear thread");
		exit (-1);
	}
	while (1)
	{
		contador++;
		printf ("Padre : %d\n", contador);
		sleep(1);
	}
 return 0;
}
void *funcionThread (void *parametro)
{
	while (1)
	{
		contador--;
		printf ("Hilo  : %d\n", contador);
		sleep(5);
	}
}

