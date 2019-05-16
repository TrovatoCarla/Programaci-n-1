#ifndef SOCIOS_H_INCLUDED
#define SOCIOS_H_INCLUDED
#include "Fecha.h"

typedef struct
{
    int isEmpty;
    int codigoSocio;
    char apellido[31];
    char nombre[31];
    char sexo;
    char telefono[16];
    char eMail[31];
    char fechaAsociado;///Ver como lo genero para [...]
}Socio;

int soc_initArray(Socio* socios,int limite);
int soc_alta(Socio* socios, int limite, int* contadorID);
int soc_modificar(Socio* socios,int limite);
int soc_baja(Socio* socios, int limite);
int soc_buscaPosicionLibre(Socio* socios,int len,int* posicionLibre);
int soc_buscaPorId(Socio* socios,int limite,int idBusqueda,int* indice);
int soc_ordenaPorApellidoNombre(Socio* socios,int limite,int orderFirst,int orderSecond);
int soc_listar(Socio* socios, int limite);



#endif // SOCIOS_H_INCLUDED
