#ifndef MOVIE_H_INCLUDED
#define MOVIE_H_INCLUDED
typedef struct{
    char titulo[100];
    char genero[50];
    int duracion;
    int idMovie;
    char descripcion[200];
    int puntaje;
    char link[200];
}Movie;
#endif // MOVIE_H_INCLUDED

/** \brief libera la memoria del array
 *
 * \param this Movie* array a liberar memoria
 * \return void
 *
 */
void movie_delete(Movie* this);

/** \brief  asigna memoria dinamica
 *
 * \return Movie* el array con la memoria asignada
 *
 */
Movie* movie_new();

/** \brief Setea los datos al array
 *
 * \param titulo char* titulo a guardar
 * \param genero char* genero a guardar
 * \param duracion int duracion a guardar
 * \param descripcion char* descripcion a guardar
 * \param puntaje int puntaje a guardar
 * \param link char* link a guardar
 * \param id int id a guardar
 * \return Movie* array con los valores cargados, NULL si los parametros son invalidos
 *
 */
Movie* movie_newLoad(char* titulo, char* genero,int duracion,char* descripcion,int puntaje,char* link, int id);
////////////////////////////////////////////////////////
/** \brief Obtiene el id de una pelicula
 *
 * \param this Movie* array de las peliculas
 * \param id int* donde se guarda el id por referencia
 * \return int -1 error en los parametros, 0 correcto
 *
 */
int movie_getId(Movie *this, int* id);

/** \brief setea el titulo al array de peliculas
 *
 * \param this Movie* array de las peliculas
 * \param titulo char* titulo a guardar
 * \return int -1 error en los parametros, 0 todo correcto
 *
 */
int movie_setTitulo(Movie *this, char* titulo);

/** \brief Obtiene el titulo de una pelicula
 *
 * \param this Movie* array de las peliculas
 * \param titulo char* donde se guarda el titulo por referencia
 * \return int -1 error en los parametros, 0 correcto
 *
 */
int movie_getTitulo(Movie *this, char* titulo);

/** \brief setea el genero al array de peliculas
 *
 * \param this Movie* array de las peliculas
 * \param genero char* genero a guardar
 * \return int -1 error en los parametros, 0 todo correcto
 *
 */
int movie_setGenero(Movie *this, char* genero);

/** \brief Obtiene el genero de una pelicula
 *
 * \param this Movie* array de las peliculas
 * \param genero char* donde se guarda el genero por referencia
 * \return int -1 error en los parametros, 0 correcto
 *
 */
int movie_getGenero(Movie *this, char* genero);

/** \brief setea la duracion al array de peliculas
 *
 * \param this Movie* array de las peliculas
 * \param duracion int duracion a guardar
 * \return int -1 error en los parametros, 0 todo correcto
 *
 */
int movie_setDuracion(Movie *this, int duracion);

/** \brief Obtiene la duracion de una pelicula
 *
 * \param this Movie* array de las peliculas
 * \param duracion int* donde se guarda la duracion por referencia
 * \return int -1 error en los parametros, 0 correcto
 *
 */
int movie_getDuracion(Movie *this, int* duracion);

/** \brief setea la descripcion al array de peliculas
 *
 * \param this Movie* array de las peliculas
 * \param descripcion char* descripcion a guardar
 * \return int -1 error en los parametros, 0 todo correcto
 *
 */
int movie_setDescripcion(Movie *this, char* descripcion);

/** \brief Obtiene la descripcion de una pelicula
 *
 * \param this Movie* array de las peliculas
 * \param descripcion char* donde se guarda la descripcion por referencia
 * \return int -1 error en los parametros, 0 correcto
 *
 */
int movie_getDescripcion(Movie *this, char* descripcion);

/** \brief setea el link al array de peliculas
 *
 * \param this Movie* array de las peliculas
 * \param link char* link a guardar
 * \return int -1 error en los parametros, 0 todo correcto
 *
 */
int movie_setLink(Movie *this, char* link);

/** \brief Obtiene el link de una pelicula
 *
 * \param this Movie* array de las peliculas
 * \param link char* donde se guarda el link por referencia
 * \return int -1 error en los parametros, 0 correcto
 *
 */
