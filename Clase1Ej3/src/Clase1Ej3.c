/*
 ============================================================================
 Name        : Clase1Ej3.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdio_ext.h>

int main(void) {
	int a;
	int b;
	int resultado;

	do{
		printf("\nIngrese 1 numero distinto de 0: ");
		scanf("%d",&a);
	}while(a == 0);

	do{
		printf("\nIngrese otro numero distinto de 0: ");
		scanf("%d",&b);
	}while(b == 0);

	resultado=a-b;

	printf("______________________________________\n");
	printf("\nEl resultado es: %d \n",resultado);
	if(resultado >= 0){
		printf("\nResultado positivo \n");
	}
	if(resultado < 0){
		printf("\nResultado negativo \n");
	}
	printf("______________________________________\n\n\n\n");

	return EXIT_SUCCESS;
}
