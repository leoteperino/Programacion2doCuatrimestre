#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdio_ext.h>
#include "Fantasma.h"
#include "utn.h"

static int entidad_generarNuevoId (void);

/**
 * \brief Genera un nuevo ID cada vez que se da de alta una Entidad
 * \return Retorna el id que se genero.
 */
static int entidad_generarNuevoId (void) {
	static int id = 0;
	id = id+1;
	return id;
}

/**
 * \brief Imprime los datos de un Entidad
 * \param pEntidad Puntero al producto que se busca imprimir
 * \return Retorna 0 (EXITO) y -1 (ERROR)
 *
 */
int entidad_imprimirEntidad(Entidad* pEntidad)
{
	int retorno=-1;
	if(pEntidad != NULL && pEntidad->isEmpty == FALSE)
	{
		retorno=0;
		printf("\nID: %d - Nombre: %s - Apellido: %s - Cuit: %s - Precio:%.2f - Sector:%d - isEmpty:%d",
				pEntidad->id,
				pEntidad->nombre,
				pEntidad->apellido,
				pEntidad->cuit,
				pEntidad->precio,
				pEntidad->sector,
				pEntidad->isEmpty);
	}
	return retorno;
}

/**
 * \brief Imprime el array de Entidades
 * \param array Array de Entidades a ser actualizado
 * \param limite Limite del array de Entidades
 * \return Retorna 0 (EXITO) y -1 (ERROR)
 *
 */
int entidad_imprimirArrayEntidad(Entidad* array,int limite)
{
	int ret = -1;
	int i;
	if(array != NULL && limite > 0)
	{
		entidad_ordenarEntidadID(array,limite);
		for(i=0;i<limite;i++)
		{
			entidad_imprimirEntidad(&array[i]);
		}
		ret = 0;
	}
	return ret;
}

/**
 * \brief Inicializa el array
 * \param array Array de Entidad a ser actualizado
 * \param limite Limite del array de Entidad
 * \return Retorna 0 (EXITO) y -1 (ERROR)
 */
int entidad_inicializarArrayEntidad(Entidad* array,int limite)
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
 * \brief Da de alta un Entidad en una posicion del array
 * \param array Array de Entidad a ser actualizado
 * \param limite Limite del array de Entidad
 * \return Retorna 0 (EXITO) y -1 (ERROR)
 */
