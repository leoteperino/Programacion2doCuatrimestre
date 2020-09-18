/*
 ============================================================================
 Name        : Clase7Ej3-fgetsValidaciones.c
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

#define ARRAY_LEN 10
#define QTY_REINT 2

int main(void) {

	char nombre[ARRAY_LEN];

	if(!utn_getNombre(nombre, "Ingrese un nombre: ", "ERROR\n", QTY_REINT, ARRAY_LEN))
	{
		printf("%s", nombre);
	}
	else
	{
		printf("Algo salio mal\n");
	}

	return EXIT_SUCCESS;
}
