#ifndef con_H_
#define con_H_

#define LENGTH_ARCHIVO 50
#define LENGTH_CUIT 14
#define MIN_DIAS 1
#define MAX_DIAS 360
#define LENGTH_CONT 1000

typedef struct
{
	int id;
	char cuitCliente[LENGTH_CUIT];
	int cantDias;
	char nombreArchivo[LENGTH_ARCHIVO];
	int idPantalla;
	int isEmpty;
}Contratacion;

int con_imprimirContratacion(Contratacion* pContratacion);
int con_imprimirArrayContratacion(Contratacion* array,int limite);
int con_inicializarArrayContratacion(Contratacion* array,int limite);
int con_altaArrayContratacion(Contratacion* array,int limite);
int con_modificarArrayContratacion(Contratacion* array,int limite);
int con_bajaArrayContratacion(Contratacion* array,int limite);
int con_buscarIdContratacion(Contratacion* array, int limite, int valorBuscado);
int con_getEmptyIndexContratacion(Contratacion* array,int limite);
int con_ordenarContratacionID(Contratacion* array,int limite);
int con_mocksContratacion(Contratacion* array,int limite, int indice, int id,char* cuitCliente,int cantDias, char* nombreArchivo, int idPantalla);
int con_ordenarContratacionDobleCriterio(Contratacion* list, int len, int order);

#endif /* con_H_ */
