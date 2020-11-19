/*
 ============================================================================
 Name        : PracticaListaDinamica.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"
#include "C"

int main(void) {
	int option = 0;
	do{
		if(!utn_getNumero(   &option,
							"\n*****Menu de Opciones*****\n"
							"1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).\n"
							"2. Cargar los datos de los empleados desde el archivo data.csv (modo binario).\n"
							"3. Alta de empleado.\n"
							"4. Modificar datos de empleado.\n"
							"5. Baja de empleado.\n"
							"6. Listar empleados.\n"
							"7. Ordenar empleados.\n"
							"8. Guardar los datos de los empleados en el archivo data.csv (modo texto).\n"
							"9. Guardar los datos de los empleados en el archivo data.csv (modo binario).\n"
							"10. Salir.\n"
							"-----------------------------\n"
							"Elija una opcion del menu: ",
							"ERROR",0,10,2))
		switch(option)
		{
			case 1:

				break;
			case 2:
				printf("2\n");
				break;
			case 3:
				printf("3\n");
				break;
			case 4:
				printf("4\n");
				break;
			case 5:
				printf("5\n");
				break;
			case 6:

				break;
			case 7:
				printf("7\n");
				break;
			case 8:
				printf("8\n");
				break;
			case 9:
				printf("9\n");
				break;
			case 10:
				printf("Hasta luego!!\n");
				break;
		}
	}while(option != 10);
	return EXIT_SUCCESS;
}
