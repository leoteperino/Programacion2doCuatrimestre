#ifndef pan_H_
#define pan_H_

#define LENGTH_NOMBRE 50
#define LENGTH_DIRECCION 60
#define TRUE 1
#define FALSE 0
#define QTY_REINT 2
#define MIN_TIPO 1
#define MAX_TIPO 2
#define LENGTH_PANTALLAS 100
#define MIN_PRECIO 0
#define MAX_PRECIO 999999
#define MIN_ID 1
#define MAX_ID 999999999

typedef struct
{
	int id;
	int tipo;
	char nombre[LENGTH_NOMBRE];
	char direccion[LENGTH_DIRECCION];
	float precio;
	int isEmpty;
}Pantalla;

int pan_imprimirPantalla(Pantalla* pPantalla);
int pan_imprimirArrayPantalla(Pantalla* array,int limite);
int pan_inicializarArrayPantalla(Pantalla* array,int limite);
int pan_altaArrayPantalla(Pantalla* array,int limite);
int pan_modificarArrayPantalla(Pantalla* array,int limite);
int pan_bajaArrayPantalla(Pantalla* array,int limite);
int pan_buscarIdPantalla(Pantalla* array, int limite, int valorBuscado);
int pan_getEmptyIndexPantalla(Pantalla* array,int limite);
int pan_ordenarPantallaID(Pantalla* array,int limite);
int pan_mocksPantalla(Pantalla* array,int limite, int indice, int id, int tipo, char* nombre,char* direccion, float precio);
int ordenarPantallaDobleCriterio(Pantalla* list, int len, int order);

#endif /* pan_H_ */
