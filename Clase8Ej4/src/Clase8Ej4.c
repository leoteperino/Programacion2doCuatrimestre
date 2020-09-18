/*
 ============================================================================
 Name        : Clase8Ej4.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */
/*
 * 4) Dada la siguiente cadena de caracteres:
char nombre[8]={'p','e','p','e','1','2','3','\0'};
​
Hacer una funcion que reciba el array y su tamaño,
y cuente cuantas veces aparece la letra 'e'.Al terminar de contar,
la funcion deberá imprimir por pantalla el valor contado.
Escribir un programa para probar la funcion.
 * */
#include <stdio.h>
#include <stdlib.h>

int utn_contarLetrasArray(char* array, int limite, int *pResultado);

int main(void) {

	char nombre[8]={'p','e','p','e','1','2','3','\0'};
	int letrasE;

	if(!utn_contarLetrasArray(nombre, sizeof(nombre), &letrasE))
	{
		printf("El array tiene %d letras e\n", letrasE);
	}
	else
	{
		printf("Algo salio mal.\n");
	}

	return EXIT_SUCCESS;
}

int utn_contarLetrasArray(char* array, int limite, int *pResultado)
{
	int retorno = -1;
	int i;
	int contador = 0;
	if(array!=NULL && limite>0 && pResultado!=NULL)
	{
		for(i=0;i<limite;i++)
		{
			if(array[i] == 'e')
			{
				contador++;
			}
		}
		*pResultado = contador;
		retorno = 0;
	}
	return retorno;
}
