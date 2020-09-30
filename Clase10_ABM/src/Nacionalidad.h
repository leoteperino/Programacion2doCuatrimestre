/*
 * Nacionalidad.h
 *
 *  Created on: Sep 29, 2020
 *      Author: leandro
 */

#ifndef nac_H_
#define nac_H_

typedef struct{
	int id;
	char name[ARRAY_LEN_NAME];
	int isEmpty;
}Nacionalidad;

int nac_inicializarArray(Nacionalidad* array, int len);
int nac_mostrarLista(Nacionalidad* array, int len);
int nac_buscarVacio(Nacionalidad* array, int len);
int nac_AltaDeNacionalidad(Nacionalidad* array, int len, int indice);
int nac_buscarIndicexId(Nacionalidad* array, int len, int id);
int nac_ModificarNacionalidad(Nacionalidad* array, int len, int indice);
int nac_BajaNacionalidad(Nacionalidad* array, int len, int indice);
int nac_ordenarPorNombre(Nacionalidad* array,int len);


#endif /* nac_H_ */
