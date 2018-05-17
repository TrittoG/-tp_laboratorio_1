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
    int clie = 0;
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
                clie =1;

            }
        }
        if(clie ==0)
        {
            printf("no hay clientes!");
            retorno =0;
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

static int buscarLugarLibre(Publicacion* array,int limite)
{
    int retorno = -1;
    int i;
    if(limite > 0 && array != NULL)
    {
        retorno = -2;
        for(i=0;i<limite;i++)
        {
            if(array[i].isEmpty == LIBRE)
            {
                retorno = i;
                break;
            }
        }
    }
    return retorno;
}


int Publicacion_alta(Publicacion* array,int limite, Cliente *arrayC, int limiteC)
{
    int retorno = -1;
    char texto[65];
    int rubro;
    int idCliente;
    int id;
    int indice;

        if(limite > 0 && array != NULL && arrayC != NULL && limiteC > 0)
        {
            retorno = -2;
            indice = buscarLugarLibre(array,limite);
            if(indice >= 0)
            {
                retorno = -3;
                id = proximoId();
                printf("se creara un nuevo aviso. :)\n");
                if(!getValidInt("id del cliente?","Error", &idCliente,0,50,2))
                {
                        if(!getValidString("Texto del aviso?","Error","Overflow", texto,65,2))
                        {
                            if(!getValidInt("Rubro?", "Error", &rubro, 0, 50, 2))
                            {
                                retorno = 0;
                                array[indice].rubro = rubro;
                                array[indice].idCliente = idCliente;
                                strcpy(array[indice].textoAviso,texto);
                                array[indice].idPublicacion = id;
                                array[indice].isEmpty = OCUPADO;
                                array[indice].estado = ACTIVO;
                                printf("Texto: %s  IdCliente: %d\n", array[indice].textoAviso, arrayC[indice].idCliente);

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


int idPublicacionesCliente(Cliente *arrayC, int limiteC, Publicacion *arrayP, int limiteP, int idCliente)
{
    int i;
    for(i=0;i<limiteC;i++)
    {
        if(!arrayC[i].isEmpty && arrayC[i].idCliente == idCliente)
        {
            return i;
        }
    }
    return -1;
}



int publicaciones_mostrar(Cliente* array,int limite, Publicacion *arrayP, int limite_publicacion)
{
    int retorno = -1;
    int i,index;
    //char cuit[50];
    int publi = 0;

    if(limite_publicacion > 0 && arrayP != NULL && limite>0 && array != NULL)
    {
        retorno = -2;
        for(i=0;i<limite_publicacion;i++)
        {
            if(!arrayP[i].isEmpty && arrayP[i].estado == ACTIVO)
            {
                index = idPublicacionesCliente(array,limite,arrayP,limite_publicacion,arrayP[i].idCliente);

                printf("TEXTO: %s - RUBRO %d - ID %d - cuit del cliente: %s\n", arrayP[i].textoAviso, arrayP[i].rubro,arrayP[i].idPublicacion,array[index].cuit );
                publi = 1;
                retorno =0;
            }
        }
        if(publi ==0)
        {
            printf("no hay publicaciones!");
            retorno =0;
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
                if(!arrayP[j].isEmpty && arrayP[j].idCliente == arrayC[i].idCliente && arrayP[j].estado && arrayP[j].estado == ACTIVO)
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
    int retorno=-1;

    if(arrayC != NULL && limite >0)
    {
        retorno = -2;
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
                    if(!arrayP[j].isEmpty && arrayP[j].idCliente == arrayC[i].idCliente && arrayP[j].estado == PAUSADO)
                    {
                        contador++;
                        retorno =0;
                    }

                }

            }

        }
    }
    printf("El cliente con mas avisos pausados es: %s, con %d avisos\n", arrayC[indice].nombre, maximo);
    return retorno;
}


int informar_clienteConMasAvisos(Cliente* arrayC,int limite, Publicacion *arrayP, int limite_publicacion)
{

    int i;
    int indice;
    int maximo = 0;
    int contador = 0;
    int j;
    int retorno = -1;
    if(arrayC != NULL && arrayP != NULL && limite > 0 && limite_publicacion > 0)
    {
        retorno = -2;
        for(i=0;i<limite;i++)
        {
            if(contador > maximo)
            {
                maximo = contador;
                indice = i - 1;
                retorno = 0;
            }
            contador = 0;
            for(j=0;j<limite_publicacion;j++)
            {
                if(!arrayP[j].isEmpty && arrayP[j].idCliente == arrayC[i].idCliente)
                    contador++;
            }
        }
    }
    if(retorno == 0)
        printf("El cliente con mas avisos es: %s, con %d avisos\n", arrayC[indice].nombre, maximo);
    return retorno;
}


int cantidadPublicacionRubroIngresado(Publicacion *arrayP, int limiteP)
{
    int i;
    int rubro;
    int contador = 0;
    int retorno = -1;
    getValidInt("Rubro?", "Error", &rubro, 0, 100, 2);
    for(i=0;i<limiteP;i++)
    {   retorno = -2;
        if(!arrayP[i].isEmpty && arrayP[i].rubro == rubro)
        {
             contador++;
            retorno = 0;
        }
    }
    printf("El rubro elegido tiene %d publicaciones\n", contador);
    return retorno;
}



int rubroMasPublicacionesActivas(Publicacion *arrayP, int limiteP)
{
    int i;
    int indice;
    int maximo = 0;
    int contador = 0;
    int j;
    int retorno=-1;
    for(i=0;i<limiteP;i++)
    {
        retorno =-2;
        if(contador > maximo)
        {
            maximo = contador;
            indice = i - 1;
        }
        contador = 0;
        for(j=i+1;j<limiteP;j++)
        {
            if(!arrayP[j].isEmpty && arrayP[j].estado && arrayP[j].rubro == arrayP[i].rubro)
               {
                 contador++;
                retorno=0;
               }
        }
    }

    printf("El rubro con mas avisos activos es: %d, con %d avisos\n", arrayP[indice].rubro, maximo);
    return retorno;
}


int rubroMenosPublicacionesActivas(Publicacion *arrayP, int limiteP)
{
    int i;
    int indice;
    int maximo = 0;
    int contador = 0;
    int j;
    int retorno= -1;

    if(arrayP != NULL && limiteP > 0)
    {
        retorno = -2;
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
                retorno = 0;
            }
        }
    }


    printf("El rubro con mas avisos activos es: %d, con %d avisos\n", arrayP[indice].rubro, maximo);
    return retorno;
}
