/*
 ============================================================================
 Name        : Archivos.c
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
	/*-----------Escribir archivos---------*/
	//Declaro una variable del tipo Empleado
	Empleado emp;
	/*
	 * Cargo datos en mu estructura Empleado
	*/
	emp.edad=41;
	sprintf(emp.name, "leandro");
	/*
	 * Declaro una variable que es un puntero a FILE
	 * Este puntero es el que va a apuntar a la direccion de memoria donde va
	 * a estar guardado mi archivo y asi voy a poder acceder al mismo.
	 */
	FILE* fp;
	/*
	 *Con fopen creo el archivo que quiero escribir
	 *Si el archivo no existe, lo crea y si este existe lo destruye y lo
	 *vuelve a crear, se borra todo lo que hay dentro del mismo, el parametro
	 *'W' indica que el archivo lo abre o crea para operaciones de lectura
	 */
	fp = fopen("primerArchivo.b","w");

	if(fp!=NULL)
	{
		/*
		 * Con fwrite escribo en el archivo, en este caso le voy pasar el Emleado
		 */
		fwrite(&emp,sizeof(Empleado),1,fp);

		//Cierro el archivo despues de usarlo siempre.
		fclose(fp);
	}
	return EXIT_SUCCESS;
}
