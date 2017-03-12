#include <pthread.h>
#include "stdio.h"
#include "stdlib.h"
#include "unistd.h"

typedef struct{
    int valor;
}Entero;

void decrementar (int*);
void potencia (int*);
int contador = 0;

int main()
{
	pthread_t idHilo;
	pthread_t idHilo2;

	int val1 = 1;
	int val2 = 2;

	int hilo1, hilo2;
	int valor = 2;

	hilo1 = pthread_create (&idHilo, NULL, (void *)decrementar,(void *)&val1);
	hilo2 = pthread_create (&idHilo2, NULL, (void *)potencia, (void *)&val2);
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

void  decrementar (int *val)
{
	int cont;
	while (1)
	{
		contador -= *val;
		printf ("Hilo1  : %d\n", contador);
		sleep(5);
	}
}

void potencia (int *val){
	while(1){

		contador *= *val;
		printf ("Hilo2  : %d\n", contador);
		sleep(2);
	}
}

