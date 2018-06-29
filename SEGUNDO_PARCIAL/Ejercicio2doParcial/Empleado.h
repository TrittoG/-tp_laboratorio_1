#ifndef EMPLEADO_H_INCLUDED
#define EMPLEADO_H_INCLUDED
typedef struct
{
    int id;
    char nombre[128];
    int horasTrabajadas;
}Empleado;

Empleado* Empleado_new();
void Empleado_delete();

int Empleado_setId(Empleado* this,int id);
int Empleado_getId(Empleado* this,int* id);

int Empleado_setNombre(Empleado* this,char* nombre);
int Empleado_getNombre(Empleado* this,char* nombre);

int Empleado_setHorasTrabajadas(Empleado* this,int horasTrabajadas);
int Empleado_getHorasTrabajadas(Empleado* this,int* horasTrabajadas);

Empleado *empleado_newParamateros(int id, char *nombre, int horasTrabajadas);

#endif // EMPLEADO_H_INCLUDED
