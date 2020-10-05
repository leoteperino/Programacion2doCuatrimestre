#include <stdio.h>
#include <stdlib.h>
#include <stdio_ext.h>
#include <string.h>
#include "utn.h"
#include "Pantalla.h"

int main(void) {
	//Declaracion de variables
	Pantalla pantallas[LENGTH_PANTALLAS];
	int id=0;
	//Inicalizacion
	pan_inicializarArrayPantalla(pantallas,LENGTH_PANTALLAS);
	//Mocks
	pan_mocksPantalla(pantallas,LENGTH_PANTALLAS,0,id,1,"PanUno","Larrea 2980",14582);
	pan_mocksPantalla(pantallas,LENGTH_PANTALLAS,1,id,2,"PanDos","Av. de los Corrales 1548",5871);
	pan_mocksPantalla(pantallas,LENGTH_PANTALLAS,2,id,1,"PanTres","Av Del Libertador 245",98562);
	pan_mocksPantalla(pantallas,LENGTH_PANTALLAS,3,id,2,"PanCuatro","Av. Ledesma 8245",27582);
	pan_mocksPantalla(pantallas,LENGTH_PANTALLAS,4,id,1,"PanCinco","Cangallo 978",98562);


	return EXIT_SUCCESS;
}
