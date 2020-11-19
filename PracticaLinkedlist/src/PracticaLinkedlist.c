/*
 ============================================================================
 Name        : PracticaLinkedlist.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Element.h"
#include "LinkedList.h"

int main(void) {

	LinkedList* linkedList;
	int sizeLL;
	Node* nodo;
	Element* pElemento;

	linkedList = ll_newLinkedList();
	printf("Creo una LinkedList: \n");
	printf("la direccion de la LinkedList es: %p\n", linkedList);
	printf("pFirstnode: %p\nsize: %d\n",linkedList->pFirstNode, linkedList->size);
	printf("##########################################################\n");
	sizeLL = ll_len(linkedList);
	printf("La cantidad de elementos de la lista es: %d\n", sizeLL);
	printf("##########################################################\n");
	printf("Todavia no hay nodos creados: \n");
	nodo = ll_getNode(linkedList, 0);
	printf("La direccion al Nodo 0 es: %p\n", nodo);
	printf("##########################################################\n");
	printf("Agrego un elemento: \n");
	pElemento = element_new();
	printf("la direccion del nuevo elemento es: %p\n", pElemento);
	printf("##########################################################\n");
	printf("Agregamos un Nodo a la lista: \n");
	ll_addNode(linkedList, 0, pElemento);
	nodo = ll_getNode(linkedList, 0);
	printf("La direccion al Nodo 0 es: %p\n", nodo);
	printf("##########################################################\n");
	printf("Agregamos un nuevo Nodo con un nuevo elemento al final de la lista: \n");
	pElemento = element_new();
	printf("la direccion del nuevo elemento es: %p\n", pElemento);
	ll_add(linkedList, pElemento);
	printf( "Ingresamos en la LinkedList:\n"
			"size: %d nodos\n"
			"pFirstNode:%p\n",
			ll_len(linkedList),
			linkedList->pFirstNode);
	nodo = ll_getNode(linkedList, 0);
	printf( "Ingresamos al Nodo 0:\n"
			"pElement=%p\n"
			"pNextNode=%p\n",
			nodo->pElement,
			nodo->pNextNode);
	nodo = ll_getNode(linkedList, 1);
	printf( "Ingresamos al Nodo 1:\n"
			"pElement=%p\n"
			"pNextNode=%p\n",
			nodo->pElement,
			nodo->pNextNode);
	printf("##########################################################\n");
	printf("Removemos el Primer Nodo.\n");
	if(!ll_remove(linkedList, 0))
	{
		printf("OK\n");
	}
	printf( "Ingresamos en la LinkedList:\n"
				"size: %d nodos\n"
				"pFirstNode:%p\n",
				ll_len(linkedList),
				linkedList->pFirstNode);
	printf("##########################################################\n");
	printf("Removemos todos los Nodos de la lista.\n");
	if(!ll_clear(linkedList))
	{
		printf("OK\n");
	}
	printf( "Ingresamos en la LinkedList:\n"
				"size: %d nodos\n"
				"pFirstNode:%p\n",
				ll_len(linkedList),
				linkedList->pFirstNode);
	return EXIT_SUCCESS;
}
