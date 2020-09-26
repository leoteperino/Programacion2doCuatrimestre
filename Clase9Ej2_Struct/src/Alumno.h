/*
 * Alumno.h
 *
 *  Created on: Sep 24, 2020
 *      Author: leandro
 */

#ifndef ALUMNO_H_
#define ALUMNO_H_

#define LONG_NOMBRE 50
#define QTY_REINT 2
#define ZERO 0
#define TRUE 1
#define FALSE 0
#define MAX_LEGAJO 99999

typedef struct
{
	char nombre[LONG_NOMBRE];
	int legajo;
	int isEmpty;
	int id;
}Alumno;

int alumno_inicializarArray(Alumno* array,int limite);
int alumno_altaAlumnos(Alumno* arrayAlumnos,int limite, int indice,int* id);
int alumno_imprimir(Alumno* pArrayAlumnos, int limite);
int alumno_modificarAlumno(Alumno* arrayAlumnos,int limite, int indice);
int alumno_imprimirIndice(Alumno* pArrayAlumnos, int limite, int indice);
int alumno_buscarVacio(Alumno* array, int limite);
int alumnos_buscarIndicexId(Alumno array[], int limite, int id);

#endif /* ALUMNO_H_ */
