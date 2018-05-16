#include <stdio.h>
#include <stdlib.h>
#include "persona.h"
#include <string.h>

/** \brief crea un elemento de la entidad
 *
 * \return Alumno* un elemento de la entidad
 *
 */
Alumno* alumno_new()
{
    return malloc(sizeof(Alumno));
}


/** \brief borra a un elemento de la entidad
 *
 * \param this Alumno*
 *
 */
void alumno_delete(Alumno *this)
{
    free(this);
}


int alumno_setEdad(Alumno *this, int edad)
{
    int retorno = -1;

    if(this != NULL && edad >=0)
    {
        retorno = 0;
        this->edad = edad;
    }

    return retorno;
}

int alumno_getEdad(Alumno *this, int *edad)
{
    int retorno = -1;

     if(this != NULL && edad != NULL)
    {
        retorno = 0;
        *edad = this->edad;
    }

    return retorno;

}

int alumno_setNombre(Alumno *this, char *nombre)
{
    int retorno = -1;

    if(this != NULL)
    {
        strcpy(this->nombre, nombre);
        retorno = 0;
    }
    return retorno;
}



int alumno_getNombre(Alumno *this, char *nombre)
{
    int retorno = -1;

     if(this != NULL)
    {
        strcpy(*nombre, this->nombre);
         retorno = 0;
    }

    return retorno;

}
