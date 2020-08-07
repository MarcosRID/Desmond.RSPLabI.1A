#include <stdio.h>
#include <stdlib.h>
#include "Cliente.h"
#include "Prestamo.h"



int pre_listarUno(ePrestamo elemento)
{
    int ok = -1;

    if(elemento.isEmpty==0)
    {
        printf("|%d| %7d |  %02d   |%s |\n",elemento.id,elemento.importe,elemento.cantCuotas,elemento.estado);
        ok=0;
    }

    return ok;
}

/*---------------------------------------------------*/

int pre_listarTodo(ePrestamo* pListaP,int lenListaP)
{
    int ok = -1;


    if(pListaP != NULL && lenListaP>=0)
    {
        printf("________________________________\n"
               "| ID | importe| cuotas | estadso|\n"
               "|____|________|________|________|\n");

        for(int i=0 ; i<lenListaP ; i++)
        {
            if(pListaP[i].isEmpty==0)
            {
                pre_listarUno(pListaP[i]);
            }
        }
        printf("|____|_________|_______|________|\n");
        ok = 0;
    }

    return ok;
}
/*---------------------------------------------------*/

int pre_inicializar(ePrestamo* pListaP,int lenListaP)
{
    int ok = -1;

    if(pListaP != NULL && lenListaP>=0)
    {
        for(int i=0 ; i<lenListaP ; i++)
        {
            pListaP[i].isEmpty=1;
        }
        ok = 0;
    }

    return ok;
}


/*---------------------------------------------------------------------*/
int pre_buscarIndiceLibre(ePrestamo* pListaP,int lenListaP)
{
    int indice = -1;

    if(pListaP != NULL && lenListaP >= 0)
    {
        for(int i=0 ; i<lenListaP ; i++)
        {
            if(pListaP[i].isEmpty==1)
            {
                indice=i;
                break;
            }
        }
    }

    return indice;
}

/*---------------------------------------------------------------------*/

int pre_buscarById(ePrestamo* pListaP,int lenListaP,int id)
{
    int indice = -1;

    if(pListaP != NULL && lenListaP >= 0)
    {
        for(int i=0 ; i<lenListaP ; i++)
        {
            if(pListaP[i].isEmpty==0 && pListaP[i].id==id)
            {
                indice=i;
                break;
            }
        }
    }
    return indice;
}
/*---------------------------------------------------------------------*/

int pre_alta(ePrestamo* pListaP,int lenListaP,int id,eCliente* pListaC,int lenListaC)
{
    int ok = -1;
    int indice;
    ePrestamo auxPrestamo;
    int validar=0;

    indice = pre_buscarIndiceLibre(pListaP,lenListaP);

    if(pListaP != NULL && lenListaP >= 0 && indice!=-1)
    {
        cli_listarTodo(pListaC,lenListaC);
        validar+=utn_getNumero(&auxPrestamo.idCliente,"Igrese id cliente: ","error Id inexistente\n",1000,999+lenListaC,-1);

        validar+=utn_getNumero(&auxPrestamo.importe,"Igrese importe: ","error (Min: 500 Max:50.000)\n",500,50000,-1);
        validar+=utn_getNumero(&auxPrestamo.cantCuotas,"Ingrese Cantidad de cuotas: ","Error Max Cuotas 24.\n",1,24,-1);

        if(!validar)
        {
            pListaP[indice]=auxPrestamo;
            pListaP[indice].id=id;
            pListaP[indice].isEmpty=0;
            ok=0;
        }
    }
    return ok;
}

/*---------------------------------------------------------------------*/

