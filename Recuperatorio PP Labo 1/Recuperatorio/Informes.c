#include <stdio.h>
#include <stdlib.h>
#include "Cliente.h"
#include "Prestamo.h"
#include "Informes.h"


void info_ClienteMasPrestamosActivos(ePrestamo* pListaP,int lenListaP,eCliente* pListaC,int lenListaC)
{
    int arrayClientes[lenListaC];
    int arrayMaximos[lenListaC];
    int maxClientePrestamo;
    int indice=0;
    int flag=1;


    //inisializo el array
    for(int i=0; i<lenListaC; i++)
    {
        arrayClientes[i]=0;
    }

    //Cuento cuandos prestamos activos tiene cada uno
    for(int c=0; c<lenListaC; c++)
    {
        if(pListaC[c].isEmpty==0)
        {
            for(int p=0 ; p<lenListaP; p++)
            {
                if(pListaC[c].id==pListaP[p].idCliente && strcmp(pListaP[p].estado,"Activo")==0)
                {
                    arrayClientes[c]++;
                }
            }
        }
    }

    //busco maximo
    for(int i=0; i<lenListaC; i++)
    {
        if(arrayClientes[i]>maxClientePrestamo || flag==1)
        {
            maxClientePrestamo=arrayClientes[i];
            flag=0;
        }
    }

    //busco si hay otros maximos
    for(int i=0; i<lenListaC; i++)
    {
        if(maxClientePrestamo==arrayClientes[i])
        {
            arrayMaximos[indice]=i;
            indice++;
        }
    }

    printf("Clientes con mayor cantidad de prestamos activos: Cantidad total %d\n",maxClientePrestamo);
    for(int i=0; i<indice; i++)
    {
        cli_listarUno(pListaC[arrayClientes[i]]);
    }
}

/*-------------------------------------------------------------------------*/

