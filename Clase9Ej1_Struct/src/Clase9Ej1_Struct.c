/*
 ============================================================================
 Name        : Clase9Ej1_Struct.c
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
#include "struct.h"

int main(void) {
	Alumno arrayAlumno[30];
	arrayAlumno[0].legajo = 0001;
	strncpy(arrayAlumno[0].nombre,"Juan",30);

	return EXIT_SUCCESS;
}
