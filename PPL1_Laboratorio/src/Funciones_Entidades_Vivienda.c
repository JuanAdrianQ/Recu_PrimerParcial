#include "Funciones_Entidades_Vivienda.h"
#include "Funciones_Entidades_Censistas.h"
#include "utn.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define LIBRE -2
#define OCUPADO 0

int inicializarArray(eVivienda* listaViviendas,int tamanio)
{
	int retorno = -1;
	int i;

	if(listaViviendas != NULL)
	{
		if(tamanio > 0)
		{
			for(i = 0;i < tamanio;i++)
			{
				listaViviendas[i].isEmpty = LIBRE;
				retorno = 0;
			}
		}
	}

	return retorno;
}
int buscarEspacioLibre(eVivienda* listaViviendas,int len)
{
	int retorno = -1;
	int i;

	if(listaViviendas != NULL && len > 0)
	{
		for(i = 0; i < len;i++)
		{
			if(listaViviendas[i].isEmpty == LIBRE)
			{
				retorno = i;
				break;
			}
		}

	}

	return retorno;
}
int alta_Vivienda(eVivienda* listaViviendas,int tamanio,int idVivienda,char calle[],int cantidadPersonas,int cantiHabit,int tpoVivienda,int legajoCensista,int idCatastro)
{
	int retorno = -1;
	eVivienda nuevaVivienda;
	int espacioLibre;

	if(listaViviendas != NULL && tamanio > 0)
	{
		espacioLibre = buscarEspacioLibre(listaViviendas,tamanio);
		if(espacioLibre >= 0)
		{
			nuevaVivienda.idVivienda = idVivienda;
			nuevaVivienda.cantidadPersonas = cantidadPersonas;
			nuevaVivienda.cantidadHabitaciones = cantiHabit;
			nuevaVivienda.tipoVivienda = tpoVivienda;
			nuevaVivienda.legajoCensista = legajoCensista;
			nuevaVivienda.idCatastro = idCatastro;
			strcpy(nuevaVivienda.calle,calle);
			nuevaVivienda.isEmpty = OCUPADO;
			listaViviendas[espacioLibre] = nuevaVivienda;


			retorno = 0;

		}
	}

	return retorno;
}
int buscarViviendaID(eVivienda* listaViviendas,int tamanio,int idABuscar)
{
	int retorno = -1;
	int i;

	if(listaViviendas != NULL && tamanio >= 0 && idABuscar >= 20000)
	{
		for(i = 0;i < tamanio;i++)
		{
			if(listaViviendas[i].idVivienda == idABuscar)
			{
				retorno = i;
				break;
			}
		}
	}
	return retorno;
}
int modificarVivienda(eVivienda* listaViviendas,int tamanio,int idABuscar, int opcionElejida)
{
	int retorno = -1;
	char nuevaCalle[25];
	int nuevaCantidadPersonas;
	int nuevaCantidadHabitaciones;
	char nuevoTipoVivienda[4];

	if(listaViviendas != NULL)
	{
		if(tamanio >= 0)
		{
			switch(opcionElejida)
			{
			case 1:
				utn_getString(nuevaCalle,"Ingrese el nombre de la nueva calle: ","Error.No se ingreso una calle valida.");
				strcpy(listaViviendas[idABuscar].calle,nuevaCalle);
				break;
			case 2:
				utn_getNumero(&nuevaCantidadPersonas,"Ingrese cuantas personas conviven en su vivienda: ","Error.No se ingreso una cantidad valida.",1,15,5);
				break;
			case 3:
				utn_getNumero(&nuevaCantidadHabitaciones,"Ingrese la cantidad de habitaciones: ","Error.No se ingreso una cantidad valida.",1,15,5);
				break;
			case 4:
				utn_getString(nuevoTipoVivienda,"Ingrese el nuevo tipo de vivienda: ","Error.No se ingreso un tipo de vivienda valido.");
				strcpy(listaViviendas[idABuscar].calle,nuevoTipoVivienda);
				break;

			}
			retorno = 0;
		}
	}

	return retorno;
}
int bajaVivienda(eVivienda* listaViviendas,int tamanio,int id)
{
	int retorno = -1;

	if(listaViviendas != NULL && tamanio > 0)
	{
		listaViviendas[id].isEmpty = LIBRE;
		retorno = 0;
	}

	return retorno;
}
int ordenarViviendasPorCalle(eVivienda* listaViviendas, int tamanio)
{
	int retorno = -1;
	eVivienda auxiliar;
	int i;
	int j;

	if(listaViviendas != NULL && tamanio > 0)
	{
		for(i = 0;i < tamanio;i++)
		{
			for(j = 0;j < tamanio;j++)
			{
				if(strcmp(listaViviendas[i].calle,listaViviendas[j].calle) > 0)
				{
					auxiliar = listaViviendas[j];
					listaViviendas[j] = listaViviendas[i];
					listaViviendas[i] = auxiliar;
				}
				if(strcmp(listaViviendas[i].calle, listaViviendas[j].calle) == 0)
				{
					if(listaViviendas[i].cantidadPersonas > listaViviendas[j].cantidadPersonas)
					{
						auxiliar = listaViviendas[j];
						listaViviendas[j] = listaViviendas[i];
						listaViviendas[i] = auxiliar;
					}
				}
			}
		}
		retorno = 0;
	}
	return retorno;
}
int listarViviendas(eVivienda* listaViviendas, int tamanio, eCensista* censista, int tamanioCensista, eTipoDeVivienda* tipoVivienda,int tamanioTipo,eCatastro* tipoCatastro,int tamanioCatastro)
{
	int retorno = -1;

	if(listaViviendas != NULL && censista != NULL && tipoVivienda != NULL && tipoCatastro != NULL)
	{
		if(tamanio >= 0)
		{
			printf("\nID\t\t\t Calle\t Cantidad de Personas  Cantidad de Habitaciones  Tipo de Vivienda  Legajo Censista\t ID Catastro\t Localidad\t Manzana\t Parcela\n");
			for(int i = 0;i < tamanio;i++)
			{
				if(listaViviendas[i].isEmpty == OCUPADO)
				{
					for(int j = 0;j < tamanioCensista;j++)
					{
						if(listaViviendas[i].legajoCensista == censista[j].legajoCensista)
						{
							for(int k = 0;k < tamanioTipo;k++)
							{
								if(listaViviendas[i].tipoVivienda == tipoVivienda[k].tipoVivienda)
								{
									for(int m = 0;m < tamanioCatastro;m++)
									{
										if(listaViviendas[i].idCatastro == tipoCatastro[m].idCatastro)
										{
											printf("%-25d %-21s %-21d %-21d %-15s %-15d %-15d %-21s %-15d %d\n", listaViviendas[i].idVivienda,listaViviendas[i].calle,listaViviendas[i].cantidadPersonas,
											listaViviendas[i].cantidadHabitaciones, tipoVivienda[k].descripcion, censista[j].legajoCensista,listaViviendas[i].idCatastro,tipoCatastro[m].localidad,tipoCatastro[m].manzana,tipoCatastro[m].parcela);
											retorno = 0;
											break;
										}
									}
									break;
								}
							}

						}
					}

				}

			}

		}

	}
	return retorno;
}
int ordenarCatastroLocalidad(eCatastro* catastros,int lenCatastros)
{
	int retorno = -1;
	int i;
	int j;
	eCatastro auxiliar;

	if(catastros != NULL && lenCatastros >= 0)
	{
		for(i = 0;i < lenCatastros;i++)
		{
			for(j = i + 1;j < lenCatastros -1;j++)
			{
				if(strcmp(catastros[i].localidad,catastros[j].localidad)>0)
				{
					auxiliar = catastros[j];
					catastros[j] = catastros[i];
					catastros[i] = auxiliar;
				}
				if(strcmp(catastros[i].localidad,catastros[j].localidad)==0)
				{
					auxiliar = catastros[j];
					catastros[j] = catastros[i];
					catastros[i] = auxiliar;
				}

			}
			retorno = 0;
		}
	}


	return retorno;
}
int listarCatastroOrdenadoLocalidad(eCatastro* catastros,int lenCatastros)
{
	int retorno = -1;

	if(catastros != NULL && lenCatastros >= 0)
	{
		printf("\nID Catastro\t Localidad\t Manzana\t Parcela\n");
		for(int i = 0; i < lenCatastros;i++)
		{
			printf("%-12d %-24s %-12d %-12d\n",catastros[i].idCatastro,catastros[i].localidad,catastros[i].manzana,catastros[i].parcela);
			retorno = 0;
		}
	}

	return retorno;
}
int mostrarDatosVivienda(int tipoViviendaSeleccionada,eVivienda* viviendas,int len,eCensista* censistas,int lenCensistas,eCatastro* catastros,int lenCatastros)
{
	int retorno = -1;

	if(viviendas != NULL && censistas != NULL && catastros != NULL && tipoViviendaSeleccionada >= 1 && tipoViviendaSeleccionada <= 4)
	{
		printf("\nID Vivienda\t Calle Vivienda\t Cantidad de Personas\t Cantidad de Habitaciones\t Nombre Censista\t ID Catastro\t Localidad\t Manzana\t Parcela\n");
		for(int i = 0;i < len;i++)
		{
			if(tipoViviendaSeleccionada == viviendas[i].tipoVivienda)
			{
				for(int j = 0;j < lenCensistas;j++)
				{
					if(viviendas[i].legajoCensista == censistas[j].legajoCensista)
					{
						for(int k = 0;k < lenCatastros;k++)
						{
							if(viviendas[i].idCatastro == catastros[k].idCatastro)
							{
								printf("\n%-20d %-20s %-25d %-25d %-20s %-15d %-20s %-15d %-15d\n",viviendas[i].idVivienda,viviendas[i].calle,viviendas[i].cantidadPersonas,viviendas[i].cantidadHabitaciones,censistas[j].nombre,catastros[k].idCatastro,catastros[k].localidad,catastros[k].manzana,catastros[k].parcela);
								retorno = 0;
							}
						}
					}
				}
			}
		}
	}
	return retorno;
}
int mostrarDatosViviviendaCensista(eVivienda* viviendas,int lenViviendas,eCensista* censistas,int lenCensista,int localidad,eTipoDeVivienda* tipoViviendas,int lenTipo)
{
	int retorno = -1;
	int i;
	int j;
	int k;
	if(viviendas != NULL && censistas != NULL && tipoViviendas != NULL)
	{
		printf("\nID Vivienda Calle Cantidad Personas Cantidad Habitaciones Tipo de Vivienda Nombre Censista\n");
		for(i = 0;i < lenViviendas;i++)
		{
			if(localidad == viviendas[i].idCatastro)
			{
				for(j = 0;j < lenCensista;j++)
				{
					if(viviendas[i].legajoCensista == censistas[j].legajoCensista)
					{
						for(k = 0;k < lenTipo;k++)
						{
							if(viviendas[i].tipoVivienda == tipoViviendas[k].tipoVivienda)
							{
								printf("\n%d %s %d %d %s %s\n",viviendas[i].idVivienda,viviendas[i].calle,viviendas[i].cantidadPersonas,viviendas[i].cantidadHabitaciones,tipoViviendas[k].descripcion,censistas[j].nombre);
								retorno = 0;
								break;
							}
						}
					}

				}
			}
		}
	}

	return retorno;
}
int mostrarViviendasCensadas(eVivienda* viviendas,int len,int legajoCensita,eCatastro* datosCatastro,int tamanioDatos)
{
	int retorno = -1;
	int i;
	int j;
	if(viviendas != NULL && datosCatastro != NULL && len >= 0)
	{
		printf("\nLos ID de las viviendas que censo\t ID Catastro\t Localidad\t Manzana\t Parcela\n");
		for(i = 0;i < len;i++)
		{
			if(legajoCensita == viviendas[i].legajoCensista)
			{
				for(j = 0;j < tamanioDatos;j++)
				{
					if(viviendas[i].idCatastro == datosCatastro[j].idCatastro)
					{
						printf("\n%-40d %-15d %-15s %-15d %d\n",viviendas[i].idVivienda,datosCatastro[j].idCatastro,datosCatastro[j].localidad,datosCatastro[j].manzana,datosCatastro[j].parcela);
						retorno = 0;
						break;
					}
				}

			}
		}
	}
	return retorno;
}
//int calculoHabitantesPorVivienda(int totalHabitanes,e,eTipoDeVivienda* arrayTipoViviendas,int lenTipoViviendas)
//{
//	int retorno = -1;
//
//	if(arrayTipoViviendas != NULL && lenTipoViviendas  > 0)
//	{
//		if(arrayTipoViviendas[i].descripcion == )
//	}
//
//	return retorno;
//}