int entidad_altaArrayEntidad(Entidad* array,int limite)
{
	int ret = -1;
	Entidad bufferEntidad;
	int auxIndice;
	if(array != NULL && limite > 0)
	{
		auxIndice = entidad_getEmptyIndexEntidad(array,limite);
		if(auxIndice>=0)
		{
			if( !utn_getNombre(bufferEntidad.nombre,LENGTH_NOMBRE,"Ingrese su Nombre: ","ERROR, nombre invalido.\n",QTY_REINT) &&
				!utn_getApellido(bufferEntidad.apellido,LENGTH_APELLIDO,"Ingrese su apellido: ","ERROR, apellido invalido.\n",QTY_REINT) &&
				!utn_getCuit(bufferEntidad.cuit,LENGTH_CUIT,"Ingrese su Cuit [xx-xxxxxxxx-x]: ", "ERROR, cuit invalido.\n",QTY_REINT) &&
				!utn_getNumeroFlotante(&bufferEntidad.precio, "Ingrese el precio: ", "ERROR",0,999,QTY_REINT) &&
				!utn_getNumero(&bufferEntidad.sector,"Ingrese el sector: ","ERROR",1,99,QTY_REINT))
			{
				bufferEntidad.id = entidad_generarNuevoId();
				bufferEntidad.isEmpty = FALSE;
				array[auxIndice] = bufferEntidad;
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
 * \brief Actualiza los datos de un Entidad en una posicion del array
 * \param array Array de Entidad a ser actualizado
 * \param limite Limite del array de Entidad
 * \return Retorna 0 (EXITO) y -1 (ERROR)
 */
int entidad_modificarArrayEntidad(Entidad* array,int limite)
{
	int ret = -1;
	Entidad bufferEntidad;
	int auxIndice;
	int auxID;
	if(array != NULL && limite > 0)
	{
		entidad_imprimirArrayEntidad(array, limite);
		utn_getNumero(&auxID,"\nIngresa el ID de la pantalla a modificar: ","ERROR",0,999,QTY_REINT);
		auxIndice = entidad_buscarIdEntidad(array, limite, auxID);
		if(auxIndice>=0)
		{
			if(	!utn_getNombre(bufferEntidad.nombre,LENGTH_NOMBRE,"Ingrese nuevo Nombre: ","ERROR, nombre invalido.\n",QTY_REINT) &&
				!utn_getApellido(bufferEntidad.apellido,LENGTH_APELLIDO,"Ingrese nuevo apellido: ","ERROR, apellido invalido.\n",QTY_REINT) &&
				!utn_getCuit(bufferEntidad.cuit,LENGTH_CUIT,"Ingrese nuevo Cuit [xx-xxxxxxxx-x]: ", "ERROR, cuit invalido.\n",QTY_REINT) &&
				!utn_getNumeroFlotante(&bufferEntidad.precio,"Ingrese el nuevo precio: ","ERROR",0,999,QTY_REINT) &&
				!utn_getNumero(&bufferEntidad.sector,"Ingrese nuevo sector: ","ERROR",0,99,QTY_REINT))
			{
				bufferEntidad.id = array[auxIndice].id;
				bufferEntidad.isEmpty = 0;
				array[auxIndice] = bufferEntidad;
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
 * \param array Array de Entidad a ser actualizado
 * \param limite Limite del array de Entidad
 * \return Retorna 0 (EXITO) y -1 (ERROR)
 */
int entidad_bajaArrayEntidad(Entidad* array,int limite)
{
	int ret = -1;
	int auxIndice;
	int auxID;
	if(array != NULL && limite > 0)
	{
		entidad_imprimirArrayEntidad(array, limite);
		utn_getNumero(&auxID,"\nIngresa el ID de la pantalla a borrar: ","ERROR",0,999,QTY_REINT);
		auxIndice = entidad_buscarIdEntidad(array, limite, auxID);
		if(auxIndice>=0)
		{
			array[auxIndice].isEmpty = TRUE;
			ret = 0;
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
* \param array Entidad Array de Entidad
* \param limite int Tamaño del array
* \param posicion int* Puntero a la posicion del array donde se encuentra el valor buscado
* \return int Return (-1) si no encuentra el valor buscado o Error [Invalid length or NULL pointer] - (0) si encuentra el valor buscado
*/
int entidad_buscarIdEntidad(Entidad* array, int limite, int valorBuscado)
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
 * \param array Array de Entidad
 * \param limite Limite del array de Entidad
 * \return Retorna el incice de la posicion vacia y -1 (ERROR)
 */
int entidad_getEmptyIndexEntidad(Entidad* array,int limite)
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
 * \brief Ordenar el array de Entidad por ID ascendente
 * \param array Array de Entidad
 * \param limite Limite del array de Entidad
 * \return Retorna el incice de la posicion vacia y -1 (ERROR)
 */
int entidad_ordenarEntidadID(Entidad* array,int limite)
{
	int ret = -1;
	int flagSwap;
	int i;
	Entidad buffer;
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
 * \brief Ordenar el array de Entidad por un doble criterio ascendente o descendente
 * \param array Array de Entidad
 * \param len int Limite del array de Entidad
 * \param orden int [1]-Indica ascendente - [0]-Indica Descendente
 * \return Retorna el incice de la posicion vacia y -1 (ERROR)
 */
int entidad_ordenarEntidadDobleCriterio(Entidad* list, int len, int order)
{
	int ret=-1;
	int flagSwap;
	int i;
	Entidad buffer;
	if(list!=NULL && len>0)
	{
		do
		{
			flagSwap = 0;
			for(i=0;i<len-1;i++)
			{
				if(
					(order==1 && strncmp(list[i].nombre,list[i+1].nombre,ARRAY_LEN_NOMBRE)>0) ||
				    ((order==1 && strncmp(list[i].nombre,list[i+1].nombre,ARRAY_LEN_NOMBRE)==0) &&
				    (list[i].sector > list[i+1].sector)) ||
				    (order==0 && strncmp(list[i].nombre,list[i+1].nombre,ARRAY_LEN_NOMBRE) < 0) ||
				    ((order==0 && strncmp(list[i].nombre,list[i+1].nombre,ARRAY_LEN_NOMBRE) == 0) &&
				    (list[i].sector < list[i+1].sector)))
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
 * \brief Da de alta una Entidad en una posicion del array
 * \param array Array de Entidad a ser actualizado
 * \param limite Limite del array de Entidad
 * \param indice Posicion a ser actualizada
 * \param id Identificador a ser asignado a la Entidad
 * \return Retorna 0 (EXITO) y -1 (ERROR)
 */
int entidad_mocksEntidad(Entidad* array,int limite, int indice, int id,char* nombre,char* apellido, char* cuit, float precio, int sector)
{
	int ret = -1;
	Entidad bufferEntidad;
	if(array != NULL && limite > 0 && indice < limite && indice >= 0)
	{
		    bufferEntidad.id = entidad_generarNuevoId();
			strncpy(bufferEntidad.nombre,nombre,LENGTH_NOMBRE);
			strncpy(bufferEntidad.apellido,apellido,LENGTH_APELLIDO);
			strncpy(bufferEntidad.cuit,cuit,LENGTH_CUIT);
			bufferEntidad.precio = precio;
			bufferEntidad.sector = sector;
			bufferEntidad.isEmpty = 0;
			array[indice] = bufferEntidad;
			ret = 0;
	}
	return ret;
}


















