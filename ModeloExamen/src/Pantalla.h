#ifndef PANTALLA_H_
#define PANTALLA_H_

#define LENGTH_NOMBRE 30
#define LENGTH_DIRECCION 50
#define LENGTH_PANTALLA 100
#define LENGTH_CONT 1000
#define TRUE 1
#define FALSE 0
#define QTY_REINT 2
#define MIN_OPTION_MENU 1
#define MAX_OPTION_MENU 10
#define MAX_OPTION_MENU_INFO 3
#define MIN_TIPO 1
#define MAX_TIPO 2
#define MIN_PRECIO 1
#define MAX_PRECIO 999999999
#define MIN_DIAS 1
#define MAX_DIAS 365
#define MIN_ID 1
#define MAX_ID 999999999
#define PANTALLA_TIPO_LCD 1
#define PANTALLA_TIPO_LED 2

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
int pan_modificarArrayPantalla(Pantalla* array,int limite, int indice);
int pan_bajaArrayPantalla(Pantalla* array,int limite,int indice);
int pan_buscarIdPantalla(Pantalla* array, int limite, int valorBuscado);
int pan_getEmptyIndexPantalla(Pantalla* array,int limite);
int pan_ordenarPantallaID(Pantalla* array,int limite);
int pan_mocksPantalla(Pantalla* array,int limite, int indice, int id,int tipo, char* nombre,char* direccion, float precio);
int pan_ordenarPantallaDobleCriterio(Pantalla* list, int len, int order);
int pan_checkListaVacia(Pantalla* list, int len);

#endif /* PANTALLA_H_ */
