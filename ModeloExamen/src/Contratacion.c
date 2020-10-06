#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdio_ext.h>
#include "Contratacion.h"
#include "utn.h"
#include "Pantalla.h"

static int cont_generarNuevoId (void);

/**
 * \brief Genera un nuevo ID cada vez que se da de alta una Contratacion
 * \return Retorna el id que se genero.
 */
static int cont_generarNuevoId (void) {
	static int id = 0;
	id = id+1;
	return id;
}

/**
 * \brief Imprime los datos de un Contratacion
 * \param pContratacion Puntero al producto que se busca imprimir
 * \return Retorna 0 (EXITO) y -1 (ERROR)
 *
 */
int cont_imprimirContratacion(Contratacion* pContratacion)
{
	int retorno=-1;
	if(pContratacion != NULL && pContratacion->isEmpty == FALSE)
	{
		retorno=0;
		printf("\nID:%d - Cuit cliente:%s - Dias:%d - Nombre archivo:%s - IdPantalla:%d",
				pContratacion->id,
				pContratacion->cuitCliente,
				pContratacion->dias,
				pContratacion->nombreArchivo,
				pContratacion->idPantalla);
	}
	return retorno;
}

/**
 * \brief Imprime el array de Contrataciones
 * \param array Array de Contrataciones a ser actualizado
 * \param limite Limite del array de Contrataciones
 * \return Retorna 0 (EXITO) y -1 (ERROR)
 *
 */
int cont_imprimirArrayContratacion(Contratacion* array,int limite)
{
	int ret = -1;
	int i;
	if(array != NULL && limite > 0)
	{
		cont_ordenarContratacionID(array,limite);
		for(i=0;i<limite;i++)
		{
			cont_imprimirContratacion(&array[i]);
		}
		ret = 0;
	}
	return ret;
}

/**
 * \brief Inicializa el array
 * \param array Array de Contratacion a ser actualizado
 * \param limite Limite del array de Contratacion
 * \return Retorna 0 (EXITO) y -1 (ERROR)
 */
int cont_inicializarArrayContratacion(Contratacion* array,int limite)
{
	int ret = -1;
	int i;
	if(array != NULL && limite > 0)
	{
		for(i=0;i<limite;i++)
		{
			array[i].isEmpty = TRUE;
		}
		ret = 0;
	}
	return ret;
}

/**
 * \brief Da de alta un Contratacion en una posicion del array
 * \param array Array de Contratacion a ser actualizado
 * \param limite Limite del array de Contratacion
 * \return Retorna 0 (EXITO) y -1 (ERROR)
 */
int cont_altaArrayContratacion(Contratacion* array,int limite)
{
	int ret = -1;
	Contratacion bufferContratacion;
	int auxIndice;
	if(array != NULL && limite > 0)
	{
		auxIndice = cont_getEmptyIndexContratacion(array,limite);
		if(auxIndice>=0)
		{
			if( !utn_getCuit(bufferContratacion.cuitCliente,LENGTH_CUIT,"Ingrese Cuit del Cliente [xx-xxxxxxxx-x]: ", "ERROR, cuit invalido.\n",QTY_REINT) &&
				!utn_getNumero(&bufferContratacion.dias,"Ingrese cantidad de dias a contratar: ","ERROR",MIN_DIAS,MAX_DIAS,QTY_REINT) &&
				!utn_getTexto(bufferContratacion.nombreArchivo, LENGTH_ARCHIVO, "Ingrese el nombre del archivo: ", "ERROR", QTY_REINT) &&
				!utn_getNumero(&bufferContratacion.idPantalla,"Ingrese el ID de la pantalla a contratar: ","ERROR",MIN_ID,MAX_ID,QTY_REINT))
			{
				bufferContratacion.id = cont_generarNuevoId();
				bufferContratacion.isEmpty = FALSE;
				array[auxIndice] = bufferContratacion;
				ret = 0;
			}
			else
			{
				printf("No hay lugares vacios en el Array.\n");
			}
		}
	}
	return ret;
}

/**
 * \brief Actualiza los datos de un Contratacion en una posicion del array
 * \param array Array de Contratacion a ser actualizado
 * \param limite Limite del array de Contratacion
 * \return Retorna 0 (EXITO) y -1 (ERROR)
 */
