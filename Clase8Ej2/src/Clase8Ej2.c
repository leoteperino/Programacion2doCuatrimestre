/*
 ============================================================================
 Name        : Clase8Ej2.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */
/*
 * 2) Hacer una funcion que reciba el array del punto 1 y su tamaño,
 * y cuente cuantas veces aparece el numero 7. Al terminar de contar,
 * la funcion deberá imprimir por pantalla el valor contado.
 * Escribir un programa para probar la funcion.*/
#include <stdio.h>
#include <stdlib.h>

#define ARRAY_LEN 12

int utn_contarNumerosArray(int* array, int limite, int *pResultado);

int main(void) {
	int numeros[ARRAY_LEN]={3,7,4,5,2,3,7,1,7,3,2,7};
	int contador;
	if(!utn_contarNumerosArray(numeros, ARRAY_LEN, &contador))
	{
		printf("El numero 7 se repite: %d\n", contador);
	}
	else
	{
		printf("Algo salio mal.\n");
	}
	return EXIT_SUCCESS;
}

int utn_contarNumerosArray(int* array, int limite, int *pResultado)
{
	int retorno = -1;
	int i;
	int contador = 0;
	if(array!=NULL && limite>0 && pResultado!=NULL)
	{
		for(i=0;i<limite;i++)
		{
			if(array[i] == 7)
			{
				contador++;
			}
		}
		*pResultado = contador;
		retorno = 0;
	}
	return retorno;
}
