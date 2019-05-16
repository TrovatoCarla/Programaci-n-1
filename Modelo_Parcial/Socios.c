#ifndef SOCIOS_C_INCLUDED
#define SOCIOS_C_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdio_ext.h>
#include "Autores.h"
#include "Libros.h"
#include "Socios.h"
#include "funcionesUTN.h"
#include "misValid.h"
#define MIN_CARACTER 1
#define  CANT_DIG_MIN   1
#define  CANT_DIG_MAX   50
#define SALARIO_MAXIMO 100000
#define SALARIO_MINIMO 100


int soc_initArray(Socio* socios,int limite)
{
    int i;
    int retorno;
    for(i=0;i<limite;i++)
    {
        socios[i].isEmpty=VACIO;
        retorno=0;
    }
    return retorno;
}
int soc_buscaPorId(Socio* socios,int limite,int idBusqueda,int* indice)///Agrego idBusqueda e indice
{
    int i;
    int retorno=-1;
    ///Saco bufferID y lo reemplazo por idBusqueda
    ///Quito el getInt de aca y lo agrego al main.

    for(i=0;i<limite;i++)
    {
        if(idBusqueda==socios[i].codigoSocio)
        {
            *indice=i;///Cambio idEncontrado por indice
            retorno=0;
            break;
        }
    }

    return retorno;
}
int soc_buscaPosicionLibre(Socio* socios,int len,int* posicionLibre)
{
    int i;
    int retorno;

    for(i=0;i<len;i++)
    {
        if(socios[i].isEmpty==VACIO)
        {
            *posicionLibre=i;
            retorno=0;
            break;
        }
    }
    return retorno;
}
int soc_alta(Socio* socios, int limite, int* contadorID)
{
    int retorno=-1;
    int posicion;
    if(socios!=NULL && limite>0 && contadorID!=NULL)
    {
        if(soc_buscaPosicionLibre(socios,limite,&posicion)==-1)
        {
            printf("\nNo hay lugares vacios");
        }
        else
        {
            (*contadorID)++;
            socios[posicion].codigoSocio=*contadorID;
            socios[posicion].isEmpty=0;
            if((!getName("\nIngrese nombre: ","\nNombre invalido\n",MAXIMO_CARACTER,MIN_CARACTER,2,socios[posicion].nombre)) &&          //mensaje + cambiar campo varInt
            (!getApellido("\nIngrese apellido: ","\nApellido invalido\n",MAXIMO_CARACTER,MIN_CARACTER,2,socios[posicion].apellido)) &&             //mensaje + cambiar campo varFloat
            ///(!getFloat("\nIngrese salario: ","\nSalario invalido\n",SALARIO_MAXIMO,SALARIO_MINIMO,2,&socios[posicion].auxFloat))&&                      //mensaje + cambiar campo varString
            ///(!getSexo("\nIngrese sexo F o M: ","\nSexo invalido\n",CANT_DIG_MAX,CANT_DIG_MIN,2,&socios[posicion].sexo))&& //mensaje + cambiar campo varLongString
            (!getTelefono("\nIngrese telefono: ","Telefono invalido\n",MAXIMO_CARACTER,MIN_CARACTER,2,socios[posicion].telefono))&&
            (!getMail("\nIngrese Mail: ","\nMail invalido\n",MAXIMO_CARACTER,MIN_CARACTER,2,socios[posicion].eMail)))
            printf("\n Posicion: %d\n ID: %d\n Nombre: %s\n Apellido: %s\n Telefono: %s\n Mail: %s\n\n",
                   posicion, socios[posicion].codigoSocio,socios[posicion].nombre,
                   socios[posicion].apellido,socios[posicion].telefono,socios[posicion].eMail);

                retorno=0;
        }
    }
    return retorno;
}
int soc_modificar(Socio* socios,int limite)///OK
{
    int retorno=-1;
    int opcion;
    int posicion;
    int id;
    char auxNombre[MAXIMO_CARACTER];
    char auxApellido[MAXIMO_CARACTER];
    char auxSexo;
    char auxTelefono[16];
    char auxMail[31];
    ///Agrego indiceAmodificar

    if(socios!=NULL && limite>0)
    {
        soc_listar(socios,MAX_ARRAY);
        getInt("\nIngrese ID a modificar: ","\nError",CANT_DIG_MAX,CANT_DIG_MIN,2,&id); ///cambiar si no se busca por ID
        if(soc_buscaPorId(socios,limite,id,&posicion)==-1)  ///cambiar si no se busca por ID
        {
            printf("\nNo existe este ID");///cambiar si no se busca por ID
        }
        else
        {
            do
            {
                /*printf("\n Posicion: %d\n ID: %d\n Nombre: %s\n Apellido: %s\n Telefono: %s\n Mail: %s\n\n",
                        posicion,socios[posicion].codigoSocio,socios[posicion].nombre,
                        socios[posicion].apellido,socios[posicion].telefono,socios[posicion].eMail);*/
                getInt("\nMENU DE MOFICICACIONES: \n 1-Apellido \n 2-Nombre\n 3-Sexo\n 4-Telefono\n 5-Mail\n 6-Salir\n","\nError,opcion invalida",6,1,2,&opcion);

            switch(opcion)
            {
                case 1:
                    if(getApellido("\nIngrese Apellido: ","\nApellido invalido",MAXIMO_CARACTER,2,3,auxApellido)==0)
                    {
                        strncpy(socios[posicion].apellido,auxApellido,MAXIMO_CARACTER);
                        printf("\nAPELLIDO MODIFICADO CORRECTAMENTE\n");
                    }
                break;
                case 2:
                    if(getName("\nIngrese nombre: ","\nNombre invalido\n",MAXIMO_CARACTER,2,3,auxNombre)==0)
                    {
                        strncpy(socios[posicion].nombre,auxNombre,MAXIMO_CARACTER);
                        printf("\nNOMBRE MODIFICADO CORRECTAMENTE");
                    }
                    break;
                case 3:
                    if(getSexo("\nIngrese sexo F o M: ","\nSexo invalido",2,1,3,&auxSexo)==0)
                    {
                        socios[posicion].sexo=auxSexo;
                        printf("\nSEXO MODIFICADO CORRECTAMENTE");
                    }
                    break;
                case 4:
                    if(getTelefono("\nIngrese telefono: ","Telefono invalido",16,2,3,auxTelefono)==0)
                    {
                        strncpy(socios[posicion].telefono,auxTelefono,MAXIMO_CARACTER);
                        printf("\nTELEFONO MODIFICADO CORRECTAMENTE");
                    }
                    break;
                case 5:
                    if(getMail("\nIngrese mail: ","\nMail invalido",MAXIMO_CARACTER,2,3,auxMail)==0)
                    {
                        strncpy(socios[posicion].eMail,auxMail,MAXIMO_CARACTER);
                    }
                    break;
                case 6:
                    break;
                }
            }while(opcion!=6);
            retorno=0;
        }
    }
    return retorno;
}
int soc_baja(Socio* socios, int limite)///OK
{
    int retorno=-1;
    int posicion;
    int id;
    if(socios!=NULL && limite>0)
    {
        soc_listar(socios,MAX_ARRAY);
        getInt("\nIngrese ID a cancelar: ","\nError",CANT_DIG_MAX,CANT_DIG_MIN,2,&id); ///cambiar si no se busca por ID
        if(soc_buscaPorId(socios,limite,id,&posicion)==-1)         ///cambiar si no se busca por ID
        {
            printf("\nNo existe este ID");  ///cambiar si no se busca por ID
        }
        else
        {
            socios[posicion].isEmpty=1;
            socios[posicion].codigoSocio=0;            ///cambiar campo id
            //socios[posicion].auxInt=0;             ///cambiar campo auxInt
           // socios[posicion].auxFloat=0;   ///cambiar campo auxFloar
            strcpy(socios[posicion].telefono,"");
            strcpy(socios[posicion].eMail,"");
            strcpy(socios[posicion].nombre,"");    ///cambiar campo nombre
            strcpy(socios[posicion].apellido,"");  ///cambiar campo apellido
            retorno=0;
        }
    }
    return retorno;
}
int soc_ordenaPorApellidoNombre(Socio* socios,int limite,int orderFirst,int orderSecond)                              //cambiar fantasma
{
    int retorno=-1;
    int i;
    Socio buffer;
    int flagSwap;

    if(socios!=NULL && limite>=0)
    {
        do
        {
            flagSwap=0;
            for (i = 0; i < limite-1; i++)
            {
                if(((strcmp(socios[i].apellido,socios[i+1].apellido) < 0) && orderFirst) ||
                    ((strcmp(socios[i].apellido,socios[i+1].apellido) > 0) && !orderFirst))
                {
                    flagSwap=1;
                    buffer = socios[i];
                    socios[i] = socios[i+1];
                    socios[i+1] = buffer;
                }
                else if(strcmp(socios[i].apellido,socios[i+1].apellido) == 0)
                {
                    if( ((strcmp(socios[i].nombre,socios[i+1].nombre)< 0) && orderSecond) ||
                       ( (strcmp(socios[i].nombre,socios[i+1].nombre)> 0) && !orderSecond) )
                    {
                        flagSwap=1;
                        buffer = socios[i];
                        socios[i] = socios[i+1];
                        socios[i+1] = buffer;
                    }
                }
            }
        }while(flagSwap);
        retorno=0;
    }
    return retorno;
}
int soc_listar(Socio* socios, int limite)///OK
{
    int retorno=-1;
    int i;
    if(socios!=NULL && limite>=0)
    {
        for(i=0;i<limite;i++)
        {
            if(socios[i].isEmpty==1)
                continue;
            else
                 printf("\n Posicion: %d\n ID: %d\n Apellido: %s\n Nombre: %s\n Telefono: %s\n Mail: %s\n\n",
                   i, socios[i].codigoSocio,socios[i].apellido,socios[i].nombre,socios[i].telefono,socios[i].eMail);

        }
        retorno=0;
    }
    return retorno;
}
#endif // SOCIOS_C_INCLUDED
