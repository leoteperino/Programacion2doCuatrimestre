/*
 ============================================================================
 Name        : Clase3Ej3.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int suma(int num1, int num2);

int main(void) {
	int num1 = 10;
	int num2 = 10;
	int result;

	result = suma(num1, num2);
	printf("%d", result);
	return EXIT_SUCCESS;
}

int suma(int num1, int num2)
{
	int result;
	result = num1 + num2;
	return result;
}
