#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdio_ext.h>
#include "Pantalla.h"
#include "utn.h"
#include "Contratacion.h"

int main(void) {
	//Declaracion de variables y arrays
	Pantalla pantallas[LENGTH_PANTALLA];
	Contratacion contrataciones[LENGTH_CONT];
	int id=0;
	int optionMenu;
	//Inicalizacion
	pan_inicializarArrayPantalla(pantallas,LENGTH_PANTALLA);
	cont_inicializarArrayContratacion(contrataciones, LENGTH_CONT);
	//Mocks Pantallas
	pan_mocksPantalla(pantallas,LENGTH_PANTALLA,0,id,1,"Pantalla1","Direccion1",1526);
	pan_mocksPantalla(pantallas,LENGTH_PANTALLA,1,id,2,"Pantalla2","Direccion2",1526);
	pan_mocksPantalla(pantallas,LENGTH_PANTALLA,2,id,1,"Pantalla3","Direccion3",1526);
	pan_mocksPantalla(pantallas,LENGTH_PANTALLA,3,id,2,"Pantalla4","Direccion4",1526);
	pan_mocksPantalla(pantallas,LENGTH_PANTALLA,4,id,1,"Pantalla5","Direccion5",1526);
	//Mocks Contrataciones
	cont_mocksContratacion(contrataciones,LENGTH_CONT,0,id,"00-00000000-0",10,"Archivo1.mpeg",1);
	cont_mocksContratacion(contrataciones,LENGTH_CONT,1,id,"00-00000000-0",10,"Archivo1.mpeg",1);
	cont_mocksContratacion(contrataciones,LENGTH_CONT,2,id,"00-00000000-0",10,"Archivo1.mpeg",1);
	cont_mocksContratacion(contrataciones,LENGTH_CONT,3,id,"00-00000000-0",10,"Archivo1.mpeg",1);
	cont_mocksContratacion(contrataciones,LENGTH_CONT,4,id,"00-00000000-0",10,"Archivo1.mpeg",1);
	//Menu Principal
	do
	{
		if(!utn_getNumero(   &optionMenu,
							"\n*****Menu de Opciones*****\n"
							"1 -Alta de Pantalla\n"
							"2 -Modificar datos de Pantalla\n"
							"3 -Baja de Pantalla\n"
							"4 -Contratar una Publicidad\n"
							"5 -Modificar Contratacion\n"
							"6 -Cancelar contratacion\n"
							"7 -Consulta Facturacion\n"
							"8 -Listar Contrataciones\n"
							"9 -Listar Pantallas\n"
							"10 -Informar\n"
							"-----------------------------\n"
							"Elija una Opcion del Menu: ",
							"ERROR",MIN_OPTION_MENU,MAX_OPTION_MENU,QTY_REINT))
		{
			switch(optionMenu)
			{
				case 1:
					printf("\n***************************************\n");
					if(!pan_altaArrayPantalla(pantallas, LENGTH_PANTALLA))
					{
						printf("Se dio de alta la pantalla!\n");
					}
					printf("Lista de pantallas actualizada:");
					pan_imprimirArrayPantalla(pantallas, LENGTH_PANTALLA);
					printf("\n***************************************\n");
					break;
				case 2:
					printf("\n***************************************\n");
					if(pan_checkListaVacia(pantallas, LENGTH_PANTALLA)==-1)
					{
						printf("El array de pantallas esta vacio.");
					}
					else
					{
						if(!pan_modificarArrayPantalla(pantallas, LENGTH_PANTALLA))
						{
							printf("La pantalla se actualizo con exito!!\n");
							printf("Lista de pantallas actualizada");
							pan_imprimirArrayPantalla(pantallas, LENGTH_PANTALLA);
						}
					}
					printf("\n***************************************\n");
					break;
				case 3:
					printf("\n***************************************\n");
					if(pan_checkListaVacia(pantallas, LENGTH_PANTALLA)==-1)
					{
						printf("El array de pantallas esta vacio.");
					}
					else
					{
						if(!pan_bajaArrayPantalla(pantallas,LENGTH_PANTALLA))
						{
							printf("La pantalla se dio de baja.\n");
							if(!pan_checkListaVacia(pantallas, LENGTH_PANTALLA))
							{
								printf("Lista de pantallas actualizada");
								pan_imprimirArrayPantalla(pantallas, LENGTH_PANTALLA);
							}
						}
					}
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
											"1 -Lista​ de​ ​cada​ ​cliente​ ​con​ cantidad​ ​de​ ​contrataciones​ ​e ​importe​ ​a ​pagar​ por​ cada​ ​una.\n"
											"2 -Cliente con importe mas alto a facturar.\n"
											"3 - Volver al Menu Principal.\n"
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
							}
						}
					}while(optionMenu!=3);
				printf("\n***************************************\n");
				break;
			}
		}
	}while(optionMenu);
	return EXIT_SUCCESS;
}
