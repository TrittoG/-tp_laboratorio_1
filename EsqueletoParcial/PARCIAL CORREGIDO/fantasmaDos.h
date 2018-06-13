#ifndef PublicacionDOS_H_INCLUDED
#define PublicacionDOS_H_INCLUDED

typedef struct
{
    int idCliente;
    char textoAviso[64];
    int rubro;
    //------------
    int idPublicacion;
    int isEmpty;
    int estado;
}Publicacion;

#endif // PublicacionDOS_H_INCLUDED

int Publicacion_init(Publicacion* array,int limite);
int Publicacion_buscarPorId(Publicacion* array,int limite, int id);
int Publicacion_baja(Publicacion* array,int limite, int id);

int Publicacion_mostrar(Publicacion* array,int limite);
int Publicacion_mostrarDebug(Publicacion* array,int limite);
int Publicacion_modificacion(Publicacion* array,int limite, int id);
int Publicacion_ordenar(Publicacion* array,int limite, int orden);



