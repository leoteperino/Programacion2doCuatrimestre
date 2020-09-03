/*
 ============================================================================
 Name        : Clase3Ej2.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 Crear una función que permita ingresar un numero al usuario y lo retorne.
 Crear una función que reciba el radio de un círculo y retorne su área.
 Utilizar las funciones de los puntos 1 y 2 para hacer un programa que calcule
 el área de un círculo cuyo radio es ingresado por el usuario. Documentar las
 funciones al estilo Doxygen.
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdio_ext.h>
#define PI 3.14

float getFloat(void);
float calcularAreaCirculo(float radio);

int main(void) {
	float numeroIngresado;
	float area;

	numeroIngresado = getFloat();
	area = calcularAreaCirculo(numeroIngresado);
	printf("%.2f", area);

	return EXIT_SUCCESS;
}

float getFloat(void)
{
	float numeroIngresado;
	printf("Ingrese un numero: ");
	__fpurge(stdin);
	scanf("%f", &numeroIngresado);
	return numeroIngresado;
}

float calcularAreaCirculo(float radio)
{
	float area;
	area = PI * (radio * radio);
	return area;
}
