/*
 * utn.c
 *
 *  Created on: Sep 5, 2020
 *      Author: leandro
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdio_ext.h>

/**
 *\brief Funcion que pide un numero entero
 *\param Recibe un puntero int* pResultado, para guardar el resultado obtenido.
 *\param Recibe un puntrero char para el mensaje que se va a mostrar.
 *\param Recibe un puntero char para mostrar el mensaje de Error
 *\param Recibe un entero como minimo y un entero con maximo que determinan
 *\		 el rango de los valores a obtener.
 *\param Recibe un entero que indica la cantidad de reintentos en caso de Error
 *\return Devuelve un entero - 0 si pudo obtener el valor -1 si no lo obtuvo.
 */
int utn_getInt(int* pResultado, char* pMensaje, char* pMensajeError, int min, int max, int reintentos)
{
	int retorno = -1;
	int i;
	int buffer;
	if(pResultado!=NULL && pMensaje!=NULL && pMensajeError!=NULL && min<=max && reintentos>=0)
	{
		for(i=0;i<=reintentos;i++)
		{
			printf("%s", pMensaje);
			__fpurge(stdin);
			if(scanf("%d", &buffer))
			{
				if(buffer>=min && buffer<=max)
				{
					*pResultado = buffer;
					retorno = 0;
					break;
				}
				else
				{
					printf("%s - Estas fuera de rango\n", pMensajeError);
				}
			}
			else
			{
				printf("%s - No escribiste un numero\n", pMensajeError);
			}
		}
	}
	return retorno;
}

/**
 *\brief Funcion que pide un numero flotante
 *\param Recibe un puntero float* pResultado, para guardar el resultado obtenido.
 *\param Recibe un puntrero char para el mensaje que se va a mostrar.
 *\param Recibe un puntero char para mostrar el mensaje de Error
 *\param Recibe un float como minimo y un float con maximo que determinan
 *\		 el rango de los valores a obtener.
 *\param Recibe un entero que indica la cantidad de reintentos en caso de Error
 *\return Devuelve un entero - 0 si pudo obtener el valor -1 si no lo obtuvo.
 */
int utn_getFloat(float* pResultado, char* pMensaje, char* pMensajeError, float min, float max, int reintentos)
{
	int retorno = -1;
	int i;
	float bufferFloat;
	if(pResultado!=NULL && pMensaje!=NULL && pMensajeError!=NULL && min<max && reintentos>=0)
	{
		for(i=0; i<=reintentos; i++)
		{
			printf("%s", pMensaje);
			__fpurge(stdin);
			if(scanf("%f", &bufferFloat))
			{
				if(bufferFloat>=min && bufferFloat<=max)
				{
					*pResultado = bufferFloat;
					retorno = 0;
					break;
				}
				else
				{
					printf("%s - Estas fuera de rango\n", pMensajeError);
				}
			}
			else
			{
				printf("%s - No escribiste un numero\n", pMensajeError);
			}
		}
	}
	return retorno;
}

/**
 *\brief Funcion que pide un dato tipo char, un caracter.
 *\param Recibe un puntero char* pResultado, para guardar el resultado obtenido.
 *\param Recibe un puntrero char para el mensaje que se va a mostrar.
 *\param Recibe un puntero char para mostrar el mensaje de Error
 *\param Recibe un char como minimo y un char con maximo que determinan
 *\		 el rango de los valores a obtener.
 *\param Recibe un entero que indica la cantidad de reintentos en caso de Error
 *\return Devuelve un entero - 0 si pudo obtener el valor -1 si no lo obtuvo.
 */
int utn_getChar(char* pResultado, char* pMensaje, char* pMensajeError, char min, char max, int reintentos)
{
	int retorno = -1;
	int i;
	char bufferChar;
	if(pResultado!=NULL && pMensaje!=NULL && pMensajeError!=NULL && min<max && reintentos>=0)
	{
		for(i=0; i<=reintentos; i++)
		{
			printf("%s", pMensaje);
			__fpurge(stdin);
			scanf("%c", &bufferChar);
			if(bufferChar>=min && bufferChar<=max)
			{
				*pResultado = bufferChar;
				retorno = 0;
				break;
			}
			else
			{
				printf("%s - Ingresaste una letra invalida\n", pMensajeError);
			}
		}
	}
	return retorno;
}
