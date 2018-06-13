#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

typedef struct {

    char nombre[50];
    int edad;
    int isEmpty;
    int dni;
    int IDEpersona;

}EPersona;

/**
 * Obtiene el primer indice libre del array.
 * @param lista el array se pasa como parametro.
 * @return el primer indice disponible
 */
int obtenerEspacioLibre(EPersona lista[], int cantidad_de_elementos);

/**
 * Obtiene el indice que coincide con el dni pasado por parametro.
 * @param lista el array se pasa como parametro.
 * @param dni el dni a ser buscado en el array.
 * @return el indice en donde se encuentra el elemento que coincide con el parametro dni
 */
int buscarPorDni(EPersona lista[], int dni);


void per_alta(EPersona lista[], int dni, int edad, char nombre[30],int id);

int per_baja(EPersona lista[], int cantidad_de_elementos);

void InicializarArry(EPersona array[], int cantidad_de_elementos);

void per_ordenar(EPersona lista[], int cantidad_de_elementos, int orden);

void imprimir_grafico(EPersona lista[], int cantidad_de_elementos);

#endif // FUNCIONES_H_INCLUDED
