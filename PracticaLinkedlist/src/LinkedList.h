/*
 * LinkedList.h
 *
 *  Created on: Nov 17, 2020
 *      Author: leandro
 */

#ifndef LINKEDLIST_H_
#define LINKEDLIST_H_

struct Node
{
    void* pElement;                 //puntero al elemento (persona, empleado, etc.)
    struct Node* pNextNode;         //puntero al prox nodo
}typedef Node;

struct LinkedList
{
    Node* pFirstNode;
    int size;                       //cada vez que agrego o elimino un elemento size++/--
}typedef LinkedList;


#endif /* LINKEDLIST_H_ */

//Publicas
LinkedList* ll_newLinkedList(void);
int ll_len(LinkedList* this);                                       //devuelve el valor del campo int size
Node* ll_getNode(LinkedList* this, int nodeIndex);
int ll_addNode(LinkedList* this, int nodeIndex,void* pElement);
int ll_add(LinkedList* this, void* pElement);
int ll_remove(LinkedList* this,int index);
int ll_clear(LinkedList* this);
