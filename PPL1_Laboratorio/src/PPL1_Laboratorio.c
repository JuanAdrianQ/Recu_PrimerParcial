
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "Funciones_Entidades_Vivienda.h"
#include "Funciones_Entidades_Censistas.h"
#include "utn.h"


#define CANT_VIVIENDAS 30
#define CANT_TIPO_VIVIENDAS 4
#define LIMITE_CALLE 25
#define TAM_CENSISTAS 3
#define TAM_TIPO_VIVIENDAS 4
#define TAM_CATASTROS 5

int main(void)
{
	setbuf(stdout, NULL);

	eVivienda viviendas[CANT_VIVIENDAS];
	char opcion;
	char calleViviendas[LIMITE_CALLE];
	int cantidadPersonas;
	int cantidadHabitaciones;
	int tipoVivienda;
	int idVivienda = 20000;
	int legajoCensista;
	int idCatastro;
	int opcionesSubMenu;
	int idABuscar;
	int IdBaja;
	int IdEncontrar;
	int menuOpcionesInformes;
	int contadorViviendasAvellaneda = 0;
	int contadorTipoCasa = 0;
	int contadorDeparta = 0;
	int censista;
	int salidaViviendasCensadas;
	int localidad;
	int contadorTipoDepartamento = 0;
	int contadorTipoCasilla = 0;
	int contadorTipoRancho = 0;
	eCensista censistas[TAM_CENSISTAS] = {{100,"Ana",34,"1203-2345"},{101,"Juan",24,"4301-54678"},{102,"Sol",47,"5902-37487"}};
	eTipoDeVivienda tipoViviendas[TAM_TIPO_VIVIENDAS] = {{1, "Casa"},
														{2, "Departamento"},
														{3, "Casilla"},
														{4, "Rancho"}};
	eCatastro catastros[TAM_CATASTROS] = {{1000,"Avellaneda",28,1540},{1001,"Lanus",43,1789},{1002,"Quilmes",32,1624},{1003,"La Plata",67,1677},{1004,"Lomas de Zamora",32,1923}};


	if(inicializarArray(viviendas,CANT_VIVIENDAS)==0)
	{
		printf("\nSe inicializaron las viviendas correctamente.\n");
	}
	else
	{
		printf("\nHubo un problema al querer inicializar las viviendas.\n");
	}

	do
	{
	printf("\nMenu de opciones\n"
				"A.Alta Vivienda\n"
				"B.Modificar Vivienda\n"
				"C.Baja Vivienda\n"
				"D.Listar Viviendas\n"
				"E.Listar Censistas\n"
				"F.Listar Catastro ordenado por Localidad\n"
				"G.Salir\n"
				"H.Acceder Menu Informes\n"
				"Elija una opcion: ");
		fflush(stdin);
		scanf("%c",&opcion);
		opcion = toupper(opcion);
		switch(opcion)
		{
		case 'A': //Añadir Viviendas
			idVivienda++;
			utn_getString(calleViviendas,"\nIngrese una calle: ","\nError.No se ingreso una calle valida.");
			utn_getNumero(&cantidadPersonas,"Ingrese cuantas personas habitan en su vivienda: ","\nError.No se ingreso una cantidad valida.",0,15,5);
			utn_getNumero(&cantidadHabitaciones,"Ingrese la cantidad de habitaciones que dispone en su hogar: ","\nError.No se ingreso una cantidad valida.",0,15,5);
			utn_getNumero(&tipoVivienda,"Ingrese su tipo de vivienda(1-Casa,2- Departamento,3-Casilla,4-Rancho): ","\nError.No se ingreso un tipo valido.",0,4,5);
			utn_getNumero(&legajoCensista,"Ingrese el numero de legajo del censista(100- Ana,101- Juan,102- Sol): ","\nError.Ingrese un numero de legajo valido",100,102,5);
			utn_getNumero(&idCatastro,"Ingrese el id de su catastro(1-1000,2-1001,3-1002,4-1003,5-1004): ","\nError.Ingrese un id catastro valido.",1000,1004,5);



			if(idCatastro == 1000)
			{
				contadorViviendasAvellaneda++;
			}
			if(tipoVivienda == 1)
			{
				contadorTipoCasa++;
			}
			if(tipoVivienda == 2)
			{
				contadorTipoDepartamento++;
			}
			if(tipoVivienda == 3)
			{
				contadorTipoCasilla++;
			}
			if(tipoVivienda == 4)
			{
				contadorTipoRancho++;
			}

			if(tipoVivienda == 2 && idCatastro == 1001)
			{
				contadorDeparta++;
			}
			 if(alta_Vivienda(viviendas,CANT_VIVIENDAS,idVivienda,calleViviendas,cantidadPersonas,cantidadHabitaciones,tipoVivienda,legajoCensista,idCatastro) == 0)
			 {
				 printf("\nSe agrego una vivienda al sistema\n");
			 }
			 else
			 {
				 printf("\nSe ha producido un error al intentar agregar una vivienda\n");
			 }
			break;
		case 'B': //Modificar vivienda

			printf("\nPorfavor ingrese el id de la vivienda a modificar: ");
			scanf("%d",&idABuscar);
			idABuscar = buscarViviendaID(viviendas,CANT_VIVIENDAS,idABuscar);
			if(idABuscar > -1)
			{
				printf("\nSe ha encontrado la vivienda.Se procedera a modificarla.\n");
			}
			do
			{
				printf("\nSubmenu de opciones:\n"
						"1.La calle\n"
						"2.La cantidad de personas\n"
						"3.La cantidad de habitaciones\n"
						"4.El tipo de vivienda\n"
						"5.Salir\n"
						"Elija una opcion: ");
				scanf("%d",&opcionesSubMenu);
				if(modificarVivienda(viviendas,CANT_VIVIENDAS,idABuscar,opcionesSubMenu)== 0)
				{
					printf("\nSe ha modificado la vivienda correctamente.\n");
				}
				else
				{
					printf("\nNo se pudo modificar la vivienda.\n");
				}

			}while(opcionesSubMenu != 5);
			break;
		case 'C': //Baja Vivienda
			utn_getNumero(&IdBaja,"\nIngrese la ID a dar de baja: ","Error.No se ingreso una id valida.",20000,999999,5);
			IdEncontrar = buscarViviendaID(viviendas,CANT_VIVIENDAS,IdBaja);

			if(IdEncontrar > -2)
			{
				if(bajaVivienda(viviendas,CANT_VIVIENDAS,IdEncontrar)== 0)
				{
					printf("\nSe ha dado de baja la vivienda correctamente\n");
				}
				else
				{
					printf("\nHa ocurrido un problema al intentar dar de baja\n");
				}
			}
			else
			{
				printf("No se ha encontrado ninguna vivienda con esa ID");
			}
			break;
		case 'D': //LISTAR VIVENDAS: Hacer un único listado de todas las viviendas ordenados por calle y ante igualdad
			//de calle por cantidad de personas.
			if(ordenarViviendasPorCalle(viviendas, CANT_VIVIENDAS) == 0)
			{
				printf("\nSe ordenaron las viviendas por calle.\n");
				if(listarViviendas(viviendas,CANT_VIVIENDAS,censistas,TAM_CENSISTAS,tipoViviendas,TAM_TIPO_VIVIENDAS,catastros,TAM_CATASTROS) == 0)
				{
					printf("\nSe listaron las viviendas correctamente.\n");
				}
				else
				{
					printf("\nOcurrio un error al intentar listar las viviedas.\n");
				}
			}
			else
			{
				printf("\nHubo un error al intentar ordenar las viviendas.\n");
			}
			break;
		case 'E'://Listado de censistas.
			listarCensistas(censistas,TAM_CENSISTAS);
			break;
		case 'F': //Listar catastro ordenado por localidad
			if(ordenarCatastroLocalidad(catastros,TAM_CATASTROS)==0)
			{
				printf("\nSe ordenaron los catastros por localidad correctamente.\n");
				if(listarCatastroOrdenadoLocalidad(catastros,TAM_CATASTROS)==0)
				{
					printf("\nSe listaror los catastros ordenados por localidad correctamente.\n");
				}
				else{
					printf("\nSurgio un error al querer listar los catastros ordenados por localidad.\n");
				}
			}
			else{
				printf("\nHubo un error al intentar ordenar los catastros por localidad.\n");
			}
			break;
		case 'G':
			printf("\nSaliendo del sistema...\n");
			exit(1);
			break;
		case 'H':
			do
			{
				printf("\nMenu Informes\n"
						"1.Elejir un tipo de vivienda y mostrar todos los datos de la vivienda,nombre del censista"
						"y datos de catastro del tipo seleccionado\n"
						"2.Elejir una Localidad y mostrar todos los datos de la vivienda y nombre del censista de la"
						"Localidad seleccionada\n"
						"3.Cantidad de viviendas censadas en la localidad de Avellaneda\n"
						"4.Elejir un censista y mostrar todas las viviendas que censó con los datos de catastro\n"
						"5.Cantidad de viviendas de tipo 'casa' censadas\n"
						"6.Cantidad de viviendas de tipo 'departamento' de la localidad de Lanús\n"
						"7.Promedio de habitantes por vivienda\n"
						"8.Salir\n"
						"Elija una opcion: ");
				scanf("%d",&menuOpcionesInformes);
				switch(menuOpcionesInformes)
				{
				case 1:

				printf("\nElija una vivienda(1.CASA,2.DEPARTAMENTO,3.CASILLA,4.RANCHO): ");
				scanf("%d",&tipoVivienda);

				if(mostrarDatosVivienda(tipoVivienda,viviendas,CANT_VIVIENDAS,censistas,TAM_CENSISTAS,catastros,TAM_CATASTROS)==0)
				{
					printf("\nSe mostraron datos de las viviendas,nombre del censista y datos de catastro del tipo de vivienda seleccionada.\n");
				}
				else{
					printf("\nHubo un error al intentar mostrar los datos.\n");
				}
					break;
				case 2: //Elegir una localidad y mostrar todos los datos de la vivienda y nombre del censista de la localidad seleccionada.

					printf("\nElija una localidad(1000-Avellaneda,1001-Lanus,1002-Quilmes,1003-La Plata,1004-Lomas de Zamora): ");
					scanf("%d",&localidad);

					if(mostrarDatosViviviendaCensista(viviendas,CANT_VIVIENDAS,censistas,TAM_CENSISTAS,localidad,tipoViviendas,TAM_TIPO_VIVIENDAS)==0)
					{
						printf("\nSe mostraron todos los datos de la vivienda y nombre del censista correctamente.\n");
					}
					else
					{
						printf("\nOcurrio un error al intentar mostrar los datos.\n");
					}
					break;
				case 3: //Cantidad de viviendas censadas en Avellaneda

					printf("\nLa cantidad de viviendas censadas en la localidad de Avellaneda es : %d\n",contadorViviendasAvellaneda);

					break;
				case 4: //Elejir un censista y mostrar todas las viviendas que censo con los datos de catastro
					printf("Escoja un censista(100-Ana,101-Juan,102-Sol): ");
					scanf("%d",&censista);

					salidaViviendasCensadas = mostrarViviendasCensadas(viviendas,CANT_VIVIENDAS,censista,catastros,TAM_CATASTROS);

					if(salidaViviendasCensadas == 0)
					{
						printf("\nSe mostraron las viviendas junto con los datos de catastro correctamente.\n");
					}
					else
					{
						if(salidaViviendasCensadas == -1)
						{
							printf("\nHubo un problema al mostrar las viviendas.\n");
						}
					}
					break;
				case 5://Cantidad de viviendas de tipo "casa" censadas.

					printf("\nLa cantidad de viviendas tipo 'casa' censadas es: %d\n",contadorTipoCasa);

					break;
				case 6: //Cantidad de viviendas de tipo "departamento" de la localidad de Lanus.

					printf("\nLa cantidad de viviendas de tipo departamento perteneciente a la localidad de Lanus es: %d\n",contadorDeparta);

					break;
				case 7: //Promedio de habitantes por vivienda

					if(calculoPromedioHabitantes(viviendas,CANT_VIVIENDAS,tipoViviendas,TAM_TIPO_VIVIENDAS,contadorTipoCasa,contadorTipoDepartamento,contadorTipoCasilla,contadorTipoRancho)==0)
					{
						printf("\nSe calculo el promedio de habitantes por tipo de vivienda\n");
					}
					else
					{
						printf("\nOcurrio un error al intentar calcular el promedio de habitantes por vivienda\n");
					}

					break;
				case 8:
					printf("\nSaliendo del sistema...\n");
					break;
				}

			}while(menuOpcionesInformes != 8);
			break;
		default:
			printf("\nElija una opcion correcta.\n");
			break;
		}

	}while(opcion != 'H');

	return EXIT_SUCCESS;
}


