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

/**
 * \brief Funcion que pide numeros y carga un Array de Enteros
 * \param Se le pasa como parametro el array
 * \param Se le pasa el largo del array
 * \param Se le pasa el minimo y el maximo de los numeros que quiero ingresar
 * \param Se le pasa la cantidad de reintentos en caso de error
 * \return No se devuelve nada
 */
void utn_cargandoArrayInt(int Array[], int len, int min, int max, int reintentos)
{
	int bufferInt;
	int i;

	for(i=0;i<len;i++)
	{
		if(!utn_getInt(&bufferInt, "Ingrese un numero: ", "ERROR", min, max, reintentos))
		{
			Array[i] = bufferInt;
		}
		else
		{
			printf("\nAlgo salio mal, no hay mas reinmtentos");
		}
	}
}

/**
 * \brief Funcion que imprime un Array de Numeros
 * \param Recibe como primer parametro el array a imprimir
 * \param Recibe como segundfo parametro el largo del Array
 * \return No Devuelde nada
 */
void utn_imprimirArrayInt(int Array[], int len)
{
	int i;
	for(i=0;i<len;i++)
	{
		printf("\nIndice: %d - Valor: %d", i, Array[i]);
	}
}

/*
 * \brief Funcion que calcula el promedio de un Array de enteros
 * \param Se pasa un puntero float que llevara el resultado
 * \param Se pasa el Array
 * \param Se pasa el largo del Array
 * \return Devielve -1 en casdo de no haber podido leer el Array, Devuelve 0 si esta todo OK
 */
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

/*
 * \brief Funcion que calcula el maximo numero de un Array de enteros
 * \param Se pasa un puntero int que llevara el numero maximo
 * \param Se pasa el Array
 * \param Se pasa el largo del Array
 * \return Devielve -1 en caso de no haber podido completarse la operacion, Devuelve 0 si esta todo OK
 */
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

/*
 * \brief Funcion que calcula el minimo numero de un Array de enteros
 * \param Se pasa un puntero int que llevara el numero maximo
 * \param Se pasa el Array
 * \param Se pasa el largo del Array
 * \return Devuelve -1 en caso de no haber podido completarse la operacion, Devuelve 0 si esta OK
 */
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

/*
 * \brief Funcion que ordena de menor a mayor los numeros de un Array
 * \param Se pasa el Array
 * \param Se pasa el largo del Array
 * \return Devuelve -1 en caso de no haber podido completarse la operacion, Devuelve 0 si esta OK
 */
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


/*
 * \brief Funcion que ordena de Mayor a menor los numeros de un Array
 * \param Se pasa el Array
 * \param Se pasa el largo del Array
 * \return Devuelve -1 en caso de no haber podido completarse la operacion, Devuelve 0 si esta OK
 */
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





