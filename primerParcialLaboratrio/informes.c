#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "informes.h"

/** \brief despliega un menu de opciones
 * \param void
 * \return int retorna la opcion ingresada por el usuario
 */
int menuInformes()
{
    int opcion;
    system("cls");
    printf("1) Mostrar bicicletas por color seleccionado.\n");
    printf("2) Mostrar bicicletas por tipo seleccionado.\n");
    printf("3) Informar la bicicleta de menor rodado.\n");
    printf("4) Mostrar bicicletas separadas por tipo.\n");
    printf("5) Elegir color y tipo, y contar cuantas bicicletas hay.\n");
    printf("6) Mostrar el/los colores mas elegidos por los clientes.\n");
    printf("7) Pedir una bicicleta y mostrar todos los trabajos.\n");
    printf("8) Pedir una bicicleta e informar la suma de los servicios que se le hicieron.\n");
    printf("9) Pedir un servicio y mostrar las bicicletas a las que se les realizo.\n");
    printf("10) Pedir una fecha y mostrar todos los servicios realizados en la misma.\n");
    printf("\nElija una opcion: ");
    scanf("%d", &opcion);
    return opcion;
}

int mostrarBicicletasPorColor(eBicicleta bicicletas[],int tamb,eColor colores[],int tamc,eTipo tipos[],int tamt,eCliente clientes[],int tamcli)
{
    int todoOk=0;
    if(bicicletas!=NULL&&tamb>0&&colores!=NULL&&tamc>0&&tipos!=NULL&&tamt>0&&clientes!=NULL&&tamcli>0)
    {
        int idColor;
        int indice;
        int flag=0;
        system("cls");
        printf("        Informe de bicicletas por color.\n\n");
        mostrarcolores(colores,tamc);
        printf("Ingrese el ID del color: ");
        scanf("%d",&idColor);
        indice=buscarColor(idColor,colores,tamc);
        while(indice==-1)
        {
            printf("ID invalido. Ingrese el ID del color: ");
            scanf("%d",&idColor);
            indice=buscarColor(idColor,colores,tamc);
        }
        system("cls");
        printf("    Listado de bicicletas del color %s\n\n",colores[indice].nombrecolor);
        printf("CLIENTE   ID BICI   MARCA       TIPO         COLOR        RODADO\n");
        printf("------------------------------------------------------------------------\n");
        for(int i=0; i<tamb; i++)
        {
            if(!bicicletas[i].isEmpty &&bicicletas[i].idcolor==idColor)
            {
                mostrarbicicleta(bicicletas[i],colores,tamc,tipos,tamt,clientes,tamcli);
                flag=1;
            }
        }
        if(!flag)
        {
            printf("\nNo hay bicicletas del color %s.\n",colores[indice].nombrecolor);
        }
        todoOk=1;
    }
    return todoOk;
}

int mostrarBicicletasPorTipo(eBicicleta bicicletas[],int tamb,eColor colores[],int tamc,eTipo tipos[],int tamt,eCliente clientes[],int tamcli)
{
    int todoOk=0;
    if(bicicletas!=NULL&&tamb>0&&colores!=NULL&&tamc>0&&tipos!=NULL&&tamt>0&&clientes!=NULL&&tamcli>0)
    {
        int idTipo;
        int indice;
        int flag=0;
        system("cls");
        printf("        Informe de bicicletas por tipo.\n\n");
        mostrarTipos(tipos,tamt);
        printf("Ingrese el ID del tipo: ");
        scanf("%d",&idTipo);
        indice=buscarTipo(idTipo,tipos,tamt);
        while(indice==-1)
        {
            printf("ID invalido. Ingrese el ID del tipo: ");
            scanf("%d",&idTipo);
            indice=buscarTipo(idTipo,tipos,tamt);
        }
        system("cls");
        printf("    Listado de bicicletas del tipo %s\n\n",tipos[indice].descripcion);
        printf("CLIENTE   ID BICI   MARCA       TIPO         COLOR        RODADO\n");
        printf("------------------------------------------------------------------------\n");
        for(int i=0; i<tamb; i++)
        {
            if(!bicicletas[i].isEmpty &&bicicletas[i].idtipo==idTipo)
            {
                mostrarbicicleta(bicicletas[i],colores,tamc,tipos,tamt,clientes,tamcli);
                flag=1;
            }
        }
        if(!flag)
        {
            printf("\nNo hay bicicletas del tipo %s.\n",tipos[indice].descripcion);
        }
        todoOk=1;
    }
    return todoOk;
}

