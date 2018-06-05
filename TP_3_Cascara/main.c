#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"
#include "movie.h"
#define QTY 50
#include "utn.h"
int main()
{
    Movie *arrayMovie[QTY];
    char seguir='s';
    int opcion=0;
    int QTY_OCUPADO = 0;
    int id;
    int resultado;
    funciones_movieLoad(arrayMovie, &QTY_OCUPADO, "Datos/datos2.bin");
    while(seguir=='s')
    {
        printf("1- Agregar pelicula\n");
        printf("2- Borrar pelicula\n");
        printf("3- Modificar pelicula\n");
        printf("4- Generar pagina web\n");
        printf("5- Salir\n");

        scanf("%d",&opcion);

        switch(opcion)
        {
            case 1:
                resultado = movie_Alta(arrayMovie, &QTY_OCUPADO);
                if(resultado == -1)
                {
                    printf("Error\n");
                }
                else
                {
                    if(resultado == -2)
                    {
                        printf("Error\n");
                    }
                    else
                        printf("Creado\n");
                }
                break;
            case 2:
                movie_lista(arrayMovie, QTY_OCUPADO);
                getValidInt("Id?", "Error", &id, 0, 1000, 2);
                resultado = movie_Baja(arrayMovie, &QTY_OCUPADO, id);
                if(resultado == -1)
                {
                    printf("Parametros invalidos\n");
                }
                else
                {
                    if(resultado == -2)
                    {
                        printf("ID invalida\n");
                    }
                    else
                    {
                        if(resultado == -3)
                        {
                            printf("La ID no fue encontrada\n");
                        }
                        else
                            printf("Borrado\n");
                    }
                }
                break;
            case 3:
                movie_lista(arrayMovie, QTY_OCUPADO);
                getValidInt("Id a modificar", "Error", &id, 0, 1000, 2);
                resultado = movie_modificar(arrayMovie, QTY_OCUPADO, id);
                if(resultado == -1)
                {
                    printf("Parametros invalidos\n");
                }
                else
                {
                    if(resultado == -2)
                    {
                        printf("ID invalida\n");
                    }
                    else
                    {
                        if(resultado == -3)
                        {
                            printf("La ID no fue encontrada\n");
                        }
                        else
                            printf("Modificado\n");
                    }
                }
                break;
            case 4:
                resultado = funciones_GenerarPaginaWeb(arrayMovie, &QTY_OCUPADO, QTY, "Pagina Web/index.html");
                if(resultado == -1)
                {
                    printf("Parametros invalidos\n");
                }
                else
                {
                    printf("Generada correctamente en la carpeta 'Pagina Web/index.html'");
                }
                break;
            case 5:
                seguir = 'n';
                break;
            default :
                printf("Opcion invalida\n");
                break;
        }
    }
    funciones_MovieDump(arrayMovie, QTY_OCUPADO, "Datos/datos2.bin");

    return 0;
}
