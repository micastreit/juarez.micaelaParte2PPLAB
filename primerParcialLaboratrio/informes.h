#include "bicicleta.h"
#include "color.h"
#include "tipo.h"
#include "trabajo.h"

#ifndef INFORMES_H_INCLUDED
#define INFORMES_H_INCLUDED



#endif // INFORMES_H_INCLUDED
int menuInformes();
int mostrarBicicletasPorColor(eBicicleta bicicletas[],int tamb,eColor colores[],int tamc,eTipo tipos[],int tamt,eCliente clientes[],int tamcli);
int mostrarBicicletasPorTipo(eBicicleta bicicletas[],int tamb,eColor colores[],int tamc,eTipo tipos[],int tamt,eCliente clientes[],int tamcli);
int bicicletaDeMenorRodado(eBicicleta bicicletas[],int tamb,int tamr,eColor colores[],int tamc,eTipo tipos[],int tamt,eCliente clientes[],int tamcli);
int listarAllTipos(eBicicleta lista[],int tam,eTipo tipos[],int tamt,eColor colores[],int tamc,eCliente clientes[],int tamcli);
int contadorBicicletasPorTipoyColor(eBicicleta bicicletas[],int tamb,eColor colores[],int tamc,eTipo tipos[],int tamt);
int colorMasElegido(eBicicleta bicicletas[],int tamb,eColor colores[],int tamc);
int mostrarTrabajosPorBicicleta(eBicicleta bicicletas[],int tamb,eTrabajo trabajos[],int tamtrab,eServicio servicios[],int tams,eColor colores[],int tamc,eTipo tipos[],int tamt,eCliente clientes[],int tamcli);
int gastosDeTrabajosPorBicicleta(eBicicleta bicicletas[],int tamb,eTrabajo trabajos[],int tamtrab,eServicio servicios[],int tams,eColor colores[],int tamc,eTipo tipos[],int tamt,eCliente clientes[],int tamcli);
int mostrarTrabajosPorServicio(eBicicleta bicicletas[],int tamb,eServicio servicios[],int tams,eTrabajo trabajos[],int tamtrab);
int mostrarTrabajosPorFecha(eBicicleta bicicletas[],int tamb,eServicio servicios[],int tams,eTrabajo trabajos[],int tamtrab);
