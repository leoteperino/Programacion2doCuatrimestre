/*
 * Nodo.c
 *
 *  Created on: Nov 18, 2020
 *      Author: leandro
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Element.h"
#include "LinkedList.h"

Element* element_new(void)
{
    return (Element*)malloc(sizeof(Element));
}


