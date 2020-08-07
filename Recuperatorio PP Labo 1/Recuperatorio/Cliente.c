#include <stdio.h>
#include <stdlib.h>
#include "Cliente.h"



int cli_listarUno(eCliente elemento)
{
    int ok = -1;

    if(elemento.isEmpty==0)
    {
        printf("|%d|%10s    |  %10s | %d |\n",elemento.id,elemento.nombre,elemento.apellido,elemento.cuil);
        ok=0;
    }

    return ok;
}

/*---------------------------------------------------*/

int cli_listarTodo(eCliente* pListaC,int lenListaC)
{
    int ok = -1;


    if(pListaC != NULL && lenListaC>=0)
    {
        printf("_________________________________________\n"
               "| ID |    Nombre    |   apellido  | cuil |\n"
               "|____|______________|_____________|______|\n");

        for(int i=0 ; i<lenListaC ; i++)
        {
            cli_listarUno(pListaC[i]);
        }
        printf("|____|______________|_____________|______|\n");
        ok = 0;
    }

    return ok;
}

/*---------------------------------------------------*/

int cli_inicializar(eCliente* pListaC,int lenListaC)
{
    int ok = -1;

    if(pListaC != NULL && lenListaC>=0)
    {
        for(int i=0 ; i<lenListaC ; i++)
        {
            pListaC[i].isEmpty=1;
        }
        ok = 0;
    }

    return ok;
}


/*---------------------------------------------------------------------*/

int cli_buscarIndiceLibre(eCliente* pListaC,int lenListaC)
{
    int indice = -1;

    if(pListaC != NULL && lenListaC >= 0)
    {
        for(int i=0 ; i<lenListaC ; i++)
        {
            if(pListaC[i].isEmpty==1)
            {
                indice=i;
                break;
            }
        }
    }

    return indice;
}

/*---------------------------------------------------------------------*/

int cli_buscarById(eCliente* pListaC,int lenListaC,int id)
{
    int indice = -1;

    if(pListaC != NULL && lenListaC >= 0)
    {
        for(int i=0 ; i<lenListaC ; i++)
        {
            if(pListaC[i].isEmpty==0 && pListaC[i].id==id)
            {
                indice=i;
                break;
            }
        }
    }
    return indice;
}

/*---------------------------------------------------------------------*/

int cli_alta(eCliente* pListaC,int lenListaC,int id)
{
    int ok = -1;
    int indice;
    eCliente auxCliente;
    int validar=0;

    indice = cli_buscarIndiceLibre(pListaC,lenListaC);

    if(pListaC != NULL && lenListaC >= 0 && indice!=-1)
    {
        validar+=utn_getString(auxCliente.nombre,"Ingrese Nombre: ","Error nombre\n",51,-1);
        validar+=utn_getString(auxCliente.apellido,"Ingrese apellido: ","Error apellido\n",51,-1);
        validar+=utn_getNumero(&auxCliente.cuil,"Ingrese Cuil: ","Error Cuil.\n",2000,9000,-1);

        if(!validar)
        {
            pListaC[indice]=auxCliente;
            pListaC[indice].id=id;
            pListaC[indice].isEmpty=0;
            ok=0;
        }
    }
    return ok;
}

/*---------------------------------------------------------------------*/

int cli_modificar(eCliente* pListaC,int lenListaC)
{
    int ok=-1;
    int auxId,opcion,indice,auxCuil;
    char auxNombre[51];
    char auxApellido[51];

    if(pListaC != NULL && lenListaC >= 0)
    {
        cli_listarTodo(pListaC,lenListaC);

        if(!utn_getNumero(&auxId,"Ingrese Id a modificar: ","Error id modificar\n",1000,999+lenListaC,-1))
        {
            indice = cli_buscarById(pListaC,lenListaC,auxId);

            system("cls");
            if(indice!=-1 && !utn_getNumero(&opcion," [_Submenu Modificar_]\n"
                                                    "1-Nombre\n"
                                                    "2-Apellidp\n"
                                                    "3-CUIL\n"
                                                    "Ingrese opcion: ",
                                                    "Error opcion inexistente\n",1,3,-1))
            {
                switch(opcion)
                    {
                    case 1:
                        if(!utn_getString(auxNombre,"Ingrese  nuevo NOMBRE : ","Error  nuevo NOMBRE\n",51,-1))
                        {
                            strcpy(pListaC[indice].nombre,auxNombre);
                            ok=0;
                        }
                        break;

                    case 2:
                        if(!utn_getString(auxApellido,"Ingrese  nuevo APELLIDO : ","Error  nuevo APELLIDO\n",51,-1))
                        {
                            strcpy(pListaC[indice].apellido,auxApellido);
                            ok=0;
                        }
                        break;
                    case 3:
                        if(!utn_getNumero(&auxCuil,"Ingrese nevo cuil: ","Error nuevo cuiel\n",2000,9000,-1))
                        {
                            pListaC[indice].cuil=auxCuil;
                            ok=0;
                        }

                        break;
                    }
            }
        }
    }
    return ok;
}

/*---------------------------------------------------------------------*/

int cli_baja(eCliente* pListaC,int lenListaC)
{
    int indice;
    int auxId=-1;

    if(pListaC != NULL && lenListaC >= 0)
    {
        cli_listarTodo(pListaC,lenListaC);

        if(!utn_getNumero(&auxId,"Ingrese Id a dar de baja: ","Error id baja\n",1000,1000+lenListaC,-1))
        {
            indice=cli_buscarById(pListaC,lenListaC,auxId);

            if(indice!=-1)
            {
                pListaC[indice].isEmpty=1;
            }
        }
    }
    return auxId;
}