int pre_saldar(ePrestamo* pListaP,int lenListaP,eCliente* pListaC,int lenListaC)
{
    int ok=-1;
    int indice;
    int auxId;
    int auxIndiceCliente;
    int confirmar;

    if(pListaP != NULL && lenListaP >= 0)
    {
        pre_listarTodo(pListaP,lenListaP);

        if(!utn_getNumero(&auxId,"Ingrese Id a saldar : ","Error id \n",5000,4999+lenListaP,-1))
        {
            indice=pre_buscarById(pListaP,lenListaP,auxId);
            auxIndiceCliente = cli_buscarById(pListaC,lenListaC,pListaP[indice].idCliente);

            cli_listarUno(pListaC[auxIndiceCliente]);

            utn_getNumero(&confirmar,"Confirma Deuda sladada 1-SI 2-NO: ","ERROR Operacion fallida\n\n",1,2,0);
            if(confirmar==1)
            {
                strcpy(pListaP[indice].estado,"Saldado");
                ok=0;
            }
        }
    }
    return ok;
}
/*-------------------------------------------------------------*/

int pre_reanudar(ePrestamo* pListaP,int lenListaP,eCliente* pListaC,int lenListaC)
{
    int ok=-1;
    int indice;
    int auxId;
    int auxIndiceCliente;
    int confirmar;

    if(pListaP != NULL && lenListaP >= 0)
    {
        pre_listarTodo(pListaP,lenListaP);

        if(!utn_getNumero(&auxId,"Ingrese Id a reanudar: ","Error id \n",5000,4999+lenListaP,-1))
        {
            indice=pre_buscarById(pListaP,lenListaP,auxId);
            auxIndiceCliente = cli_buscarById(pListaC,lenListaC,pListaP[indice].idCliente);

            cli_listarUno(pListaC[auxIndiceCliente]);

            utn_getNumero(&confirmar,"Confirma el cambio a Activo 1-SI 2-NO: ","ERROR Operacion fallida\n\n",1,2,0);
            if(confirmar==1)
            {
                strcpy(pListaP[indice].estado,"Activo");
                ok=0;
            }
        }
    }
    return ok;
}
/*-------------------------------------------------------------*/

int pre_listarConDeudas(ePrestamo* pListaP,int lenListaP,eCliente* pListaC,int lenListaC)
{
    int okey=-1;
    if(pListaP!=NULL && pListaC!= NULL && lenListaC>0 && lenListaP>0)
    {


        for(int i=0; i<lenListaC; i++)
        {
            if(pListaC[i].isEmpty==0)
            {   printf("_____________________________________________________\n");
                cli_listarUno(pListaC[i]);
                for(int j=0; j<lenListaP; j++)
                {
                    if(pListaC[i].id==pListaP[j].idCliente)
                    {
                        pre_listarUno(pListaP[j]);
                    }
                }
                printf("|___________________________________________________|\n");
            }
        }
        okey=0;
    }

    return okey;
}
/*-------------------------------------------------------------*/

int pre_listarActivos(ePrestamo* pListaP,int lenListaP,eCliente* pListaC,int lenListaC)
{
    int okey=-1;
    int indice;
    int auxIndiceCliente;

    for(int i=0; i<lenListaP; i++)
    {

        if(pListaP[i].isEmpty==0 && strcmp(pListaP[i].estado,"Activo")==0)
        {
            indice=pre_buscarById(pListaP,lenListaP,pListaP[i].id);
            auxIndiceCliente = cli_buscarById(pListaC,lenListaC,pListaP[indice].idCliente);

            printf("cuil/cliente: %d",pListaC[auxIndiceCliente].cuil);
            pre_listarUno(pListaP[i]);
        }


    }

    return okey;
}

/*---------------------------------------------------------------------*/

int pre_baja(ePrestamo* pListaP,int lenListaP,int idCliente)
{
    int ok=-1;
    int indice;
    int auxId;
    int auxIndice;

    if(pListaP != NULL && lenListaP >= 0)
    {
       for(int i=0; i<lenListaP;i++)
       {
           auxIndice=pre_buscarById(pListaP,lenListaP,pListaP[i].id);

           if(pListaP[auxIndice].idCliente==idCliente)
           {
               pListaP[i].isEmpty=1;
           }
       }
    }
    return ok;
}

/*---------------------------------------------------------------------*/
