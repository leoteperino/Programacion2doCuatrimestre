/*
 ============================================================================
 Name        : Clase2Ej1.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 Realizar un programa que solicite cinco números e imprima por pantalla el promedio, el máximo y el mínimo.
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdio_ext.h>

#define QTY_NUMBERS 5

int main(void)
{
	int numbers;
	int sum = 0;
	float prom;
	int max;
	int min;
	int i;

	printf("Ingrese el numero 1: ");
	__fpurge(stdin);
	scanf("%d", &numbers);
	max = numbers;
	min = numbers;
	sum = numbers;

	for(i=1; i<QTY_NUMBERS; i++)
	{
		printf("Ingrese el numero %d: ",i+1);
		__fpurge(stdin);
		scanf("%d", &numbers);
		sum += numbers;

		if(numbers > max)
		{
			max = numbers;
		}

		if(numbers < min)
		{
			min = numbers;
		}
	}

	prom = (float)sum/QTY_NUMBERS;
	printf("\nEl promedio de todos los numeros ingresados es: %.2f", prom);
	printf("\nEl numero maximo ingresado es: %d", max);
	printf("\nEl numero minimo ingresado es: %d", min);

	return EXIT_SUCCESS;
}
