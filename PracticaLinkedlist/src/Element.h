/*
 * Nodo.h
 *
 *  Created on: Nov 18, 2020
 *      Author: leandro
 */

#ifndef ELEMENT_H_
#define ELEMENT_H_

#define SIZE_NAME 32

typedef struct
{
    int id;
    char nombre[SIZE_NAME];
}Element;

Element* element_new(void);

#endif /* ELEMENT_H_ */
