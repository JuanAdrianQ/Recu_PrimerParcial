#include <stdio.h>
#include <stdlib.h>
#include "utn.h"
#include "Funciones_Entidades_Censistas.h"

#ifndef FUNCIONES_ENTIDADES_CENSISTAS_C_
#define FUNCIONES_ENTIDADES_CENSISTAS_C_



#endif /* FUNCIONES_ENTIDADES_CENSISTAS_C_ */

int listarCensistas(eCensista* censistas,int tamanio)
{
	int retorno = -1;

	if(censistas != NULL && tamanio > 0)
		{
			printf("\nLegajo\t Nombre\t  Edad\t Numero de telefono\n");
			for(int i = 0; i < tamanio; i++)
			{
				printf("%-8d %-8s %-6d %s\n", censistas[i].legajoCensista, censistas[i].nombre, censistas[i].edad, censistas[i].telefono);
			}
			retorno = 0;
		}

		return retorno;


}
