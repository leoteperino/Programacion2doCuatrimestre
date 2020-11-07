/*
 ============================================================================
 Name        : MemoriaDinamica3.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//genero la estructura Cliente
typedef struct{
	int id;
	char name[32];
}Cliente;

/*
 * Funcion que pide memoria para generar un Cliente
 * lo carga con los valores pasados por parametro.
 */
Cliente* cli_newConParametros(int id, char* name)
{
	/*
	 * Declaro el puntero que voy a devolver
	 * Lo igualo a NULL para que no quede cargado con basura
	 */
	Cliente* pCliente=NULL;
	if(id>=0 && name!=NULL)
	{
		pCliente=(Cliente*)malloc(sizeof(Cliente));
		if(pCliente!=NULL)
		{
			pCliente->id=id;
			strncpy(pCliente->name,name,sizeof(pCliente->name));
		}
	}
	return pCliente;
}
int main(void) {
	/*
	 * Declaro la variable del tipo puntero Cliente donde guardo
	 * la direccion de memoria donde va a estar alojado ese cliente
	 */
	Cliente* pCliente;
	Cliente* pCliente1;
	Cliente* pCliente2;

	pCliente=cli_newConParametros(0,"leandro");
	pCliente1=cli_newConParametros(1,"Ernesto");
	pCliente2=cli_newConParametros(2,"Mauricio");
	printf("ID:%d - Name:%s\n",pCliente->id,pCliente->name);
	printf("ID:%d - Name:%s\n",pCliente1->id,pCliente1->name);
	printf("ID:%d - Name:%s\n",pCliente2->id,pCliente2->name);

	return EXIT_SUCCESS;
}
