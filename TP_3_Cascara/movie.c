#include "movie.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"

static int movie_setId(Movie *this, int id);


Movie* movie_new()
{
    return (Movie*) malloc(sizeof(Movie));
}

void movie_delete(Movie* this)
{
    if(this != NULL)
    free(this);
}

Movie* movie_newAlta(char* titulo, char* genero,int duracion,char* descripcion,int puntaje,char* link)
{
    Movie *auxArray = movie_new();
    movie_setTitulo(auxArray, titulo);
    movie_setDescripcion(auxArray, descripcion);
    movie_setDuracion(auxArray, duracion);
    movie_setGenero(auxArray, genero);
    movie_setLink(auxArray, link);
    movie_setId(auxArray, -1);
    movie_setPuntaje(auxArray, puntaje);
    return auxArray;
}

Movie* movie_newMod(char* titulo, char* genero,int duracion,char* descripcion,int puntaje,char* link, int id)
{
    Movie *auxArray = movie_new();
    movie_setTitulo(auxArray, titulo);
    movie_setDescripcion(auxArray, descripcion);
    movie_setDuracion(auxArray, duracion);
    movie_setGenero(auxArray, genero);
    movie_setLink(auxArray, link);
    movie_setPuntaje(auxArray, puntaje);
    movie_setId(auxArray, id);
    return auxArray;
}
int movie_Alta(Movie **ArrayMovie, int *qtyMovieActual)
{
    int retorno = -1;
    char auxTitulo[100];
    char auxGenero[50];
    int auxDuracion;
    char auxDescripcion[200];
    int auxPuntaje;
    char auxLink[200];
    if(ArrayMovie != NULL && *qtyMovieActual > -1)
    {
        retorno = -2;
        if(getString("Titulo?", auxTitulo))
        {
            retorno = -2;
            if(getString("Genero?", auxGenero))
            {
                retorno = -2;
                if(getString("Descripcion?", auxDescripcion))
                {
                    retorno = -2;
                    if(!getValidInt("Duracion?", "Error", &auxDuracion, 30, 250, 2))
                    {
                        retorno = -2;
                        if(!getValidUrl("Link?", "Error", "Demasiado largo", auxLink, 200, 2))
                        {
                            retorno = -2;
                            if(!getValidInt("Puntaje?", "Error", &auxPuntaje, 1, 10, 2))
                            {
                                ArrayMovie[*qtyMovieActual] = movie_newAlta(auxTitulo, auxGenero, auxDuracion, auxDescripcion, auxPuntaje, auxLink);
                                *qtyMovieActual = *qtyMovieActual + 1;
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

int movie_Baja(Movie **ArrayMovie, int *qtyMovieActual, int id)
{
    int retorno = -1;
    int i;
    int auxId;
    if(ArrayMovie != NULL && *qtyMovieActual > 0)
    {
        retorno = -2;
        if(id >= 0)
        {
            for(i = 0; i < *qtyMovieActual; i++)
            {
                movie_getId(ArrayMovie[i], &auxId);
                if(auxId == id)
                {
                    retorno = 0;
                    movie_delete(ArrayMovie[i]);

                    break;
                }
                retorno = -3;
            }
            if(retorno == 0)
            {
                if(i < *qtyMovieActual)
                {
                    for(; i < *qtyMovieActual; i++)
                    {
                        ArrayMovie[i] = ArrayMovie[i+1];
                    }
                }
                *qtyMovieActual = *qtyMovieActual - 1;
            }
        }
    }
    return retorno;
}

int movie_setTitulo(Movie *this, char* titulo)
{
    int retorno = -1;
    if(this != NULL && titulo != NULL)
    {
        strcpy(this->titulo, titulo);
        retorno = 0;
    }
    return retorno;
}
int movie_getTitulo(Movie *this, char* titulo)
{
    int retorno = -1;
    if(this != NULL && titulo != NULL)
    {
        strcpy(titulo, this->titulo);
        retorno = 0;
    }
    return retorno;
}
int movie_setGenero(Movie *this, char* genero)
{
    int retorno = -1;
    if(this != NULL && genero != NULL)
    {
        strcpy(this->genero, genero);
        retorno = 0;
    }
    return retorno;
}
int movie_getGenero(Movie *this, char* genero)
{
    int retorno = -1;
    if(this != NULL && genero != NULL)
    {
        strcpy(genero, this->genero);
        retorno = 0;
    }
    return retorno;
}
int movie_setDuracion(Movie *this, int duracion)
{
    int retorno = -1;
    if(this != NULL)
    {
        this->duracion = duracion;
        retorno = 0;
    }
    return retorno;
}
int movie_getDuracion(Movie *this, int* duracion)
{
    int retorno = -1;
    if(this != NULL && duracion != NULL)
    {
        *duracion = this->duracion;
        retorno = 0;
    }
    return retorno;
}
int movie_setDescripcion(Movie *this, char* descripcion)
{
    int retorno = -1;
    if(this != NULL && descripcion != NULL)
    {
        strcpy(this->descripcion, descripcion);
        retorno = 0;
    }
    return retorno;
}
int movie_getDescripcion(Movie *this, char* descripcion)
{
    int retorno = -1;
    if(this != NULL && descripcion != NULL)
    {
        strcpy(descripcion, this->descripcion);
        retorno = 0;
    }
    return retorno;
}
int movie_setLink(Movie *this, char* link)
{
    int retorno = -1;
    if(this != NULL && link != NULL)
    {
        strcpy(this->link, link);
        retorno = 0;
    }
    return retorno;
}
int movie_getLink(Movie *this, char* link)
{
    int retorno = -1;
    if(this != NULL && link != NULL)
    {
        strcpy(link, this->link);
        retorno = 0;
    }
    return retorno;
}
int movie_setPuntaje(Movie *this, int puntaje)
{
    int retorno = -1;
    if(this != NULL)
    {
        this->puntaje = puntaje;
        retorno = 0;
    }
    return retorno;
}
int movie_getPuntaje(Movie *this, int* puntaje)
{
    int retorno = -1;
    if(this != NULL && puntaje != NULL)
    {
        *puntaje = this->puntaje;
        retorno = 0;
    }
    return retorno;
}

static int movie_setId(Movie *this, int id)
{
    int retorno = -1;
    static int maximoId = -1;
    if(this != NULL)
    {
        retorno = 0;
        if(id >= 0)
        {
            if(id > maximoId)
                maximoId = id;
            this->idMovie = id;
        }
        else
        {
            maximoId++;
            this->idMovie = maximoId;
        }
    }
    return retorno;
}

int movie_getId(Movie *this, int* id)
{
    int retorno = -1;
    if(this != NULL && id != NULL)
    {
        *id = this->idMovie;
        retorno = 0;
    }
    return retorno;
}

int isValidUrl(char *url)
{
    int retorno = -1;
    int size = strlen(url);
    int i;
    size = size - 4;
    if(!strncmp(url, "www.", 4) || !strncmp(url, "http://", 7) || !strncmp(url, "https://", 8))
    {
        if(url[size] == '.' && url[size+1] == 'j' && url[size+2] == 'p' && url[size+3] == 'g')
        {
            retorno = 0;
            for(i = 0; i < strlen(url); i++)
            {
                if(url[i] == '.' && url[i+1] == '.')
                {
                    retorno = -1;
                    break;
                }
            }
        }

    }
    return retorno;
}

int getValidUrl(char *requestMessage,char *errorMessage, char *errorMessageLenght,char *input, int maxLenght,int attemps)
{
    int i;
    int retorno=-1;
    char buffer[1024];

    for(i=0;i<attemps;i++)
    {
        if (!getString(requestMessage,buffer) && !isValidUrl(buffer))
        {
            printf ("%s",errorMessage);
            continue;
        }
        if(strlen(buffer) >= maxLenght)
        {
            printf ("%s",errorMessageLenght);
            continue;

        }
        retorno=0;
        strcpy(input,buffer);
        break;
    }
    return retorno;
}

Movie* movie_newLoad(char* titulo, char* genero,int duracion,char* descripcion,int puntaje,char* link, int id)
{
    Movie* auxMovie = movie_new();
    if(     !movie_setTitulo(auxMovie, titulo)
       &&   !movie_setGenero(auxMovie, genero)
       &&   !movie_setDuracion(auxMovie, duracion)
       &&   !movie_setDescripcion(auxMovie, descripcion)
       &&   !movie_setPuntaje(auxMovie, puntaje)
       &&   !movie_setLink(auxMovie, link)
       &&   !movie_setId(auxMovie, id))
    {
        return auxMovie;
    }
    movie_delete(auxMovie);
    return NULL;
}

int movie_lista(Movie** movie, int qtyMovieActual)
{
    int retorno = -1;
    int i;
    char titulo[50];
    int id;
    if(movie != NULL && qtyMovieActual > 0)
    {
        retorno = 0;
        for(i = 0; i < qtyMovieActual; i++)
        {
            movie_getTitulo(movie[i], titulo);
            movie_getId(movie[i], &id);
            printf("Titulo: %s, ID: %d\n", titulo, id);
        }
    }
    return retorno;
}

int movie_modificar(Movie** movie, int qtyMovieActual, int id)
{
    int retorno = -1;
    char auxTitulo[100];
    char auxGenero[50];
    int auxDuracion;
    char auxDescripcion[200];
    int auxPuntaje;
    char auxLink[200];
    int auxId;
    if(movie != NULL && qtyMovieActual > 0 && id >= 0)
    {
        int i;
        for(i = 0; i < qtyMovieActual; i++)
        {
            retorno = -2;
            movie_getId(movie[i], &auxId);
            if(auxId == id)
            {
                if(getString("Titulo?", auxTitulo))
                {
                    retorno = -3;
                    if(getString("Genero?", auxGenero))
                    {
                        retorno = -3;
                        if(getString("Descripcion?", auxDescripcion))
                        {
                            retorno = -3;
                            if(!getValidInt("Duracion?", "Error", &auxDuracion, 30, 250, 2))
                            {
                                retorno = -3;
                                if(!getValidUrl("Link?", "Error", "Demasiado largo", auxLink, 200, 2))
                                {
                                    retorno = -3;
                                    if(!getValidInt("Puntaje?", "Error", &auxPuntaje, 1, 10, 2))
                                    {
                                        movie[i] = movie_newMod(auxTitulo, auxGenero, auxDuracion, auxDescripcion, auxPuntaje, auxLink, id);
                                        retorno = 0;
                                    }
                                }
                            }
                        }
                    }
                }
                break;
            }
        }
    }
    return retorno;
}
