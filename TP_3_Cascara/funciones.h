#include "movie.h"
#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

/**
 *  Agrega una pelicula al archivo binario
 *  @param movie la estructura a ser agregada al archivo
 *  @return retorna -1 o 0 de acuerdo a si pudo agregar la pelicula o no
 */
int funciones_GenerarPaginaWeb(Movie **movie, int *qtyMovieActual, int qtyMovieTotal, char* path);

/** \brief Carga el array con los dato de un archivo
 *
 * \param movie Movie** el array a cargar
 * \param qtyMovieActual int* la cantidad ocupada del array
 * \param path char* direccion del archivo a cargar
 * \return int -1 parametros invalidos, 0 todo correcto
 *
 */
int funciones_movieLoad(Movie** movie, int* qtyMovieActual, char* path);

/** \brief Crea un archivo con los datos del array
 *
 * \param movie Movie** array a guardar
 * \param qtyMovieActual int* cantidad ocupada del array
 * \param path char* direecion donde se debe guardar el archivo
 * \return int -1 parametros invalidos, 0 todo correcto
 *
 */
int funciones_MovieDump(Movie** movie,int qtyMovieActual, char* path);


#endif // FUNCIONES_H_INCLUDED
