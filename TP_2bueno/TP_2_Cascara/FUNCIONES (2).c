#include <stdio.h>
#include <stdlib.h>
#include <string.h>



float getFloat(char mensaje[])
{
    float auxiliar;
    printf("%s",mensaje);
    scanf("%f",&auxiliar);
    return auxiliar;
}




int getIntTrucho(char mensaje[])
{
    int auxiliar;
    printf("%s" ,mensaje);
    scanf("%d", &auxiliar);
    return auxiliar;
}

int getInt(char *mensaje, char *error, int intentos, int maximo, int minimo, int *resultado)
{
    int auxiliarEntero;
    int retorno = -1;
    do
    {
        intentos--;
        printf("%s \n", mensaje);
        scanf("%d", &auxiliarEntero);
        if(auxiliarEntero >= minimo && auxiliarEntero <= maximo)
        {
            retorno = 0;
            *resultado = auxiliarEntero;
            break;
        }
        else
        {
            if(auxiliarEntero < minimo)
            {
                retorno = -2;
            }
            else
            {
                retorno = -1;
            }
        }
        printf("%s", error);
    }while(intentos >= 0);

    return retorno;
}



/** \brief verifica si el valor recibido tiene solo numeros
 *
 * \param string[] array con la cadena a analizar
 * \return 1 si contiene solo numeros 0 si no
 *
 */
int esNumerico(char string[])
{
    int i =0;

    while(string[i]!='\0')
    {
        if(string[i]<'0' || string[i]>'9')
        {
            return 0;
            break;
        }
        i++;
    }//fin del for
    return 1;
}

int esSoloLetras(char string[])
{
    int i=0;

    while(string[i]!='\0')
    {
        if((string[i]!=' ') && (string[i]< 'a' || string[i]>'z')&&(string[i]<'A' || string[i]>'z'))
        {
            return 0;
            break;
        }
        i++;
    }//fin del for
    return 1;
}


int esAlfanumerico(char string[])
{
    int i=0;

    while(string[i]!='\0')
    {
        if((string[i]!=' ') && (string[i]< 'a' || string[i]>'z')&&(string[i]<'A' || string[i]>'z') && (string[i]<'0' || string[i]>'9'))
        {
            return 0;
            break;
        }
        i++;
    }//fin del for
    return 1;
}



int esTelefono(char string[])
{
    int i=0;
    int contadorGuiones;
    contadorGuiones =0;

    while(string[i]!='\0')
    {
        if((string[i]!=' ') && (string[i] != '-')&& (string[i]<'0' || string[i]>'9'))
        {
            return 0;
        }
        if(string[i]== '-')
        {
            contadorGuiones++;
        }
        i++;
    }//fin del for

    if(contadorGuiones == 1)
    {
        return 1;
    }

    return 0;
}


void pedirString(char mensaje[], char string[])
{
    printf("%s" ,mensaje);
    scanf("%s", string);
}


/** \brief solicita un texto al usuario y lo devuelve
 *
 * \param mensaje[] char es el mensaje a ser mostrado
 * \param string[] char es el string que devuelve
 * \return int 1 si el texo cotiene solo letras
 *
 */
int getStringLetras(char mensaje[], char string[])
{
    char aux[256];

    pedirString(mensaje, aux);
    if(esSoloLetras(aux))
    {
        strcpy(string,aux);
        return 1;
    }
    return 0;
}


int getStringNumeros(char mensaje[], char string[])
{
    char aux[256];

    pedirString(mensaje, aux);
    if(esNumerico(aux))
    {
        strcpy(string,aux);
        return 1;
    }
    return 0;
}


void inicializarArray(int array[], int cantidad_de_elementos, int ponerValor)
{
    int i;

    for(i=0;i<cantidad_de_elementos; i++)
    {
        array[i]=ponerValor;
    }

}


int buscarPrimerOcurrencia(int array[], int cantidad_de_elementos, int ponerValor)
{
    int i;
    int retorno = -1;

    for(i=0;i<cantidad_de_elementos;i++)
    {
        if(array[i]== ponerValor)
        {
            retorno = i;
        }
    }

    return retorno;
}
