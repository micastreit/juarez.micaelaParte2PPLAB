#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "rodado.h"

/** \brief
 *
 * \param int numero del rodado
 * \param float array rodados
 * \param int tamaño del array
 * \return int retorna -1 si hubo un problema
 * \return int retorna el indice de la posicion en el array donde se encuentra
 */
int buscarrodado(int numerodado,float rodados[],int tamr)
{
    int indice=-1;
    if(rodados!=NULL&&tamr>0)
    {
        for(int i=0; i<tamr; i++ )
        {
            if(rodados[i]==numerodado)
            {
                indice=i;
                break;
            }
        }
    }
    return indice;
}

/** \brief muestra los datos del array
 *
 * \param float array rodados
 * \param int tamaño del array rodados
 * \return int retorna 0 si hubo un error y 1 si pudo realizar la funcion
 *
 */
int mostrarRodados(float rodados[],int tamr)
{
    int todoOk=0;
    if(rodados!=NULL&&tamr>0)
    {
        printf("\n  LISTA DE RODADOS.\n\n");
        printf("NUMERO \n");
        printf("--------------------\n");

        for(int i=0; i<tamr; i++)
        {
            printf("%.1f\n",rodados[i]);
            todoOk=1;
        }
    }
    return todoOk;
    }

