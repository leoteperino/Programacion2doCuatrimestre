/*
 ============================================================================
 Name        : Clase3Ej1.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdio_ext.h>

int sumar(int a, int b, int *pResultado);
int restar(int a, int b, int *pResultado);
int multiplicacion(int a, int b, int *pResultado);

int main(void) {
	int num1;
	int num2;
	int resultado;
	int resultadoResta;
	int resScanf;

	do
	{
		printf("Ingrese el numero 1: ");
		__fpurge(stdin);
		resScanf = scanf("%d", &num1);
	}while(resScanf == 0);

	do
	{
		printf("Ingrese el numero 2: ");
		__fpurge(stdin);
		resScanf = scanf("%d", &num2);
	}while(resScanf == 0);

	sumar(num1, num2, &resultado);
	restar(num1, num2, &resultadoResta);
	//multiplicacion(num1, num2, &resultado);
	printf("la suma es: %d", resultado);
	printf("\nla resta es: %d", resultadoResta);
	printf("\nla multiplicacion es: %d", resultado);

	return EXIT_SUCCESS;
}

int sumar(int a, int b, int *pResultado)
{
	*pResultado = a+b;
	return 0;
}

int restar(int a, int b, int *pResultado)
{
	*pResultado = a-b;
	return 0;
}
//
//int multiplicacion(int a, int b, int *pResultado)
//{
//	*pResultado = a*b;
//	return 0;
//}
