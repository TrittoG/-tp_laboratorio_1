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




/** \brief inicia un array de clientes
 *
 * \param array Cliente*
 * \param limite int
 * \return int 0 si todo salio correcto -1 si hay un error
 *
 */
int Cliente_init(Cliente* array,int limite);


/** \brief busca un cliente dentro del array que coincida con el campo ID solicitado
 *
 * \param array Cliente*
 * \param limite int
 * \param id int campo id del cliente
 * \return int la posicion dentro del array del cliente con ese id o -1 si hubo error
 *
 */
int Cliente_buscarPorId(Cliente* array,int limite, int id);


/** \brief da de baja a un cliente buscado por su id
 *
 * \param array Cliente*
 * \param limite int
 * \param id int campo id del cliente
 * \return int 0 si no hubo errores o -1 si hay error
 *
 */
int Cliente_baja(Cliente* array,int limite, int id);




/** \brief da de alta un nuevo cliente
 *
 * \param array Cliente*
 * \param limite int
 * \return int -1 si el array es nulo o si el limite es menor a 0, -2 si el inidice es menor a 0, -3 si hay error en la validacion, 0 si todo esta correcto
 *
 */
int Cliente_alta(Cliente* array,int limite);


/** \brief modifica un cliente dentro del array
 *
 * \param array Cliente*
 * \param limite int
 * \param id int
 * \return int 0 si esta todo correcto, -1 si hay un error en el indice, -2 si hay error de validacion y 0 si esta todo correcto
 *
 */
int Cliente_modificacion(Cliente* array,int limite, int id);


/** \brief
 *
 * \param array Cliente*
 * \param limite int
 * \param orden int
 * \return int
 *
 */
int Cliente_ordenar(Cliente* array,int limite, int orden);



