/*
 ============================================================================
 Name        : Clase1Ej2.c
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

	int numero1;
	int numero2;
	int suma;
	int respuestaScanf;

	printf("Ingrese el numero 1: ");
	__fpurge(stdin);
	respuestaScanf =  scanf("%d", &numero1);
	while(respuestaScanf == 0)
	{
		printf("ERROR Ingrese el numero 1: ");
		__fpurge(stdin);
		respuestaScanf =  scanf("%d", &numero1);
	}

	printf("Ingrese el numero 2: ");
	__fpurge(stdin);
	respuestaScanf =  scanf("%d", &numero2);
	while(respuestaScanf == 0)
	{
		printf("ERROR Ingrese el numero 2: ");
		__fpurge(stdin);
		respuestaScanf =  scanf("%d", &numero2);
	}

	suma = numero1 + numero2;
	printf("La suma de los numeros es: %d", suma);
}
