/*
 ============================================================================
 Name        : library.c
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

#define MIN 0
#define MAX 10
#define QTY_REINT 3

int main(void) {
	char nombre[ARRAY_LEN_TEL];

	if(!utn_getTelefono(nombre, ARRAY_LEN_CUIT, "Ingrese un telefono: ", "ERROR\n", QTY_REINT))
	{
		printf("El Nombre ingresado es: %s", nombre);
	}
	else
	{
		printf("Algo salio mal, se acabaron tus reintentos.");
	}



	return EXIT_SUCCESS;
}
