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
#include "Nacionalidad.h"


#define MAX_OPTION 6
#define MAX_REINT 3
#define MAX_ID 999999999

int main(void)
{
	Alumno arrayAlumnos[ARRAY_LEN_ALUMNOS];
	int menuOptions;
	int auxIndice;
	int auxId;

	if(!alumno_inicializarArray(arrayAlumnos, ARRAY_LEN_ALUMNOS))
	{
		printf("\nEl array de Alunmos se inicializo con exito!!\n");
	}
	else
	{
		printf("\nAlgo salio mal, no se pudo inicializar el Array de alumnos.\n");
	}

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
					printf("Opcion 1\nDar de alta un Alumno:\n");
					auxIndice=alumno_buscarVacio(arrayAlumnos,ARRAY_LEN_ALUMNOS);
					if(auxIndice>=ZERO)
					{
						if(!alumno_AltaDeAlumnos(arrayAlumnos,ARRAY_LEN_ALUMNOS,auxIndice))
						{
							printf("El alumno se cargo con exito!!\n");
						}
						else
						{
							printf("Algo salio mal, se acabaron tus reintentos.\n");
						}
					}
					else
					{
						printf("No hay lugares vacios en el array.\n");
					}
					printf("\n***************************************\n");
					break;
				case 2:
					printf("\n***************************************\n");
					printf("Opcion 2\nModificar un Alumno:\n");
					if(alumno_mostrarLista(arrayAlumnos,ARRAY_LEN_ALUMNOS)==-1)
					{
						printf("No hay alumnos cargados es esta lista.\n");
					}
					else
					{
					if(!utn_getNumero( &auxId,"Ingrese el numero de ID que desea modificar: ",
										   "ERROR\n",ZERO,MAX_ID,QTY_REINT))
						{
							auxIndice = alumnos_buscarIndicexId(arrayAlumnos,ARRAY_LEN_ALUMNOS,auxId);
							if(auxIndice>=ZERO)
							{
								if(!alumno_ModificarAlumnos(arrayAlumnos,ARRAY_LEN_ALUMNOS,auxIndice))
								{
									printf("El alumno fue modificado con exito!!\n");
								}
								else
								{
									printf("El alumno no puede ser modificado.\n");
								}
							}
							else
							{
								printf("Ingreso un ID invalido.\n");
							}
						}
					}
					printf("\n***************************************\n");
					break;
				case 3:
					printf("\n***************************************\n");
					printf("Opcion 3\nBorrar un Alumno:\n");
					if(alumno_mostrarLista(arrayAlumnos,ARRAY_LEN_ALUMNOS)==-1)
					{
						printf("No hay alumnos cargados es esta lista.\n");
					}
					else
					{
					if(!utn_getNumero( &auxId,"Ingrese el numero de ID que desea Borrar: ",
										   "ERROR\n",ZERO,MAX_ID,QTY_REINT))
						{
							auxIndice = alumnos_buscarIndicexId(arrayAlumnos,ARRAY_LEN_ALUMNOS,auxId);
							if(auxIndice>=ZERO)
							{
								if(!alumno_BajaAlumnos(arrayAlumnos,ARRAY_LEN_ALUMNOS,auxIndice))
								{
									printf("El alumno fue dado de baja\n");
								}
								else
								{
									printf("El alumno no fue dado de baja.\n");
								}
							}
							else
							{
								printf("Ingreso un ID invalido.\n");
							}
						}
					}
					printf("\n***************************************\n");
					break;
				case 4:
					printf("\n***************************************\n");
					printf("Opcion 4\nLista de Alumnos:\n");
					if(alumno_mostrarLista(arrayAlumnos,ARRAY_LEN_ALUMNOS)==-1)
					{
						printf("No hay alumnos cargados es esta lista.\n");
					}
					printf("\n***************************************\n");
					break;
				case 5:
					printf("\n***************************************\n");
					printf("Opcion 5\nLista de Alunos ordenada por nombre:\n");
					alumno_ordenarPorNombre(arrayAlumnos,ARRAY_LEN_ALUMNOS);
					if(alumno_mostrarLista(arrayAlumnos,ARRAY_LEN_ALUMNOS)==-1)
					{
						printf("No hay alumnos cargados es esta lista.\n");
					}
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