int cont_modificarArrayContratacion(Contratacion* array,int limite)
{
	int ret = -1;
	Contratacion bufferContratacion;
	int auxIndice;
	int auxID;
	if(array != NULL && limite > 0)
	{
		cont_imprimirArrayContratacion(array, limite);
		utn_getNumero(&auxID,"\nIngresa el ID de la pantalla a modificar: ","ERROR",0,999,QTY_REINT);
		auxIndice = cont_buscarIdContratacion(array, limite, auxID);
		if(auxIndice>=0)
		{
			if(	!utn_getCuit(bufferContratacion.cuitCliente,LENGTH_CUIT,"Ingrese nuevo Cuit del Cliente [xx-xxxxxxxx-x]: ", "ERROR, cuit invalido.\n",QTY_REINT) &&
				!utn_getNumero(&bufferContratacion.dias,"Ingrese nueva cantidad de dias a contratar: ","ERROR",MIN_DIAS,MAX_DIAS,QTY_REINT) &&
				!utn_getTexto(bufferContratacion.nombreArchivo, LENGTH_ARCHIVO, "Ingrese nuevo nombre del archivo: ", "ERROR", QTY_REINT) &&
				!utn_getNumero(&bufferContratacion.idPantalla,"Ingrese el ID de la nueva pantalla a contratar: ","ERROR",MIN_ID,MAX_ID,QTY_REINT))
			{
				bufferContratacion.id = array[auxIndice].id;
				bufferContratacion.isEmpty = 0;
				array[auxIndice] = bufferContratacion;
				ret = 0;
			}
		}
		else
		{
			printf("No se encontro el ID ingresado.\n");
		}
	}
	return ret;
}

/**
 * \brief Actualiza una posicion del array
 * \param array Array de Contratacion a ser actualizado
 * \param limite Limite del array de Contratacion
 * \return Retorna 0 (EXITO) y -1 (ERROR)
 */
int cont_bajaArrayContratacion(Contratacion* array,int limite)
{
	int ret = -1;
	int auxIndice;
	int auxID;
	char auxChar;
	if(array != NULL && limite > 0)
	{
		cont_imprimirArrayContratacion(array, limite);
		utn_getNumero(&auxID,"\nIngresa el ID de la contratacion a borrar: ","ERROR",MIN_ID,MAX_ID,QTY_REINT);
		auxIndice = cont_buscarIdContratacion(array, limite, auxID);
		if(auxIndice>=0)
		{

			if(!utn_getCaracterSN(&auxChar,ARRAY_LEN_CHAR,
								  "Esta seguro que desea borrar esta Contratacion?[S/N]:",
								  "ERROR\n",QTY_REINT))
			{
				switch(auxChar)
				{
					 case 'S':
					 case 's':
						 array[auxIndice].isEmpty = TRUE;
						 ret = 0;
						break;
					 case 'N':
					 case 'n':
						 break;
				}
			}
		}
		else
		{
			printf("No se encontro el ID ingresado.\n");
		}
	}
	return ret;
}

/**
* \brief Busca un ID en un array y devuelve la posicion en que se encuentra
* \param array Contratacion Array de Contratacion
* \param limite int Tamaño del array
* \param posicion int* Puntero a la posicion del array donde se encuentra el valor buscado
* \return int Return (-1) si no encuentra el valor buscado o Error [Invalid length or NULL pointer] - (0) si encuentra el valor buscado
*/
int cont_buscarIdContratacion(Contratacion* array, int limite, int valorBuscado)
{
	int ret = -1;
	int i;
	if(array != NULL && limite > 0 && valorBuscado >= 0)
	{
		for(i=0;i<limite;i++)
		{
			if(array[i].isEmpty==FALSE && array[i].id == valorBuscado)
			{
				ret = i;
				break;
			}
		}
	}
	return ret;
}

/**
 * \brief Buscar primer posicion vacia
 * \param array Array de Contratacion
 * \param limite Limite del array de Contratacion
 * \return Retorna el incice de la posicion vacia y -1 (ERROR)
 */
int cont_getEmptyIndexContratacion(Contratacion* array,int limite)
{
	int ret = -1;
	int i;
	if(array != NULL && limite > 0)
	{
		for(i=0;i<limite;i++)
		{
			if(array[i].isEmpty == TRUE)
			{
				ret = i;
				break;
			}
		}
	}
	return ret;
}

