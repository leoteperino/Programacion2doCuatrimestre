/*
 * utn.c
 *
 *  Created on: Sep 16, 2020
 *      Author: leandro
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdio_ext.h>
#include <string.h>

static int myGets(char* cadena, int longitud);
static int utn_esNombre(char* cadena, int limite);

/*
 * \brief Funcion que lee una cadena de caracteres pasada por el usuario
 * \param Se le pasa el puntero char a un array de caracteres.
 * \param Se le pasa la longitud del array
 * \return Devuelve -1 en caso de Error y 0 si puedo leer OK.
 */
static int myGets(char* cadena, int longitud)
{
	int retorno = -1;
	if(cadena!=NULL && longitud>0)
	{
		__fpurge(stdin);
		fgets(cadena, longitud, stdin);
		cadena[strnlen(cadena,sizeof(cadena))-1]= '\0';
		retorno = 0;
	}
	return retorno;
}

/**
 * \brief Solicita un nombre al usuario
 * \param char* pMensaje, Es el mensaje a ser mostrado al usuario
 * \param char* pMensajeError, Es el mensaje de error a ser mostrado al usuario
 * \param char* pResultado, puntero al espacio de memoria donde se dejara el valor obtenido
 * \param int reintentos, cantidad de oportunidades para ingresar el dato
 * \param int limiteArray, indica la cantidad de letras maxima del nombre
 * \return (-1) Error / (0) Ok
 *
 */
int utn_getNombre(char* pResultado, char* pMensaje, char* pMensajeError, int reintentos, int limiteArray)
{
	int retorno = -1;
	char bufferChar[limiteArray];
	int i;
	if(pResultado!=NULL && pMensaje!=NULL && pMensajeError!=NULL && reintentos>0 && limiteArray>0)
	{
		for(i=0;i<reintentos;i++)
		{
			printf("%s", pMensaje);
			if( !myGets(bufferChar, limiteArray) &&
				strnlen(bufferChar,sizeof(bufferChar)-1)<= limiteArray &&
				utn_esNombre(bufferChar,limiteArray))
			{
				strncpy(pResultado, bufferChar, limiteArray);
				retorno = 0;
				break;
			}
			else
			{
				printf("%s", pMensajeError);
			}
		}
	}
	return retorno;
}

/**
 * \brief 	Verifica una cadena recibida como parametro para determinir
 * 			si es un nombre valido
 * \param char* cadena, Cadena a analizar
 * \param int limite, indica la cantidad de letras maxima de la cadena
 * \return (0) Indicar que no es un nombre valido / (1) Indica que que es un nombre valido
 *
 */
static int utn_esNombre(char* cadena, int limite)
{
	int retorno = -1;
	int i;
	if(cadena!=NULL && limite>0)
	{
		for(i=0; i<limite && cadena[i]!='\0'; i++)
		{
			if(	(cadena[i] < 'A' || cadena[i] > 'Z') &&
				(cadena[i] < 'a' || cadena[i] > 'z') &&
				 cadena[i] != '.' && cadena[i]!= ' ')
			{
				retorno = 0;
				break;
			}
		}
	}
	return retorno;
}
