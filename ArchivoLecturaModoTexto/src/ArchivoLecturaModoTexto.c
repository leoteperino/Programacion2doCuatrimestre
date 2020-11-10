/*
 ============================================================================
 Name        : ArchivoLecturaModoTexto.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void){

	int num;
	char nombre[32];
	char texto[64];
	//para leer los empleados
	char cadena1[32];
	char cadena2[32];
	char cadena3[32];

	int respuesta;
	FILE* fp = fopen("modoTexto.txt","r");
	FILE* fp2 = fopen("modoTexto2.b","r");
	FILE* fp3 = fopen("modoTexto3.txt","r");
	FILE* fp4 = fopen("modoTexto4.txt","r");
	if(fp!=NULL)
	{

		//Nuestro archivo modoTexto.txt contiene el numero 41
		//fscanf nos va a devolver 0 si no leyo, y la cantidad de variables que
		//pudo escribir si leyo.
		//fscanf termina colocando en una variable el valor retornado
		respuesta = fscanf(fp,"%d",&num);
		printf("fscanf devuelve:%d y lee:%d\n",respuesta,num);
		fclose(fp);

		//Ahora voy a leer el archivo modoTexto2 que solo contiene la
		//palabra Leandro.
		//En este caso el %s tambien va a leer numeros, ya el archivo
		//es texto, pero el %d no me va a leer letras.
		respuesta = fscanf(fp2,"%s",nombre);
		printf("fscanf devuelve:%d y lee:%s\n",respuesta,nombre);
		fclose(fp2);

		//Ahora voy a leer el modoTexto3.txt que contiene un texto
		//formado por letras y espacios
		//con el %s solo puedo leer letras, pero no puedo leer espacios
		//entonces debemos definir un grupo para indicar lo que queremos
		//leer.
		respuesta = fscanf(fp3,"%[a-zA-Z ]",texto);
		printf("fscanf devuelve:%d y lee:%s\n",respuesta,texto);
		fclose(fp3);

		//El archivo modoTexto4 tiene datos separados por , y finaliza
		//cada linea con un \n salto de linea, cada linea representa a un
		//empleado, vamos a leer cada empleado.
		//Para eso le pedimos que lea toodo lo que encuentra menos una coma
		//que luego se encuentra con una coma y que lea toodo hasta llegar
		//de eso modo al \n
		//%[^,], -> lee toodo meno la coma, despues lee la coma, lo que esta
		//adentro del % me lo guardo para mostrar, el resto solo lo lee.
		//a esto se lo llama clases.

//		fscanf(fp4,"%[^,],%[^,],%[^\n]\n", cadena1,cadena2,cadena3);
//		printf("Empleado 1:%s - %s - %s\n",cadena1,cadena2,cadena3);
//
//		fscanf(fp4,"%[^,],%[^,],%[^\n]\n", cadena1,cadena2,cadena3);
//		printf("Empleado 2:%s - %s - %s\n",cadena1,cadena2,cadena3);
//
//		fscanf(fp4,"%[^,],%[^,],%[^\n]\n", cadena1,cadena2,cadena3);
//		printf("Empleado 3:%s - %s - %s\n",cadena1,cadena2,cadena3);

		//vamos a hacer lo de arriba bien hecho
		//Vamos a recorrer el archivo con un bucle do While, ya que no sabemos
		//cuando termina
		//Siempre que leemos un archivo en modo lectura el sistema nos da un
		//flag llemado EOF(end of file) que nos coloca un flag en el final del
		//archivo y si es el final nos devuelve 1.
		//Lee siempre que feof sea igual a 0, cuando cambia es que llego al final
		//y no lee mas.
		printf("Leer con un Bucle: \n");
		do
		{
			respuesta = fscanf(fp4,"%[^,],%[^,],%[^\n]\n", cadena1,cadena2,cadena3);
			//con esto verificamos que haya leido bien, que le archivo no este roto
			if(respuesta==3)
			{
				printf("Empleado: %s - %s - %s\n",cadena1,cadena2,cadena3);
			}
			else
			{
				printf("No se pudo seguir leyendo el archivo.\n");
				break;
			}
		}while(feof(fp4)==0);

		fclose(fp4);
	}
	return EXIT_SUCCESS;
}
