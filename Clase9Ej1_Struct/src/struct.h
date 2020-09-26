/*
 * struct.h
 *
 *  Created on: Sep 22, 2020
 *      Author: leandro
 */

#ifndef STRUCT_H_
#define STRUCT_H_

typedef struct
{
	char nombre[50];
	int legajo[20];
}Alumno;

int imprimir_Alumnos(Alumno* array,int limite);

#endif /* STRUCT_H_ */
