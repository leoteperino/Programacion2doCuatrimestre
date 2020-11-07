/*
 ============================================================================
 Name        : MemoriaDinamica.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

//Generamos una funcion para Inicializar los valores del Array
int initArray(int* pArray, int limite, int valor)
{
	int retorno=-1;
	int i;
	if(pArray!=NULL && limite>0)
	{
		retorno=0;
		for(i=0;i<limite;i++)
		{
			//aqui se utiliza Algebra de punteros
			*(pArray+i)=valor; // Esto es lo mismo que decir pArray[i]=valor;
		}
	}
	return retorno;
}

//Imprimimos el Array
int imprimirArray(int* pArray, int limite)
{
	int retorno=-1;
	int i;
	if(pArray!=NULL && limite>0)
	{
		retorno=0;
		for(i=0;i<limite;i++)
		{
			printf("%d\n", *(pArray+i));
		}
	}
	return retorno;
}

//Pido mas memoria
int resizeArray(int** pArray, int* sizeActual, int sizeNuevo)
{
	int* pArrayTemp=NULL;
	int retorno=-1;
	if(pArray!=NULL && sizeActual!=NULL && sizeNuevo>=0)
	{
		pArrayTemp=(int*)realloc(*pArray,sizeof(int)*sizeNuevo);
		if(pArrayTemp!=NULL)
		{
			*sizeActual+=sizeNuevo;
			*pArray=pArrayTemp;
			pArrayTemp=NULL;
			retorno=0;
		}
	}
	return retorno;
}

int main(void) {
	//Declaro un puntero int, que es donde guardo lo que me devuelve malloc
	//Lo igualo a NULL por si tiene basura guardada.
	int* pArrayEdades=NULL;
	int sizeArrayEdades=10;
	//Pido memoria para guardar un array de 10 int
	/*Casteo a int* el resultado de malloc, ya que este me devuelve
	 * un puntero a void y lo estoy guardando en un puntero a int
	 */
	pArrayEdades=(int*)malloc(sizeof(int)*sizeArrayEdades);
	//Si la direccion devuelta es NULL es porque no encontro lugar en memoria
	if(pArrayEdades!=NULL)
	{
		if(!initArray(pArrayEdades, sizeArrayEdades, 0))
		{
			printf("INIT OK\n");
			imprimirArray(pArrayEdades, sizeArrayEdades);
		}

		/*
		 * Asi pido mas memoria, pero luego la pedimos a traves de una funcion.
		pArrayTemp=(int*)realloc(pArrayEdades,sizeof(int)*(sizeArrayEdades+10));
		if(pArrayTemp!=NULL)
		{
			sizeArrayEdades+=10;
			pArrayEdades=pArrayTemp;
			pArrayTemp=NULL;
			imprimirArray(pArrayEdades, sizeArrayEdades);
		}
		*/

		if(!resizeArray(&pArrayEdades, &sizeArrayEdades, 10))
		{
			printf("RESIZE OK\n");
			imprimirArray(pArrayEdades, sizeArrayEdades);
		}

	}
	return EXIT_SUCCESS;
}
