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
#define QTY_REINT 2

int main(void) {
	int opcionesMenu;
	float num_a = 0;
	float num_b = 0;
	//Menu de Inicio
	do{
		printf( "--Menu de opciones--\n"
				"1. Ingresar primer operando (A=%.2f)\n"
				"2. Ingresar Segundo operando (B=%.2f)\n"
				"3. Calcular todas las operaciones:\n"
				"   a) Calcular la suma (%.2f+%.2f)\n"
				"   b) Calcular la resta (%.2f-%.2f)\n"
				"   c) Calcular la division (%.2f/%.2f)\n"
				"   d) Calcular la multiplicacion (%.2f*%.2f)\n"
				"   e) Calcular el factorial (%.2f!)\n"
				"4. Informar resultados\n",
				num_a,
				num_b,
				num_a,
				num_b,
				num_a,
				num_b,
				num_a,
				num_b,
				num_a,
				num_b,
				num_a);
		if(!utn_getInt(	&opcionesMenu,
						"Ingrese la opcion de Menu deseada: ",
						"ERROR",
						QTY_MIN,
						QTY_MAX,
						QTY_REINT))
		{
			//Seteo de la opcion deseada
			switch(opcionesMenu){
					case 1:
						printf("\n*********************************************\n");
						printf("--Opcion 1--\n");
						if(!utn_getFloat(	&num_a,
											"Ingrese un numero: ",
											"ERROR",
											QTY_MIN,
											QTY_MAX,
											QTY_REINT))
						{
							printf("Su numero se cargo con exito!!\n");
						}
						else
						{
							printf("Algo salio mal, se acabaron tus reintentos\n");
						}
						printf("*********************************************\n\n");
						break;
					case 2:
						printf("\n*********************************************\n");
						printf("--Opcion 2--\n");
						if(!utn_getFloat(	&num_b,
											"Ingrese un numero: ",
											"ERROR",
											QTY_MIN,
											QTY_MAX,
											QTY_REINT))
						{
							printf("Su numero se cargo con exito!!\n");
						}
						else
						{
							printf("Algo salio mal, se acabaron tus reintentos\n");
						}
						printf("*********************************************\n\n");
						break;
					case 5:
						printf("\n*********************************************\n");
						printf("Gracias por usar la calculadora!!");
						printf("\n*********************************************\n");
						break;
					default:
						printf( "ERROR, Usted ingreso un numero incorrecto.\n"
								"Vuelva a intentarlo.\n\n");
						break;
			}
		}
		else
		{
			printf("Algo salio mal, se acabaron tus reintentos\n\n");
		}
	}while(opcionesMenu != 5);
	return EXIT_SUCCESS;
}
