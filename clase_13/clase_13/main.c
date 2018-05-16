#include <stdio.h>
#include <stdlib.h>
#include "persona.h"



void cargar(Alumno **arrayA, int QTY);
void mostrar(Alumno **arrayA, int QTY);



int main()
{
    Alumno *ArrayPunteroA[50];


    cargar(ArrayPunteroA, 50);
    mostrar(ArrayPunteroA,50);

    return 0;
}
void cargar(Alumno **arrayA, int QTY)
{
    int i;


    for(i=0;i<QTY;i++)
    {
        *(arrayA+i) = alumno_new();
        alumno_setEdad(*(arrayA+i), 10+i);
        alumno_setNombre(*(arrayA+i),"asd");


        //(arrayA+i)->edad = 10+i;
        //arrayA[i].edad = 22; *********NO SE USA MAS***************************
    }
}

/*void mostrar(Alumno *arrayA, int QTY)
{
    Alumno *limite = arrayA+ QTY;
    for(;arrayA<limite;arrayA++)
    {
        printf("%d\n" ,arrayA->edad);
    }
}*/


void mostrar(Alumno **arrayA, int QTY)
{
    int auxiliarEdad;
    char auxNombre[20];

    for(;QTY > 0;arrayA++, QTY--)
    {
        alumno_getEdad(*arrayA, &auxiliarEdad);
        alumno_getNombre(*arrayA, &auxNombre);
        printf("%d %s\n" ,auxiliarEdad, auxNombre);
    }
}
