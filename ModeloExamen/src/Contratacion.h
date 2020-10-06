#ifndef CONTRATACION_H_
#define CONTRATACION_H_

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
int cont_altaArrayContratacion(Contratacion* array,int limite);
int cont_modificarArrayContratacion(Contratacion* array,int limite);
int cont_bajaArrayContratacion(Contratacion* array,int limite);
int cont_buscarIdContratacion(Contratacion* array, int limite, int valorBuscado);
int cont_getEmptyIndexContratacion(Contratacion* array,int limite);
int cont_ordenarContratacionID(Contratacion* array,int limite);
int cont_mocksContratacion(Contratacion* array,int limite, int indice, int id,char* cuitCliente,int dias, char* nombreArchivo, int idPantalla);
int cont_ordenarContratacionDobleCriterio(Contratacion* list, int len, int order);
int cont_checkListaVacia(Contratacion* list, int len);

#endif /* CONTRATACION_H_ */
