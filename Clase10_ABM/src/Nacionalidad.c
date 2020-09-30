/*
 * Nacionalidad.c
 *
 *  Created on: Sep 29, 2020
 *      Author: leandro
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdio_ext.h>
#include <string.h>
#include "utn.h"
#include "Alumno.h"
#include "Nacionalidad.h"

static int generarIdNuevo(void);

/**
 * \brief Inicializa el array
 * \param Array a ser actualizado
 * \param int Limite del array
 * \return Retorna 0 (EXITO) y -1 (ERROR)
 */
int nac_inicializarArray(Nacionalidad* array, int len)
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
 * \brief Imprime los Nacionalidads cargados
 * \param Nacionalidad arrayNacionalidads[], Es el puntero al array de Nacionalidads
 * \param int limite, es el limite de array
 * \return (-1) Error / (0) Ok
 */
int nac_mostrarLista(Nacionalidad* array, int len)
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
				printf("ID:%d - Nacionalidad:%s - Estado:%d\n",
						array[i].id,
						array[i].name,
						array[i].isEmpty);
			}
		}
	}
	return ret;
}
/**
 * \brief Busca el primer lugar vacio de la lista de Nacionalidads
 * \param Nacionalidad arrayNacionalidads[], Es el puntero al array de Nacionalidads
 * \param int limite, es el limite de array
 * \return devuelve el indice del lugar vacio de la lista o -1 en caso de no encontrar lugar vacio
 */
int nac_buscarVacio(Nacionalidad* array, int len)
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
 * \brief Realiza el alta de un Nacionalidad solo si el indice corresponde a un Empty
 * \param Nacionalidad arrayNacionalidads[], Es el puntero al array de Nacionalidads
 * \param int len, es el limite de array
 * \param int indice, es el indice donde se cargara el Nacionalidad
 * \return (-1) Error / (0) Ok
 */
int nac_AltaDeNacionalidad(Nacionalidad* array, int len, int indice)
{
	int ret=-1;
	Nacionalidad bufferNacionalidad;
	if(array!=NULL && len>0 && indice>=0 && indice<=len && array[indice].isEmpty==TRUE)
	{
		if(	!utn_getNombre(bufferNacionalidad.name,ARRAY_LEN_NAME,
			"Ingrese su Nacionalidad: ","ERROR\n",QTY_REINT))
		{
			bufferNacionalidad.id=generarIdNuevo();
			array[indice].isEmpty=FALSE;
			array[indice]=bufferNacionalidad;
			ret=0;
		}
	}
	return ret;
}
/**
 * \brief Devuelve el Indice del id pasado por parametro
 * \param Nacionalidad arrayNacionalidads[], Es el puntero al array de Nacionalidads
 * \param int len, es el limite de array
 * \param int id, es el id del Nacionalidad que quiero obtener
 * \return (-1) Error / Devuelve el Indice del ID pasado por parametro
 */
int nac_buscarIndicexId(Nacionalidad* array, int len, int id)
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
 * \brief Realiza la edicion de un Nacionalidad solo si el indice es valido.
 * \param Nacionalidad arrayNacionalidads[], Es el puntero al array de Nacionalidads
 * \param int len, es el limite de array
 * \param int indice, es el indice donde se cargara el Nacionalidad
 * \return (-1) Error / (0) Ok
 */
int nac_ModificarNacionalidad(Nacionalidad* array, int len, int indice)
{
	int ret=-1;
	Nacionalidad bufferNacionalidad;
	if(array!=NULL && len>0 && indice>=0 && indice<=len)
	{
		if(	!utn_getNombre(bufferNacionalidad.name,ARRAY_LEN_NAME,
			"Ingrese una Nacionalidad: ","ERROR\n",QTY_REINT))
		{
			bufferNacionalidad.id = array[indice].id;
			array[indice]=bufferNacionalidad;
			ret=0;
		}
	}
	return ret;
}
/**
 * \brief Realiza la baja logica de un Nacionalidad solo si el indice es valido
 * \param Nacionalidad arrayNacionalidads[], Es el puntero al array de Nacionalidads
 * \param int len, es el limite de array
 * \param int indice, es el indice donde se cargara el Nacionalidad
 * \return (-1) Error / (0) Ok
 */
int nac_BajaNacionalidad(Nacionalidad* array, int len, int indice)
{
	int ret=-1;
	Nacionalidad bufferNacionalidad;
	char auxChar;
	if(array!=NULL && len>0 && indice>=0 && indice<=len)
	{
		if(!utn_getCaracterSN(&auxChar,ARRAY_LEN_CHAR,
		   "Esta seguro que desea borrar este Nacionalidad?[S/N]:",
		    "ERROR\n",QTY_REINT))
		{
			switch(auxChar)
			{
			 	 case 'S':
			 	 case 's':
			 		array[indice].isEmpty=TRUE;
					bufferNacionalidad.id = array[indice].id;
					array[indice]=bufferNacionalidad;
					ret=0;
			 		break;
			 	 case 'N':
			 	 case 'n':
			 		 break;
			}
		}
	}
	return ret;
}
/**
 * \brief Ordena el array por nombre
 * \param array Nacionalidad
 * \param len Limite del array de clientes
 * \return Retorna el incice de la posicion vacia y -1 (ERROR)
 *
 */
int nac_ordenarPorNombre(Nacionalidad* array,int len)
{
	int ret = -1;
	int flagSwap;
	int i;
	Nacionalidad buffer;
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
				if(strncmp(array[i].name,array[i+1].name,ARRAY_LEN_NOMBRE) > 0)
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
