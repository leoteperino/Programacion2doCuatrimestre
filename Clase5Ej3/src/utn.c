/*
 * utn.c
 *
 *  Created on: Sep 13, 2020
 *      Author: leandro
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdio_ext.h>

int utn_getInt(int* pResultado, char* pMensaje, char* pMensajeError, int min, int max, int reintentos)
{
	int retorno = -1;
	int bufferInt;
	int i;

	if(pResultado!=NULL && pMensaje!=NULL && pMensajeError!=NULL && min<=max && reintentos>0)
	{
		for(i=0;i<=reintentos;i++)
		{
			printf("%s", pMensaje);
			__fpurge(stdin);
			if(scanf("%d", &bufferInt))
			{
				if(bufferInt>=min && bufferInt<=max)
				{
					*pResultado = bufferInt;
					retorno = 0;
					break;
				}
				else
				{
					printf("%s - No ingresaste un numero valido\n", pMensajeError);
				}
			}
			else
			{
				printf("%s - No ingresaste un numero\n", pMensajeError);
			}
		}
	}
	return retorno;
}

int utn_cargarArrayEnteros(int* array, int len, int min, int max, int reintentos)
{
	int retorno = -1;
	int bufferInt;
	int i;
	if(array!=NULL && len>0 && min<max && reintentos>0)
	{
		for(i=0;i<len;i++)
		{
			if(!utn_getInt(&bufferInt, "Ingrese un numero: ", "ERROR", min, max, reintentos))
			{
				array[i] = bufferInt;
				retorno = 0;
			}
			else
			{
				printf("\nAlgo salio mal, no hay mas reintentos\n");
				break;
			}
		}
	}
	return retorno;
}

int utn_mostrarArrayInt(int* array, int len)
{
	int retorno = -1;
	int i;
	if(array!=NULL && len>0)
	{
		retorno = 0;
		for(i=0;i<len;i++)
		{
			printf("\nIndice: %d - Valor: %d", i, array[i]);
		}
	}
	return retorno;
}

int utn_promedioArrayInt(int Array[], int len, float* pResultado)
{
	int retorno = -1;
	int acumulador = 0;
	float promedio;
	int i;
	if(pResultado!=NULL && len>0)
	{
		for(i=0;i<len;i++)
		{
			acumulador+=Array[i];
		}
		promedio=(float)acumulador/len;
		*pResultado = promedio;
		retorno = 0;
	}
	return retorno;
}

int utn_calcularmaximoArray(int* Array, int len, int* maximo)
{
	int retorno = -1;
	int bufferInt;
	int i;
	if(Array!=NULL && len>0 && maximo!=NULL)
	{
		bufferInt = Array[0];
		for(i=1;i<len;i++)
		{
			if(Array[i]>bufferInt)
			{
				bufferInt = Array[i];
			}
			*maximo = bufferInt;
			retorno = 0;
		}
	}
	return retorno;
}

int utn_calcularminimoArray(int Array[], int len, int* minimo)
{
	int retorno = -1;
	int bufferInt;
	int i;
	if(Array!=NULL && len>0 && minimo!=NULL)
	{
		bufferInt = Array[0];
		for(i=1;i<len;i++)
		{
			if(Array[i]<bufferInt)
			{
				bufferInt = Array[i];
			}
			*minimo = bufferInt;
			retorno = 0;
		}
	}
	return retorno;
}

int utn_ordenarArrayMenorMayor(int array[], int len)
{
	int retorno=-1;
	int i;
	int bufferInt;
	int flagEstadoDesordenado=1;
	int nuevoLimite;

	if(array!=NULL && len >=1)
	{
		nuevoLimite = len -1;
		while(flagEstadoDesordenado==1)
		{
			flagEstadoDesordenado=0;
			for(i=0 ; i<nuevoLimite  ; i++)
			{
				if(array[i] > array[i+1])
				{
					bufferInt = array[i];
					array[i] = array[i+1];
					array[i+1] = bufferInt;
					flagEstadoDesordenado=1;
				}
			}
			nuevoLimite--;
		}
		retorno=0;
	}
	return retorno;
}

int utn_ordenarArrayMayorMenor(int array[], int len)
{
	int retorno=-1;
	int i;
	int bufferInt;
	int flagEstadoDesordenado=1;
	int nuevoLimite;

	if(array!=NULL && len >=1)
	{
		nuevoLimite = len -1;
		while(flagEstadoDesordenado==1)
		{
			flagEstadoDesordenado=0;
			for(i=0 ; i<nuevoLimite  ; i++)
			{
				if(array[i] < array[i+1])
				{
					bufferInt = array[i];
					array[i] = array[i+1];
					array[i+1] = bufferInt;
					flagEstadoDesordenado=1;
				}
			}
			nuevoLimite--;
		}
		retorno=0;
	}
	return retorno;
}


