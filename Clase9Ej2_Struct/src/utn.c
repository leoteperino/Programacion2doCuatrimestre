/*
 * utn.c
 *
 *  Created on: Sep 20, 2020
 *      Author: leandro
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdio_ext.h>
#include <string.h>
#include "Alumno.h"

#define ARRAY_LEN_STRING 4096
#define ARRAY_LEN_INT 64
#define ARRAY_LEN_NOMBRE 35

/*********Prototipos*********/
static int getString(char* array, int len);
static int getInt(int* pResultado);
static int esNumerica(char* cadena, int limite);
static int getFloat(float* pResultado);
static int esNumericaFloat(char* cadena, int limite);
static int getTexto(char* pResultado, int longitud);
static int esTexto(char* cadena,int longitud);
static int getNombre(char* pResultado, int longitud);
static int esNombre(char* cadena,int longitud);

/*********Funciones Estaticas*********/
/*********GET*********/
/*
 * \brief 	Lee de stdin hasta que encuentra un \n o hasta que haya copiado en cadena
 * 			un maximo de len-1 caracteres.
 * 	\param array puntero al array donde se copiara la cadena obtenida
 * 	\param len es un entero que define el tamaño de la cadena
 * 	\return retorna 0 en caso de Exito y -1 en caso de ERROR
 * */
static int getString(char* array, int len)
{
	int ret=-1;
	char bufferString[ARRAY_LEN_STRING];
	if(array!=NULL && len>0)
	{
		__fpurge(stdin);
		if(fgets(bufferString,sizeof(bufferString),stdin)!=NULL)
		{
			if(bufferString[strnlen(bufferString,sizeof(bufferString))-1] == '\n')
			{
				bufferString[strnlen(bufferString,sizeof(bufferString))-1] = '\0';
			}
			if(strnlen(bufferString,sizeof(bufferString))<=len)
			{
				strncpy(array,bufferString,len);
				ret=0;
			}
		}
	}
	return ret;
}
/**
 * \brief Obtien un numero entero
 * \param pResultado Puntero al espacio de memoria donde se dejara el resultado de la funcion
 * \return Retorna 0 (EXITO) si se obtiene un numero entero y -1 (ERROR) si no
 **/
static int getInt(int* pResultado)
{
    int retorno=-1;
    char bufferString[ARRAY_LEN_INT];
    if( pResultado!=NULL &&
    	!getString(bufferString,sizeof(bufferString)) &&
    	esNumerica(bufferString,sizeof(bufferString)))
	{
		*pResultado = atoi(bufferString);
		retorno=0;

	}
    return retorno;
}
/**
 * \brief Obtiene un numero decimal
 * \param pResultado Puntero al espacio de memoria donde se dejara el resultado de la funcion
 * \return Retorna 0 (EXITO) si se obtiene un numero entero y -1 (ERROR) si no
 **/
static int getFloat(float* pResultado)
{
    int retorno=-1;
    char bufferString[ARRAY_LEN_INT];
    if( pResultado!=NULL &&
    	!getString(bufferString,sizeof(bufferString)) &&
		esNumericaFloat(bufferString,sizeof(bufferString)))
	{
		*pResultado = atof(bufferString);
		retorno=0;
	}
    return retorno;
}
/**
 * \brief Obtiene un texto
 * \param pResultado Puntero char al espacio de memoria donde se dejara el resultado de la funcion
 * \param longitud entrero que marca la longitud de la cadena a ingresar.
 * \return Retorna 0 (EXITO) si se obtiene un numero entero y -1 (ERROR)
 **/
static int getTexto(char* pResultado, int longitud)
{
	int res = -1;
	char bufferString[ARRAY_LEN_STRING];
	if(pResultado!=NULL && longitud>0)
	{
		if( !getString(bufferString,sizeof(bufferString)) &&
		    esTexto(bufferString, sizeof(bufferString)))
		{
			strncpy(pResultado,bufferString,longitud);
			res = 0;
		}
	}
	return res;
}
/**
 * \brief Obtiene un nombre
 * \param pResultado Puntero char al espacio de memoria donde se dejara el resultado de la funcion
 * \param longitud entrero que marca la longitud de la cadena a ingresar.
 * \return Retorna 0 (EXITO) si se obtiene un numero entero y -1 (ERROR)
 **/
