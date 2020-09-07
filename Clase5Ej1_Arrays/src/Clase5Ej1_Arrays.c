/*
 ============================================================================
 Name        : Clase5Ej1_Arrays.c
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

#define QTY_SIZE_ARRAY 5
#define QTY_MIN -999999999
#define QTY_MAX 999999999
#define QTY_REINT 2

int main(void) {
	//Arrays
	int numeros[QTY_SIZE_ARRAY];
	int i;
	int bufferInt;

	//Carga del Array
	for(i=0;i<QTY_SIZE_ARRAY;i++)
	{
		if(!utn_getInt(&bufferInt, "Ingrese un numero: ", "ERROR", QTY_MIN, QTY_MAX, QTY_REINT))
		{
			numeros[i] = bufferInt;
		}
		else
		{
			printf("\nAlgo salio mal, se acabaron tus reintentos");
		}
	}

	printf("\nEl Array de Numeros se cargo de esta manera:\n");
	//Mostrar el array
	for(i=0;i<QTY_SIZE_ARRAY;i++)
	{
		printf("Indice: %d - Valor: %d\n", i, numeros[i]);
	}

	return EXIT_SUCCESS;
}
