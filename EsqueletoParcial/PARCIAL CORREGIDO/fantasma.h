#ifndef CLIENTE_H_INCLUDED
#define CLIENTE_H_INCLUDED

typedef struct
{
    char nombre[50];
    char apellido[50];
    char cuit[50];
    //------------
    int idCliente;
    int isEmpty;
}Cliente;
#endif // Cliente_H_INCLUDED




int Cliente_init(Cliente* array,int limite);
int Cliente_buscarPorId(Cliente* array,int limite, int id);
int Cliente_baja(Cliente* array,int limite, int id);

int Cliente_mostrarDebug(Cliente* array,int limite);
int Cliente_alta(Cliente* array,int limite);
int Cliente_modificacion(Cliente* array,int limite, int id);
int Cliente_ordenar(Cliente* array,int limite, int orden);



