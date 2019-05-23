#ifndef PERSONA_C_INCLUDED
#define PERSONA_C_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Persona.h"
#include "funcionesUTN.h"
#include "misValid.h"
#define MAX_CARACTER 50

Persona* Per_new(void)
{
    return (Persona*) malloc(sizeof(Persona));
}

int Per_delete(Persona* this)
{
    int retorno = -1;
    if(this != NULL)
    {
        free(this);
        retorno = 0;
    }
    return retorno;
}

int Per_setId(Persona* this, int id)
{
    int retorno = -1;
    if(this != NULL && id >= 0)
    {
        this->id = id;
        retorno = 0;
    }
    return retorno;
}

int Per_getId(Persona* this, int* resultado)
{
    int retorno = -1;
    if(this != NULL && resultado != NULL)
    {
        *resultado = this->id;
        retorno = 0;
    }
    return retorno;
}

int Per_setNombre(Persona* this, char *nombre)
{
    int retorno = -1;
    if(this != NULL && (!isValidNombre(nombre)))
    {
        strncpy(this->nombre,nombre,MAX_CARACTER);
        retorno = 0;
    }
    return retorno;
}

int Per_getNombre(Persona* this, char* resultado)
{
    int retorno = -1;
    if(this != NULL && resultado != NULL)
    {
        strncpy(resultado,this->nombre,MAX_CARACTER);
        retorno = 0;
    }
    return retorno;
}

int Per_setApellido(Persona* this, char *apellido)
{
    int retorno = -1;
    if(this != NULL && (!isValidNombre(apellido)))
    {
        strncpy(this->apellido,apellido,MAX_CARACTER);
        retorno = 0;
    }
    return retorno;
}

int Per_getApellido(Persona* this, char* resultado)
{
    int retorno = -1;
    if(this != NULL && resultado != NULL)
    {
        strncpy(resultado,this->apellido,MAX_CARACTER);
        retorno = 0;
    }
    return retorno;
}

int Per_setEstado(Persona* this, int estado)
{
    int retorno = -1;
    if(this != NULL &&  estado>= 0)
    {
        this->estado = estado;
        retorno = 0;
    }
    return retorno;
}

int Per_getEstado(Persona* this, int* resultado)
{
    int retorno = -1;
    if(this != NULL && resultado != NULL)
    {
        *resultado = this->estado;
        retorno = 0;
    }
    return retorno;
}

int Per_construtor(Persona* this,int id,int estado,char nombre,char apellido)
{
    int retorno=-1;

    if(this != NULL)
    {
        Per_new();
        Per_setId(this,id);
        Per_setNombre(this,&nombre);
        Per_setApellido(this,&apellido);
        Per_setEstado(this,estado);
        retorno=0;
    }
    return retorno;
}

#endif // PERSONA_C_INCLUDED
