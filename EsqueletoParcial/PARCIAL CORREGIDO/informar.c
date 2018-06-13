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
                                if(!getValidInt("ingrese el numero de rubro: (0-xxxxxx 1-xxxxxx)", "error",&rubro,-1,5,5))
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
                    if(array[i].idCliente == arrayP[j].idCliente)
                    {
                        strcpy(cuit,array[i].cuit);
                    }
                }

                printf("TEXTO: %s - RUBRO %d - ID %d - cuit del cliente: %s\n", arrayP[i].textoAviso, arrayP[i].rubro,arrayP[i].idPublicacion,cuit );


            }
        }
    }
    return retorno;
}

int contador_avisos(Publicacion *arrayP, int limite_publicacion, int id)
{
    int i;
    int contador =0;

    if(arrayP != NULL && limite_publicacion > 0)
    {
        for(i=0;i<limite_publicacion;i++)
        {
            if(!arrayP[i].isEmpty && arrayP[i].idCliente == id)
            {
                contador++;
            }
        }
    }
    return contador;
}


int informar_clienteConMasAvisosActivos(Cliente* arrayC,int limite, Publicacion *arrayP, int limite_publicacion)
{
    int i;
    int indice;
    int maximo = 0;
    int contador = 0;
    int j;

    if(arrayC != NULL && limite >0)
    {
        for(i=0;i<limite;i++)
        {
            if(contador > maximo)
            {
                maximo = contador;
                indice = i - 1;
            }
            contador = 0;
            for(j=0;j<limite_publicacion;j++)
            {
                if(!arrayP[j].isEmpty && arrayP[j].idCliente == arrayC[i].idCliente && arrayP[j].estado)
                contador++;
            }
        }

    }

    printf("El cliente con mas avisos activos es: %s, con %d avisos\n", arrayC[indice].nombre, maximo);
    return 0;
}

int informar_clienteConMasAvisosPausados(Cliente* arrayC,int limite, Publicacion *arrayP, int limite_publicacion)
{
    int i;
    int indice;
    int maximo = 0;
    int contador = 0;
    int j;

    if(arrayC != NULL && limite >0)
    {

        for(i=0;i<limite;i++)
        {
            if(!arrayC[i].isEmpty)
            {
                if(contador > maximo)
                {
                    maximo = contador;
                    indice = i - 1;
                }
                contador = 0;
                for(j=0;j<limite_publicacion;j++)
                {
                    if(!arrayP[j].isEmpty && arrayP[j].idCliente == arrayC[i].idCliente && !arrayP[j].estado)
                    contador++;
                }

            }

        }
    }
    printf("El cliente con mas avisos pausados es: %s, con %d avisos\n", arrayC[indice].nombre, maximo);
    return 0;
}


int informar_clienteConMasAvisos(Cliente* arrayC,int limite, Publicacion *arrayP, int limite_publicacion)
{
    int i;
    int indice;
    int maximo = 0;
    int contador = 0;
    int j;
    for(i=0;i<limite;i++)
    {
        if(contador > maximo)
        {
            maximo = contador;
            indice = i - 1;
        }
        contador = 0;
        for(j=0;j<limite_publicacion;j++)
        {
            if(!arrayP[j].isEmpty && arrayP[j].idCliente == arrayC[i].idCliente)
                contador++;
        }
    }

    printf("El cliente con mas avisos es: %s, con %d avisos\n", arrayC[indice].nombre, maximo);
    return 0;

}


int cantidadPublicacionRubroIngresado(Publicacion *arrayP, int limiteP)
{
    int i;
    int rubro;
    int contador = 0;
    getValidInt("Rubro?", "Error", &rubro, 0, 100, 2);
    for(i=0;i<limiteP;i++)
    {
        if(!arrayP[i].isEmpty && arrayP[i].rubro == rubro)
            contador++;
    }
    printf("El rubro elegido tiene %d publicaciones\n", contador);
    return 0;
}



int rubroMasPublicacionesActivas(Publicacion *arrayP, int limiteP)
{
    int i;
    int indice;
    int maximo = 0;
    int contador = 0;
    int j;
    for(i=0;i<limiteP;i++)
    {
        if(contador > maximo)
        {
            maximo = contador;
            indice = i - 1;
        }
        contador = 0;
        for(j=i+1;j<limiteP;j++)
        {
            if(!arrayP[j].isEmpty && arrayP[j].estado && arrayP[j].rubro == arrayP[i].rubro)
                contador++;
        }
    }

    printf("El rubro con mas avisos activos es: %d, con %d avisos\n", arrayP[indice].rubro, maximo);
    return 0;
}


int rubroMenosPublicacionesActivas(Publicacion *arrayP, int limiteP)
{
    int i;
    int indice;
    int maximo = 0;
    int contador = 0;
    int j;
    for(i=0;i<limiteP;i++)
    {
        if(contador < maximo)
        {
            maximo = contador;
            indice = i - 1;
        }
        contador = 0;
        for(j=i+1;j<limiteP;j++)
        {
            if(!arrayP[j].isEmpty && arrayP[j].estado && arrayP[j].rubro == arrayP[i].rubro)
                contador++;
        }
    }

    printf("El rubro con mas avisos activos es: %d, con %d avisos\n", arrayP[indice].rubro, maximo);
    return 0;
}
