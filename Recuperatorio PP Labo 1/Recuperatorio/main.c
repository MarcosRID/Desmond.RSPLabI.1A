#include <stdio.h>
#include <stdlib.h>
#include "Cliente.h"
#include "Prestamo.h"
#include "Informes.h"
#include "dataWhereHauose.h"

#define LEN_CLIENTE 50
#define LEN_CLIENTE_HARCODEADO 5

#define LEN_PRESTAMO 50
#define LEN_PRESTAMO_HARCODEADO 4


void harcodeoCliente(eCliente* lista,int len);
int menu(void);


int main()
{
    char confirmar;
    char continuar;
    int autoIdCliente=1000;
    int autoIdPrestamo=5000;
    int idBaja;
    eCliente listaCliente[LEN_CLIENTE];
    ePrestamo listaPrestamo[LEN_PRESTAMO];

    cli_inicializar(listaCliente,LEN_CLIENTE);
    pre_inicializar(listaPrestamo,LEN_PRESTAMO);

/*------------*/
harcodeoCliente(listaCliente,LEN_CLIENTE_HARCODEADO);
autoIdCliente+=LEN_CLIENTE_HARCODEADO;

/*------------*/

harcodeoPrestamo(listaPrestamo,LEN_PRESTAMO_HARCODEADO);
autoIdPrestamo+=LEN_PRESTAMO_HARCODEADO;


    do
    {
        system("cls");
        switch ( menu())
        {
            case 1:
                system("cls");
                 printf(" ______________________________________\n"
                        "|_____________Atla Cliente_____________|\n\n");
                if(!cli_alta(listaCliente,LEN_CLIENTE,autoIdCliente))
                {
                   printf("Se realizo la operacion con exito\n");
                   autoIdCliente++;
                }else
                {
                    printf("Error al dar de alta\n");
                }
                system("pause");
                break;

            case 2:
                system("cls");
                if(!cli_modificar(listaCliente,LEN_CLIENTE))
                {
                   printf("Se realizo la operacion con exito\n");
                }else
                {
                    printf("Error al dar de baja\n");
                }
                system("pause");
                break;

            case 3:
                system("cls");
                idBaja=cli_baja(listaCliente,LEN_CLIENTE);

                if(idBaja!=-1)
                {
                   pre_baja(listaPrestamo,LEN_PRESTAMO,idBaja);
                   printf("Se realizo la operacion con exito\n");

                }else
                {
                    printf("Error al dar de baja\n");
                }
                system("pause");
                break;

            case 4:
                system("cls");
                if(!pre_alta(listaPrestamo,LEN_PRESTAMO,autoIdPrestamo,listaCliente,LEN_CLIENTE))
                {
                   printf("Error al listar Mascotas\n");
                   autoIdPrestamo++;
                }else
                {
                    printf("Error al dar de baja\n");
                }
                system("pause");
                break;

            case 5:
                system("cls");
                if(!pre_saldar(listaPrestamo,LEN_PRESTAMO,listaCliente,LEN_CLIENTE))
                {
                   printf("Error al listar Mascotas\n");
                }else
                {
                    printf("Error al dar de baja\n");
                }
                system("pause");
                break;

           case 6:
                system("cls");
                if(!pre_reanudar(listaPrestamo,LEN_PRESTAMO,listaCliente,LEN_CLIENTE))
                {
                   printf("Error al listar Mascotas\n");
                }else
                {
                    printf("Error al dar de baja\n");
                }
                system("pause");
                break;

           case 7:
                system("cls");
                if(!pre_listarConDeudas(listaPrestamo,LEN_PRESTAMO,listaCliente,LEN_CLIENTE))
                {
                   printf("Error al listar Mascotas\n");
                }else
                {
                    printf("Error al dar de baja\n");
                }
                system("pause");
                break;

            case 8:
                system("cls");
                if(!pre_listarActivos(listaPrestamo,LEN_PRESTAMO,listaCliente,LEN_CLIENTE))
                {
                   printf("Error al listar Mascotas\n");
                }else
                {
                    printf("Error al dar de baja\n");
                }
                system("pause");
                break;

            case 9:
                system("cls");
                info_ClienteMasPrestamosActivos(listaPrestamo,LEN_PRESTAMO,listaCliente,LEN_CLIENTE);
                system("pause");
                break;

            case 10:
                system("cls");
               // info_ClienteMasPrestamosSaldados(listaPrestamo,LEN_PRESTAMO,listaCliente,LEN_CLIENTE);
                system("pause");
                break;

            case 11:

                    utn_getCaracter(&confirmar,"Confirmar Salida s=SI n=NO \n","Error. Salir (Solo S o N)",'N','s',0);
                    confirmar=tolower(confirmar);

                    if (confirmar=='s')
                    {
                        continuar='n';
                    }

                break;
        }

    } while(continuar!='n');
    return 0;
}
void harcodeoCliente(eCliente* lista,int len)
{
    for(int i=0 ; i <len ; i++)
    {
        lista[i].id=idC[i];
        strcpy(lista[i].nombre,auxNombre[i]);
        strcpy(lista[i].apellido,auxApellido[i]);
        lista[i].cuil= auxCuil[i];
        lista[i].isEmpty=0;
    }
}
void harcodeoPrestamo(ePrestamo* lista,int len)
{
    for(int i=0 ; i <len ; i++)
    {
        lista[i].id=idP[i];
        lista[i].idCliente=idCliente[i];
        lista[i].importe= auxImporte[i];
        lista[i].cantCuotas= auxCantCuotas[i];
        strcpy(lista[i].estado,auxEstado[i]);
        lista[i].isEmpty=0;
    }
}

int menu(void)
{
    int opcion=-1;

                   printf(" ______________________________________\n"
                          "|____________Menu Principal____________|\n");
                            /*------CAJA DE MENU PRINCIPAL-------*/
    utn_getNumero(&opcion,"|1-Alta                                |\n"
                          "|2-Modificar                           |\n"
                          "|3-Baja                                |\n"
                          "|4-Alta prestamo                       |\n"
                          "|5-Saldar prestamo                     |\n"
                          "|6-Reanudar prestamo                   |\n"
                          "|7-Imprimir Clinetes                   |\n"
                          "|8-Imprimir Prestamos                  |\n"
                          "|9-INFORME (Cliente Max. Activos)      |\n"
                          "|10-Salir                              |\n"
                          "|______________________________________|\n"
                          ,"Error. Opcion inexistente\n",1,10,0);
    return opcion;
}



