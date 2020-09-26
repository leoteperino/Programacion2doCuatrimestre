/*
 ============================================================================
 Name        : Clase9Ej2_Struct.c
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
#include "Alumno.h"

#define QTY_ALUMNOS 10

int main(void) {
	Alumno arrayAlumnos[QTY_ALUMNOS];
	int op;
	int indice;
	int lugarVacio;
	int auxIndice;
	int id_alumnos=0;

	if(!alumno_inicializarArray(arrayAlumnos, QTY_ALUMNOS))
	{
		printf("El Array Alumno se inicializo con exito!\n");
	}

	do{
		utn_getNumero(  &op,
						"\n1 - Dar de alta un alumno\n"
						"2 - Modificar un alumno\n"
						"3 - Dar de baja un Alumno\n"
						"4 - Ordenar por Nombre\n"
						"5 - Imprimir la lista de Alumnos\n"
						"6 - Salir\n",
						"\nERROR",
						1,6,2);
		switch(op)
		{
			case 1:
				auxIndice = alumno_buscarVacio(arrayAlumnos, QTY_ALUMNOS);
				if(auxIndice>=0)
				{
					if(!alumno_altaAlumnos(arrayAlumnos, QTY_ALUMNOS, auxIndice, &id_alumnos))
					{
						printf("El alumno se dio de alta con exito\n");
					}
					else
					{
						printf("Algo salio mal, no se dio de alta el alumno.\n");
					}
				}
				break;
			case 2:
				if(!utn_getNumero(	&indice,"Ingrese el Indice del Alumno a modificar: ",
									"ERROR",ZERO,QTY_ALUMNOS,QTY_REINT))
				{
					if(!alumno_modificarAlumno(arrayAlumnos, QTY_ALUMNOS, indice))
					{
						printf("El alumno se modifico con exito\n");
					}
					else
					{
						printf("Algo salio mal, no se modofico el alumno.\n");
					}
				}
				break;
			case 3:
				printf("3");
				break;
			case 4:
				lugarVacio = alumno_buscarVacio(arrayAlumnos, QTY_ALUMNOS);
				if(lugarVacio == -1)
				{
					printf("No hay lugares vacios\n");
				}
				else
				{
					printf("El lugar vacio es: %d\n", lugarVacio);
				}
				break;
			case 5:
				alumno_imprimir(arrayAlumnos, QTY_ALUMNOS);
				break;
			case 6:
				auxIndice = alumnos_buscarIndicexId(arrayAlumnos,QTY_ALUMNOS,3);
				printf("\n%d\n", auxIndice);
				break;
		}
	}while(op!=7);

	return EXIT_SUCCESS;
}
