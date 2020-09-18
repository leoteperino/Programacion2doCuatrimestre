/*
 ============================================================================
 Name        : Clase7Ej2.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdio_ext.h>
#include <string.h>
#include "utn.h"

#define LIMITE_BUFFER_STRING 10

int main(void) {

	char nombre[LIMITE_BUFFER_STRING];

	if(!utn_getNombre("Ingrese un nombre: ", "ERROR\n", nombre, 2, LIMITE_BUFFER_STRING))
	{
		printf("%s", nombre);
	}
	else
	{
		printf("Algo salio mal.\n");
	}


	return EXIT_SUCCESS;
}
