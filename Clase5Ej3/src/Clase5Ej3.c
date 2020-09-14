/*
 ============================================================================
 Name        : Clase5Ej3.c
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

#define MIN_NUMBER -999999999
#define MAX_NUMBER 999999999
#define QTY_REINT 2
#define QTY_LEN 5

int main(void) {

	int optionMenu;
	int arrayNumeros[QTY_LEN];
	int maximo;
	int minimo;

	do
	{
		printf(	"\n1 - Ingrese 5 Numeros.\n"
				"2 - Mostrar los numeros ingresados.\n"
				"3 - Mostrar el maximo numero ingresado.\n"
				"4 - Mostrar el minimo numero ingresado.\n"
				"5 - Ordenarlos de menor a mayor.\n"
				"6 - Obtener el promedio de todos los numeros.\n"
				"7 - Indicar y mostrar cuantos numeros positivos se ingresaron.\n"
				"8 - Indicar y mostrar cunatos numeros negativos se ingresaron.\n"
				"9 - Indicar numeros pares.\n"
				"10 - Indicar numeros impares.\n"
				"11 - Modificar el Array.\n"
				"12 - Salir.\n");

		if(!utn_getInt(&optionMenu, "Ingrese una opcion del Menu: ", "ERROR", MIN_NUMBER, MAX_NUMBER, QTY_REINT))
		{
			switch(optionMenu)
			{
				case 1:

					printf("\n********************************************\n");
					if(!utn_cargarArrayEnteros(arrayNumeros, QTY_LEN, MIN_NUMBER, MAX_NUMBER, QTY_REINT))
					{
						printf("\nLos numeros se han cargado con exito!!\n");
					}
					else
					{
						printf("ERROR, Algo salio mal\n");
					}
					printf("\n********************************************\n");
					break;

				case 2:

					printf("\n********************************************\n");
					if(utn_mostrarArrayInt(arrayNumeros, QTY_LEN)==-1)
					{
						printf("\nAlgo salio mal, no se puesde mostrar el Array.\n");
					}
					printf("\n********************************************\n");
					break;

				case 3:

					printf("\n********************************************\n");
					if(!utn_calcularmaximoArray(arrayNumeros, QTY_LEN, &maximo))
					{
						printf("\nEl maximo numero infresado es: %d\n", maximo);
					}
					else
					{
						printf("\nNo se pudo calcular el maximo\n");
					}
					printf("\n********************************************\n");
					break;

				case 4:

					printf("\n********************************************\n");
					if(!utn_calcularminimoArray(arrayNumeros, QTY_LEN, &minimo))
					{
						printf("\nEl minimo numero infresado es: %d\n", minimo);
					}
					else
					{
						printf("\nNo se pudo calcular el minimo\n");
					}
					printf("\n********************************************\n");
					break;

				case 12:
					printf("\nGracias, vuelva prontos.\n");
					break;
				default:
					printf("\nIngreso un numero que no es una opcion.\n");
					break;
			}
		}
		else
		{
			printf("- Se acabaron tus reintentos\n");
		}
	}while(optionMenu != 12);

	return EXIT_SUCCESS;
}
