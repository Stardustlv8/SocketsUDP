#include <pthread.h>
#include "stdio.h"
#include "stdlib.h"
#include "unistd.h"
void *decrementar (void *parametro);
void *potencia (void *parametro);
int contador = 0;
int main()
{
	pthread_t idHilo;
	pthread_t idHilo2;

	int hilo1, hilo2;

	hilo1 = pthread_create (&idHilo, NULL, decrementar, NULL);
	hilo2 = pthread_create (&idHilo2, NULL, potencia, NULL);
	if (hilo1 != 0) return -1;
	if (hilo2 != 0) return -1;

	while (1)
	{
		contador++;
		printf ("Padre : %d\n", contador);
		sleep(1);
	}
 return 0;
}

void * decrementar (void *parametro)
{
	while (1)
	{
		contador--;
		printf ("Hilo1  : %d\n", contador);
		sleep(5);
	}
}

void * potencia (void * parametro){
	while(1){

		contador *= 2;
		printf ("Hilo2  : %d\n", contador);
		sleep(2);
	}
}

