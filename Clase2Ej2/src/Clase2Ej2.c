/*
 ============================================================================
 Name        : Clase2Ej2.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdio_ext.h>

int main(void) {

	int acumulador = 0;
	int contador = 0;
	int numero;
	float promedio;

	while(1)
	{
		printf("Ingrese un numero: ");
		__fpurge(stdin);
		scanf("%d", &numero);
		if(numero != 999)
		{
			acumulador+=numero;
			contador++;
		}
		else
		{
			break;
		}
	}

	promedio = (float)acumulador/contador;
	printf("El promedio es: %.2f", promedio);

	return EXIT_SUCCESS;
}
