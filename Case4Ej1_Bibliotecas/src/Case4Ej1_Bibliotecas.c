/*
 ============================================================================
 Name        : Case4Ej1_Bibliotecas.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdio_ext.h>
#include "utn.h"

int main(void) {
	//Ejemplo de armado de Bibliotecas.
	/*
	 * Se deben generar dos archivos utn.h y utn.c
	 * En el archivo utn.c vamos a colocar todas las funciones
	 * En el archivo utn.h vam,os a colocar todos los prototipos
	 * En este archivo solo estara el main
	 * Tener en cuenta que todas las bibliotecas que se usan en-
	 * este archivo deben estar en el .c tambien  incluidas.
	 * En esta archivo se debe incluir el archivo.h #include "utn.h"
	 * En el utn.h no se debe incluir nada, ya que el mismo se vincula con el .c
	 * porque tienen el mismo nombre-Siempre deben tener el miimo nombre.
	 * Esto sirve para modularizar nuestro codigo, mas facil de leer, mas facil de
	 * depurar y mas ordenado
	 * Tambien esto nos permite reutilizar esta biblioteca en otro codigo u
	 * otro proyecto.
	 * */
	utn_saludar();

	return EXIT_SUCCESS;
}
