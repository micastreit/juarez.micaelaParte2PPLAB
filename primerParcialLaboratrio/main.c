#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "fecha.h"
#include "tipo.h"
#include "color.h"
#include "servicio.h"
#include "bicicleta.h"
#include "trabajo.h"
#include "rodado.h"
#include "cliente.h"

#define TAMT 4
#define TAMC 5
#define TAMS 4
#define TAMB 5
#define TAMR 4
#define TAMTRAB 5
#define TAMCLIENTE 10


int main()
{

    int nextIdbicicleta= 50;
    int nextIdtrabajo= 100;
    int nextIdcliente= 47500;

    eBicicleta bicicletas[TAMB];
    eCliente clientes[TAMCLIENTE];
    eTipo tipos[TAMT]=
    {
        {1000,"RUTERA"},
        {1001,"CARRERA"},
        {1002,"MOUNTAIN"},
        {1003,"BMX"},
    };
    eColor colores[TAMC]=
    {
        {5000,"GRIS"},
        {5001,"NEGRO"},
        {5002,"BLANCO"},
        {5003,"AZUL"},
        {5004,"ROJO"},
    };
    eServicio servicios[TAMS]=
    {
        {20000,"LIMPIEZA",250},
        {20001,"PARCHE",300},
        {20002,"CENTRADO",400},
        {20003,"CADENA",350},
    };
    eTrabajo trabajos[TAMTRAB];
    float rodados[TAMR]= {20,26,27.5,29};

    inicializarBicicletas(bicicletas,TAMB);
    inicializartrabajos(trabajos,TAMTRAB);
    inicializarClientes(clientes,TAMCLIENTE);

    int contador=0;
    char salir='n';
    int flagcliente=0;

    do
    {
        switch(menu())
        {
            case 1:
            if(altacliente(clientes,TAMCLIENTE,&nextIdcliente))
            {
                printf("\nAlta exitosa!\n\n");
                flagcliente=1;
            }
            else
            {
                printf("\nHubo un problema al realizar el alta.\n\n");
            }
            break;
        case 2:
            if(flagcliente)
            {
                if(altabicicleta(bicicletas,TAMB,&nextIdbicicleta,colores,TAMC,tipos,TAMT,rodados,TAMR,clientes,TAMCLIENTE))
                {
                printf("\nAlta exitosa!\n\n");
                contador++;
                }else
                {
                printf ("\nHubo un problema al realizar el alta.\n\n");
                }
            }else
            {
                printf("\nNo puede dar alta una bicicleta hasta dar alta cliente.\n\n");
            }
            break;
        case 3:
            if(contador!=0&&modificarbicicleta(bicicletas,TAMB,tipos,TAMT,rodados,TAMR,colores,TAMC,clientes,TAMCLIENTE))
            {
                printf("\nModificacion exitosa!\n\n");
            }
            else if(!modificarbicicleta(bicicletas,TAMB,tipos,TAMT,rodados,TAMR,colores,TAMC,clientes,TAMCLIENTE))
            {
                printf("\nNo se pudo realizar la modificacion.\n\n");
            }
            else if(contador==0)
            {
                printf("\nNo puede acceder a esta opcion hasta dar un alta.\n\n");
            }
            break;
        case 4:
            if(contador!=0&&bajabicicleta(bicicletas,TAMB,tipos,TAMT,colores,TAMC,clientes,TAMCLIENTE))
            {
                printf("Baja exitosa.\n\n");
                contador--;
            }
            else if(!bajabicicleta(bicicletas,TAMB,tipos,TAMT,colores,TAMC,clientes,TAMCLIENTE))
            {
                printf("No se pudo realizar la baja.\n\n");
            }
            else if(contador==0)
            {
                printf("\nNo puede acceder a esta opcion hasta dar un alta.\n\n");
            }
            break;
        case 5:
            system("cls");
            if(!mostrarbicicletas(bicicletas,TAMB,colores,TAMC,tipos,TAMT,clientes,TAMCLIENTE))
            {
                printf("\nHubo un error al cargar las bicicletas.\n");
            }
            break;
        case 6:
            system("cls");
            if(!mostrarTipos(tipos,TAMT))
            {
                printf("\nHubo un error al cargar los tipos.\n");
            }
            break;
        case 7:
            system("cls");
            if(!mostrarcolores(colores,TAMC))
            {
                printf("\nHubo un error al cargar los colores.\n");
            }
            break;
        case 8:
            system("cls");
            if(!mostrarServicios(servicios,TAMS))
            {
                printf("\nHubo un error al cargar los servicios.\n");
            }
            break;
        case 9:
            if(altatrabajo(trabajos,TAMTRAB,&nextIdtrabajo,bicicletas,TAMB,servicios,TAMS,colores,TAMC,tipos,TAMT,clientes,TAMCLIENTE))
            {
                printf("Alta exitosa!\n\n");
            }
            else
            {
                printf("Hubo un problema al realizar el alta.\n\n");
            }
            break;
        case 10:
            system("cls");
            if(!mostrartrabajos(trabajos,TAMTRAB,bicicletas,TAMB,servicios,TAMS))
            {
                printf("\nHubo un error al cargar los trabajos.\n");
            }
            break;
        case 11:
            system("cls");
            switch(menuInformes())
            {
            case 1:
                if(!mostrarBicicletasPorColor(bicicletas,TAMB,colores,TAMC,tipos,TAMT,clientes,TAMCLIENTE))
                {
                    printf("\nHubo un error al cargar el informe.\n\n");
                }
                else
                {
                    printf("\nInforme exitoso.\n\n");
                }
                break;
            case 2:
                if(!mostrarBicicletasPorTipo(bicicletas,TAMB,colores,TAMC,tipos,TAMT,clientes,TAMCLIENTE))
                {
                    printf("\nHubo un error al cargar el informe.\n\n");
                }
                else
                {
                    printf("\nInforme exitoso.\n\n");
                }
                break;
            case 3:
                if(!bicicletaDeMenorRodado(bicicletas,TAMB,colores,TAMC,tipos,TAMT,clientes,TAMCLIENTE))
                {
                    printf("\nHubo un error al cargar el informe.\n\n");
                }
                else
                {
                    printf("\nInforme exitoso.\n\n");
                }
                break;
            case 4:
                if(!listarAllTipos(bicicletas,TAMB,tipos,TAMT,colores,TAMC,clientes,TAMCLIENTE))
                {
                    printf("\nHubo un error al cargar el informe.\n\n");
                }
                else
                {
                    printf("\nInforme exitoso.\n\n");
                }
                break;
            case 5:
                if(!contadorBicicletasPorTipoyColor(bicicletas,TAMB,colores,TAMC,tipos,TAMT))
                {
                    printf("\nHubo un error al cargar el informe.\n\n");
                }
                else
                {
                    printf("\nInforme exitoso.\n\n");
                }
                break;
            case 6:
                if(!colorMasElegido(bicicletas,TAMB,colores,TAMC))
                {
                    printf("\nHubo un error al cargar el informe.\n\n");
                }
                else
                {
                    printf("\nInforme exitoso.\n\n");
                }
                break;
            case 7:
                if(!mostrarTrabajosPorBicicleta(bicicletas,TAMB,trabajos,TAMTRAB,servicios,TAMS,colores,TAMC,tipos,TAMT,clientes,TAMCLIENTE))
                {
                    printf("\nHubo un error al cargar el informe.\n\n");
                }
                else
                {
                    printf("\nInforme exitoso.\n\n");
                }
                break;
            case 8:
                if(!mostrarTrabajosPorServicio(bicicletas,TAMB,servicios,TAMS,trabajos,TAMTRAB))
                {
                    printf("\nHubo un error al cargar el informe.\n\n");
                }
                else
                {
                    printf("\nInforme exitoso.\n\n");
                }
                break;
            case 9:
                if(!mostrarTrabajosPorFecha(bicicletas,TAMB,servicios,TAMS,trabajos,TAMTRAB))
                {
                    printf("\nHubo un error al cargar el informe.\n\n");
                }
                else
                {
                    printf("\nInforme exitoso.\n\n");
                }
                break;
            default:
                printf("Opcion invalida");
                system("pause");
            }
            system("pause");
            break;
        case 12:
            printf("Confirma salida? (s/n): ");
            fflush(stdin);
            salir=getchar();
            break;
        default:
            printf("Opcion invalida");
            system("pause");
        }
        system("pause");
    }
    while(!(salir=='s'||salir=='S'));

    return 0;
}
