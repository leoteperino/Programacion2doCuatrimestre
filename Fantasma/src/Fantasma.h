#ifndef FANTASMA_H_
#define FANTASMA_H_

#define LENGTH_NOMBRE 30
#define LENGTH_APELLIDO 50
#define LENGTH_CUIT 14
#define LENGTH_ENTIDAD 100
#define TRUE 1
#define FALSE 0
#define QTY_REINT 2
#define MIN_OPTION_MENU 1
#define MAX_OPTION_MENU 10
#define MAX_OPTION_MENU_INFO 4

typedef struct
{
	int id;
	char nombre[LENGTH_NOMBRE];
	char apellido[LENGTH_APELLIDO];
	char cuit[LENGTH_CUIT];
	float precio;
	int sector;
	int isEmpty;
}Entidad;

int entidad_imprimirEntidad(Entidad* pEntidad);
int entidad_imprimirArrayEntidad(Entidad* array,int limite);
int entidad_inicializarArrayEntidad(Entidad* array,int limite);
int entidad_altaArrayEntidad(Entidad* array,int limite);
int entidad_modificarArrayEntidad(Entidad* array,int limite);
int entidad_bajaArrayEntidad(Entidad* array,int limite);
int entidad_buscarIdEntidad(Entidad* array, int limite, int valorBuscado);
int entidad_getEmptyIndexEntidad(Entidad* array,int limite);
int entidad_ordenarEntidadID(Entidad* array,int limite);
int entidad_mocksEntidad(Entidad* array,int limite, int indice, int id,char* nombre,char* apellido, char* cuit, float precio, int sector);
int entidad_ordenarEntidadDobleCriterio(Entidad* list, int len, int order);
int entidad_checkListaVacia(Entidad* list, int len);

#endif /* FANTASMA_H_ */
