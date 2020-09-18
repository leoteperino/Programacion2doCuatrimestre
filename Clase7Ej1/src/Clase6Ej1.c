/*
 ============================================================================
 Name        : Clase6Ej1.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void){
	char nombre[50] = "Juan";
	char nombre2[50] = "Juan";
	char nombre3[50] = "Francisco";
	int respuestaStrnlen;
	int respuestaStrncmp;
	char varSprintf[1250];

	printf("Uso de la Biblioteca strings para el manejo de Arrays:\n");
	printf("Print de un Array: %s\n", nombre);
	printf("Sizeof de un Array: %ld\n", sizeof(nombre));
	respuestaStrncmp=strncmp(nombre, nombre2, sizeof(nombre)-1);
	printf("Respuesta de comparar un Array con otro strncmp: %d\n", respuestaStrncmp);
	respuestaStrnlen=strnlen(nombre, sizeof(nombre)-1);
	printf("Uso de la funcion strnlen: %d\n", respuestaStrnlen);
	strncpy(nombre, nombre3,(sizeof(nombre)-1));
	printf("El array nombre ahora tiene el valor: %s (funcion strncpy)\n", nombre);
	sprintf(varSprintf,
			"*************************************************************\n"
			"Este es el uso del sprintf\nEl primer Array creado es: %s\n"
			"El segundo Array creado es: %s\n"
			"*************************************************************",
			nombre,
			nombre2);
	printf("%s", varSprintf);


	return EXIT_SUCCESS;
}
