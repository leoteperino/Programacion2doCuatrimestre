/*
 ============================================================================
 Name        : Biblioteca.c
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

#define QTY_REINT 2
#define QTY_MIN -999999999
#define QTY_MAX 999999999

int main(void)
{
	int getInt;
	float getFloat;
	char getChar;
	int respuestaScan;

	if(!utn_getInt(&getInt,"Ingrese un numero entero: ", "ERROR", QTY_MIN, QTY_MAX, QTY_REINT))
	{
		printf("El numero ingresado es: %d", getInt);
	}
	else
	{
		printf("\nAlgo salio mal, Se acabaron tus reintentos");
	}

	printf("\n************************************************************************************\n");

	if(!utn_getFloat(&getFloat, "Ingrese un numero decimal: ", "ERROR", 0, 100, QTY_REINT))
	{
		printf("El numero decimal ingresado es: %.2f", getFloat);
	}
	else
	{
		printf("\nAlgo salio mal, se acabaron tus reintentos");
	}

	printf("\n************************************************************************************\n");

	if(!utn_getChar(&getChar, "Ingrese una letra: ", "ERROR", 'a', 'c', QTY_REINT))
	{
		printf("la letra ingresada es: %c", getChar);
	}
	else
	{
		printf("\nAlgo salio mal, se acabaron tus reintentos");
	}

	printf("\n************************************************************************************\n");

	printf("letra: ");
	__fpurge(stdin);
	respuestaScan = scanf("%c", &getChar);
	printf("%d - %c", respuestaScan, getChar);
	return EXIT_SUCCESS;
}
