/*
 ============================================================================
 Name        : Clase5Ej2_Arrays.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdio_ext.h>
#include "utn.h"

#define ARRAY_LEN 5
#define QTY_MIN -999999999
#define QTY_MAX 999999999
#define QTY_REINT 2

int main(void) {
	int array[ARRAY_LEN];
	float promedioArray;
	int maximo;
	int minimo;

	printf("\nCargando el Array: \n");
	utn_cargandoArrayInt(array, ARRAY_LEN, QTY_MIN, QTY_MAX, QTY_REINT);
	printf("\nRecorriendo el Array: ");
	utn_imprimirArrayInt(array, ARRAY_LEN);
	printf("\n\nPromedio de los numeros Ingresados en el Array:");
	if(!utn_promedioArrayInt(array, ARRAY_LEN, &promedioArray))
	{
		printf("\nEl promedio del Array es: %.2f\n", promedioArray);
	}
	else
	{
		printf("\nAlgo salio mal, vuelve a intentarlo.\n");
	}
	printf("\n\nNumero maximo ingresado en el Array:\n");
//	if(!utn_calcularmaximoArray(array, ARRAY_LEN, &maximo))
//	{
//		printf("El numero maximo ingresado es: %d\n", maximo);
//	}
//	else
//	{
//		printf("\nAlgo salio mal, vuelve a intentarlo.\n");
//	}
//	printf("\n\nNumero minimo ingresado en el Array:\n");
//	if(!utn_calcularminimoArray(array, ARRAY_LEN, &minimo))
//	{
//		printf("El numero minimo ingresado es: %d", minimo);
//	}
//	else
//	{
//		printf("\nAlgo salio mal, vuelve a intentarlo.\n");
//	}
	utn_calcularminimoArray(array, ARRAY_LEN, &minimo);
	printf("\n%d\n", minimo);
	return EXIT_SUCCESS;
}
