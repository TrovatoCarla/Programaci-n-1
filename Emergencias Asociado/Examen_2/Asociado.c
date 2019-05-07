#ifndef ASOCIADO_C_INCLUDED
#define ASOCIADO_C_INCLUDED
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdio_ext.h>
#include "Asociado.h"
#include "funcionesUTN.h"
#include "misValid.h"
#define MAX_ARRAY 10
#define MAX_CARACTER 50
#define TRUE 1
#define FALSE 0
#define VACIO 1
#define HABILITADO 2
#define INHABILITADO 3

int aso_baja(Asociado* aPaciente,int limite,int idBaja)
{
    int retorno=-1;

    if(aso_buscarId(aPaciente,MAX_ARRAY,"\nIngrese ID a dar de baja","\nError,ID no encontrado",100,0,3,&idBaja)==0)
    {
        aPaciente[idBaja].estado=INHABILITADO;
        retorno=0;
    }
    else
    {
        printf("\nID no encontrado");
    }
    return retorno;
}

int aso_modificacion(Asociado* aPaciente,int limite)
{
    int retorno=1;
    int i;
    int bufferId;
    int opcion;
    char seguir='s';
    char auxNuevoNombre[MAX_CARACTER];
    char auxNuevoApellido[MAX_CARACTER];
    char auxNuevoDNI[MAX_CARACTER];
    int auxNuevaEdad;

    aso_muestra(aPaciente,MAX_ARRAY);

    if(aso_buscarId(aPaciente,MAX_ARRAY,"\nIngrese el ID a modificar ","\nError,ID incorrecto",1000,0,3,&bufferId)==0)
    {
        i=bufferId;
        while(seguir=='s')
        {
            printf("\n 1- Nombre");
            printf("\n 2- Apellido");
            printf("\n 3- DNI");
            printf("\n 4- Edad");
            printf("\n 5- Salir de Modificaciones");
            do
            {
                printf("\n\n       INDIQUE EL DATO QUE DESEA MODIFICAR: ");
                scanf("%d",&opcion);
            }while(opcion<1 || opcion>5);

                switch(opcion)
                {
                    case 1:
                        if(getName("\n\n   Ingrese nombre: ","Error",2,50,3,auxNuevoNombre)==0)
                        {
                            strncpy(aPaciente[i].nombre,auxNuevoNombre,MAX_CARACTER);
                            printf("\n      NOMBRE MODIFICADO CORRECTAMENTE\n");
                            break;
                        }
                    case 2:
                        if(getName("\n\n  Ingrese apellido: ","Error",2,50,3,auxNuevoApellido)==0)
                        {
                            strncpy(aPaciente[i].apellido,auxNuevoApellido,MAX_CARACTER);
                            printf("\n\n      APELLIDO MODIFICADO CORRECTAMENTE\n");
                            break;
                        }
                    case 3:
                        if(getDni("\n\n    Ingrese DNI: ","Error",1,999999,3,auxNuevoDNI)==0)
                        {
                            strncpy(aPaciente[i].DNI,auxNuevoDNI,MAX_CARACTER);
                            printf("\n\n      DNI MODIFICADO CORRECTAMENTE\n");
                            break;
                        }
                    case 4:
                        if(getInt("\n\n  Ingrese edad: ","Error",120,0,3,&auxNuevaEdad)==0)
                        {
                            aPaciente[i].edad=auxNuevaEdad;
                            printf("\n\n     Edad modificada correctamente\n");
                            break;
                        }
                    case 5:
                        seguir='n';
                        break;
                }
        }
             retorno=0;
    }
    else
    {
        printf("\n ID no encontrado");
    }
    return retorno;
}
int aso_buscarId(Asociado* aPaciente,int limite,char* msj,char* msjError,int maximo,int minimo,int reintentos,int* idEncontrado)
{
    int i;
    int retorno=1;
    int buffer;

    if(getInt(msj,msjError,maximo,minimo,reintentos,&buffer)==0)
    {
        for(i=0;i<limite;i++)
        {
            if(aPaciente[i].estado==buffer)
            {
                *idEncontrado=i;
                retorno=0;
                break;
            }
        }
    }
    return retorno;
}
int aso_alta(Asociado* aPaciente,char* msjError,int limite,int lugarDisponible)
{
    int retorno=-1;

    if(aso_buscaLugarLibre(aPaciente,MAX_ARRAY,&lugarDisponible)==0)
    {
        if(getName("\nIngrese nombre: ","\nError nombre invalido",40,2,3,aPaciente[lugarDisponible].nombre)==0)
        {
            if(getApellido("\nIngrese nombre: ","\nIngrese apellido: ",40,2,3,aPaciente[lugarDisponible].apellido)==0)
            {
                if(getDni("\nIngrese DNI: ","\nDNI invalido",2,20,3,aPaciente[lugarDisponible].DNI)==0)
                {
                    if(getInt("\nIngrese edad: ","\nEdad,invalida",120,0,3,&aPaciente[lugarDisponible].edad)==0)
                    {
                        aPaciente[lugarDisponible].estado=HABILITADO;
                        retorno=0;
                    }
                }
            }
        }
    }
    else
    printf("\nno hay lugar");
    return retorno;
}
void aso_muestra(Asociado* aPaciente,int limite)
{
    int i;

     for(i=0;i<limite;i++)
     {
        if(aPaciente[i].estado==HABILITADO)
        {
            printf("\n\nPosicion %d : NOMBRE: %s",i,aPaciente[i].nombre);
            printf("\n\n            : APELLIDO: %s",aPaciente[i].apellido);
            printf("\n\n            : DNI: %s",aPaciente[i].DNI);
            printf("\n\n            : EDAD: %d",aPaciente[i].edad);
            printf("\n\n            : ID: %d\n",aPaciente[i].idAsociado);
            printf("\n            : ESTADO: HABILITADO\n\n");
        }
    }
}
int aso_buscaLugarLibre(Asociado* aPaciente,int limite,int* posicionVacia)
{
    int i;
    int retorno=-1;

    for(i=0;i<limite;i++)
    {
        if(aPaciente[i].estado==VACIO)
        {
            *posicionVacia=i;
            retorno=0;
            break;
        }
    }
    return retorno;
}
int aso_initArray(Asociado* aPaciente,int limite)
{
    int i;
    int retorno=1;

    for(i=0;i<limite;i++)
    {
        aPaciente[i].estado=VACIO;
        retorno=0;
    }
    return retorno;
}



#endif // ASOCIADO_C_INCLUDED