int bicicletaDeMenorRodado(eBicicleta bicicletas[],int tamb,int tamr,eColor colores[],int tamc,eTipo tipos[],int tamt,eCliente clientes[],int tamcli)
{
    int todoOk=0;
    if(bicicletas!=NULL&&tamb>0&&tamr>0&&colores!=NULL&&tamc>0&&tipos!=NULL&&tamt>0)
    {
        float rodadosbicis[tamb];
        float menor;
        int flag=0;
        system("cls");
        printf("       BICICLETAS DE MENOR RODADO.\n\n");

        for(int i=0; i<tamb; i++)
        {
            if(bicicletas[i].isEmpty==0)
            {
                if(flag==0 || bicicletas[i].rodado<menor)
                {
                    menor= bicicletas[i].rodado;
                    flag=1;
                }
            }
        }

        for (int i =0; i<tamb; i++)
        {
            if(menor==bicicletas[i].rodado)
            {
                mostrarbicicleta(bicicletas[i],colores,tamc,tipos,tamt,clientes,tamcli);
            }
        }
        printf("\n\n");
    todoOk=1;
    }
return todoOk;
}


int listarAllTipos(eBicicleta lista[],int tam,eTipo tipos[],int tamt,eColor colores[],int tamc,eCliente clientes[],int tamcli)
{
    int todoOk=0;
    if(lista!=NULL&&tam>0&&colores!=NULL&&tamc>0&&tipos!=NULL&&tamt>0&&clientes!=NULL&&tamcli>0)
    {
        int flag;
        system("cls");
        printf("Listado de bicicletas por tipos.\n");
        for(int i=0; i<tamt; i++)
        {
            printf("\n   Tipo: %s\n\n",tipos[i].descripcion);
            flag=1;
            for(int j=0; j<tam; j++)
            {
                if(!lista[j].isEmpty&&lista[j].idtipo==tipos[i].idTipo)
                {
                    mostrarbicicleta(lista[j],colores,tamc,tipos,tamt,clientes,tamcli);
                    flag=0;
                }
            }
            if(flag)
            {
                printf("No hay bicicletas que pertenezcan a este tipo.\n");
            }
            printf("---------------------------------------------------------------------\n");
        }
        todoOk=1;
    }
    return todoOk;
}

int contadorBicicletasPorTipoyColor(eBicicleta bicicletas[],int tamb,eColor colores[],int tamc,eTipo tipos[],int tamt)
{
    int todoOk=0;
    if(bicicletas!=NULL&&tamb>0&&colores!=NULL&&tamc>0&&tipos!=NULL&&tamt>0)
    {
        int idTipo;
        int idColor;
        int indicetipo;
        int indicecolor;
        int contador=0;
        system("cls");
        printf("        Contador de bicicletas por tipo y color.\n\n");
        mostrarTipos(tipos,tamt);
        printf("Ingrese el ID del tipo: ");
        scanf("%d",&idTipo);
        indicetipo=buscarTipo(idTipo,tipos,tamt);
        while(indicetipo==-1)
        {
            printf("ID invalido. Ingrese el ID del tipo: ");
            scanf("%d",&idTipo);
            indicetipo=buscarTipo(idTipo,tipos,tamt);
        }
        mostrarcolores(colores,tamc);
        printf("Ingrese el ID del color: ");
        scanf("%d",&idColor);
        indicecolor=buscarColor(idColor,colores,tamc);
        while(indicecolor==-1)
        {
            printf("ID invalido. Ingrese el ID del color: ");
            scanf("%d",&idColor);
            indicecolor=buscarColor(idColor,colores,tamc);
        }
        system("cls");
        printf("    Cantidad de bicicletas del tipo %s y color %s\n\n",tipos[indicetipo].descripcion,colores[indicecolor].nombrecolor);

        for(int i=0; i<tamb; i++)
        {
            if(!bicicletas[i].isEmpty &&bicicletas[i].idtipo==idTipo&&bicicletas[i].idcolor==idColor)
            {
                contador++;
            }
        }
        if(!contador)
        {
            printf("\nNo hay bicicletas del tipo %s y color %s\n\n",tipos[indicetipo].descripcion,colores[indicecolor].nombrecolor);
        }
        else
        {
            printf("\nHay %d bicicletas de tipo %s y color %s\n\n",contador,tipos[indicetipo].descripcion,colores[indicecolor].nombrecolor);
        }

        todoOk=1;
    }
    return todoOk;
}

