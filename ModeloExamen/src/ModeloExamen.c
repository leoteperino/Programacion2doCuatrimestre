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
	int auxID;
	int auxIndice;
	char auxCuit[LENGTH_CUIT];
	//Inicalizacion
	pan_inicializarArrayPantalla(pantallas,LENGTH_PANTALLA);
	cont_inicializarArrayContratacion(contrataciones, LENGTH_CONT);
	//Mocks Pantallas
	pan_mocksPantalla(pantallas,LENGTH_PANTALLA,0,id,1,"Pantalla1","Direccion1",1526);
	pan_mocksPantalla(pantallas,LENGTH_PANTALLA,1,id,2,"Pantalla2","Direccion2",4587);
	pan_mocksPantalla(pantallas,LENGTH_PANTALLA,2,id,1,"Pantalla3","Direccion3",5865);
	pan_mocksPantalla(pantallas,LENGTH_PANTALLA,3,id,2,"Pantalla4","Direccion4",7841);
	pan_mocksPantalla(pantallas,LENGTH_PANTALLA,4,id,1,"Pantalla5","Direccion5",7489);
	//Mocks Contrataciones
	cont_mocksContratacion(contrataciones,LENGTH_CONT,0,id,"00-00000000-1",10,"Archivo1.mpeg",1);
	cont_mocksContratacion(contrataciones,LENGTH_CONT,1,id,"00-00000000-2",10,"Archivo1.mpeg",5);
	cont_mocksContratacion(contrataciones,LENGTH_CONT,2,id,"00-00000000-3",10,"Archivo1.mpeg",5);
	cont_mocksContratacion(contrataciones,LENGTH_CONT,3,id,"00-00000000-4",10,"Archivo1.mpeg",5);
	cont_mocksContratacion(contrataciones,LENGTH_CONT,4,id,"00-00000000-5",10,"Archivo1.mpeg",5);
	cont_mocksContratacion(contrataciones,LENGTH_CONT,5,id,"00-00000000-1",10,"Archivo1.mpeg",2);
	cont_mocksContratacion(contrataciones,LENGTH_CONT,6,id,"00-00000000-1",10,"Archivo1.mpeg",3);
	cont_mocksContratacion(contrataciones,LENGTH_CONT,7,id,"00-00000000-1",10,"Archivo1.mpeg",5);
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
						pan_imprimirArrayPantalla(pantallas, LENGTH_PANTALLA);
						if(!utn_getNumero(&auxID,"\nIngrese el ID a modificar: ","ERROR",MIN_ID,MAX_ID,QTY_REINT))
						{
							auxIndice = pan_buscarIdPantalla(pantallas, LENGTH_PANTALLA, auxID);
							if(auxIndice>=0)
							{
								if(!pan_modificarArrayPantalla(pantallas, LENGTH_PANTALLA,auxIndice))
								{
									printf("La pantalla se actualizo con exito!!\n");
									printf("Lista de pantallas actualizada");
									pan_imprimirArrayPantalla(pantallas, LENGTH_PANTALLA);
								}
							}
						}
						else
						{
							printf("No se encontro el ID ingresado.\n");
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
						pan_imprimirArrayPantalla(pantallas, LENGTH_PANTALLA);
						if(!utn_getNumero(&auxID,"\nIngrese el ID de Pantalla a borra: ","ERROR",MIN_ID,MAX_ID,QTY_REINT))
						{
							auxIndice = pan_buscarIdPantalla(pantallas, LENGTH_PANTALLA, auxID);
							if(auxIndice>=0)
							{
								printf("Esta pantalla esta contratada por los siguientes clientes:\n");
								cont_listarPantallasContratadas(contrataciones, LENGTH_CONT, pantallas, LENGTH_PANTALLA, auxID);
								if(!pan_bajaArrayPantalla(pantallas,LENGTH_PANTALLA,auxIndice))
								{
									cont_bajaArrayContratacion(contrataciones,LENGTH_CONT,pantallas,LENGTH_PANTALLA,auxID);
									printf("Lista de pantallas actualizada");
									pan_imprimirArrayPantalla(pantallas, LENGTH_PANTALLA);
									printf("\nContrataciones:");
									cont_imprimirArrayContratacion(contrataciones, LENGTH_CONT);
								}
							}
							else
							{
								printf("No se encontro el ID.\n");
							}
						}
					}
					printf("\n***************************************\n");
					break;
				case 4:
					printf("\n***************************************\n");
					pan_imprimirArrayPantalla(pantallas, LENGTH_PANTALLA);
					if(!utn_getNumero(&auxID,"\nIngrese el ID de pantalla a contratar: ","ERROR",MIN_ID,MAX_ID,QTY_REINT))
					{
						if(pan_buscarIdPantalla(pantallas, LENGTH_PANTALLA, auxID)>=0)
						{
							if(!cont_altaArrayContratacion(contrataciones, LENGTH_CONT, auxID))
							{
								printf("La pantalla se dio de alta con exito!!\n");
								printf("Lista de contrataciones actualizada");
								cont_imprimirArrayContratacion(contrataciones, LENGTH_CONT);
							}
						}
						else
						{
							printf("No se encontro el ID ingresado.\n");
						}
					}
					printf("\n***************************************\n");
					break;
				case 5:
					printf("\n***************************************\n");
					cont_imprimirArrayContratacion(contrataciones, LENGTH_CONT);
					if(!utn_getCuit(auxCuit, LENGTH_CUIT, "\nCuit: ", "ERROR", QTY_REINT))
					{
						cont_listarClientesPorCuit(contrataciones, LENGTH_CONT,auxCuit);
						if(!utn_getNumero(&auxID,"\nID: ","ERROR",MIN_ID,MAX_ID,QTY_REINT))
						{
							auxIndice=cont_buscarIdContratacion(contrataciones, LENGTH_CONT, auxID);
							if(auxIndice>=0)
							{
								if(!cont_modificarArrayContratacion(contrataciones,LENGTH_CONT,auxIndice))
								{
									printf("La contratacion se modifico con exito.!!\n");
									printf("Lista de contrataciones actualizada");
									cont_imprimirArrayContratacion(contrataciones, LENGTH_CONT);
								}
							}
							else
							{
								printf("No se encontro el ID ingresado.\n");
							}
						}
					}
					printf("\n***************************************\n");
					break;
				case 6:
					printf("\n***************************************\n");
					cont_imprimirArrayContratacion(contrataciones, LENGTH_CONT);
					if(!utn_getCuit(auxCuit, LENGTH_CUIT, "\nCuit: ", "ERROR", QTY_REINT))
					{
						cont_listarClientesPorCuit(contrataciones, LENGTH_CONT,auxCuit);
						if(!utn_getNumero(&auxID,"\nID: ","ERROR",MIN_ID,MAX_ID,QTY_REINT))
						{
							auxIndice=cont_buscarIdContratacion(contrataciones, LENGTH_CONT, auxID);
							if(auxIndice>=0)
							{
								if(!cont_bajaArrayContratacionID(contrataciones,LENGTH_CONT,auxIndice))
								{
									printf("La contratacion se dio de baja con exito.!!\n");
									printf("Lista de contrataciones actualizada");
									cont_imprimirArrayContratacion(contrataciones, LENGTH_CONT);
								}
							}
							else
							{
								printf("No se encontro el ID ingresado.\n");
							}
						}
					}
					printf("\n***************************************\n");
					break;
				case 7:
					printf("\n***************************************\n");
					printf("Pantallas");
					pan_imprimirArrayPantalla(pantallas, LENGTH_PANTALLA);
					printf("\nContrataciones");
					cont_imprimirArrayContratacion(contrataciones, LENGTH_CONT);
					if(!utn_getCuit(auxCuit, LENGTH_CUIT, "\nIngrese el Cuit del cliente: ", "ERROR", QTY_REINT))
					{
						if(cont_consultarFacturacion(contrataciones,LENGTH_CONT,pantallas,LENGTH_PANTALLA,auxCuit)==-1)
						{
							printf("Ingreso de un Cuit invalido.\n");
						}
					}
					printf("\n***************************************\n");
					break;
				case 8:
					printf("\n***************************************\n");
					if(cont_listarContrataciones(contrataciones,LENGTH_CONT,pantallas,LENGTH_PANTALLA)==-1)
					{
						printf("No hay contrataciones.\n");
					}
					printf("\n***************************************\n");
					break;
				case 9:
					printf("\n***************************************\n");
					if(pan_checkListaVacia(pantallas, LENGTH_PANTALLA)==-1)
					{
						printf("La lista esta vacia.\n");
					}
					else
					{
						pan_imprimirArrayPantalla(pantallas, LENGTH_PANTALLA);
					}
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
									printf("1-informes\n");
									cont_listarClientes(contrataciones, LENGTH_CONT, pantallas, LENGTH_PANTALLA);
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
