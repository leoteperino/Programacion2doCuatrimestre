/*
 ============================================================================
 Name        : RepasoClases1y2.c
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
//	- Asigne a las variables numero1 y numero2 los valores obtenidos
//	- Realice la resta de dichas variables
//	- Muestre el resultado por pantalla
//	int numero1;
//	int numero2;
//	int resta;
//
//	printf("Ingrese un numero: ");
//	__fpurge(stdin);
//	scanf("%d", &numero1);
//
//	printf("Ingrese un numero: ");
//	__fpurge(stdin);
//	scanf("%d", &numero2);
//
//	resta = numero1 - numero2;
//	printf("la resta de los numeros ingresados es: %d", resta);
//

	/******************************************************************/
	/******************************************************************/

//	- Solicite dos valores numéricos al usuario distintos de cero *
//	- Asigne a las variables numero1 y numero2 los valores obtenidos
//	- Realice la resta de dichas variables
//	- Muestre el resultado por pantalla
//	- Muestre por pantalla la leyenda "Resultado positivo" en caso de ser mayor *
//	- Muestre por pantalla la leyenda "Resultado negativo" si es menor que cero *

//	int numero1;
//	int numero2;
//	int resta;
//	int resScanf;
//
//	do
//	{
//		printf("Ingrese un numero distinto de cero: ");
//		__fpurge(stdin);
//		resScanf = scanf("%d", &numero1);
//	}
//	while(numero1==0 || resScanf==0);
//
//	do
//	{
//		printf("Ingrese otro numero distinto de cero: ");
//		__fpurge(stdin);
//		resScanf = scanf("%d", &numero2);
//	}
//	while(numero2==0 || resScanf==0);
//
//	resta = numero1 - numero2;
//	printf("la resta de los numeros ingresados es: %d", resta);
//	if(resta<0)
//	{
//		printf("\nResultado Negativo.");
//	}
//	else
//	{
//		printf("\nResultado Positivo.");
//	}

	/******************************************************************/
	/******************************************************************/

//	- Solicite al usuario 10 números
//	- Calcule cuántos son negativos y cuantos son positivos
//	- Muestre por pantalla la cantidad de negativos y la cantidad de positivos

//	int numerosIngresados;
//	int contadorNegativos = 0;
//	int contadorPositivos = 0;
//	int i = 0;

	//Utilizandso for--Si sabemos la cantidad de veces que queremos iterar se debe utilizar for
//	for(i=0; i<10; i++)
//	{
//		printf("Ingrese el numero (%d): ", i+1);
//		__fpurge(stdin);
//		scanf("%d", &numerosIngresados);
//
//		if(numerosIngresados>=0)
//		{
//			contadorPositivos++;
//		}
//		else
//		{
//			contadorNegativos++;
//		}
//	}

	//Utilizando While
//	while(i<10)
//	{
//		printf("Ingrese el numero (%d): ", i+1);
//		__fpurge(stdin);
//		scanf("%d", &numerosIngresados);
//
//		if(numerosIngresados>=0)
//		{
//			contadorPositivos++;
//		}
//		else
//		{
//			contadorNegativos++;
//		}
//		i++;
//	}
//
//	printf("La cantidad de positivos ingresados es: %d", contadorPositivos);
//	printf("\nLa cantidad de negativos ingresados es: %d", contadorNegativos);

	/******************************************************************/
	/******************************************************************/

//	-Solicite 5 numeros
//	-mostrar el promedio

//	int numerosIngresados;
//	int qty_numeros = 5;
//	int i;
//	float promedio;
//	int acumulador = 0;
//	int resScanf;
//
//	for(i=0; i<qty_numeros; i++)
//	{
//		do
//		{
//			printf("Ingrese el numero(%d): ",i+1);
//			__fpurge(stdin);
//			resScanf = scanf("%d", &numerosIngresados);
//		}while(resScanf==0);
//		acumulador+=numerosIngresados;
//	}
//
//	promedio = (float)acumulador/qty_numeros;
//	printf("El promedio de los numeros ingresados es: %.2f", promedio);

	/******************************************************************/
	/******************************************************************/

//	Realizar un programa que solicite cinco números e imprima por pantalla el promedio, el máximo y el mínimo.

//	int numerosIngresados;
//	int qty_numeros = 5;
//	float promedio;
//	int acumulador = 0;
//	int maximo;
//	int minimo;
//	int resScanf;
//	int i;
//
//	do
//	{
//		printf("Ingrese un numero(1):");
//		__fpurge(stdin);
//		resScanf = scanf("%d", &numerosIngresados);
//		acumulador = numerosIngresados;
//		maximo = numerosIngresados;
//		minimo = numerosIngresados;
//	}while(resScanf == 0);
//
//	for(i=1; i<qty_numeros; i++)
//	{
//		do
//		{
//			printf("Ingrese un numero(%d):", i+1);
//			__fpurge(stdin);
//			resScanf = scanf("%d", &numerosIngresados);
//		}while(resScanf == 0);
//
//		acumulador+=numerosIngresados;
//
//		if(numerosIngresados > maximo)
//		{
//			maximo = numerosIngresados;
//		}
//		if(numerosIngresados < minimo)
//		{
//			minimo = numerosIngresados;
//		}
//	}
//
//	promedio = (float)acumulador/qty_numeros;
//	printf("Promedio %.2f", promedio);
//	printf("\nMaximo: %d", maximo);
//	printf("\nMinimo: %d", minimo);

	/******************************************************************/
	/******************************************************************/

//	Solicite numeros hasta el 999 y luego muestre el promedio, la suma, el maximo, el minimo, la suma de todos
//	los positivos, la suma de todos los negativos, cuantos positivos, cuantos negativos.

	int numerosIngresados = 0;
	float promedio;
	int contadorTotal = 0;
	int acumulador = 0;
	int maximo;
	int minimo;
	int acumPositivos = 0;
	int acumNegativos = 0;
	int contadorPositivos = 0;
	int contadorNegativos = 0;
	int flag = 1;

	while(numerosIngresados != 999)
	{
		printf("Ingrese un Numero: ");
		__fpurge(stdin);
		scanf("%d", &numerosIngresados);
		if(numerosIngresados!=999)
		{
			contadorTotal++;
			acumulador+=numerosIngresados;
			if(flag)
			{
				flag = 0;
				maximo = numerosIngresados;
				minimo = numerosIngresados;
			}

			if(numerosIngresados > maximo)
			{
				maximo = numerosIngresados;
			}
			if(numerosIngresados < minimo)
			{
				minimo = numerosIngresados;
			}
			if(numerosIngresados>0)
			{
				contadorPositivos++;
				acumPositivos+=numerosIngresados;
			}
			if(numerosIngresados<0)
			{
				contadorNegativos++;
				acumNegativos+=numerosIngresados;
			}
		}
	}

	promedio = (float)acumulador/contadorTotal;

	printf("\nMaximo: %d", maximo);
	printf("\nMinimo: %d", minimo);
	printf("\nla suma de todos los numeros ingresados es: %d", acumulador);
	printf("\nPromedio: %.2f", promedio);
	printf("\nPositivos Ingresados: %d", contadorPositivos);
	printf("\nNegativos Ingresados: %d", contadorNegativos);
	printf("\nla suma de todos los positivos es: %d", acumPositivos);
	printf("\nla suma de todos los negativos es: %d", acumNegativos);
	return EXIT_SUCCESS;
}
