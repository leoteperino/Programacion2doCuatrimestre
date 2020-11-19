/*
 * Linkedlist.c
 *
 *  Created on: Nov 17, 2020
 *      Author: leandro
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Element.h"
#include "LinkedList.h"

/** \brief Crea un nuevo LinkedList en memoria de manera dinamica
 *  \param void
 *  \return LinkedList* Retorna (NULL) en el caso de no conseguir espacio en memoria
 *                      o el puntero al espacio reservado
 */
LinkedList* ll_newLinkedList(void)
{
	LinkedList* this = NULL;
	this = (LinkedList*)malloc(sizeof(LinkedList));
	if(this!=NULL)
	{
		this->pFirstNode = NULL;
		this->size = 0;
	}
	return this;
}

/** \brief Retorna la cantidad de elementos de la lista
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna (-1) si el puntero es NULL o la cantidad de elementos de la lista
 */
int ll_len(LinkedList* this)
{
	int ret=-1;
	if(this!=NULL)
	{
		ret = this->size;
	}
	return ret;
}

/** \brief  Obtiene un nodo de la lista
 * \param this LinkedList* Puntero a la lista
 * \param index int Indice del nodo a obtener
 * \return Node* Retorna  (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        (pNode) Si funciono correctamente
 */
Node* ll_getNode(LinkedList* this, int nodeIndex)
{
	Node* nodoDevuelto = NULL;
	int i;
	if(this!=NULL && nodeIndex>=0 && nodeIndex<ll_len(this))
	{
		if(this->pFirstNode!=NULL)
		{
			nodoDevuelto = this->pFirstNode;
			if(nodeIndex>0)
			{
				for(i=0;i<nodeIndex;i++)
				{
					nodoDevuelto = nodoDevuelto->pNextNode;
				}
			}
		}
	}
	return nodoDevuelto;
}

/** \brief Agrega y enlaza un nuevo nodo a la lista
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo nodo
 * \param pElement void* Puntero al elemento a ser contenido por el nuevo nodo
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 */
int ll_addNode(LinkedList* this, int nodeIndex,void* pElement)
{
	int returnAux = -1;
	Node* newNode = NULL;
	Node* prevNode = NULL;
	if (this!=NULL && nodeIndex>=0 && nodeIndex<=ll_len(this))
	{
		newNode = (Node*)malloc(sizeof(Node));
		printf("La direccion del nuevo nodo es: %p\n", newNode);
		if (newNode != NULL)
		{
			if(nodeIndex==0)
			{
				newNode->pNextNode = this->pFirstNode;
				printf("pNextNode: %p\n", newNode->pNextNode);
				this->pFirstNode = newNode;
				printf("LinkedList pFirstNode: %p\n", this->pFirstNode);
				newNode->pElement = pElement;
				printf("pElement: %p\n", newNode->pElement);
			}
			else
			{
				prevNode = ll_getNode(this,(nodeIndex-1));
				if(prevNode != NULL)
				{
					newNode->pNextNode = prevNode->pNextNode;
					prevNode->pNextNode = newNode;
					newNode->pElement = pElement;
				}
			}
			this->size++;
			returnAux=0;
		}
	}
	return returnAux;
}

/** \brief  Agrega un elemento al final lista
 * \param pList LinkedList* Puntero a la lista
 * \param pElement void* Puntero al elemento a ser agregado
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
int ll_add(LinkedList* this, void* pElement)
{
    int returnAux = -1;
    if(this!=NULL)
	{
		if(!ll_addNode(this,ll_len(this),pElement))
		{
			returnAux = 0;
		}
	}
    return returnAux;
}

/** \brief Elimina un nodo de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a eliminar
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int ll_remove(LinkedList* this,int index)
{
    int returnAux = -1;
    Node* pNodeToRemove = NULL;
	Node* pPrevNode = NULL;
	if (this!=NULL && index>=0 && index<ll_len(this))
	{
		pNodeToRemove = ll_getNode(this, index);
		if (pNodeToRemove!=NULL)
		{
			if (index == 0)
			{
				this->pFirstNode = ll_getNode(this,(index+1));
			}
			else
			{
				pPrevNode = ll_getNode(this,(index-1));
				if (pPrevNode != NULL)
				{
					pPrevNode->pNextNode = pNodeToRemove->pNextNode;
				}
			}
			free(pNodeToRemove);
			pNodeToRemove = NULL;
			this->size--;
			returnAux = 0;
		}
	}
    return returnAux;
}

/** \brief Elimina todos los elementos de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
int ll_clear(LinkedList* this)
{
    int returnAux = -1;
    int len;
    int i;
	if (this!=NULL)
	{
		len = ll_len(this);
		if (len > 0)
		{
			for (i=0; i<len; i++)
			{
				if(!(ll_remove(this, i)))
				{
					returnAux = 0;
				}
			}
		}
	}
    return returnAux;
}
