#ifndef COLOR_H_INCLUDED
#define COLOR_H_INCLUDED

typedef struct
{
    int idColor;
    char nombrecolor[20];
}eColor;

#endif // COLOR_H_INCLUDED

int cargarDescripcioncolor(int idcolor, eColor colores[], int tam, char desc[]);
int mostrarcolores(eColor colores[],int tam);
void mostrarcolor(eColor uncolor);
int validarIdColor(int idcolor,eColor colores[],int tam);
int buscarColor(int idcolor,eColor colores[],int tam);
