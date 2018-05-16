#ifndef PERSONA_H_INCLUDED
#define PERSONA_H_INCLUDED


typedef struct
{
    char nombre[20];
    char apellido[20];
    int edad;

}Alumno;

#endif // PERSONA_H_INCLUDED
Alumno* alumno_new();
void alumno_delete(Alumno *this);
int alumno_setEdad(Alumno *this, int edad);
int alumno_getEdad(Alumno *this, int *edad);
int alumno_setNombre(Alumno *this, char *nombre);
int alumno_getNombre(Alumno *this, char *nombre);