int calculoPromedioHabitantes(eVivienda* arrayViviendas,int lenViviendas,eTipoDeVivienda* arrayTipoViviendas,int lenTipoViviendas,int contadorCasa,int contadorTipoDepartamento,int contadorTipoCasilla,int contadorTipoRancho)
{
	int retorno = -1;
	int i;
	int j;
	int sumaHabitantes = 0;
	float promedioHabitantesCasa = 0;
	float promedioHabitantesDepartamento = 0;
	float promedioHabitantesCasilla = 0;
	float promedioHabitantesRancho = 0;
	int totalSumaHabitantes;
	if(arrayViviendas != NULL && lenViviendas > 0)
	{

		for(i = 0;i < lenViviendas;i++)
		{
			if(arrayViviendas[i].isEmpty == OCUPADO)
			{
				sumaHabitantes += arrayViviendas[i].cantidadPersonas;

				totalSumaHabitantes = sumaHabitantes;

				for(j = 0;j < lenTipoViviendas;j++)
				{
					if(arrayViviendas[i].tipoVivienda == arrayTipoViviendas[j].tipoVivienda)
					{
						if(arrayTipoViviendas[j].tipoVivienda == 1)
						{
							promedioHabitantesCasa = totalSumaHabitantes / (float)contadorCasa;
						}
						if(arrayTipoViviendas[j].tipoVivienda == 2)
						{
							promedioHabitantesDepartamento = totalSumaHabitantes / (float)contadorTipoDepartamento;
						}
						if(arrayTipoViviendas[j].tipoVivienda == 3)
						{
							promedioHabitantesCasilla = totalSumaHabitantes / (float)contadorTipoCasilla;

						}
						if(arrayTipoViviendas[j].tipoVivienda == 4)
						{
							promedioHabitantesRancho = totalSumaHabitantes / (float)contadorTipoRancho;
						}
						retorno = 0;
					}
			}

		}

		}
		printf("\nEl promedio de habitantes por casa es: %.2f\n",promedioHabitantesCasa);
		printf("\nEl promedio de habitantes por departamento es: %.2f\n",promedioHabitantesDepartamento);
		printf("\nEl promedio de habitantes por casilla es: %.2f\n",promedioHabitantesCasilla);
		printf("\nEl promedio de habitantes por rancho es: %.2f\n",promedioHabitantesRancho);


	}
	return retorno;
}
