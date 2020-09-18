/*
 ============================================================================
 Name        : Clase8Ej5.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */
/*5) Hacer una funcion que reciba el array del punto 4,
y verifique que las letras dentro del mismo esten en el rango de 'a' a 'z' o de 'A' a 'Z'.
Si estan dentro del rango la funcion deberá devolver por valor(usando el return) un 0,
de lo contrario devolverá -1.*/

#include <stdio.h>
#include <stdlib.h>

int utn_verificarLetrasArray(char* array);

int main(void) {
	char nombre[8]={'p','e','p','e','1','2','3','\0'};
	int respuesta = utn_verificarLetrasArray(nombre);
	printf("\n%d\n", respuesta);
	if(!utn_verificarLetrasArray(nombre))
	{
		printf("Esta dentro del rango\n");
	}
	else
	{
		printf("No esta dentro del rango\n");
	}
	return EXIT_SUCCESS;
}

int utn_verificarLetrasArray(char* array)
{
	int retorno = 0;
	int i;
	if(array!=NULL)
	{
		for(i=0;array[i]!='\0';i++)
		{
			if(	(array[i] < 'A' || array[i] > 'Z') &&
				(array[i] < 'a' || array[i] > 'z'))
			{
				retorno = -1;
				break;
			}
		}
	}
	return retorno;
}