int movie_getLink(Movie *this, char* link);

/** \brief setea el puntaje al array de peliculas
 *
 * \param this Movie* array de las peliculas
 * \param puntaje int puntaje a guardar
 * \return int -1 error en los parametros, 0 todo correcto
 *
 */
int movie_setPuntaje(Movie *this, int puntaje);

/** \brief Obtiene el puntaje de una pelicula
 *
 * \param this Movie* array de las peliculas
 * \param puntaje int* donde se guarda el puntaje por referencia
 * \return int -1 error en los parametros, 0 correcto
 *
 */
int movie_getPuntaje(Movie *this, int* puntaje);
///////////////////////////////////////////////////////////
/** \brief Funcion para setear los datos al array
 *
 * \param titulo char* titulo a guardar
 * \param genero char* genero a guardar
 * \param duracion int duracion a guardar
 * \param descripcion char* descripcion a guardar
 * \param puntaje int puntaje a guardar
 * \param link char* link a guardar
 * \return Movie* retorna el array cargado con los datos, NULL si los parametros no son correctos
 *
 */
Movie* movie_newAlta(char* titulo, char* genero,int duracion,char* descripcion,int puntaje,char* link);

/** \brief Agrega una pelicula al array
 *
 * \param ArrayMovie Movie** array de las peliculas
 * \param qtyMovieActual int* cantidad de espacio ocupado en el array
 * \return int -1 si los parametros son invalidos, -2 si los datos a cargar son invalidos, 0 todo correcto
 *
 */
int movie_Alta(Movie **ArrayMovie, int *qtyMovieActual);

/** \brief borra una pelicula del array
 *
 * \param ArrayMovie Movie** array de peliculas
 * \param qtyMovieActual int* cantidad de espacio ocupado en el array
 * \param id int el id a borrar
 * \return int -1 parametros invalidos, -2 id invalida, -3 id no se encontro, 0 todo correcto
 *
 */
int movie_Baja(Movie **ArrayMovie, int *qtyMovieActual, int id);
////////////////////////////////////////////////////////////
/** \brief valida que sea un link valido
 *
 * \param url char* el link a validar
 * \return int -1 si no es, 0 si es
 *
 */
int isValidUrl(char *url);

/** \brief Obtiene un link valido
 *
 * \param requestMessage char* mensaje a mostrar al pedir
 * \param errorMessage char* mensaje de error
 * \param errorMessageLenght char* mensaje de error si se acaban los intentos
 * \param input char* donde guardar el link por referencia
 * \param maxLenght int la cantidad maxima de caracteres
 * \param attemps int la cantidad de intentos
 * \return int -1 si no se encontro, 0 si es correcto
 *
 */
int getValidUrl(char *requestMessage,char *errorMessage, char *errorMessageLenght,char *input, int maxLenght,int attemps);
/////////////////////////////////////////////////////////////
/** \brief Muestra una lista de las peliculas con su titulo e id
 *
 * \param movie Movie** el array de las peliculas
 * \param qtyMovieActual int la cantidad ocupada del array
 * \return int -1 si los parametros son invalidos, 0 si esta todo correcto
 *
 */
int movie_lista(Movie** movie, int qtyMovieActual);

/** \brief Modifica un pelicula del array
 *
 * \param movie Movie** el array de las peliuclas
 * \param id int el id a modificar
 * \return int -1 parametros invalidos, -2 si no se encontro el id, -3 datos ingresados para modificar invalidos, 0 todo bien
 *
 */
int movie_modificar(Movie** movie, int qtyMovieActual, int id);

/** \brief Carga el array con los datos ingresados se usa para modificar
 *
 * \param titulo char* el titulo a cargar
 * \param genero char* el genero a cargar
 * \param duracion int la duracion a cargar
 * \param descripcion char* la descripcion a cargar
 * \param puntaje int el puntaje a cargar
 * \param link char* el link a cargar
 * \return Movie* devuelve el array cargado
 *
 */
Movie* movie_newMod(char* titulo, char* genero,int duracion,char* descripcion,int puntaje,char* link, int id);
