
#ifndef FUNCIONES_ENTIDADES_CENSISTAS_H_
#define FUNCIONES_ENTIDADES_CENSISTAS_H_

struct
{
	int legajoCensista;
	char nombre[50];
	int edad;
	char telefono[20];

}typedef eCensista;

#endif /* FUNCIONES_ENTIDADES_CENSISTAS_H_ */

/// @brief Funcion para mostrar el array de censistas
/// @param censistas eCensista* Puntero al array de censistas.
/// @param tamanio int tamaño del array
/// @return retorna -1 en caso de error y 0 en caso contrario
int listarCensistas(eCensista* censistas,int tamanio);
