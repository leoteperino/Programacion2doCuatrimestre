/*
 ============================================================================
 Name        : trabajoPractico1.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdio_ext.h>
#include "utn.h"

#define QTY_MIN -999999999
#define QTY_MAX 999999999
#define OPT_MENU_MIN 1
#define OPT_MENU_MAX 5
#define QTY_REINT 2

int main(void) {
	int opcionesMenu;
	float num_a = 0;
	float num_b = 0;
	//Menu de Inicio
	do{
		printf("\n1 .Ingresar primer operando: (A=%.f)\n", num_a );
		if(!utn_getInt(&opcionesMenu, "Ingrese la opcion de Menu deseada: ", "ERROR", OPT_MENU_MIN, OPT_MENU_MAX, QTY_REINT))
		{
			switch(opcionesMenu){
					case 1:
						printf("Aprestaste el uno\n");
						break;
			}
		}
	}while(opcionesMenu != 5);
	return EXIT_SUCCESS;
}
