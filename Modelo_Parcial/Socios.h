#ifndef SOCIOS_H_INCLUDED
#define SOCIOS_H_INCLUDED

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


#endif // SOCIOS_H_INCLUDED
