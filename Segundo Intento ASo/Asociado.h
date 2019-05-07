///NUEVOOOOO

#ifndef ASOCIADO_H_INCLUDED
#define ASOCIADO_H_INCLUDED

typedef struct
{
    int estado;
    int isEmpty;
    char nombre[50];
    char apellido[50];
    char DNI[50];
    int edad;
}Asociado;

int aso_initArray(Asociado* paciente,int limite);
int aso_buscaLugarLibre(Asociado* paciente,int limite,int* PosicionLibre);


#endif // ASOCIADO_H_INCLUDED
