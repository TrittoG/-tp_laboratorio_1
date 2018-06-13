#include "funciones.h"
#include <string.h>
#define QTY 20
#include "FUNCIONES.h"
#include <string.h>
#include <stdio.h>

void InicializarArry(EPersona array[], int cantidad_de_elementos)
{
    int i;

    for(i=0;i<cantidad_de_elementos;i++)
    {
        array[i].dni = '\0';
        array[i].edad = '\0';
        strcpy(array[i].nombre, " ");
        array[i].isEmpty = 1;

    }

}

/**
 * Obtiene el primer indice libre del array.
 * @param lista el array se pasa como parametro.
 * @return el primer indice disponible
 */
int obtenerEspacioLibre(EPersona lista[], int cantidad_de_elementos)
{

    int i;
    int retorno = -1;

    for(i=0; i< cantidad_de_elementos; i++)//no se puede hacer una cascara de eso y despues modificarla para cada uso?
    {
        if(lista[i].isEmpty == 1)
        {
            retorno = i;
            break;
        }

    }

    return retorno;

}


void per_alta(EPersona lista[], int dni, int edad, char nombre[30], int id)
{
    int espacioLibre;


    espacioLibre = obtenerEspacioLibre(lista, QTY);

    if(espacioLibre >=0)
    {
        lista[espacioLibre].dni = dni;
        lista[espacioLibre].edad = edad;
        strcpy(lista[espacioLibre].nombre,nombre);
        lista[espacioLibre].isEmpty = 0;
        lista[espacioLibre].IDEpersona = id;
    }
    else
    {
        printf("error no hay lugar.");
    }


}

int per_baja(EPersona lista[], int cantidad_de_elementos)
{
    int i;
    int id;
    int retorno;

    id = getIntTrucho("Ingrese el ID de la persona a ser borrada: ");

    for(i=0; i < cantidad_de_elementos;i++)
    {
        if(lista[i].IDEpersona == id)
        {
            lista[i].isEmpty = 1;
            retorno = 0;
            break;
        }
        else
        {
            retorno = -1;
        }
    }
    return retorno;
}

void per_ordenar(EPersona lista[], int cantidad_de_elementos, int orden)
{

    EPersona aux;

    int i;
    int flagSwap;
    int resultadoComparacion;

    do
    {
        flagSwap = 0;
        for(i=0;i< cantidad_de_elementos-1;i++)
        {
            resultadoComparacion = strcmp(lista[i].nombre, lista[i+1].nombre);
            if((resultadoComparacion > 0 && orden == 0) || (resultadoComparacion < 0 && orden == 1))
            {
                if(lista[i].isEmpty==0 && lista[i+1].isEmpty == 0)
                {

                    aux = lista[i];
                    lista[i]=lista[i+1];
                    lista[i+1] = aux;
                    flagSwap = 1;




                }

            }

        }//fin del for

    }while(flagSwap==1);


}





void per_mostrar(EPersona lista[], int cantidad_de_elementos)
{
    int i;
    int contador =0;

    for(i=0; i< cantidad_de_elementos;i++)
    {
        if(lista[i].isEmpty == 0)
        {
            printf("NOMBRE: %s ", lista[i].nombre);
            printf("EDAD: %d ", lista[i].edad);
            printf("DNI: %d ", lista[i].dni);
            printf("ID: %d\n\n", lista[i].IDEpersona);
            contador++;

        }

    }


    if(contador == 0)
    {
        printf("error no hay usuarios registrados!\n");
    }

}




void imprimir_grafico(EPersona lista[], int cantidad_de_elementos)
{
    int i;
    int contadorMenores=0;
    int contadorMedianos=0;
    int contadorViejos=0;


    for(i=0;i<cantidad_de_elementos;i++)
    {
        if(lista[i].isEmpty == 0)
        {
                if(lista[i].edad <= 18)
                {
                    contadorMenores++;
                }
                if(lista[i].edad >18 && lista[i].edad < 35)
                {
                    contadorMedianos++;
                }
                if(lista[i].edad >= 35)
                {
                    contadorViejos++;
                }

        }//fin del if

    }//fin del for


    for(int j=0; j< contadorMenores;j++)
    {
        printf("  *                               \n");
    }
   // printf("\n");

    //*****************************************
    //printf("entre 19 y 35: ");

    for(int q=0; q< contadorMedianos;q++)
    {
        printf("           *         \n");
    }
    //*****************************************
    for(int a=0; a< contadorViejos;a++)
    {
        printf("                   *\n");
    }
    printf("\n");

    printf("<18     19 y 35     >35 \n");

}
