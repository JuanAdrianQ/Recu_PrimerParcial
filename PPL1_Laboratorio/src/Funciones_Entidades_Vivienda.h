
#ifndef FUNCIONES_ENTIDADES_VIVIENDA_H_
#define FUNCIONES_ENTIDADES_VIVIENDA_H_
#include "Funciones_Entidades_Censistas.h"
struct
{
	int idVivienda;
	char calle[25];
	int cantidadPersonas;
	int cantidadHabitaciones;
	int tipoVivienda;
	int legajoCensista;
	int isEmpty;
	int idCatastro;

}typedef eVivienda;

struct
{
	int tipoVivienda;
	char descripcion[15];
}typedef eTipoDeVivienda;

struct
{
	int idCatastro;
	char localidad[50];
	int manzana;
	int parcela;

}typedef eCatastro;


#endif /* FUNCIONES_ENTIDADES_VIVIENDA_H_ */


/// @brief inicializo en -2 para saber las viviendas que estan libres o llenas a la hora de una modificacion.
/// @param listaViviendas eVivienda* Puntero al array de viviendas.
/// @param tamanio int tamaño del array
/// @return int retorna -1 en caso de error y 0 en caso de que todo funciono perfectamente.
int inicializarArray(eVivienda* listaViviendas,int tamanio);
/// @brief doy de alta una vivienda.
/// @param listaViviendas eVivienda* Puntero al array de viviendas.
/// @param tamanio int tamaño del array
/// @param idVivienda int id de la vivienda autoincremental
/// @param calle char array calle
/// @param cantidadPersonas int cantidadPersonas de la vivienda.
/// @param cantidadHabit int cantidad de habitantes de la vivienda.
/// @param tpoVivienda int tipo de vivienda.
/// @param legajoCensista int legajo del censista.
/// @return int retorna -1 en caso de error y 0 en caso de que todo funciono perfectamente.
int buscarEspacioLibre(eVivienda* listaViviendas,int len);


int alta_Vivienda(eVivienda* listaViviendas,int tamanio,int idVivienda,char calle[],int cantidadPersonas,int cantiHabit,int tpoVivienda,int legajoCensista,int idCatastro);
/// @brief Busco la ID a modificar.
/// @param listaViviendas eVivienda* Puntero al array de viviendas.
/// @param tamanio int tamaño del array
/// @param idABuscar int ID pasada por valor para la posterior modificacion
/// @return int retorna -1 en caso de error y la ID encontrada en caso contrario.
int buscarViviendaID(eVivienda* listaViviendas,int tamanio,int idABuscar);
/// @brief Funcion una vez conseguida la ID modifica la vivienda recibiendo como parametro la misma.
/// @param listaViviendas eVivienda* Puntero al array de viviendas.
/// @param tamanio int tamaño del array
/// @param idABuscar int ID pasada por valor para la posterior modificacion
/// @param opcionElejida int opcion elejida en el submenu pasada por parametro.
/// @return int retorna -1 en caso de error y 0 en caso de que halla funcionado correctamente.
int modificarVivienda(eVivienda* listaViviendas,int tamanio,int idABuscar, int opcionElejida);
/// @brief Funcion para dar de baja logica a una vivienda.Cambiando el campo IsEmpty.
/// @param listaViviendas eVivienda* Puntero al array de viviendas.
/// @param tamanio int tamaño del array
/// @param id int id de la vivienda pasado por parametro para la baja logica.
/// @return int retorna -1 en caso de error y 0 en caso de que halla funcionado correctamente.
int bajaVivienda(eVivienda* listaViviendas,int tamanio,int id);
/// @brief Funcion para ordenar las viviendas por calle.
/// @param listaViviendas eVivienda* Puntero al array de viviendas.
/// @param tamanio int tamaño del array
/// @return int retorna -1 en caso de error y 0 en caso de que halla funcionado correctamente.
int ordenarViviendasPorCalle(eVivienda* listaViviendas, int tamanio);
/// @brief Funcion para mostrar las viviendas una vez ordenadas.
/// @param listaViviendas eVivienda* Puntero al array de viviendas.
/// @param tamanio int tamaño del array
/// @param censista eCensista* puntero al array censista
/// @param tamanioCensista int tamaño del array censista
/// @param tipo eTipoDeVivienda puntero al array tipoVivienda
/// @param tamanioTipo int tamañop del array tipoVivienda
/// @return int retorna -1 en caso de error y 0 en caso de que halla funcionado correctamente.
int listarViviendas(eVivienda* listaViviendas, int tamanio, eCensista* censista, int tamanioCensista, eTipoDeVivienda* tipo, int tamanioTipo,eCatastro* tipoCatastro,int tamanioCatastro);

int ordenarCatastroLocalidad(eCatastro* catastros,int lenCatastros);

int listarCatastroOrdenadoLocalidad(eCatastro* catastros,int lenCatastros);

int mostrarDatosVivienda(int tipoViviendaSeleccionada,eVivienda* viviendas,int len,eCensista* censistas,int lenCensistas,eCatastro* catastros,int lenCatastros);

int mostrarDatosViviviendaCensista(eVivienda* viviendas,int lenViviendas,eCensista* censistas,int lenCensista,int localidad,eTipoDeVivienda* tipoViviendas,int lenTipo);

int mostrarViviendasCensadas(eVivienda* viviendas,int len,int legajoCensita,eCatastro* datosCatastro,int tamanioDatos);

int calculoPromedioHabitantes(eVivienda* arrayViviendas,int lenViviendas,eTipoDeVivienda* arrayTipoViviendas,int lenTipoViviendas,int contadorCasa,int contadorTipoDepartamento,int contadorTipoCasilla,int contadorTipoRancho);

//int calculoHabitantesPorVivienda(int totalHabitanes,eTipoDeVivienda* arrayTipoViviendas,int lenTipoViviendas);
