/*
 ============================================================================
 Name        : Clase1Ej4.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================

 Escribir un programa que realice las siguientes acciones:
    - Solicite al usuario 10 números
    - Calcule cuántos son negativos y cuantos son positivos
    - Muestre por pantalla la cantidad de negativos y la cantidad de positivos
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdio_ext.h>

#define CANT_NUM 10

int main(void) {

	int numerosIngresados;
	int contadorNegativos = 0;
	int contadorPositivos = 0;
	int i;

	for(i=0;i<CANT_NUM;i++){
		printf("Ingrese el numero %d: ", i+1);
		__fpurge(stdin);
		scanf("%d", &numerosIngresados);

		if(numerosIngresados >= 0){
			contadorPositivos++;
		}else{
			contadorNegativos++;
		}
	}

	printf("La cantiad de numeros negativos es: %d", contadorNegativos);
	printf("\nLa cantiad de numeros positivos es: %d", contadorPositivos);

	return EXIT_SUCCESS;
}
