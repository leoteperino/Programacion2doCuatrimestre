/*
 ============================================================================
 Name        : Punteros_a_funcion.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

//Genero un tipo de dato para hacer referencia al puntero al prototipo del puntero a funcion
typedef int(*tpfSaludar)(char*, int);

//Punteros a Funcion
void saludar()
{
	printf("Hola\n");
}

//Punteros a funcion como parametros
void sumar(int a, int b, int* pResultado)
{
	*pResultado = a + b;
}

void restar(int a, int b, int* pResultado)
{
	*pResultado = a - b;
}

//Funcion calcular, que recibe como parametro un puntero a funcion.
int calcular(int a, int b, void(*pFuncion)(int,int,int*))
{
	int auxResultado;
	pFuncion(a,b,&auxResultado);
	return auxResultado;
}

int saludarEsp(char* mensaje, int numero)
{
	printf("Hola %s - %d\n", mensaje, numero);
	return 0;
}

int saludarIng(char* mensaje, int numero)
{
	printf("Hello %s - %d\n", mensaje, numero);
	return 0;
}

//Funcion saludo que recibe como parametro el puntero a funcion
void saludo(char* mensaje, int numero, tpfSaludar pFuncSaludar)
{
	pFuncSaludar(mensaje, numero);
}

int main(void) {
	void(*pFuncion)(void); //Recibo el puntero a la funcion
	pFuncion = saludar; //Igualo el puntero a la funcion
	printf("%p\n", pFuncion); //Direccion de memoria de la funcion
	pFuncion(); //ejecuto la funcion desde su puntero.

	//Punteros a funcion como parametros
	printf("**********************************************\n");
	printf("Punteros a funcion como parametros:\n");

	int auxiliar;
	auxiliar = calcular(10, 5, restar);
	printf("la resta es: %d\n", auxiliar);

	auxiliar = calcular(10, 5, sumar);
	printf("la suma es: %d\n", auxiliar);
	printf("**********************************************\n");
	saludo("Leandro",41,saludarEsp);
	saludo("Leonard",22,saludarIng);

	return EXIT_SUCCESS;
}
