#include <stdio.h>
#include <stdlib.h>
#include "empleado.h"
#include "misValid.h"
#include <string.h>
#define MAX_CARACTER 50

Empleado* Emp_new(void)
{
    return (Empleado*) malloc(sizeof(Empleado));
}

int Emp_delete(Empleado* this)
{
    int retorno = -1;
    if(this != NULL)
    {
        free(this);
        retorno = 0;
    }
    return retorno;
}

int Emp_setId(Empleado* this, int id)
{
    int retorno = -1;
    if(this != NULL && id >= 0)
    {
        this->id = id;
        retorno = 0;
    }
    return retorno;
}

int Emp_getId(Empleado* this, int* resultado)
{
    int retorno = -1;
    if(this != NULL && resultado != NULL)
    {
        *resultado = this->id;
        retorno = 0;
    }
    return retorno;
}


int Emp_setPeso(Empleado* this, float peso)
{
    int retorno = -1;
    if(this != NULL && (peso>=0))
    {
        this->peso = peso;
        retorno = 0;
    }
    return retorno;
}

int Emp_getPeso(Empleado* this, float* resultado)
{
    int retorno = -1;
    if(this != NULL && resultado != NULL)
    {
        *resultado = this->peso;
        retorno = 0;
    }
    return retorno;
}


int Emp_setNombre(Empleado* this, char *nombre)
{
    int retorno = -1;
    if(this != NULL && (!isValidNombre(nombre)))
    {
        strncpy(this->nombre,nombre,MAX_CARACTER);
        retorno = 0;
    }
    return retorno;
}

int Emp_getNombre(Empleado* this, char* resultado)
{
    int retorno = -1;
    if(this != NULL && resultado != NULL)
    {
        strncpy(resultado,this->nombre,MAX_CARACTER);
        retorno = 0;
    }
    return retorno;
}

int Emp_setEstado(Empleado* this, int estado)
{
    int retorno = -1;
    if(this != NULL &&  estado>= 0)
    {
        this->estado = estado;
        retorno = 0;
    }
    return retorno;
}

int Emp_getEstado(Empleado* this, int* resultado)
{
    int retorno = -1;
    if(this != NULL && resultado != NULL)
    {
        *resultado = this->estado;
        retorno = 0;
    }
    return retorno;
}

int Emp_construtor(Empleado* this,int id,int estado,float peso,char nombre)
{
    int retorno=-1;

    if(this != NULL)
    {
        Emp_new();
        Emp_setId(this,id);
        Emp_setPeso(this,peso);
        Emp_setNombre(this,&nombre);
        Emp_setEstado(this,estado);
        retorno=0;
    }
    return retorno;
}



