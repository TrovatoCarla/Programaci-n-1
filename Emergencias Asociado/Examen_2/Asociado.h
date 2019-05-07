#ifndef ASOCIADO_H_INCLUDED
#define ASOCIADO_H_INCLUDED
#include "Asociado.h"
#include <string.h>

typedef struct
{
    int idAsociado;
    int estado;
    char nombre[50];
    char apellido[50];
    char DNI[99999999];
    int edad;
}Asociado;

int aso_initArray(Asociado* aPaciente,int limite);
void aso_muestra(Asociado* aPaciente,int limite);
int aso_buscaLugarLibre(Asociado* aPaciente,int limite,int* posicionVacia);
int aso_alta(Asociado* aPaciente,char* msjError,int limite,int lugarDisponible);
int aso_buscarId(Asociado* aPaciente,int limite,char* msj,char* msjError,int maximo,int minimo,int reintentos,int* idEncontrado);
int aso_modificacion(Asociado* aPaciente,int limite);
int aso_baja(Asociado* aPaciente,int limite,int idBaja);



#endif // ASOCIADO_H_INCLUDED
