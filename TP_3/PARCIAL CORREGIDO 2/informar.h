/** \brief muestra una lista de clientes con sus datos y la cantidad de avios que posee
 *
 * \param array Cliente*
 * \param limite int
 * \param arrayP Publicacion*
 * \param limite_publicacion int
 * \return int 0 si esta todo correcto
 *
 */
int Cliente_mostrar(Cliente* array,int limite, Publicacion *arrayP, int limite_publicacion);


/** \brief pausa una publicacion
 *
 * \param arrayP Publicacion*
 * \param cantidad_publicaciones int
 * \param arrayC Cliente*
 * \param lim_cliente int
 * \return int 0 si esta todo correcto
 *
 */
int publicacion_pausar(Publicacion *arrayP, int cantidad_publicaciones, Cliente *arrayC, int lim_cliente);



/** \brief da de alta una publicacion pidiendo datos del cliente
 *
 * \param array Publicacion*
 * \param limite int
 * \param arrayC Cliente*
 * \param limiteCliente int
 * \return int 0 si todo esta correcto
 *
 */
int Publicacion_alta(Publicacion* array,int limite, Cliente *arrayC, int limiteCliente );


/** \brief reanuda una publicacion pausada cambiando el flag de estado
 *
 * \param arrayP Publicacion*
 * \param cantidad_publicaciones int
 * \param arrayC Cliente*
 * \param lim_cliente int
 * \return int 0 si todo esta correcto
 *
 */
int publicacion_reanudar(Publicacion *arrayP, int cantidad_publicaciones, Cliente *arrayC, int lim_cliente);



/** \brief muestra una lista de publicaciones
 *
 * \param array Cliente*
 * \param limite int
 * \param arrayP Publicacion*
 * \param limite_publicacion int
 * \return int
 *
 */
int publicaciones_mostrar(Cliente* array,int limite, Publicacion *arrayP, int limite_publicacion);



/** \brief muestra el cliente con mas avisos activos
 *
 * \param arrayC Cliente*
 * \param limite int
 * \param arrayP Publicacion*
 * \param limite_publicacion int
 * \return int 0 si no hay errores
 *
 */
int informar_clienteConMasAvisosActivos(Cliente* arrayC,int limite, Publicacion *arrayP, int limite_publicacion);

/** \brief informa los clientes con mas avisos pausados
 *
 * \param arrayC Cliente*
 * \param limite int
 * \param arrayP Publicacion*
 * \param limite_publicacion int
 * \return int 0 si todo esta correcto -1 si el array es nulo -2 si no hay espacio
 *
 */
int informar_clienteConMasAvisosPausados(Cliente* arrayC,int limite, Publicacion *arrayP, int limite_publicacion);

/** \brief informa e cliente con mas avisos
 *
 * \param arrayC Cliente*
 * \param limite int
 * \param arrayP Publicacion*
 * \param limite_publicacion int
 * \return int 0 si todo esta correcto, -1 si el array es nulo -2 si no hay espacio
 *
 */
int informar_clienteConMasAvisos(Cliente* arrayC,int limite, Publicacion *arrayP, int limite_publicacion);


/** \brief informa la cantidad de publicaciones de un rubro ingresado por el usuario
 *
 * \param arrayP Publicacion*
 * \param limiteP int
 * \return int 0 si todo esta correcto, -1 si el array es nulo, -2 si no hay espacio en el array
 *
 */
int cantidadPublicacionRubroIngresado(Publicacion *arrayP, int limiteP);


/** \brief debuelve el rubro que mas publicaciones activas tenga
 *
 * \param arrayP Publicacion*
 * \param limiteP int
 * \return int 0 si todo esta correcto, -1 si el array es nulo, -2 si no hay espacio en el array
 *
 */
int rubroMasPublicacionesActivas(Publicacion *arrayP, int limiteP);



/** \brief informa el rubro con menos publicaciones activas
 *
 * \param arrayP Publicacion*
 * \param limiteP int
 * \return int 0 si todo esta correcto, -1 si el array es nulo, -2 si no hay espacio en el array
 *
 */
int rubroMenosPublicacionesActivas(Publicacion *arrayP, int limiteP);

/** \brief devuelve el cliente cuyo id tiene una publicacion
 *
 * \param arrayC Cliente*
 * \param limiteC int
 * \param arrayP Publicacion*
 * \param limiteP int
 * \param idCliente int
 * \return int retorna i que es la posicion dentro del array
 *
 */
int idPublicacionesCliente(Cliente *arrayC, int limiteC, Publicacion *arrayP, int limiteP, int idCliente);