int colorMasElegido(eBicicleta bicicletas[],int tamb,eColor colores[],int tamc)
{
    int todoOk=0;
    if(bicicletas!=NULL&&tamb>0&&colores!=NULL&&tamc>0)
    {
        int contcolores[tamc];
        int flag=0;
        int flagcol=0;
        int mayor;

        for(int c=0; c<tamc; c++)
        {
            contcolores[c]=0;
            for(int j=0; j<tamb; j++)
            {
                if(!bicicletas[j].isEmpty&&bicicletas[j].idcolor==colores[c].idColor)
                {
                    contcolores[c]++;
                    flagcol=1;
                }
            }
        }
        if(!flagcol)
        {
            printf("\nNo hay bicicletas.\n\n");
        }
        else
        {
            for(int i=0; i<tamc; i++)
            {
                if(!flag||contcolores[i]>mayor)
                {
                    mayor=contcolores[i];
                    flag=1;
                }
            }
            for(int i=0; i<tamc; i++)
            {
                if(mayor==contcolores[i])
                {
                    printf("El color mas elegido es %s\n",colores[i].nombrecolor);
                }
            }
        }

        printf("\n\n");
        todoOk=1;
    }
    return todoOk;
}

int mostrarTrabajosPorBicicleta(eBicicleta bicicletas[],int tamb,eTrabajo trabajos[],int tamtrab,eServicio servicios[],int tams,eColor colores[],int tamc,eTipo tipos[],int tamt,eCliente clientes[],int tamcli)
{
    int todoOk=0;
    if(bicicletas!=NULL&&tamb>0&&trabajos!=NULL&&tamtrab>0&&servicios!=NULL&&tams>0&&colores!=NULL&&tamc>0&&tipos!=NULL&&tamt>0&&clientes!=NULL&&tamcli>0)
    {
        int idBicicleta;
        int indice;
        int flag=0;
        system("cls");
        printf("        Informe de trabajos por bicicletas.\n\n");
        mostrarbicicletas(bicicletas,tamb,colores,tamc,tipos,tamt,clientes,tamcli);
        printf("Ingrese el ID de la bicicleta: ");
        scanf("%d",&idBicicleta);
        indice=buscarbicicleta(idBicicleta,bicicletas,tamb);
        while(indice==-1)
        {
            printf("ID invalido. Ingrese el ID de la bicicleta: ");
            scanf("%d",&idBicicleta);
            indice=buscarbicicleta(idBicicleta,bicicletas,tamb);
        }
        system("cls");
        printf("    Listado de trabajos de la bicicleta de ID %d\n\n",bicicletas[indice].idbicicleta);
        printf("ID   FECHA      ID BICICLETA    MARCA  SERVICIO \n");
        printf("-------------------------------------------------------------\n");
        for(int i=0; i<tamtrab; i++)
        {
            if(!trabajos[i].isEmpty &&trabajos[i].idbicicleta==idBicicleta)
            {
                mostrartrabajo(trabajos[i],bicicletas,tamb,servicios,tams);
                flag=1;
            }
        }
        if(!flag)
        {
            printf("\nNo hay trabajos de la bicicleta de ID %d.\n",bicicletas[indice].idbicicleta);
        }
        todoOk=1;
    }
    return todoOk;
}

int gastosDeTrabajosPorBicicleta(eBicicleta bicicletas[],int tamb,eTrabajo trabajos[],int tamtrab,eServicio servicios[],int tams,eColor colores[],int tamc,eTipo tipos[],int tamt,eCliente clientes[],int tamcli)
{
    int todoOk=0;
    if(bicicletas!=NULL&&tamb>0&&trabajos!=NULL&&tamtrab>0&&servicios!=NULL&&tams>0&&colores!=NULL&&tamc>0&&tipos!=NULL&&tamt>0&&clientes!=NULL&&tamcli>0)
    {
        int idBicicleta;
        int indice;
        float total=0;
        int flag=0;
        system("cls");
        printf("        Informe de trabajos por bicicletas.\n\n");
        mostrarbicicletas(bicicletas,tamb,colores,tamc,tipos,tamt,clientes,tamcli);
        printf("Ingrese el ID de la bicicleta: ");
        scanf("%d",&idBicicleta);
        indice=buscarbicicleta(idBicicleta,bicicletas,tamb);
        while(indice==-1)
        {
            printf("ID invalido. Ingrese el ID de la bicicleta: ");
            scanf("%d",&idBicicleta);
            indice=buscarbicicleta(idBicicleta,bicicletas,tamb);
        }
        system("cls");
        printf("    Listado de trabajos de la bicicleta de ID %d\n\n",bicicletas[indice].idbicicleta);

        for(int i=0; i<tamtrab; i++)
        {
            if(!trabajos[i].isEmpty &&trabajos[i].idbicicleta==idBicicleta)
            {
                for(int s=0; s<tams; s++)
                {
                    if(trabajos[i].idservcio==servicios[s].idservicio)
                    {
                        total=servicios[s].precio;
                        flag=1;
                    }
                }
            }
        }
        if(!flag)
        {
            printf("\nNo hay trabajos de la bicicleta de ID %d.\n",bicicletas[indice].idbicicleta);
        }
        else
        {
            printf("\nLos gastos de la bicicleta de ID %d son de: $%.2f.\n\n",bicicletas[indice].idbicicleta,total);
        }
        todoOk=1;
    }
    return todoOk;
}

