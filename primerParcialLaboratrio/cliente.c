#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "cliente.h"

/** \brief pone todos los isEmpty del array en 1 indicando que estan vacios
 *
 * \param estructura array cliente
 * \param int tamaño del array
 * \return int retorna o si hubo un error (array null o tam>0) y retorna 1 si pudo realizar la funcion
 *
 */
int inicializarClientes(eCliente lista[], int tam)
{
    int todoOk=0;
    if(lista!=NULL&&tam>0)
    {
        for(int i=0; i< tam; i++)
        {
            lista[i].isEmpty=1;
        }
        todoOk=1;
    }
    return todoOk;
}

/** \brief busca el primer lugar libre (campo isempty =1) dentro del array
 *
 * \param estructura array cliente
 * \param int tamaño del array
 * \return int retorna -1 si no pudo encontrar un lugar libre
 * \return int retorna el indice del primer espacio libre
 */
int buscarLibrecliente(eCliente lista[],int tam)
{
    int indice=-1;
    for(int i=0; i< tam; i++)
    {
        if(lista[i].isEmpty)
        {
            indice=i;
            break;
        }
    }
    return indice;
}

/** \brief
 *
 * \param int id
 * \param array estructura cliente
 * \param int tamaño del array
 * \return int retorna -1 si hubo un problema
 * \return int retorna el indice de la posicion en el array donde se encuentra
 */
int buscarcliente(int idcliente,eCliente lista[],int tam)
{
    int indice=-1;
    if(lista!=NULL&&tam>0)
    {
        for(int i=0; i<tam; i++ )
        {
            if(lista[i].idcliente==idcliente)
            {
                indice=i;
                break;
            }
        }
    }
    return indice;
}

/** \brief muestra una nomina de todos los elementos del array
 *
 * \param estructura array clientes
 * \param tamaño del array
 * \return int retorna 0 si ubo un error y 1 si pudo realizar la funcion
 *
 */
int mostrarClientes(eCliente clientes[],int tam)
{
    int todoOk=0;
    if(clientes!=NULL&&tam>0)
    {
        int flag=1;
        printf("                ***LISTADO DE CLIENTES***\n");
        printf("ID       NOMBRE     SEXO\n");
        printf("-------------------------------------------\n");
        for(int i=0; i< tam; i++)
        {
            if(!clientes[i].isEmpty)
            {
                mostrarCliente(clientes[i]);
                flag=0;
            }
        }
        printf("\n\n");

        if(flag)
        {
            printf("            No hay clientes que mostrar.\n");
            printf("\n\n");
        }
        todoOk=1;
    }
    return todoOk;
}


/** \brief muestra los datos de una sola estructura
 * \param estructura array cliente
 * \param tamaño del array
 * \return int retorna 0 si hubo un error y 1 si pudo realizar la funcion
 */
void mostrarCliente(eCliente unCliente)
{
        printf("%d   %-10s %c"
                   ,unCliente.idcliente
                   ,unCliente.nombre
                   ,unCliente.sexo
                   );

            printf("\n");
}

/** \brief realiza el alta. Pide los datos y los guarda dentro de una estructura del array
 *
 * \param estructura array cliente
 * \param int tamaño array
 * \param int puntero id cliente
 * \return int retorna 0 si hubo un error y 1 si pudo realizar la carga
 *
 */
int altacliente(eCliente lista[],int tam,int* pIdcliente)
{
    int todoOk=0;
    int indice;
    eCliente nuevocliente;
    if(lista!= NULL&& tam> 0&& pIdcliente!=NULL)
    {
        system("cls");
        printf("        Alta cliente\n\n");
        printf("ID: %d\n",*pIdcliente);

        indice=buscarLibrecliente(lista, tam);
        if(indice==-1)
        {
            printf("No hay mas lugar en el sistema.\n");
        }
        else
        {
             printf("Ingrese nombre: ");
            fflush(stdin);
            gets(nuevocliente.nombre);
            while(strlen(nuevocliente.nombre)>=20||strlen(nuevocliente.nombre)<1)
            {
                printf("Nombre muy largo. Reingrese nombre: ");
                fflush(stdin);
                gets(nuevocliente.nombre);
            }
            printf("Ingrese sexo(f/m): ");
            fflush(stdin);
            scanf("%c",&nuevocliente.sexo);
            while(!(nuevocliente.sexo=='f'||nuevocliente.sexo=='m'))
            {
                printf("Sexo invalido. Reingrese sexo(f/m): ");
                fflush(stdin);
            scanf("%c",&nuevocliente.sexo);
            }

            nuevocliente.idcliente= *pIdcliente;
            nuevocliente.isEmpty=0;
            (*pIdcliente)++;
            lista[indice]=nuevocliente;
            todoOk=1;
        }
    }

    return todoOk;
}

/** \brief carga la descripcion de recibiendo como parametro el id
 * \param int id
 * \param estructura array de cliente
 * \param int tamaño del array
 * \param char array descripcion
 * \return int retorna 0 si hubo un error y si pudo cargar la descripcion
 *
 */
int cargarDescripcioncliente(int idcliente, eCliente lista[], int tam, char desc[])
{
    int todoOk=0;

    if(lista != NULL && tam >0 && desc !=NULL)
    {
        for(int i=0; i<tam; i++)
        {
            if(lista[i].idcliente== idcliente)
            {
                strcpy(desc, lista[i].nombre);
                todoOk=1;
                break;
            }
        }
    }

    return todoOk;

}
