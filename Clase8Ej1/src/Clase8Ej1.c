/*
 ============================================================================
 Name        : Clase8Ej1.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */
/*1) Se tiene el siguiente array de variables del tipo int
int numeros[12]={3,7,4,5,2,3,7,1,7,3,2,7};
Hacer una funcion que reciba el array y su tamaño, y lo imprima. Escribir un programa para probar la funcion.*/

#include <stdio.h>
#include <stdlib.h>

#define ARRAY_LEN 12

int utn_imprimirArrayInt(int array[], int len);

int main(void) {
	int numeros[ARRAY_LEN]={3,7,4,5,2,3,7,1,7,3,2,7};
	if(utn_imprimirArrayInt(numeros, ARRAY_LEN))
	{
		printf("No se pudo imprimir el Array\n");
	}
	return EXIT_SUCCESS;
}

int utn_imprimirArrayInt(int array[], int len)
{
	int retorno = -1;
	int i;
	if(array!=NULL && len>0)
	{
		for(i=0;i<len;i++)
		{
			printf("\nIndice: %d - Valor: %d", i, array[i]);
		}
		retorno = 0;
	}
	return retorno;
}
