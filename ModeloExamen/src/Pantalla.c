#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdio_ext.h>
#include "Pantalla.h"
#include "utn.h"
#include "Contratacion.h"

static int pan_generarNuevoId (void);

/**
 * \brief Genera un nuevo ID cada vez que se da de alta una Pantalla
 * \return Retorna el id que se genero.
 */
static int pan_generarNuevoId (void) {
	static int id = 0;
	id = id+1;
	return id;
}

/**
 * \brief Imprime los datos de un Pantalla
 * \param pPantalla Puntero al producto que se busca imprimir
 * \return Retorna 0 (EXITO) y -1 (ERROR)
 *
 */
int pan_imprimirPantalla(Pantalla* pPantalla)
{
	int retorno=-1;
	char strTipo[8];
	if(pPantalla != NULL && pPantalla->isEmpty == FALSE)
	{
		if(pPantalla->tipo==PANTALLA_TIPO_LCD)
		{
			sprintf(strTipo,"LCD");
		}
		else
		{
			sprintf(strTipo,"LED");
		}
		printf("\nID:%d - Tipo:%s - Nombre:%s - Direccion:%s - Precio:%.2f",
				pPantalla->id,
				strTipo,
				pPantalla->nombre,
				pPantalla->direccion,
				pPantalla->precio);
		retorno=0;
	}
	return retorno;
}

/**
 * \brief Imprime el array de Pantallaes
 * \param array Array de Pantallaes a ser actualizado
 * \param limite Limite del array de Pantallaes
 * \return Retorna 0 (EXITO) y -1 (ERROR)
 *
 */
int pan_imprimirArrayPantalla(Pantalla* array,int limite)
{
	int ret = -1;
	int i;
	if(array != NULL && limite > 0)
	{
		pan_ordenarPantallaID(array,limite);
		for(i=0;i<limite;i++)
		{
			pan_imprimirPantalla(&array[i]);
		}
		ret = 0;
	}
	return ret;
}

/**
 * \brief Inicializa el array
 * \param array Array de Pantalla a ser actualizado
 * \param limite Limite del array de Pantalla
 * \return Retorna 0 (EXITO) y -1 (ERROR)
 */
int pan_inicializarArrayPantalla(Pantalla* array,int limite)
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
 * \brief Da de alta un Pantalla en una posicion del array
 * \param array Array de Pantalla a ser actualizado
 * \param limite Limite del array de Pantalla
 * \return Retorna 0 (EXITO) y -1 (ERROR)
 */
