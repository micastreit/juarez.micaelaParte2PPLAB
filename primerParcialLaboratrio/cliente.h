#ifndef CLIENTE_H_INCLUDED
#define CLIENTE_H_INCLUDED

typedef struct
{
    int idcliente;
    char nombre[20];
    char sexo;
    int isEmpty;
}eCliente;

#endif // CLIENTE_H_INCLUDED

int inicializarClientes(eCliente lista[], int tam);
int buscarLibrecliente(eCliente lista[],int tam);
int buscarcliente(int idcliente,eCliente lista[],int tam);
int altacliente(eCliente lista[],int tam,int* pIdcliente);
int cargarDescripcioncliente(int idcliente, eCliente lista[], int tam, char desc[]);
