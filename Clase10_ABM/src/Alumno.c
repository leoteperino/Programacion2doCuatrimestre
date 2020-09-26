/*
 * Alumno.c
 *
 *  Created on: Sep 26, 2020
 *      Author: leandro
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdio_ext.h>
#include <string.h>
#include "utn.h"
#include "Alumno.h"

static int generarIdNuevo(void);

/**
 * \brief Inicializa el array
 * \param Array a ser actualizado
 * \param int Limite del array
 * \return Retorna 0 (EXITO) y -1 (ERROR)
 */
int alumno_inicializarArray(Alumno* array, int len)
{
	int ret=-1;
	int i=0;
	if(array!=NULL && len>0)
	{
		for(i=0;i<len;i++)
		{
			array[i].isEmpty=TRUE;
		}
		ret=0;
	}
	return ret;
}
/**
 * \brief Imprime los alumnos cargados
 * \param Alumno arrayAlumnos[], Es el puntero al array de alumnos
 * \param int limite, es el limite de array
 * \return (-1) Error / (0) Ok
 */
int alumno_mostrarLista(Alumno* array, int len)
{
	int ret=-1;
	int i=0;
	if(array!=NULL && len>0)
	{
		for(i=0;i<len;i++)
		{
			if(array[i].isEmpty==FALSE)
			{
				ret=0;
				printf("ID: %d - Nombre: %s %s - Legajo: %d - Estado:%d\n",
						array[i].id,
						array[i].name,
						array[i].lastName,
						array[i].file,
						array[i].isEmpty);
			}
		}
	}
	return ret;
}
/**
 * \brief Busca el primer lugar vacio de la lista de Alumnos
 * \param Alumno arrayAlumnos[], Es el puntero al array de alumnos
 * \param int limite, es el limite de array
 * \return devuelve el indice del lugar vacio de la lista o -1 en caso de no encontrar lugar vacio
 */
int alumno_buscarVacio(Alumno* array, int len)
{
	int ret = -1;
	int i;
	if(array!=NULL && len>0)
	{
		for(i=0;i<len;i++)
		{
			if(array[i].isEmpty==TRUE)
			{
				ret = i;
				break;
			}
		}
	}
	return ret;
}
/**
 * \brief Genera un numero de id nuevo cada vez que se llama a la funcion
 * \return devuelve el numero de id generado
 */
static int generarIdNuevo(void)
{
	static int id=0;
	id = id+1;
	return id;
}
/**
 * \brief Realiza el alta de un alumno solo si el indice corresponde a un Empty
 * \param Alumno arrayAlumnos[], Es el puntero al array de alumnos
 * \param int len, es el limite de array
 * \param int indice, es el indice donde se cargara el alumno
 * \return (-1) Error / (0) Ok
 */
int alumno_AltaDeAlumnos(Alumno* array, int len, int indice)
{
	int ret=-1;
	Alumno bufferAlumno;
	if(array!=NULL && len>0 && indice>=0 && indice<=len && array[indice].isEmpty==TRUE)
	{
		if(	!utn_getNombre(bufferAlumno.name,ARRAY_LEN_NAME,
			"Ingrese un nombre: ","ERROR\n",QTY_REINT) &&
			!utn_getApellido(bufferAlumno.lastName,ARRAY_LEN_APELLIDO,
			"Ingrese un apellido: ","ERROR\n",QTY_REINT) &&
			!utn_getNumero(&bufferAlumno.file,"Ingrese un Numero de legajo: ",
			"ERROR\n",ZERO,MAX_FILE,QTY_REINT))
		{
			bufferAlumno.id=generarIdNuevo();
			array[indice].isEmpty=FALSE;
			array[indice]=bufferAlumno;
			ret=0;
		}
	}
	return ret;
}
/**
 * \brief Devuelve el Indice del id pasado por parametro
 * \param Alumno arrayAlumnos[], Es el puntero al array de alumnos
 * \param int len, es el limite de array
 * \param int id, es el id del Alumno que quiero obtener
 * \return (-1) Error / Devuelve el Indice del ID pasado por parametro
 */
