#ifndef CONTRATACION_H_
#define CONTRATACION_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdio_ext.h>
#include "Contratacion.h"
#include "utn.h"
#include "Pantalla.h"

#define LENGTH_CUIT 14
#define LENGTH_ARCHIVO 50

typedef struct
{
	int id;
	char cuitCliente[LENGTH_CUIT];
	int dias;
	char nombreArchivo[LENGTH_ARCHIVO];
	int idPantalla;
	int isEmpty;
}Contratacion;

int cont_imprimirContratacion(Contratacion* pContratacion);
int cont_imprimirArrayContratacion(Contratacion* array,int limite);
int cont_inicializarArrayContratacion(Contratacion* array,int limite);
int cont_altaArrayContratacion(Contratacion* array,int limite, int idPantalla);
int cont_modificarArrayContratacion(Contratacion* array,int limite, int indice);
int cont_bajaArrayContratacion(Contratacion* arrayCont,int limiteCont,Pantalla* arrayPan,int limitePan,int idPantalla);
int cont_buscarIdContratacion(Contratacion* array, int limite, int valorBuscado);
int cont_getEmptyIndexContratacion(Contratacion* array,int limite);
int cont_ordenarContratacionID(Contratacion* array,int limite);
int cont_mocksContratacion(Contratacion* array,int limite, int indice, int id,char* cuitCliente,int dias, char* nombreArchivo, int idPantalla);
int cont_ordenarContratacionDobleCriterio(Contratacion* list, int len, int order);
int cont_checkListaVacia(Contratacion* list, int len);
int cont_listarPantallasContratadas(Contratacion* arrayCont,int limiteCont,Pantalla* arrayPan,int limitePan,int id);
int cont_listarClientesPorCuit(Contratacion* arrayCont,int limiteCont,char* cuit);
int cont_bajaArrayContratacionID(Contratacion* array,int limite,int indice);
int cont_consultarFacturacion(Contratacion* arrayCont,int limiteCont,Pantalla* arrayPan,int limitePan,char* cuit);
int cont_buscarContratacionChar(Contratacion* array, int limite, char* valorBuscado);
int cont_listarContrataciones(Contratacion* arrayCont,int limiteCont,Pantalla* arrayPan,int limitePan);
int cont_listarClientes(Contratacion* arrayCont,int limiteCont,Pantalla* arrayPan,int limitePan);

#endif /* CONTRATACION_H_ */