static int getNombre(char* pResultado, int longitud)
{
    int retorno=-1;
    char buffer[ARRAY_LEN_NOMBRE];
    if(pResultado!=NULL && longitud>0)
    {
    	if(	getString(buffer,sizeof(buffer))==0 &&
    		esNombre(buffer,sizeof(buffer)) &&
			strnlen(buffer,sizeof(buffer))<longitud)
    	{
    		strncpy(pResultado,buffer,longitud);
			retorno = 0;
		}
    }
    return retorno;
}
/*********Estaticas Validaciones*********/
/**
 * \brief Verifica si la cadena ingresada es numerica, admite solo enteros
 * \param cadena Cadena de caracteres a ser analizada
 * \return Retorna 1 (verdadero) si la cadena es numerica, 0 (falso) si no lo es y -1 en caso de error
 **/
static int esNumerica(char* cadena, int limite)
{
	int retorno=-1;
	int i;
	if(cadena!=NULL && limite>0)
	{
		retorno = 1;
		for(i=0;i<limite&&cadena[i]!='\0';i++)
		{
			if(i==0 && (cadena[i]=='+' || cadena[i]=='-'))
			{
				continue;
			}
			if(cadena[i]<'0' || cadena[i]>'9')
			{
				retorno = 0;
				printf("ERROR, Ingrese solo numeros enteros.\n");
				break;
			}
		}
	}
	return retorno;
}
/**
 * \brief Verifica si la cadena ingresada es numerica y admite comas
 * \param cadena Cadena de caracteres a ser analizada
 * \return Retorna 1 (verdadero) si la cadena es numerica, 0 (falso) si no lo es y -1 en caso de error
 **/
static int esNumericaFloat(char* cadena, int limite)
{
	int i=0;
	int retorno = -1;
	int contadorPuntos=0;

	if(cadena != NULL && strlen(cadena) > 0)
	{
		retorno = 1;
		for(i=0 ; cadena[i] != '\0'; i++)
		{
			if(i==0 && (cadena[i] == '-' || cadena[i] == '+'))
			{
				continue;
			}
			if(cadena[i] < '0' || cadena[i] > '9' )
			{
				if(cadena[i] == '.' && contadorPuntos == 0)
				{
					contadorPuntos++;
				}
				else
				{
					if(contadorPuntos>0)
					{
						retorno=0;
						printf("El numero no puede contener mas de una coma.\n");
						break;
					}
					retorno = 0;
					printf("ERROR, Ingrese solo numeros.\n");
					break;
				}
			}
		}
	}
	return retorno;
}
/**
 * \brief Verifica si la cadena ingresada es un texto valido
 * \param cadena char de caracteres a ser analizada
 * \param longitud entero que marca la longitud de la cadena ingresada.
 * \return Retorna 1 (verdadero) si la cadena es un texto valido, 0 (falso) si no lo es.
 **/
static int esTexto(char* cadena,int longitud)
{
	int i=0;
	int retorno = 1;
	if(cadena!=NULL && longitud>0)
	{
		for(i=0;cadena[i]!='\0' && i<longitud;i++)
		{
			if((cadena[i] < 'A' || cadena[i] > 'Z' ) && (cadena[i] < 'a' || cadena[i] > 'z' ) &&
			   (cadena[i] < '0' || cadena[i] > '9') && (cadena[i] != ' ') &&
			   (cadena[i] != ',') && (cadena[i] != '.') && (cadena[i] != '+') && (cadena[i] != '-'))
			{
				retorno = 0;
				printf("Error de validacion, usted ingreso un caracter no permitido.\n");
				break;
			}
		}
	}
	return retorno;
}
/**
 * \brief Verifica si la cadena ingresada es un nombre valido
 * \param cadena char de caracteres a ser analizada
 * \param longitud entero que marca la longitud de la cadena ingresada.
 * \return Retorna 1 (verdadero) si la cadena es un nombre valido, 0 (falso) si no lo es.
 **/
static int esNombre(char* cadena,int longitud)
{
	int i=0;
	int retorno = 1;
	if(cadena != NULL && longitud > 0)
	{
		for(i=0 ; cadena[i] != '\0' && i < longitud; i++)
		{
			if((cadena[i] < 'A' || cadena[i] > 'Z' ) && (cadena[i] < 'a' || cadena[i] > 'z' ))
			{
				retorno = 0;
				break;
			}
		}
	}
	return retorno;
}
/*********GET*********/
/*
 * \brief Pide un numero al usuario dentro de un rango determinado
 * \param pResultado: puntero a int donde se guarda el valor del dato a mostrar enm el main, el numero.
 * \param pMensaje: puntero a char, donde se pasa el mensaje a mostrar.
 * \param pMensajeerror: puntero a mensaje de error que se le pasa en caso de error.
 * \param minimo y maximo: enteros donde se pasa el rango de numeros a tomar, el minimo aceptado y el maximo aceptado.
 * \param reintentos: entero, es la cantidad de reintentos que tendra el usuario en caso de error.
 * \return devuelve 0 en caso de Exito y -1 en caso de Error.
 * */
