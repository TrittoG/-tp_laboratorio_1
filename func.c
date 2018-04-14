#include <stdio.h>
#include <stdlib.h>
#define max 32000
#define min -32000


/** \brief pide un entero al usuario, permitiendo decirle el maximo y el minimo y dandole una cantidad de intentos
 *
 * \param mensaje char* mensajje que se va a mostrar
 * \param error char* error si no esta entre los limites
 * \param intentos int cantidad de intentos que dispone el usuario
 * \param maximo int numero maximo para ingresar
 * \param minimo int numero minimo a ingresar
 * \param resultado int* devuelve el valor que ingreso el usuario
 * \return int 0=ok -1 si es menor -2 si es mayor
 * funcion copiada de un compañero de clase ya que el dia que hice la funcion, no tenia acceso a internet para subir la mia a github
 */
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

/** \brief suma dos numeros ingresados
 *
 * \param numeroUno int primer numero
 * \param numeroDos int segundo numero
 * \param suma int* aca devuelve el resultado
 * \return int retorna 0 ok -1 error
 *
 */
int sumar(int numeroUno, int numeroDos, int *suma)
{
    int retorno;

    retorno = -1;

    if((numeroUno+numeroDos)<max)
    {
        *suma = numeroUno+ numeroDos;
        retorno = 0;
    }
    return retorno;
}


/** \brief resta dos numeros ingresados
 *
 * \param numeroUno int primer numero
 * \param numeroDos int segundo numero
 * \param resta int* aca devuelve el resultado de la resta
 * \return int 0 ok -1 error
 *
 */
int restar(int numeroUno, int numeroDos, int *resta)
{
    int retorno;
    retorno = -1;

    if((numeroUno-numeroDos)>min)
    {
        *resta=numeroUno-numeroDos;
        retorno = 0;
    }
    return retorno;
}

/** \brief divide dos numeros ingresados por el usuario
 *
 * \param numeroUno int primer numero
 * \param numeroDos int segundo numero
 * \param division float* aca devuelve el resultado
 * \return int 0 ok -1 error
 *
 */
int dividir(int numeroUno, int numeroDos, float *division)
{
    int restorno;
    restorno = -1;

    if(numeroDos != 0 || (numeroUno/numeroDos)>max)
    {
        *division= numeroUno/(float)numeroDos;
        restorno = 0;
    }
    return restorno;
}

/** \brief multiplica dos numeros ingresados
 *
 * \param numeroUno int primer numero
 * \param numeroDos int
 * \param multiplica int*
 * \return int
 *
 */
int multiplicacion(int numeroUno, int numeroDos, int *multiplica)
{
    int retorno;
    retorno = -1;


    if((numeroUno*numeroDos) < max)
    {
        *multiplica = numeroUno*numeroDos;
        retorno = 0;
    }
    return retorno;
}

int factorial(int numeroUno, int* factor)
{
    int i;
    int respuesta;
    int aux;
    aux=1;
    respuesta = -1;



    for(i=1; i<=numeroUno;i++)
    {
        aux= i*aux;
        respuesta = 0;
    }
    *factor=aux;
    return respuesta;
}
