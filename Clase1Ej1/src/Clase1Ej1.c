/*
 ============================================================================
 Name        : Clase1Ej1.c
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
	int numeros;
	int suma = 0;
	int i;
	int cantNumeros = 5;
	float promedio;

	for(i = 1; i<=cantNumeros; i++)
	{
		printf("Escriba un numero: ");
		__fpurge(stdin);
		scanf("%d", &numeros);
		suma += numeros;
	}

	promedio = (float)suma/cantNumeros;
	printf("El promedio de los numeros Ingresados es %.2f", promedio);

	return EXIT_SUCCESS;
}
