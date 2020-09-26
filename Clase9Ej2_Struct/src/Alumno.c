/*
 * Alumno.c
 *
 *  Created on: Sep 24, 2020
 *      Author: leandro
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdio_ext.h>
#include <string.h>
#include "utn.h"
#include "Alumno.h"

/**
 * \brief Inicializa el array
 * \param array Array a ser actualizado
 * \param limite Limite del array
 * \return Retorna 0 (EXITO) y -1 (ERROR)
 *
 */
int alumno_inicializarArray(Alumno* array,int limite)
{
	int retorno=-1;
	int i;
	if(array!=NULL && limite>0)
	{
		retorno=0;
		for(i=0;i<limite;i++)
		{
			array[i].isEmpty = TRUE;
		}
	}
	return retorno;
}
/**
 * \brief Da de alta un Alumno en una posicion del array
 * \param array Array de Alumnos a ser actualizado
 * \param limite Limite del array de Alumnos
 * \param indice Posicion a ser actualizada
 * \return Retorna 0 (EXITO) y -1 (ERROR)
 */
int alumno_altaAlumnos(Alumno* arrayAlumnos,int limite, int indice,int* id)
{
	int retorno = -1;
	Alumno bufferAlumno;
	if(arrayAlumnos!=NULL && limite>0 && indice<limite && indice>=0 && id!=NULL)
	{
		if(!utn_getNombre(	bufferAlumno.nombre,
							LONG_NOMBRE,
							"Ingrese el nombre del Alumno:",
							"ERROR\n",
							QTY_REINT) &&
			!utn_getNumero( &bufferAlumno.legajo,
							"Ingrese un numero de Legajo: ",
							"ERROR",
							ZERO,
							MAX_LEGAJO,
							QTY_REINT))
		{
			bufferAlumno.isEmpty=FALSE;
			bufferAlumno.id = *id;
			arrayAlumnos[indice] = bufferAlumno;
			(*id)++;
			retorno=0;
		}
	}
	return retorno;
}
/**
 * \brief Da de alta un Alumno en una posicion del array
 * \param array Array de Alumnos a ser actualizado
 * \param limite Limite del array de Alumnos
 * \param indice Posicion a ser actualizada
 * \return Retorna 0 (EXITO) y -1 (ERROR)
 */
int alumno_modificarAlumno(Alumno* arrayAlumnos,int limite, int indice)
{
	int retorno = -1;
	Alumno bufferAlumno;
	if(arrayAlumnos!=NULL && limite>0 && indice<limite && indice>=0)
	{
		if(!utn_getNombre(	bufferAlumno.nombre,
							LONG_NOMBRE,
							"Ingrese el nombre del Alumno:",
							"ERROR\n",
							QTY_REINT) &&
			!utn_getNumero( &bufferAlumno.legajo,
							"Ingrese un numero de Legajo: ",
							"ERROR",
							ZERO,
							MAX_LEGAJO,
							QTY_REINT))
		{
			bufferAlumno.isEmpty=FALSE;
			arrayAlumnos[indice] = bufferAlumno;
			retorno=0;
		}
	}
	return retorno;
}

/**
 * \brief Imprime los alumnos cargados
 * \param Alumno arrayAlumnos[], Es el puntero al array de alumnos
 * \param int limite, es el limite de array
 * \return (-1) Error / (0) Ok
 *
 */
int alumno_imprimir(Alumno* pArrayAlumnos, int limite)
{
	int retorno=-1;
	int i=0;
	if(pArrayAlumnos!=NULL && limite>0)
	{
		for(i=0;i<limite;i++)
		{
			if(pArrayAlumnos[i].isEmpty==FALSE)
			{
				printf("\nID: %d - Nombre: %s - Legajo: %d",
						pArrayAlumnos[i].id,
						pArrayAlumnos[i].nombre,
						pArrayAlumnos[i].legajo);
			}
		}
		retorno=0;
	}
	return retorno;
}


int alumno_imprimirIndice(Alumno* pArrayAlumnos, int limite, int indice)
{
	int retorno=-1;
	int i=0;
	if(pArrayAlumnos!=NULL && limite>0)
	{
		if(pArrayAlumnos[i].isEmpty==FALSE)
		{
			printf("\nNombre: %s - Legajo: %d",
					pArrayAlumnos[indice].nombre,
					pArrayAlumnos[indice].legajo);
		}
		retorno=0;
	}
	return retorno;
}

int alumno_buscarVacio(Alumno* array, int limite)
{
	int respuesta = -1;
	int i;
	if(array!=NULL && limite>0)
	{
		for(i=0;i<limite;i++)
		{
			if(array[i].isEmpty==TRUE)
			{
				respuesta = i;
				break;
			}
		}
	}
	return respuesta;
}

int alumnos_buscarIndicexId(Alumno array[], int limite, int id)
{
	int respuesta = -1;
	int i;
	if(array!=NULL && limite>0 && id>= 0)
	{
		for(i=0;i<limite;i++)
		{
			if(array[i].isEmpty==FALSE && array[i].id==id)
			{
				respuesta=i;
				break;
			}
		}
	}
	return respuesta;
}