int utn_getNumero(int* pResultado, char* pMensaje, char* pMensajeError, int minimo, int maximo, int reintentos)
{
	int ret = -1;
	int bufferInt;
	int i;
	for(i=0;i<=reintentos;i++){
		if(pResultado!=NULL && pMensaje!=NULL && pMensajeError!=NULL && minimo<=maximo && reintentos>0)
		{
			printf("%s", pMensaje);
			if(!getInt(&bufferInt))
			{
				if(bufferInt>=minimo && bufferInt<=maximo)
				{
					*pResultado = bufferInt;
					ret = 0;
					break;
				}
				else
				{
					printf("%s - Fuera de rango\n", pMensajeError);
				}
			}
		}
	}
	return ret;
}
/*
 * \brief Pide un numero decimal al usuario dentro de un rango determinado
 * \param pResultado: puntero a float donde se guarda el valor del dato a mostrar en el main, el numero.
 * \param pMensaje: puntero a char, donde se pasa el mensaje a mostrar.
 * \param pMensajeError: puntero a mensaje de error que se le pasa en caso de error.
 * \param minimo y maximo: floats donde se pasa el rango de numeros a tomar, el minimo aceptado y el maximo aceptado.
 * \param reintentos: entero, es la cantidad de reintentos que tendra el usuario en caso de error.
 * \return devuelve 0 en caso de Exito y -1 en caso de Error.
 * */
int utn_getNumeroFlotante(float* pResultado, char* pMensaje, char* pMensajeError, int minimo, float maximo, float reintentos)
{
	int ret = -1;
	float bufferFloat;
	int i;
	for(i=0;i<=reintentos;i++){
		if(pResultado!=NULL && pMensaje!=NULL && pMensajeError!=NULL && minimo<=maximo && reintentos>0)
		{
			printf("%s", pMensaje);
			if(!getFloat(&bufferFloat))
			{
				if(bufferFloat>=minimo && bufferFloat<=maximo)
				{
					*pResultado = bufferFloat;
					ret = 0;
					break;
				}
				else
				{
					printf("%s - Fuera de rango\n", pMensajeError);
				}
			}
		}
	}
	return ret;
}
/*
 * \brief Pide un texto al usuario.
 * \param pResultado: puntero a char donde se guarda el dato a mostrar en el main.
 * \param longitud entero que marca la longitud de la cadena a ingresar.
 * \param pMensaje: puntero a char, donde se pasa el mensaje a mostrar.
 * \param pMensajeError: puntero a mensaje de error que se le pasa en caso de error.
 * \param reintentos: entero, es la cantidad de reintentos que tendra el usuario en caso de error.
 * \return devuelve 0 en caso de Exito y -1 en caso de Error.
 * */
int utn_getTexto(char* pResultado, int longitud,char* pMensaje, char* pMensajeError, int reintentos)
{
	char bufferString[ARRAY_LEN_STRING];
	int retorno = -1;
	while(reintentos>=0)
	{
		reintentos--;
		printf("%s",pMensaje);
		if( !getTexto(bufferString,sizeof(bufferString)) &&
			strnlen(bufferString,sizeof(bufferString))<longitud)
		{
			strncpy(pResultado,bufferString,longitud);
			retorno=0;
			break;
		}
		else
		{
			printf("%s",pMensajeError);
		}
	}
	return retorno;
}
/*
 * \brief Pide un Nombre al usuario.
 * \param pResultado: puntero a char donde se guarda el valor a mostrar en el main.
 * \param longitud entero que marca la longitud de la cadena a ingresar.
 * \param pMensaje: puntero a char, donde se pasa el mensaje a mostrar.
 * \param pMensajeError: puntero a mensaje de error que se le pasa en caso de error.
 * \param reintentos: entero, es la cantidad de reintentos que tendra el usuario en caso de error.
 * \return devuelve 0 en caso de Exito y -1 en caso de Error.
 * */
int utn_getNombre(char* pResultado, int longitud,char* pMensaje, char* pMensajeError, int reintentos)
{
	char bufferString[ARRAY_LEN_NOMBRE];
	int retorno=-1;
	int i=0;
	if(pResultado!=NULL && longitud>0 && pMensaje!=NULL && pMensajeError!=NULL && reintentos>0)
	{
		for(i=0;i<=reintentos;i++)
		{
			printf("%s",pMensaje);
			if(	!getNombre(bufferString,sizeof(bufferString)) &&
				strnlen(bufferString,sizeof(bufferString))<longitud)
			{
				strncpy(pResultado,bufferString,longitud);
				retorno=0;
				break;
			}
			else
			{
				printf("%s",pMensajeError);
			}
		}
	}
	return retorno;
}
