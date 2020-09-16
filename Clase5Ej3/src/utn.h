/*
 * utn.h
 *
 *  Created on: Sep 13, 2020
 *      Author: leandro
 */

#ifndef UTN_H_
#define UTN_H_

int utn_getInt(int* pResultado, char* pMensaje, char* pMensajeError, int min, int max, int reintentos);
int utn_cargarArrayEnteros(int* array, int len, int min, int max, int reintentos);
int utn_mostrarArrayInt(int* array, int len);
int utn_promedioArrayInt(int Array[], int len, float* pResultado);
int utn_calcularmaximoArray(int* Array, int len, int* maximo);
int utn_calcularminimoArray(int Array[], int len, int* minimo);
int utn_ordenarArrayMenorMayor(int array[], int len);
int utn_ordenarArrayMayorMenor(int array[], int len);
void utn_mostrarArrayEnteros(int* array, int len);
int utn_getIndiceArray(int* array, int len, int* indice);
int utn_modificarArrayPorIndice(int* array, int len, int indice);
int utn_getIntSimple(int* pResultado, char* pMensaje);

#endif /* UTN_H_ */
