/*
 * nac.c
 *
 *  Created on: Sep 22, 2020
 *      Author: ezemanzano
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdio_ext.h>
#include <string.h>
#include "utn.h"
#include "Pantalla.h"

static int pantalla_generarNuevoId (void);

int pantalla_init(Pantalla* pArray, int limite){
	int retorno = -1;
	if (pArray != NULL && limite >0){
		for (int i = 0; i<limite; i++ )
		{
			pArray[i].isEmpty = TRUE;
		}
		retorno = 0;
	}

	return retorno;
}


int pantalla_alta (Pantalla* pArray, int limite)
{
	int retorno = -1;
	int indice;

	Pantalla bufferPantalla;
	if (pArray != NULL && limite >0)
	{
		if (pantalla_buscarLibreRef (pArray, limite, &indice)==0)
		{
			if (!utn_getNombre(bufferPantalla.nombre,LEN_NOMBRE,"\nNombre: ","ERROR",2) &&
				!utn_getNumero(&bufferPantalla.tipo,"\nTipo: ","ERROR",0,2,2) &&
				!utn_getNumeroFlotante(&bufferPantalla.precio,"\nPrecio: ","ERROR",0,999,2) &&
				!utn_getTexto(bufferPantalla.direccion,LEN_DIRECCION,"\nDireccion: ","ERROR",2))
			{
					pArray[indice] = bufferPantalla;
					pArray[indice].id = pantalla_generarNuevoId();
					pArray[indice].isEmpty = FALSE;
			}
		}
		else
		{
				printf(" \n No quedan espacios libres");
		}
	}
	return retorno ;
}


int pantalla_imprimir (Pantalla* pArray , int limite) {
	int retorno = -1;
	if (pArray != NULL && limite >0){
		for (int i=0 ; i<limite ; i++)
		{
			if(pArray[i].isEmpty == FALSE)
			{
				printf("ID:%d - Nombre:%s - Tipo:%d - Precio:%.2f - Direccion:%s\n",
						pArray[i].id,
						pArray[i].nombre,
						pArray[i].tipo,
						pArray[i].precio,
						pArray[i].direccion);
			}
		}
		retorno = 0;
	}
return retorno;
}

int pantalla_baja (Pantalla* pArray, int limite){
	int retorno = -1;
	int idABorrar;
	int indiceABorrar;

	if (pArray != NULL && limite>0)
	{
		pantalla_imprimir(pArray, limite);
		if(utn_getNumero(&idABorrar,"Ingrese pais de nac a borrar","Error",0,9999,3)==0)
		{
			// busco la posicion a borrar
			if(pantalla_buscarIndicePorId(pArray,limite,idABorrar,&indiceABorrar)==0)
			{
				// borro esa posicion
				pArray[indiceABorrar].isEmpty=TRUE;
			}
		}
	}
	return retorno;
}

// ver de no perder el ID y usar las nuevas FN
int pantalla_modificar (Pantalla* pArray, int limite)
{
	int retorno = -1;
	int idBuscar;
	int indiceAModificar;
	Pantalla bufferPantalla;

	if (pArray != NULL && limite>0)
	{
		pantalla_imprimir(pArray, limite);

		if(utn_getnumero(&idBuscar,"ID:","ERROR!",0,9999,2)==0)
		{
			if(pantalla_buscarIndicePorId(pArray, limite,idBuscar,&indiceAModificar)==0)
			{
				bufferPantalla = pArray[indiceAModificar]; // IMPORTANTE!

				if (utn_getNombre(bufferPantalla.pais, LEN_NOMBRE ,"\n Nuevo pais?", "error",2) == 0)
				{
					if (utn_getNombre(bufferPantalla.nombre, LEN_NOMBRE, " \n Ingrese nuevo nombre","ERROR",3) == 0)
					{
						pArray[indiceAModificar] = bufferPantalla; // COPIAMOS AL ARRAY
						retorno = 0;
					}
				}
			}
		}
	}

	return retorno;
}

int pantalla_buscarLibre (Pantalla* pArray, int limite){
	int retorno = -1;
	int i ;
		if (pArray != NULL && limite >0){
			for ( i = 0; i<limite; i++) {
				if(pArray[i].isEmpty == TRUE)
					{
					retorno = i;
					break;
					}
			}
		}
	return retorno;
}

int pantalla_buscarLibreRef (Pantalla* pArray, int limite, int * pIndice){
	int retorno = -1;
	int i ;
		if (pArray != NULL && limite >0 && pIndice != NULL){
			for ( i = 0; i<limite; i++) {
				if(pArray[i].isEmpty == TRUE)
					{
					*pIndice = i;
					retorno = 0;
					break;
					}
			}
		}
	return retorno;
}

static int pantalla_generarNuevoId (void) {
	static int id = 0;
	id = id+1;
	return id;
}

int pantalla_buscarIndicePorId (Pantalla* pArray, int limite,
		               int idBuscar,int * pIndice){
	int retorno = -1;
	    int i ;
	        if (pArray != NULL && limite >0 && pIndice != NULL && idBuscar >= 0)
	        {
	                for ( i = 0; i<limite; i++)
	                {
	                    if(pArray[i].isEmpty==FALSE &&
	                       pArray[i].id == idBuscar)
	                    {
	                        *pIndice = i;
	                        retorno = 0;
	                    break;
	                    }
	                }
	            }
	            else
	            {
	                printf("errrror");
	            }
	        return retorno;
}

int pantalla_ordenarPorNombre (Pantalla* pArray, int limite , int orden)
{
	int retorno = -1;
	int estadoDesordenado = 1;
	Pantalla aux;
	if (pArray != NULL && limite >0){
	while(estadoDesordenado)//mientras este desordenado
	{
		estadoDesordenado = 0;
		for(int i = 0; i < (limite - 1); i++)
		{
			if((orden == 1 && strncmp(pArray[i].nombre, pArray[i + 1].nombre,LEN_NOMBRE)>0)
					||
			  (orden == 0 && strncmp(pArray[i].nombre, pArray[i + 1].nombre,LEN_NOMBRE)<0))
			{
				aux = pArray[i];
				pArray[i] = pArray[i + 1];
				pArray[i + 1] = aux;
				estadoDesordenado = 1;
			}
		}
	}
	retorno = 0;


	}
	return retorno;
}

