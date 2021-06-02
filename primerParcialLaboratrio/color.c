#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "color.h"

/** \brief carga la descripcion de recibiendo como parametro el id
 * \param int id
 * \param array de estructura color
 * \param int tamaño del array color
 * \param char array descripcion
 * \return int retorna 0 si hubo un error y si pudo cargar la descripcion
 *
 */
int cargarDescripcioncolor(int idcolor, eColor colores[], int tam, char desc[])
{
    int todoOk=0;

    if(colores != NULL && tam >0 && desc !=NULL)
    {
        for(int i=0; i<tam; i++)
        {
            if(colores[i].idColor== idcolor)
            {
                strcpy(desc, colores[i].nombrecolor);
                todoOk=1;
                break;
            }
        }
    }

    return todoOk;

}

/** \brief muestra los datos del array de estructura
 *
 * \param array de estructura color
 * \param int tamaño del array color
 * \return int retorna 0 si hubo un error y 1 si pudo realizar la funcion
 *
 */
int mostrarcolores(eColor colores[],int tam)
{
    int todoOk=0;
    if(colores!=NULL&&tam>0)
    {
        printf("  LISTA DE COLORES.\n\n");
        printf("Id      Descripcion\n");
        printf("----------------------\n");

        for(int i=0; i<tam; i++)
        {
            mostrarcolor(colores[i]);
            todoOk=1;
        }
        printf("\n\n");
    }
    return todoOk;
}

/** \brief muestra los datos de una sola estructura
 *
 * \param estructura color
 * \return void
 *
 */
void mostrarcolor(eColor uncolor)
{
        printf("%d     %10s\n",uncolor.idColor,uncolor.nombrecolor);
}

/** \brief valida si el id pasado por parametro pertenece a un elemento del array
 *
 * \param int id
 * \param array de estructura color
 * \param int tamaño del array color
 * \return int retorna 0 si ubo un error y 1 si pudo realizar la funcion
 */
int validarIdColor(int idcolor,eColor colores[],int tam)
{
    int todoOk=0;
    if(colores!=NULL&&tam>0)
    {
        for(int i=0; i<tam; i++ )
        {
            if(colores[i].idColor==idcolor)
            {
                todoOk=1;
                break;
            }
        }
    }
    return todoOk;
}

/** \brief
 *
 * \param int id
 * \param array de estructura color
 * \param int tamaño del array color
 * \return int retorna -1 si hubo un problema
 * \return int retorna el indice de la posicion en el array donde se encuentra
 */
int buscarColor(int idcolor,eColor colores[],int tam)
{
    int indice=-1;
    if(colores!=NULL&&tam>0)
    {
        for(int i=0; i<tam; i++ )
        {
            if(colores[i].idColor==idcolor)
            {
                indice=i;
                break;
            }
        }
    }
    return indice;
}
