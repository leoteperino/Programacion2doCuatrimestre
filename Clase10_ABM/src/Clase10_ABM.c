/*
 ============================================================================
 Name        : Clase10_ABM.c
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

#define ZERO 0
#define MAX_OPTION 6
#define MAX_REINT 3
int main(void)
{
	int menuOptions;
	do
	{
		if(!utn_getNumero(	&menuOptions,
							"\n*****Menu de Opciones*****\n"
							"1 - Dar de alta un alumno\n"
							"2 - Modificar un alumno\n"
							"3 - Borrar un alumno\n"
							"4 - Imprimir la lista de alumnos\n"
							"5 - Ordenar la lista por Nombre\n"
							"6 - Salir del Menu\n"
							"-----------------------------\n"
							"Elija una Opcion del Menu: ",
							"\nERROR",ZERO,MAX_OPTION,MAX_REINT))
		{
			switch(menuOptions)
			{
				case 1:
					printf("\n***************************************\n");
					printf("Opcion 1\nDar de alta un Aluno:\n");
					printf("\n***************************************\n");
					break;
				case 2:
					printf("\n***************************************\n");
					printf("Opcion 2\nModificar un Aluno:\n");
					printf("\n***************************************\n");
					break;
				case 3:
					printf("\n***************************************\n");
					printf("Opcion 3\nBorrar un Aluno:\n");
					printf("\n***************************************\n");
					break;
				case 4:
					printf("\n***************************************\n");
					printf("Opcion 4\nLista de Alumnos:\n");
					printf("\n***************************************\n");
					break;
				case 5:
					printf("\n***************************************\n");
					printf("Opcion 5\nLista de Alunos ordenada por nombre:\n");
					printf("\n***************************************\n");
					break;
				case 6:
					printf("\n***************************************\n");
					printf("Opcion 6\nGracias por usar Alumnos!!:\n");
					printf("\n***************************************\n");
					break;
			}
		}
	}while(menuOptions);
	return EXIT_SUCCESS;
}
