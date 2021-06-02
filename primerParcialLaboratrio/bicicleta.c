#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "bicicleta.h"

/** \brief despliega un menu de opciones
 * \param void
 * \return int retorna la opcion ingresada por el usuario
 */
int menu()
{
    int opcion;
    system("cls");
    printf("     *** PRIMER PARCIAL LABORATORIO ***\n\n");
    printf("1) Alta cliente.\n");
    printf("2) Alta bicicleta.\n");
    printf("3) Modificar bicicleta.\n");
    printf("4) Baja bicicleta.\n");
    printf("5) Listar bicicleta.\n");
    printf("6) Listar tipos.\n");
    printf("7) Listar colores.\n");
    printf("8) Listar servicios.\n");
    printf("9) Alta trabajo.\n");
    printf("10) Listar trabajo.\n");
    printf("11) Informes.\n");
    printf("12) Salir.\n");
    printf("\nElija una opcion: ");
    scanf("%d", &opcion);
    return opcion;
}


/** \brief pone todos los isEmpty del array en 1 indicando que estan vacios
 *
 * \param estructura array bicicleta
 * \param int tamaño del array
 * \return int retorna o si hubo un error (array null o tam>0) y retorna 1 si pudo realizar la funcion
 *
 */
int inicializarBicicletas(eBicicleta lista[], int tam)
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
 * \param estructura array bicicleta
 * \param int tamaño del array
 * \return int retorna -1 si no pudo encontrar un lugar libre
 * \return int retorna el indice del primer espacio libre
 */
int buscarLibrebicicleta(eBicicleta lista[],int tam)
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
 * \param array estructura bicicleta
 * \param int tamaño del array
 * \return int retorna -1 si hubo un problema
 * \return int retorna el indice de la posicion en el array donde se encuentra
 */
