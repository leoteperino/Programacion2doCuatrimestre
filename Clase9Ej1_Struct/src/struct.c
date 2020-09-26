/*
 * struct.c
 *
 *  Created on: Sep 22, 2020
 *      Author: leandro
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdio_ext.h>
#include <string.h>

int imprimir_Alumnos(Alumno* array,int limite)
{
	int ret = -1;
	int i;
	if(array!=NULL && limite>0)
	{
		for(i=0;i<limite;i++)
		{
			printf("%s", array[i].nombre);
		}
		ret = 0;
	}
	return ret;
}