int pan_altaArrayPantalla(Pantalla* array,int limite)
{
	int ret = -1;
	Pantalla bufferPantalla;
	int auxIndice;
	if(array != NULL && limite > 0)
	{
		auxIndice = pan_getEmptyIndexPantalla(array,limite);
		if(auxIndice>=0)
		{
			if( !utn_getNumero(&bufferPantalla.tipo,"Ingrese el tipo de pantalla [1-LCD/2-LED]: ","ERROR",MIN_TIPO,MAX_TIPO,QTY_REINT) &&
				!utn_getNombre(bufferPantalla.nombre,LENGTH_NOMBRE,"Ingrese el Nombre de la pantalla: ","ERROR, nombre invalido.\n",QTY_REINT) &&
				!utn_getTexto(bufferPantalla.direccion, LENGTH_DIRECCION,"Ingrese la direccion: ", "ERROR", QTY_REINT) &&
				!utn_getNumeroFlotante(&bufferPantalla.precio, "Ingrese el precio: ", "ERROR",MIN_PRECIO,MAX_PRECIO,QTY_REINT))
			{
				bufferPantalla.id = pan_generarNuevoId();
				bufferPantalla.isEmpty = FALSE;
				array[auxIndice] = bufferPantalla;
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
 * \brief Actualiza los datos de un Pantalla en una posicion del array
 * \param array Array de Pantalla a ser actualizado
 * \param limite Limite del array de Pantalla
 * \return Retorna 0 (EXITO) y -1 (ERROR)
 */
int pan_modificarArrayPantalla(Pantalla* array,int limite, int indice)
{
	int ret = -1;
	Pantalla bufferPantalla;
	if(array != NULL && limite > 0)
	{
		if(	!utn_getNumero(&bufferPantalla.tipo,"Ingrese nuevo tipo de pantalla [1-LED/2-LCD]: ","ERROR",MIN_TIPO,MAX_TIPO,QTY_REINT) &&
			!utn_getNombre(bufferPantalla.nombre,LENGTH_NOMBRE,"Ingrese nuevo Nombre de la pantalla: ","ERROR, nombre invalido.\n",QTY_REINT) &&
			!utn_getTexto(bufferPantalla.direccion, LENGTH_DIRECCION,"Ingrese nueva direccion: ", "ERROR", QTY_REINT) &&
			!utn_getNumeroFlotante(&bufferPantalla.precio, "Ingrese nuevo precio: ", "ERROR",MIN_PRECIO,MAX_PRECIO,QTY_REINT))
		{
			bufferPantalla.id = array[indice].id;
			bufferPantalla.isEmpty = 0;
			array[indice] = bufferPantalla;
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
 * \brief Actualiza una posicion del array
 * \param array Array de Pantalla a ser actualizado
 * \param limite Limite del array de Pantalla
 * \return Retorna 0 (EXITO) y -1 (ERROR)
 */
int pan_bajaArrayPantalla(Pantalla* array,int limite,int indice)
{
	int ret = -1;
	char auxChar;
	if(array != NULL && limite > 0)
	{
		if(!utn_getCaracterSN(&auxChar,ARRAY_LEN_CHAR,
							  "Esta seguro que desea borrar esta Pantalla?[S/N]:",
							  "ERROR\n",QTY_REINT))
		{
			switch(auxChar)
			{
				 case 'S':
				 case 's':
					 array[indice].isEmpty = TRUE;
					 ret = 0;
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
* \brief Busca un ID en un array y devuelve la posicion en que se encuentra
* \param array Pantalla Array de Pantalla
* \param limite int Tamaño del array
* \param posicion int* Puntero a la posicion del array donde se encuentra el valor buscado
* \return int Return (-1) si no encuentra el valor buscado o Error [Invalid length or NULL pointer] - (0) si encuentra el valor buscado
*/
int pan_buscarIdPantalla(Pantalla* array, int limite, int valorBuscado)
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
 * \param array Array de Pantalla
 * \param limite Limite del array de Pantalla
 * \return Retorna el incice de la posicion vacia y -1 (ERROR)
 */
int pan_getEmptyIndexPantalla(Pantalla* array,int limite)
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
 * \brief Ordenar el array de Pantalla por ID ascendente
 * \param array Array de Pantalla
 * \param limite Limite del array de Pantalla
 * \return Retorna el incice de la posicion vacia y -1 (ERROR)
 */
int pan_ordenarPantallaID(Pantalla* array,int limite)
{
	int ret = -1;
	int flagSwap;
	int i;
	Pantalla buffer;
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
 * \brief Ordenar el array de Pantalla por un doble criterio ascendente o descendente
 * \param array Array de Pantalla
 * \param len int Limite del array de Pantalla
 * \param orden int [1]-Indica ascendente - [0]-Indica Descendente
 * \return Retorna el incice de la posicion vacia y -1 (ERROR)
 */
int pan_ordenarPantallaDobleCriterio(Pantalla* list, int len, int order)
{
	int ret=-1;
	int flagSwap;
	int i;
	Pantalla buffer;
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
				    (list[i].tipo > list[i+1].tipo)) ||
				    (order==0 && strncmp(list[i].nombre,list[i+1].nombre,ARRAY_LEN_NOMBRE) < 0) ||
				    ((order==0 && strncmp(list[i].nombre,list[i+1].nombre,ARRAY_LEN_NOMBRE) == 0) &&
				    (list[i].tipo < list[i+1].tipo)))
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
 * \brief Chequea que la lista de Pantallas este cargada
 * \param array Array de Pantallas a ser actualizado
 * \param int len longitud del array de Pantallas
 * \return Retorna 0, si la lista esta con al menos 1 empleado y -1 si la lista esta vacia.
 */
int pan_checkListaVacia(Pantalla* list, int len)
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
 * \brief Da de alta una Pantalla en una posicion del array
 * \param array Array de Pantalla a ser actualizado
 * \param limite Limite del array de Pantalla
 * \param indice Posicion a ser actualizada
 * \param id Identificador a ser asignado a la Pantalla
 * \return Retorna 0 (EXITO) y -1 (ERROR)
 */
int pan_mocksPantalla(Pantalla* array,int limite, int indice, int id,int tipo, char* nombre,char* direccion, float precio)
{
	int ret = -1;
	Pantalla bufferPantalla;
	if(array != NULL && limite > 0 && indice < limite && indice >= 0)
	{
		    bufferPantalla.id = pan_generarNuevoId();
		    bufferPantalla.tipo = tipo;
		    strncpy(bufferPantalla.nombre,nombre,LENGTH_NOMBRE);
			strncpy(bufferPantalla.direccion,direccion,LENGTH_DIRECCION);
			bufferPantalla.precio = precio;
			bufferPantalla.isEmpty = FALSE;
			array[indice] = bufferPantalla;
			ret = 0;
	}
	return ret;
}


