int buscarbicicleta(int idbici,eBicicleta bicicletas[],int tam)
{
    int indice=-1;
    if(bicicletas!=NULL&&tam>0)
    {
        for(int i=0; i<tam; i++ )
        {
            if(bicicletas[i].idbicicleta==idbici)
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
 * \param estructura array bicicleta
 * \param int tamaño array bicicleta
 * \param estructura array color
 * \param tamaño del array color
 * \param estructura array tipo
 * \param tamaño del array tipo
 * \return int retorna 0 si ubo un error y 1 si pudo realizar la funcion
 *
 */
int mostrarbicicletas(eBicicleta bicicletas[],int tamb,eColor colores[],int tamc, eTipo tipos[],int tamt,eCliente clientes[],int tamcli)
{
    int todoOk=0;
    if(bicicletas!=NULL&&colores!=NULL&&tipos!=NULL&&tamc>0&&tamb>0&&tamt>0)
    {
        int flag=1;
        printf("                ***LISTADO DE BICICLETAS***\n");
        printf("CLIENTE   ID BICI   MARCA       TIPO         COLOR        RODADO\n");
        printf("------------------------------------------------------------------------\n");
        for(int i=0; i< tamb; i++)
        {
            if(!bicicletas[i].isEmpty)
            {
                mostrarbicicleta(bicicletas[i],colores,tamc,tipos,tamt,clientes,tamcli);
                flag=0;
            }
        }
        printf("\n\n");

        if(flag)
        {
            printf("            No hay bicicletas que mostrar.\n");
            printf("\n\n");
        }
        todoOk=1;
    }
    return todoOk;
}


/** \brief muestra los datos de una sola estructura
 * \param estructura array bicicleta
 * \param int tamaño array bicicleta
 * \param estructura array color
 * \param tamaño del array color
 * \param estructura array tipo
 * \param tamaño del array tipo
 * \return int retorna 0 si hubo un error y 1 si pudo realizar la funcion
 */
int mostrarbicicleta(eBicicleta unaBicicleta,eColor colores[],int tamc, eTipo tipos[],int tamt,eCliente clientes[],int tamcli)
{
    int todoOk=0;
      if(colores!=NULL&&tipos!=NULL&&tamc>0&&tamt>0&&clientes!=NULL&&tamcli>0)
    {
        char tipo[20];
        char color[20];
        char nombrecli[20];
        if(cargarDescripcioncliente(unaBicicleta.idcliente,clientes,tamcli,nombrecli)&&cargarDescripcionTipo(unaBicicleta.idtipo,tipos,tamt,tipo)&&cargarDescripcioncolor(unaBicicleta.idcolor,colores,tamc,color))
        {
            printf("%-10s   %d     %-10s %-10s   %-10s        %.1f"
                   ,nombrecli
                   ,unaBicicleta.idbicicleta
                   ,unaBicicleta.marca
                   ,tipo
                   ,color
                   ,unaBicicleta.rodado
                   );

            printf("\n");
            todoOk=1;
        }
    }
    return todoOk;
}


/** \brief realiza el alta. Pide los datos y los guarda dentro de una estructura del array
 *
 * \param estructura array bicicleta
 * \param int tamaño array bicicleta
 * \param int puntero id bicicleta
 * \param estructura array color
 * \param tamaño del array color
 * \param estructura array tipo
 * \param tamaño del array tipo
 * \param estructura array rodados
 * \param tamaño del array rodados
 * \return int retorna 0 si hubo un error y 1 si pudo realizar la carga
 *
 */
int altabicicleta(eBicicleta bicicletas[],int tam,int* pIdbicicleta,eColor colores[],int tamc, eTipo tipos[],int tamt,float rodados[],int tamr,eCliente clientes[],int tamcli)
{
    int todoOk=0;
    int indice;
    eBicicleta nuevaBici;
    if(bicicletas!= NULL&& tam> 0&& pIdbicicleta!=NULL&& colores!=NULL&&tipos!=NULL&&tamc>0&&tamt>0&&clientes!=NULL&&tamcli>0)
    {
        system("cls");
        printf("        Alta bicicleta\n\n");
        printf("ID: %d\n",*pIdbicicleta);

        indice=buscarLibrebicicleta(bicicletas, tam);
        if(indice==-1)
        {
            printf("No hay mas lugar en el sistema.\n");
        }
        else
        {
            mostrarClientes(clientes,tamcli);
            printf("Ingrese el ID del cliente: ");
            scanf("%d",&nuevaBici.idcliente);
            while(buscarcliente(nuevaBici.idcliente,clientes,tamcli)==-1)
            {
                printf("\nEl Id ingresado es invalido.\n");
                printf("\nReingrese el id del cliente: ");
                scanf("%d",&nuevaBici.idcliente);
            }
            printf("Ingrese marca: ");
            fflush(stdin);
            gets(nuevaBici.marca);
            while(nuevaBici.marca==NULL||strlen(nuevaBici.marca)>=20)
            {
                printf("Marca invalido. Reingrese marca: ");
                fflush(stdin);
                gets(nuevaBici.marca);
            }

            mostrarTipos(tipos,tamt);
            printf("Ingrese el ID del tipo: ");
            scanf("%d",&nuevaBici.idtipo);
            while(buscarTipo(nuevaBici.idtipo,tipos,tamt)==-1)
            {
                printf("\nEl Id ingresado es invalido.\n");
                printf("\nReingrese el id del tipo: ");
                scanf("%d",&nuevaBici.idtipo);
            }

             mostrarcolores(colores,tamc);
            printf("Ingrese el ID del color: ");
            scanf("%d",&nuevaBici.idcolor);
            while(buscarColor(nuevaBici.idcolor,colores,tamc)==-1)
            {
                printf("\nEl Id ingresado es invalido.\n");
                printf("\nReingrese el id del color: ");
                scanf("%d",&nuevaBici.idcolor);
            }

            mostrarRodados(rodados,tamr);
            printf("Ingrese el numero de rodado: ");
            scanf("%f",&nuevaBici.rodado);
            while(buscarrodado(nuevaBici.rodado,rodados,tamr)==-1)
            {
                printf("\nEl numero de rodado es invalido.\n");
                printf("\nReingrese  numero de rodado: ");
                scanf("%f",&nuevaBici.rodado);
            }

            nuevaBici.idbicicleta= *pIdbicicleta;
            nuevaBici.isEmpty=0;
            (*pIdbicicleta)++;
            bicicletas[indice]=nuevaBici;
            todoOk=1;
        }
    }

    return todoOk;
}

/** \brief permite la modificacion de los datos
 * \param estructura array de bicicleta
 * \param int tamaño del array bicicleta
 * \param estructura array tipo
 * \param tamaño del array tipo
 * \param estructura array rodados
 * \param tamaño del array rodados
 * \param estructura array color
 * \param tamaño del array color
 * \return int retorna 0 si ubo un error y 1 si pudo realizar la funcion
 *
 */
int modificarbicicleta(eBicicleta lista[],int tam, eTipo tipos[],int tamt,float rodados[],int tamr,eColor colores[],int tamc,eCliente clientes[],int tamcli)
{
    int todoOk=0;
    if(lista!=NULL&&tam>0&&tipos!=NULL&&tamt>0&&rodados!=NULL&&tamr>0&&colores!=NULL&&tamc>0&&clientes!=NULL&&tamcli>0)
    {
        int tipo;
        float rodado;
        int idbici;
        int indice;
        char confirma;
        char confmodificacion;

        system("cls");
        printf("       Modificar bicicleta.\n\n");
        mostrarbicicletas(lista,tam,colores,tamc,tipos,tamt,clientes,tamcli);
        printf("Ingrese el ID: ");
        scanf("%d",&idbici);
        indice=buscarbicicleta(idbici,lista,tam);
        if(indice==-1)
        {
            printf("No hay ninguna bicicleta con el ID %d\n",idbici);
        }
        else
        {
            mostrarbicicleta(lista[indice],colores,tamc,tipos,tamc,clientes,tamcli);
            printf("Desea modificar esta bicicleta? (s/n) : ");
            fflush(stdin);
            scanf("%c",&confirma);
            if(confirma=='s'||confirma=='S')
            {
                switch(menuModificar())
                {
                case 1:
                    mostrarTipos(tipos,tamt);
                    printf("Ingrese id del tipo nuevo: ");
                    scanf("%d",&tipo);
                    while(buscarTipo(tipo,tipos,tamt)==-1)
                    {
                        printf("Id del tipo invalido. Reingrese tipo: ");
                        scanf("%d",&tipo);
                    }
                    printf("\nNuevo id tipo: %d\n",tipo);
                    printf("\nConfirma modificacion? (s/n) :");
                    fflush(stdin);
                    scanf("%c",&confmodificacion);
                    if (confmodificacion=='s'||confmodificacion=='S')
                    {
                        lista[indice].idtipo=tipo;
                    }
                    else
                    {
                        printf("\nModificacion cancelada por el usuario.\n");
                        todoOk=0;
                    }
                    break;
                case 2:
                     mostrarRodados(rodados,tamr);
                    printf("Ingrese numero de rodado nuevo: ");
                    scanf("%f",&rodado);
                    while(buscarrodado(rodado,rodados,tamr)==-1)
                    {
                        printf("numero de rodado invalido. Reingrese numero de rodado : ");
                        scanf("%f",&rodado);
                    }
                    printf("\nNuevo numero de rodado : %.2f\n",rodado);
                    printf("\nConfirma modificacion? (s/n) :");
                    fflush(stdin);
                    scanf("%c",&confmodificacion);
                    if (confmodificacion=='s'||confmodificacion=='S')
                    {
                        lista[indice].rodado=rodado;
                    }
                    else
                    {
                        printf("\nModificacion cancelada por el usuario.\n");
                        todoOk=0;
                    }
                    break;
                    default:
                    printf("Opcion invalda.\n");
                    break;
                }
                system("pause");
                todoOk=1;
            }
            else
            {
                printf("Modificacion cancelada por el usuario.\n");
            }
        }
    }
    return todoOk;
}
/** \brief despliega un menu de opciones
 * \param void
 * \return int retorna la opcion ingresada por el usuario
 */
int menuModificar(void)
{
    int opcion;
    system("cls");
    printf("1) Modificar tipo.\n");
    printf("2) Modificar rodado.\n");
    printf("\nIngrese opcion: ");
    scanf("%d", &opcion);
    return opcion;
}

/** \brief realiza la baja logica colocando el isempty en 1
 *
 * \param estructura array de bicicleta
 * \param int tamaño del array bicicleta
 * \param estructura array tipo
 * \param tamaño del array tipo
 * \param estructura array color
 * \param tamaño del array color
 * \return int retorna 0 si hubo un error y 1 si pudo realizar la funcion
 *
 */
int bajabicicleta(eBicicleta lista[],int tam, eTipo tipos[],int tamt,eColor colores[],int tamc,eCliente clientes[],int tamcli)
{
    int todoOk=0;
    if(lista!=NULL&&tam>0&&tipos!=NULL&&tamt>0&&colores!=NULL&&tamc>0&&clientes!=NULL&&tamcli>0)
    {
        int idbici;
        int indice;
        char confirma;
        system("cls");
        printf("        Baja de bicicletas.\n");
        mostrarbicicletas(lista,tam,colores,tamc,tipos,tamt,clientes,tamcli);
        printf("Ingrese el ID que desea dar de baja: ");
        scanf("%d",&idbici);
        indice=buscarbicicleta(idbici,lista,tam);
        if(indice==-1)
        {
            printf("No hay ningun bicicletas con el ID %d\n",idbici);
        }
        else
            mostrarbicicleta(lista[indice],colores,tamc,tipos,tamt,clientes,tamcli);
        printf("Confirma baja? (s/n): ");
        fflush(stdin);
        scanf("%c",&confirma);
        if(confirma=='s')
        {
            lista[indice].isEmpty=1;
            todoOk=1;
        }
        else
        {
            printf("Baja cancelada por el usuario.\n");
        }
    }
    return todoOk;
}


/** \brief carga la descripcion de recibiendo como parametro el id
 * \param int id
 * \param estructura array de bicicleta
 * \param int tamaño del array bicicleta
 * \param char array descripcion
 * \return int retorna 0 si hubo un error y si pudo cargar la descripcion
 *
 */
int cargarDescripcionbicicleta(int idbici, eBicicleta bicicletas[], int tam, char desc[])
{
    int todoOk=0;

    if(bicicletas != NULL && tam >0 && desc !=NULL)
    {
        for(int i=0; i<tam; i++)
        {
            if(bicicletas[i].idbicicleta== idbici)
            {
                strcpy(desc, bicicletas[i].marca);
                todoOk=1;
                break;
            }
        }
    }

    return todoOk;

}
