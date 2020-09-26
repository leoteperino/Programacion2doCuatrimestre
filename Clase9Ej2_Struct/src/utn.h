/*
 * utn.h
 *
 *  Created on: Sep 20, 2020
 *      Author: leandro
 */

#ifndef UTN_H_
#define UTN_H_

int utn_getNumero(int* pResultado, char* pMensaje, char* pMensajeError, int minimo, int maximo, int reintentos);
int utn_getNumeroFlotante(float* pResultado, char* pMensaje, char* pMensajeError, int minimo, float maximo, float reintentos);
int utn_getTexto(char* pResultado, int longitud,char* pMensaje, char* pMensajeError, int reintentos);
int utn_getNombre(char* pResultado, int longitud,char* pMensaje, char* pMensajeError, int reintentos);

#endif /* UTN_H_ */
