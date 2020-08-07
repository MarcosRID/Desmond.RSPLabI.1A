#ifndef PRESTAMO_H_INCLUDED
#define PRESTAMO_H_INCLUDED

typedef struct
{
    int id;
    int idCliente;
    int importe;
    int cantCuotas;
    char estado[51];

    int isEmpty;

}ePrestamo;

#endif // PRESTAMO_H_INCLUDED


/** \brief listas un prestamo
 *
 * \param elemento ePrestamo
 * \return int
 *
 */
int pre_listarUno(ePrestamo elemento);

/** \brief Lista todos los prestamos
 *
 * \param pListaP ePrestamo*
 * \param lenListaP int
 * \return int
 *
 */
int pre_listarTodo(ePrestamo* pListaP,int lenListaP);

/** \brief Inicializa el array de prestamos
 *
 * \param pListaP ePrestamo*
 * \param lenListaP int
 * \return int
 *
 */
int pre_inicializar(ePrestamo* pListaP,int lenListaP);

/** \brief Busca un indice libre (isEmpty en 1) y lo retorna
 *
 * \param pListaP ePrestamo*
 * \param lenListaP int
 * \return int
 *
 */
int pre_buscarIndiceLibre(ePrestamo* pListaP,int lenListaP);

/** \brief Busca un prestamo por su ID
 *
 * \param pListaP ePrestamo*
 * \param lenListaP int
 * \param id int
 * \return int
 *
 */
int pre_buscarById(ePrestamo* pListaP,int lenListaP,int id);

/** \brief Da de alta un prestamo
 *
 * \param pListaP ePrestamo*
 * \param lenListaP int
 * \param id int
 * \param pListaC eCliente*
 * \param lenListaC int
 * \return int
 *
 */
int pre_alta(ePrestamo* pListaP,int lenListaP,int id,eCliente* pListaC,int lenListaC);

/** \brief Marca el prestamo como saldado
 *
 * \param pListaP ePrestamo*
 * \param lenListaP int
 * \param pListaC eCliente*
 * \param lenListaC int
 * \return int
 *
 */
int pre_saldar(ePrestamo* pListaP,int lenListaP,eCliente* pListaC,int lenListaC);

/** \brief reanuda un prestamo saldado y lo marca como activo
 *
 * \param pListaP ePrestamo*
 * \param lenListaP int
 * \param pListaC eCliente*
 * \param lenListaC int
 * \return int
 *
 */
int pre_reanudar(ePrestamo* pListaP,int lenListaP,eCliente* pListaC,int lenListaC);

/** \brief  lista los clientes con deudas
 *
 * \param pListaP ePrestamo*
 * \param lenListaP int
 * \param pListaC eCliente*
 * \param lenListaC int
 * \return int
 *
 */
int pre_listarConDeudas(ePrestamo* pListaP,int lenListaP,eCliente* pListaC,int lenListaC);

/** \brief lista los prestamos activos
 *
 * \param pListaP ePrestamo*
 * \param lenListaP int
 * \param pListaC eCliente*
 * \param lenListaC int
 * \return int
 *
 */
int pre_listarActivos(ePrestamo* pListaP,int lenListaP,eCliente* pListaC,int lenListaC);

