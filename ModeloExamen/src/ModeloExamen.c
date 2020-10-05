#include <stdio.h>
#include <stdlib.h>
#include <stdio_ext.h>
#include <string.h>
#include "utn.h"
#include "Pantalla.h"
#include "Contratacion.h"

int main(void) {
	//Declaracion de variables y arrays
	Pantalla pantallas[LENGTH_PANTALLAS];
	Contratacion contrataciones[LENGTH_CONT];
	int id=0;
	//Inicalizacion
	pan_inicializarArrayPantalla(pantallas,LENGTH_PANTALLAS);
	con_inicializarArrayContratacion(contrataciones, LENGTH_CONT);
	//Mocks pantallas
	pan_mocksPantalla(pantallas,LENGTH_PANTALLAS,0,id,1,"PanUno","Larrea 2980",14582);
	pan_mocksPantalla(pantallas,LENGTH_PANTALLAS,1,id,2,"PanDos","Av. de los Corrales 1548",5871);
	pan_mocksPantalla(pantallas,LENGTH_PANTALLAS,2,id,1,"PanTres","Av Del Libertador 245",98562);
	pan_mocksPantalla(pantallas,LENGTH_PANTALLAS,3,id,2,"PanCuatro","Av. Ledesma 8245",27582);
	pan_mocksPantalla(pantallas,LENGTH_PANTALLAS,4,id,1,"PanCinco","Cangallo 978",98562);
	//Mocks contrataciones
	con_mocksContratacion(contrataciones, LENGTH_CONT,0,id,"20-27310562-0",50,"Archivo1",1);
	con_mocksContratacion(contrataciones, LENGTH_CONT,1,id,"20-27310562-1",25,"Archivo2",5);
	con_mocksContratacion(contrataciones, LENGTH_CONT,2,id,"20-27310562-2",32,"Archivo3",3);
	con_mocksContratacion(contrataciones, LENGTH_CONT,3,id,"20-27310562-3",48,"Archivo4",5);
	con_mocksContratacion(contrataciones, LENGTH_CONT,4,id,"20-27310562-4",78,"Archivo5",2);
	con_mocksContratacion(contrataciones, LENGTH_CONT,5,id,"20-27310562-5",150,"Archivo6",2);

	con_imprimirArrayContratacion(contrataciones, LENGTH_CONT);


	return EXIT_SUCCESS;
}
