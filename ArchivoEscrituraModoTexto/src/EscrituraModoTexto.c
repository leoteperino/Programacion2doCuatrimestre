/*
 ============================================================================
 Name        : EscrituraModoTexto.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

typedef struct{
	char name[32];
	int edad;
}Empleado;

int main(void) {
	Empleado emp;
	sprintf(emp.name, "leandro");
	emp.edad = 41;
	FILE* fp = fopen("modoTexto.txt","w");
	if(fp!=NULL)
	{
		/*fprintf() es para escribir en modo texto*/
		fprintf(fp,"%s %d", emp.name, emp.edad);
		fclose(fp);
	}
	return EXIT_SUCCESS;
}
