#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "fantasmaDos.h"
#include "fantasma.h"
#include "utn.h"
#define QTY 10
#define OCUPADO 0
#define LIBRE 1
#define PAUSADO 2
#define ACTIVO 1

int Cliente_mostrar(Cliente* array,int limite, Publicacion *arrayP, int limite_publicacion)
{
    int retorno = -1;
    int i,j;
    int cantidad = 0;
    if(limite > 0 && array != NULL)
    {
        retorno = 0;
        for(i=0;i<limite;i++)
        {
            if(!array[i].isEmpty)
            {
                for(j=0;j<limite_publicacion;j++)
                {
                    if(arrayP[j].idCliente == array[i].idCliente && arrayP[j].estado == 1)
                    {
                        cantidad++;
                    }
                }
                printf("\nNOMBRE: %s -APELLIDO %s -CUIT %s -ID %d -AVISOS ACTIVOS: %d",array[i].nombre, array[i].apellido, array[i].cuit,array[i].idCliente, cantidad);


            }
        }
    }
    return retorno;
}



int publicacion_pausar(Publicacion *arrayP, int cantidad_publicaciones, Cliente *arrayC, int lim_cliente)
{
    int i;
    int idPublicacion;

    int lugar;

    if(cantidad_publicaciones > 0 && arrayP != NULL)
    {
        if(!getValidInt("Ingrese el id de la publicacion a pausar", "error",&idPublicacion,-1,1001,2))
        {
            for(i=0;i<cantidad_publicaciones;i++)
            {
                if(arrayP[i].idPublicacion == idPublicacion && arrayP[i].isEmpty == OCUPADO)
                {
                     lugar = Cliente_buscarPorId(arrayC, lim_cliente, arrayP[i].idCliente);
                    if(arrayP[i].idCliente == arrayC[lugar].idCliente)
                    {
                        arrayP[i].estado = PAUSADO;
                        printf("nombre del cliente:  %s\n apellido del cliente %s\n" ,arrayC[lugar].nombre, arrayC[lugar].apellido);
                        printf("la publicacion esta pausada");
                    }

                }
            }

        }

    }
    return 0;
}

static int proximoId()
{
    static int ultimoId = -1;
    ultimoId++;
    return ultimoId;
}



int Publicacion_alta(Publicacion* array,int limite, Cliente *arrayC, int limiteCliente )
{
    int retorno = -1;
    char texto[50];
    int idcliente;
    int id;
    int rubro;
    int i;

    if(limite > 0 && array != NULL)
    {

            retorno = -3;
            id = proximoId();
            printf("se creara un nuevo aviso. :)\n");
            if(!getValidInt("id del cliente?","Error", &idcliente,0,50,2))
            {
                if(limiteCliente >0 && arrayC != NULL)
                {
                    for(i=0;i<limiteCliente;i++)
                    {
                        if(arrayC[i].idCliente == idcliente)
                        {
                            if(!getValidString("Ingrese el texto de aviso: ","error", "overflow",texto,64,2))
                            {
                                if(!getValidInt("ingrese el numero de rubro: ", "error",&rubro,-1,5,5))
                                {
                                    strcpy(array[i].textoAviso, texto);
                                    array[i].rubro = rubro;
                                    array[i].idPublicacion = id;
                                    array[i].isEmpty = OCUPADO;
                                    array[i].estado = ACTIVO;
                                    retorno = 0;
                                    printf("%s\n", texto);
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

int publicacion_reanudar(Publicacion *arrayP, int cantidad_publicaciones, Cliente *arrayC, int lim_cliente)
{
    int i;
    int idPublicacion;

    int lugar;

    if(cantidad_publicaciones > 0 && arrayP != NULL)
    {
        if(!getValidInt("Ingrese el id de la publicacion a reanudar", "error",&idPublicacion,-1,1001,2))
        {
            for(i=0;i<cantidad_publicaciones;i++)
            {
                if(arrayP[i].idPublicacion == idPublicacion && arrayP[i].isEmpty == OCUPADO)
                {
                     lugar = Cliente_buscarPorId(arrayC, lim_cliente, arrayP[i].idCliente);
                    if(arrayP[i].idCliente == arrayC[lugar].idCliente)
                    {
                        arrayP[i].estado = ACTIVO;
                        printf("nombre del cliente:  %s\n apellido del cliente %s\n" ,arrayC[lugar].nombre, arrayC[lugar].apellido);
                        printf("la publicacion se encuentra nuevamente activa\n");
                    }

                }
            }

        }

    }
    return 0;

}


int publicaciones_mostrar(Cliente* array,int limite, Publicacion *arrayP, int limite_publicacion)
{
    int retorno = -1;
    int i,j;
    char cuit[50];

    if(limite_publicacion > 0 && arrayP != NULL)
    {
        retorno = 0;
        for(i=0;i<limite_publicacion;i++)
        {
            if(!arrayP[i].isEmpty && arrayP[i].estado == ACTIVO)
            {
                for(j=0;j<limite;j++)
                {
                    if(array[j].idCliente == arrayP[i].idCliente)
                    {
                        strcpy(cuit,array[j].cuit);
                    }
                }

                printf("TEXTO: %s - RUBRO %d - ID %d - cuit del cliente: %s\n", arrayP[i].textoAviso, arrayP[i].rubro,arrayP[i].idPublicacion,cuit );


            }
        }
    }
    return retorno;
}

informar_clienteConMasAvisosActivos(Cliente* arrayC,int limite, Publicacion *arrayP, int limite_publicacion)
{
    int i;

    if(arrayC != NULL && arrayP != NULL && limite > 0 && limite_publicacion > 0)
    {
        for(i=0;i<limite_publicacion;i++)
        {
            if(arrayP[i].isEmpty)

        }
    }
}

