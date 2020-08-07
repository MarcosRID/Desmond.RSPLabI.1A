#ifndef CLIENTE_H_INCLUDED
#define CLIENTE_H_INCLUDED

typedef struct
{
    int id;
    int cuil;
    char nombre[51];
    char apellido[51];
    int isEmpty;

}eCliente;

#endif // CLIENTE_H_INCLUDED



/** \brief muestra un elemento
 *
 * \param elemento eCliente
 * \return -1 error | 0 =ok
 *
 */
int cli_listarUno(eCliente elemento);

/** \brief muestra todos los elementos
 *
 * \param pListaC eCliente*
 * \param lenListaC int
 * \return -1 error | 0 =ok
 *
 */
int cli_listarTodo(eCliente* pListaC,int lenListaC);

/** \brief inicializa el array de clientes
 *
 * \param pListaC eCliente*
 * \param lenListaC int
 * \return -1 error | 0 =ok
 *
 */
int cli_inicializar(eCliente* pListaC,int lenListaC);

/** \brief busca un indice libre (isEmpty en 1)
 *
 * \param pListaC eCliente*
 * \param lenListaC int
 * \return -1 error | 0 =ok
 *
 */
int cli_buscarIndiceLibre(eCliente* pListaC,int lenListaC);

/** \brief busca un elemento por su aid y retorna su indice
 *
 * \param pListaC eCliente*
 * \param lenListaC int
 * \param id int
 * \return indice de elemento
 *
 */
int cli_buscarById(eCliente* pListaC,int lenListaC,int id);

/** \brief da de alta un cliente
 *
 * \param pListaC eCliente*
 * \param lenListaC int
 * \param id int
 * \return -1 error | 0 =ok
 *
 */
int cli_alta(eCliente* pListaC,int lenListaC,int id);

/** \brief modifica un campo del cliente (nombre,apellido ó cuil)
 *
 * \param pListaC eCliente*
 * \param lenListaC int
 * \return -1 error | 0 =ok
 *
 */
int cli_modificar(eCliente* pListaC,int lenListaC);

/** \brief da de baja un cliente
 *
 * \param pListaC eCliente*
 * \param lenListaC int
 * \return -1 error | 0 =ok
 *
 */
int cli_baja(eCliente* pListaC,int lenListaC);