int alumnos_buscarIndicexId(Alumno* array, int len, int id)
{
	int ret=-1;
	int i;
	if(array!=NULL && len>0 && id>=0)
	{
		for(i=0;i<len;i++)
		{
			if(array[i].isEmpty==FALSE && array[i].id==id)
			{
				ret=i;
				break;
			}
		}
	}
	return ret;
}
/**
 * \brief Realiza la edicion de un alumno solo si el indice es valido.
 * \param Alumno arrayAlumnos[], Es el puntero al array de alumnos
 * \param int len, es el limite de array
 * \param int indice, es el indice donde se cargara el alumno
 * \return (-1) Error / (0) Ok
 */
int alumno_ModificarAlumnos(Alumno* array, int len, int indice)
{
	int ret=-1;
	Alumno bufferAlumno;
	if(array!=NULL && len>0 && indice>=0 && indice<=len)
	{
		if(	!utn_getNombre(bufferAlumno.name,ARRAY_LEN_NAME,
			"Ingrese un nombre: ","ERROR\n",QTY_REINT) &&
			!utn_getApellido(bufferAlumno.lastName,ARRAY_LEN_APELLIDO,
			"Ingrese un apellido: ","ERROR\n",QTY_REINT) &&
			!utn_getNumero(&bufferAlumno.file,"Ingrese un Numero de legajo: ",
			"ERROR\n",ZERO,MAX_FILE,QTY_REINT))
		{
			bufferAlumno.id = array[indice].id;
			array[indice]=bufferAlumno;
			ret=0;
		}
	}
	return ret;
}
/**
 * \brief Realiza la baja logica de un alumno solo si el indice es valido
 * \param Alumno arrayAlumnos[], Es el puntero al array de alumnos
 * \param int len, es el limite de array
 * \param int indice, es el indice donde se cargara el alumno
 * \return (-1) Error / (0) Ok
 */
int alumno_BajaAlumnos(Alumno* array, int len, int indice)
{
	int ret=-1;
	Alumno bufferAlumno;
	char auxChar;
	if(array!=NULL && len>0 && indice>=0 && indice<=len)
	{
		if(!utn_getCaracterSN(&auxChar,ARRAY_LEN_CHAR,
		   "Esta seguro que desea borrar este Alumno?[S/N]:",
		    "ERROR\n",QTY_REINT))
		{
			switch(auxChar)
			{
			 	 case 'S':
			 		array[indice].isEmpty=TRUE;
					bufferAlumno.id = array[indice].id;
					array[indice]=bufferAlumno;
					ret=0;
			 		break;
			 	 case 'N':
			 		 break;
			 	case 's':
					array[indice].isEmpty=TRUE;
					bufferAlumno.id = array[indice].id;
					array[indice]=bufferAlumno;
					ret=0;
					break;
				 case 'n':
					 break;
			 	 default:
			 		 printf("Dato invalido, solo Ingrese S o N\n");
			 		 break;
			}
		}
	}
	return ret;
}
/**
 * \brief Ordena el array por nombre
 * \param array Alumno
 * \param len Limite del array de clientes
 * \return Retorna el incice de la posicion vacia y -1 (ERROR)
 *
 */
int alumno_ordenarPorNombre(Alumno* array,int len)
{
	int ret = -1;
	int flagSwap;
	int i;
	Alumno buffer;
	if(array!=NULL && len>0)
	{
		do
		{
			flagSwap=0;
			for(i=0;i<len-1;i++)
			{
				if(array[i].isEmpty || array[i+1].isEmpty)
				{
					continue;
				}
				if(strncmp(array[i].name,array[i+1].name,ARRAY_LEN_ALUMNOS) > 0)
				{
					flagSwap = 1;
					buffer = array[i];
					array[i] = array[i+1];
					array[i+1]=buffer;
				}
			}
			len--;
		}while(flagSwap);
	}
	return ret;
}
