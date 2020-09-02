/*
 ============================================================================
 Name        : Clase3Ej1.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

/*Pedir dos numeros al usuario, verificar que sean numeros y no letras y
 * hacer la suma, resta, multiplicacion y division de esos numeros*/
#include <stdio.h>
#include <stdlib.h>
#include <stdio_ext.h>

int suma(float numero1, float numero2, float *pResultado);
int resta(float numero1, float numero2, float *pResultado);
int multiplicacion(float numero1, float numero2, float *pResultado);
int division(float numero1, float numero2, float *pResultado);

int main(void)
{
	float numero1;
	float numero2;
	int resScanf;
	float resultado;

	printf("Ingrese un numero: ");
	__fpurge(stdin);
	resScanf = scanf("%f", &numero1);
	while(resScanf == 0)
	{
		printf("ERROR, usted no Ingreso un Número.\n");
		printf("Ingrese un numero: ");
		__fpurge(stdin);
		resScanf = scanf("%f", &numero1);
	}

	printf("Ingrese un numero: ");
	__fpurge(stdin);
	resScanf = scanf("%f", &numero2);
	while(resScanf == 0)
	{
		printf("ERROR, usted no Ingreso un Número.\n");
		printf("Ingrese un numero: ");
		__fpurge(stdin);
		resScanf = scanf("%f", &numero2);
	}

	if (!suma(numero1, numero2, &resultado))
	{
		printf("\nSuma: %.f", resultado);
	}

	if (!resta(numero1, numero2, &resultado))
	{
		printf("\nResta: %.f", resultado);
	}
	if (!multiplicacion(numero1, numero2, &resultado))
	{
		printf("\nMultiplicacion: %.f", resultado);
	}

	if (!division(numero1, numero2, &resultado))
	{
		printf("\nDivision: %.2f", resultado);
	}
	else
	{
		printf("\nNo es posible dividir por el numero 0");
	}

	return EXIT_SUCCESS;
}

int suma(float numero1, float numero2, float *pResultado)
{
	*pResultado = numero1 + numero2;
	return 0;
}

int resta(float numero1, float numero2, float *pResultado)
{
	*pResultado = numero1 - numero2;
	return 0;
}

int multiplicacion(float numero1, float numero2, float *pResultado)
{
	*pResultado = numero1 * numero2;
	return 0;
}

int division(float numero1, float numero2, float *pResultado)
{
	*pResultado = numero1 / numero2;
	if(numero2 == 0)
	{
		return -1;
	}
	else
	{
		return 0;
	}
}