/**
 * \brief Ordenar el array de Contratacion por ID ascendente
 * \param array Array de Contratacion
 * \param limite Limite del array de Contratacion
 * \return Retorna el incice de la posicion vacia y -1 (ERROR)
 */
int cont_ordenarContratacionID(Contratacion* array,int limite)
{
	int ret = -1;
	int flagSwap;
	int i;
	Contratacion buffer;
	if(array != NULL && limite > 0)
	{
		do
		{
			flagSwap = 0;
			for(i=0;i<limite-1;i++)
			{
				if(array[i].isEmpty || array[i+1].isEmpty)
				{
					continue;
				}
				if(array[i].id > array[i+1].id)
				{
					flagSwap = 1;
					buffer = array[i];
					array[i] = array[i+1];
					array[i+1]=buffer;
				}
			}
			limite--;
		}while(flagSwap);
	}
	return ret;
}

/**
 * \brief Ordenar el array de Contratacion por un doble criterio ascendente o descendente
 * \param array Array de Contratacion
 * \param len int Limite del array de Contratacion
 * \param orden int [1]-Indica ascendente - [0]-Indica Descendente
 * \return Retorna el incice de la posicion vacia y -1 (ERROR)
 */
int cont_ordenarContratacionDobleCriterio(Contratacion* list, int len, int order)
{
	int ret=-1;
	int flagSwap;
	int i;
	Contratacion buffer;
	if(list!=NULL && len>0)
	{
		do
		{
			flagSwap = 0;
			for(i=0;i<len-1;i++)
			{
				if(
					(order==1 && strncmp(list[i].nombreArchivo,list[i+1].nombreArchivo,ARRAY_LEN_NOMBRE)>0) ||
				    ((order==1 && strncmp(list[i].nombreArchivo,list[i+1].nombreArchivo,ARRAY_LEN_NOMBRE)==0) &&
				    (list[i].dias > list[i+1].dias)) ||
				    (order==0 && strncmp(list[i].nombreArchivo,list[i+1].nombreArchivo,ARRAY_LEN_NOMBRE) < 0) ||
				    ((order==0 && strncmp(list[i].nombreArchivo,list[i+1].nombreArchivo,ARRAY_LEN_NOMBRE) == 0) &&
				    (list[i].dias < list[i+1].dias)))
				{
					flagSwap = 1;
					buffer = list[i];
					list[i] = list[i+1];
					list[i+1]=buffer;
				}
			}
			len--;
		}while(flagSwap);
	}
	return ret;
}

/**
 * \brief Chequea que la lista de Contrataciones este cargada
 * \param array Array de contrataciones a ser actualizado
 * \param int len longitud del array de contrataciones
 * \return Retorna 0, si la lista esta con al menos 1 empleado y -1 si la lista esta vacia.
 */
int cont_checkListaVacia(Contratacion* list, int len)
{
	int ret=-1;
	int contador = 0;
	int i;
	if(list!=NULL && len>0)
	{
		for(i=0;i<len;i++)
		{
			if(list[i].isEmpty==FALSE)
			{
				contador++;
			}
		}
		if(contador>0)
		{
			ret=0;
		}
	}
	return ret;
}

/**
 * \brief Da de alta una Contratacion en una posicion del array
 * \param array Array de Contratacion a ser actualizado
 * \param limite Limite del array de Contratacion
 * \param indice Posicion a ser actualizada
 * \param id Identificador a ser asignado a la Contratacion
 * \return Retorna 0 (EXITO) y -1 (ERROR)
 */
int cont_mocksContratacion(Contratacion* array,int limite, int indice, int id,char* cuitCliente,int dias, char* nombreArchivo, int idPantalla)
{
	int ret = -1;
	Contratacion bufferContratacion;
	if(array != NULL && limite > 0 && indice < limite && indice >= 0)
	{
		    bufferContratacion.id = cont_generarNuevoId();
		    strncpy(bufferContratacion.cuitCliente,cuitCliente,LENGTH_CUIT);
		    bufferContratacion.dias = dias;
		    strncpy(bufferContratacion.nombreArchivo,nombreArchivo,LENGTH_ARCHIVO);
			bufferContratacion.idPantalla = idPantalla;
			bufferContratacion.isEmpty = FALSE;
			array[indice] = bufferContratacion;
			ret = 0;
	}
	return ret;
}


















