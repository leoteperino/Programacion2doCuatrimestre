/*
 ============================================================================
 Name        : Archivos2.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
 * Genero una estructura Empleado que es lo que voy a escribir en
 * el archivo
*/
typedef struct{
	char name[8];
	int edad;
}Empleado;

int main(void) {
	/*****************Leer archivos************************/
	Empleado emp;
	/*
	 En esta instancia el archivo ya esta escrito con los datos de un
	 empleado, ahora vamos a abrirlo de nuevo pero en modo de lectura
	 para poder leer desde el archivo los datos cargados y mostrarlos
	 por pantalla.
	 volvemos a abrir el archivo pero esta vez en el modo read "r"
	*/
	FILE* fp = fopen("primerArchivo.b","r");
	if(fp!=NULL)
	{
		/*El comando para leer el archivo es fread*/
		fread(&emp,sizeof(Empleado),1,fp);
		printf("Empleado: \n");
		printf("Nombre: %s - Edad: %d\n", emp.name, emp.edad);
		fclose(fp);
	}
	return EXIT_SUCCESS;
}
