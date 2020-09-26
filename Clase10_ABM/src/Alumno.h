/*
 * Alumno.h
 *
 *  Created on: Sep 26, 2020
 *      Author: leandro
 */

#ifndef ALUMNO_H_
#define ALUMNO_H_

#define TRUE 1
#define FALSE 0
#define ARRAY_LEN_NAME 30
#define ARRAY_LEN_LASTNAME 50
#define QTY_REINT 3
#define ZERO 0
#define MAX_FILE 999999999
#define ARRAY_LEN_ALUMNOS 5

typedef struct{
	int id;
	char name[ARRAY_LEN_NAME];
	char lastName[ARRAY_LEN_LASTNAME];
	int file;
	int isEmpty;
}Alumno;

int alumno_inicializarArray(Alumno* array, int len);
int alumno_mostrarLista(Alumno* array, int len);
int alumno_buscarVacio(Alumno* array, int len);
int alumno_AltaDeAlumnos(Alumno* array, int len, int indice);
int alumnos_buscarIndicexId(Alumno* array, int len, int id);
int alumno_ModificarAlumnos(Alumno* array, int len, int indice);
int alumno_BajaAlumnos(Alumno* array, int len, int indice);
int alumno_ordenarPorNombre(Alumno* array,int len);

#endif /* ALUMNO_H_ */
