#include "movie.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"

int funciones_GenerarPaginaWeb(Movie **movie, int *qtyMovieActual, int qtyMovieTotal, char* path)
{
    int retorno = -1;
    int i;
    char titulo[100];
    char genero[50];
    int duracion;
    char descripcion[200];
    int puntaje;
    char link[200];
    FILE* pFile;
    pFile = fopen(path,"w");
    if(pFile != NULL && movie != NULL && qtyMovieTotal > 0 && *qtyMovieActual >= 0 &&  qtyMovieTotal > *qtyMovieActual)
    {
        retorno = 0;
        fprintf(pFile, "<!DOCTYPE html>\n\
                        <!-- Template by Quackit.com -->\n\
                        <html lang='en'>\n\
                        <head>\n\
                        <meta charset='utf-8'>\n\
                        <meta http-equiv='X-UA-Compatible' content='IE=edge'>\n\
                        <meta name='viewport' content='width=device-width, initial-scale=1'>\n\
                        <!-- The above 3 meta tags *must* come first in the head; any other head content must come *after* these tags -->\n\
                        <title>Lista peliculas</title>\n\
                        <!-- Bootstrap Core CSS -->\n\
                        <link href='css/bootstrap.min.css' rel='stylesheet'>\n\
                        <!-- Custom CSS: You can use this stylesheet to override any Bootstrap styles and/or apply your own styles -->\n\
                        <link href='css/custom.css' rel='stylesheet'>\n\
                        <!-- HTML5 Shim and Respond.js IE8 support of HTML5 elements and media queries -->\n\
                        <!-- WARNING: Respond.js doesn't work if you view the page via file:// -->\n\
                        <!--[if lt IE 9]>\n\
                        <script src='https://oss.maxcdn.com/libs/html5shiv/3.7.0/html5shiv.js'></script>\n\
                        <script src='https://oss.maxcdn.com/libs/respond.js/1.4.2/respond.min.js'></script>\n\
                        <![endif]-->\n\
                        </head>\n\
                        <body>\n\
                        <div class='container'>\n\
                        <div class='row'>\n\
                        <!-- Repetir esto para cada pelicula -->\n\
                        <article class='col-md-4 article-intro'>\n");

        for(i=0;i<*qtyMovieActual;i++)
        {
            movie_getTitulo(movie[i], titulo);
            movie_getGenero(movie[i], genero);
            movie_getDescripcion(movie[i], descripcion);
            movie_getDuracion(movie[i], &duracion);
            movie_getPuntaje(movie[i], &puntaje);
            movie_getLink(movie[i], link);
            fprintf(pFile,"<a href='#'> <img class='img-responsive img-rounded' src='%s' alt=''> </a> <h3> <a href='#'>%s</a> </h3> <ul> <li>Género:%s</li> <li>Puntaje:%d</li> <li>Duración:%d</li> </ul> <p>%s</p>",link,titulo,genero,puntaje,duracion,descripcion);
        }
        fprintf(pFile, "</article>\n\
         <!-- Repetir esto para cada pelicula -->\n\
         </div>\n\
         <!-- /.row -->\n\
         </div>\n\
         <!-- /.container -->\n\
         <!-- jQuery -->\n\
         <script src='js/jquery-1.11.3.min.js'></script>\n\
         <!-- Bootstrap Core JavaScript -->\n\
         <script src='js/bootstrap.min.js'></script>\n\
         <!-- IE10 viewport bug workaround -->\n\
         <script src='js/ie10-viewport-bug-workaround.js'></script>\n\
         <!-- Placeholder Images -->\n\
         <script src='js/holder.min.js'></script>\n\
         </body>\n\
         </html>\n");
    }
    fclose(pFile);
    return retorno;
}

int funciones_movieLoad(Movie** movie, int* qtyMovieActual, char* path)
{
    int retorno = -1;
    FILE* pFile;
    Movie* auxMovie = movie_new();
    if(movie != NULL && path != NULL)
    {
        pFile = fopen(path, "rb");
        if(pFile != NULL)
        {
            while(fread(auxMovie, sizeof(Movie), 1, pFile) == 1)
            {
                movie[*qtyMovieActual] = movie_newLoad(auxMovie->titulo, auxMovie->genero, auxMovie->duracion, auxMovie->descripcion, auxMovie->puntaje, auxMovie->link, auxMovie->idMovie);
                printf("%s\n", movie[*qtyMovieActual]->titulo);
                (*qtyMovieActual)++;
            }
            fclose(pFile);
            retorno = 0;
        }
    }
    return retorno;
}

int funciones_MovieDump(Movie** movie, int qtyMovieActual, char* path)
{
    FILE *f;
    int i;
    int retorno = -1;
    f = fopen(path, "wb");
    if(f!=NULL)
    {
        retorno = 0;
        for(i=0;i<qtyMovieActual;i++)
            fwrite(movie[i],sizeof(Movie), 1,f);
    }
    fclose(f);
    return retorno;
}