int mostrarTrabajosPorServicio(eBicicleta bicicletas[],int tamb,eServicio servicios[],int tams,eTrabajo trabajos[],int tamtrab)
{
    int todoOk=0;
    if(bicicletas!=NULL&&tamb>0&&servicios!=NULL&&tams>0&&trabajos!=NULL&&tamtrab>0)
    {
        int idServicio;
        int indice;
        int flag=0;
        system("cls");
        printf("        Informe de bicicletas por servicio.\n\n");
        mostrarServicios(servicios,tams);
        printf("Ingrese el ID del servicio: ");
        scanf("%d",&idServicio);
        indice=buscarServicio(idServicio,servicios,tams);
        while(indice==-1)
        {
            printf("ID invalido. Ingrese el ID del servicio: ");
            scanf("%d",&idServicio);
            indice=buscarServicio(idServicio,servicios,tams);
        }
        system("cls");
        printf("    Listado de bicicletas que se realizaron el servicio %s\n\n",servicios[indice].descripcion);
        printf("ID   FECHA      ID BICICLETA    MARCA  SERVICIO \n");
        printf("----------------------------------------------------------------------\n");
        for(int i=0; i<tamtrab; i++)
        {
            if(!trabajos[i].isEmpty &&trabajos[i].idservcio==idServicio)
            {
                mostrartrabajo(trabajos[i],bicicletas,tamb,servicios,tams);
                flag=1;
            }
        }
        if(!flag)
        {
            printf("\nNo hay bicicletas que le realizaran el servicio %s.\n",servicios[indice].descripcion);
        }
        todoOk=1;
    }
    return todoOk;
}

int mostrarTrabajosPorFecha(eBicicleta bicicletas[],int tamb,eServicio servicios[],int tams,eTrabajo trabajos[],int tamtrab)
{
    int todoOk=0;
    if(bicicletas!=NULL&&tamb>0&&servicios!=NULL&&tams>0&&trabajos!=NULL&&tamtrab>0)
    {
        eFecha unafecha;
        int flag=0;
        system("cls");
        printf("        Informe de trabajos por fecha.\n\n");
        mostrartrabajos(trabajos,tamtrab,bicicletas,tamb,servicios,tams);
        printf("Ingrese la fecha por la que desea filtrar los trabajos: ");
        scanf("%d/%d/%d",&unafecha.dia,&unafecha.mes,&unafecha.anio);
        while(!(unafecha.dia>0&&unafecha.dia<=31
                &&unafecha.mes>0&&unafecha.mes<=12
                &&unafecha.anio>0))
        {
            printf("Fecha invalida. Ingrese una fecha: ");
            scanf("%d/%d/%d",&unafecha.dia,&unafecha.mes,&unafecha.anio);
        }
        system("cls");
        printf("    Listado de trabajos que se realizaron la fecha %d/%d/%d\n\n",unafecha.dia,unafecha.mes,unafecha.anio);
        printf("ID   FECHA      ID BICICLETA    MARCA  SERVICIO \n");
        printf("----------------------------------------------------------------------\n");
        for(int i=0; i<tamtrab; i++)
        {
            if(!trabajos[i].isEmpty &&trabajos[i].fecha.dia==unafecha.dia
                    &&trabajos[i].fecha.mes==unafecha.mes
                    &&trabajos[i].fecha.anio==unafecha.anio)
            {
                mostrartrabajo(trabajos[i],bicicletas,tamb,servicios,tams);
                flag=1;
            }
        }
        if(!flag)
        {
            printf("\nNo hay trabajos que se realizaron la fecha %d/%d/%d\n\n",unafecha.dia,unafecha.mes,unafecha.anio);
        }
        todoOk=1;
    }
    return todoOk;
}

