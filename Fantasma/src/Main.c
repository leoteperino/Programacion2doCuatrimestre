#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdio_ext.h>
#include "Fantasma.h"
#include "utn.h"

int main(void) {
	//Declaracion de variables y arrays
	Entidad entidades[LENGTH_ENTIDAD];
	int id=0;
	int optionMenu;
	//Inicalizacion
	entidad_inicializarArrayEntidad(entidades,LENGTH_ENTIDAD);
	//Mocks Fantasmas
	entidad_mocksEntidad(entidades, LENGTH_ENTIDAD, 0, id, "Entidad1", "Apellido1", "00-00000000-0",1,1);
	entidad_mocksEntidad(entidades, LENGTH_ENTIDAD, 1, id, "Entidad2", "Apellido2", "00-00000000-0",1,5);
	entidad_mocksEntidad(entidades, LENGTH_ENTIDAD, 2, id, "Entidad3", "Apellido3", "00-00000000-0",1,3);
	entidad_mocksEntidad(entidades, LENGTH_ENTIDAD, 3, id, "Entidad4", "Apellido4", "00-00000000-0",1,5);
	entidad_mocksEntidad(entidades, LENGTH_ENTIDAD, 4, id, "Entidad5", "Apellido5", "00-00000000-0",1,8);
	//imprimir fantasma
	entidad_imprimirArrayEntidad(entidades, LENGTH_ENTIDAD);
	//Menu Principal
	do
	{
		if(!utn_getNumero(   &optionMenu,
							"\n*****Menu de Opciones*****\n"
							"1 - \n"
							"2 - \n"
							"3 - \n"
							"4 - \n"
							"5 - \n"
							"6 - \n"
							"7 - \n"
							"8 - \n"
							"9 - \n"
							"10 -\n"
							"-----------------------------\n"
							"Elija una Opcion del Menu: ",
							"ERROR",MIN_OPTION_MENU,MAX_OPTION_MENU,QTY_REINT))
		{
			switch(optionMenu)
			{
				case 1:
					printf("\n***************************************\n");
					printf("1");
					printf("\n***************************************\n");
					break;
				case 2:
					printf("\n***************************************\n");
					printf("2");
					printf("\n***************************************\n");
					break;
				case 3:
					printf("\n***************************************\n");
					printf("3");
					printf("\n***************************************\n");
					break;
				case 4:
					printf("\n***************************************\n");
					printf("4");
					printf("\n***************************************\n");
					break;
				case 5:
					printf("\n***************************************\n");
					printf("5");
					printf("\n***************************************\n");
					break;
				case 6:
					printf("\n***************************************\n");
					printf("6");
					printf("\n***************************************\n");
					break;
				case 7:
					printf("\n***************************************\n");
					printf("7");
					printf("\n***************************************\n");
					break;
				case 8:
					printf("\n***************************************\n");
					printf("8");
					printf("\n***************************************\n");
					break;
				case 9:
					printf("\n***************************************\n");
					printf("9");
					printf("\n***************************************\n");
					break;
				case 10:
					printf("\n***************************************\n");
					do
					{
						if(!utn_getNumero(	&optionMenu,
											"\n*****Informar*****\n"
											"1 - \n"
											"2 - \n"
											"3 - \n"
											"4 - Volver al Menu Principal.\n"
											"-----------------------------\n"
											"Elija una Opcion del Menu: ",
											"ERROR",MIN_OPTION_MENU,MAX_OPTION_MENU_INFO,QTY_REINT))
						{
							switch(optionMenu)
							{
								case 1:
									printf("\n***************************************\n");
									printf("1-informes");
									printf("\n***************************************\n");
									break;
								case 2:
									printf("\n***************************************\n");
									printf("2-informes");
									printf("\n***************************************\n");
									break;
								case 3:
									printf("\n***************************************\n");
									printf("3-informes");
									printf("\n***************************************\n");
									break;
							}
						}
					}while(optionMenu!=4);
				printf("\n***************************************\n");
				break;
			}
		}
	}while(optionMenu);
	return EXIT_SUCCESS;
}
