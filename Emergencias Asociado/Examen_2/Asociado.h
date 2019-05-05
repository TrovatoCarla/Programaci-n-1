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
    char DNI[50];
    int edad;
}Asociado;

int getName (char* mensaje, char* mensajeError, int minimo, int maximo, int reintentos, char* resultado);
int aso_buscaLugarLibre(Asociado* aPaciente,int limite,int* posicionVacia);
int aso_alta(Asociado* aPaciente,char* msjError,int limite,int lugarDisponible);
int isValidIntArray(char* cadena);
int getString(char *mensaje,char *mensajeError,char maximo,char minimo,int reintentos,char *resultado);
int isValidNombre(char *cadena);
int getDni(char *msj,char *msjError,int minimo,int maximo,int reintentos,char *resultado);
int getInt(char *msj,char *msjError,int maximo,int minimo,int reintentos,int *resultado);
int isValidInt(int numero, int maximo);
int aso_initArray(Asociado* paciente,int limite);


#endif // ASOCIADO_H_INCLUDED
