/*
 ============================================================================
 Name        : MemoriaDinamica2.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

//Defino la estructura Cliente
typedef struct{
	int id;
	char name[32];
}Cliente;

int main(void){


	/*
	 * Defino una variable pCliente del tipo puntero a Cliente
	 * Lo bueno de esto es que esta es una varieble del tipo
	 * puntero que es dinamica, ya que alli yo voy a guardar
	 * una direccion de memoria a la cual le puedo meter un
	 * free en cualquier momento y liberar esa memoria.
	 * Esto lo hago para poder guardar la direccion de memoria
	 * con la cual podre acceder luego a la primer posicion del
	 * Cliente.
	 */
	Cliente* pCliente;

	/*
	 * Pido memoria para guardar un solo cliente
	 * El Malloc me devuelve la direccion de memoria que un puntero
	 * a void (void*), por esta razon casteamos a (Cliente*) porque
	 * esa direccion la voy a guardar en un puntero a Cliente para
	 * poder acceder luego.
	 */
	pCliente = (Cliente*)malloc(sizeof(Cliente));
	printf("La direccion de memoria del Cliente es: %p\n", pCliente);

	/*
	 * De esta forma puedo acceder a los campos de la entidad
	 * Se usa la notacion de flecha, recordar que estamos usando
	 * la direccion de memoria para acceder a esos campos y por
	 * esto usamos esta notacion.
	 */
	pCliente->id=100;
	pCliente->name[0]='L';
	printf("ID: %d - Name: %s\n",pCliente->id,pCliente->name);

	return EXIT_SUCCESS;
}
