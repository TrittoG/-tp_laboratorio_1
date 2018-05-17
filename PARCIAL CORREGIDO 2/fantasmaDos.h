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

/** \brief inicia el array de publicacion
 *
 * \param array Publicacion*
 * \param limite int
 * \return int -1 si el array es nulo 0 si esta todo correcto
 *
 */
int Publicacion_init(Publicacion* array,int limite);

/** \brief busca por id una posicion del array
 *
 * \param array Publicacion*
 * \param limite int
 * \param id int
 * \return int -1 si no encuentra i si encuentra un id
 *
 */
int Publicacion_buscarPorId(Publicacion* array,int limite, int id);

/** \brief da de baja una publicacion
 *
 * \param array Publicacion*
 * \param limite int
 * \param id int
 * \return int
 *
 */









