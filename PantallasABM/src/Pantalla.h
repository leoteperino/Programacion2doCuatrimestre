/*
 * nac.h
 *
 *  Created on: Sep 29, 2020
 *      Author: ezemanzano
 */

#ifndef PANTALLA_H_
#define PANTALLA_H_

#define LEN_NOMBRE 50
#define LEN_DIRECCION 50
#define TRUE 1
#define FALSE 0

typedef struct
{
	int id;
	char nombre[LEN_NOMBRE];
	int tipo;
	float precio;
	char direccion[LEN_DIRECCION];
	int isEmpty;
}Pantalla;

int pantalla_init(Pantalla * pArray, int limite);
int pantalla_alta (Pantalla * pArray, int limite);
int pantalla_baja (Pantalla * pArray, int limite);
int pantalla_modificar (Pantalla * pArray, int limite);
int pantalla_imprimir (Pantalla * pArray , int limite);
int pantalla_buscarLibre (Pantalla * pArray, int limite);
int pantalla_buscarLibreRef (Pantalla * pArray, int limite, int * pIndice);
int pantalla_buscarIndicePorId (Pantalla * pArray, int limite, int idBuscar,int * pIndice);
int pantalla_ordenarPorNombre (Pantalla * pArray, int limite , int orden);

#endif /* PANTALLA_H_ */
