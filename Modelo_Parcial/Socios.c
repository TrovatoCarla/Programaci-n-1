#ifndef SOCIOS_C_INCLUDED
#define SOCIOS_C_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdio_ext.h>
#include "Autores.h"
#include "Libros.h"
#include "Socios.h"
#include "Fecha.h"
#include "funcionesUTN.h"
#include "misValid.h"


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

int soc_alta(Socio* socios,int limite,int posicionLibre,int id)
{
    int retorno;
    //__fpurge(stdin);

    if(soc_buscaPosicionLibre(socios,MAX_ARRAY,&posicionLibre)==0)
    {
        if(getApellido("\nIngrese apellido: ","\nError,apellido invalido",MAXIMO_CARACTER,2,3,socios[posicionLibre].apellido)==0)
        {
            if(getName("\nIngrese nombre: ","\nError,nombre invalido",MAXIMO_CARACTER,2,3,socios[posicionLibre].nombre)==0)
            {
                if(getSexo("\nIngrese sexo F o M: ","\nError,Sexo invalido",2,1,3,&socios[posicionLibre].sexo)==0)
                {
                    if(getTelefono("\nIngrese telefono: ","\nError,telefono invalido",16,3,3,socios[posicionLibre].telefono)==0)
                    {
                        if(getMail("\nIngrese mail: ","\nError,mail invalido",31,1,3,socios[posicionLibre].eMail)==0)
                        {
                                socios[posicionLibre].isEmpty=HABILITADO;
                                socios[posicionLibre].codigoSocio=id;
                                retorno=0;
                        }
                    }
                }
            }
        }
    }
    return retorno;
}

int soc_modificar(Socio* socios,int limite,int idAmodificar)
{
    int retorno;
    char seguir='s';
    int opcion;
    char auxNombre[MAXIMO_CARACTER];
    char auxApellido[MAXIMO_CARACTER];
    char auxSexo;
    char auxTelefono[16];
    char auxMail[31];
    int indiceAmodificar;///Agrego indiceAmodificar


    if(soc_buscaPorId(socios,MAX_ARRAY,idAmodificar,&indiceAmodificar)==0)///cambio puntero de idMofic aca y puso indiceAmodif
    {
        while(seguir=='s')
        {
            printf("\nMENU DE MOFICICACIONES: \n 1-Apellido \n 2-Nombre\n 3-Sexo\n 4-Telefono\n 5-Mail\n 6-Salir\n");
            do
            {

            }while(getInt("\nIngrese una opcion: ","\nError,opcion invalida",3,1,2,&opcion));

            switch(opcion)
            {
                case 1:
                    if(getApellido("\nIngrese Apellido: ","\nApellido invalido",MAXIMO_CARACTER,2,3,auxApellido)==0)
                    {
                        strncpy(socios[indiceAmodificar].apellido,auxApellido,MAXIMO_CARACTER);
                        printf("\nAPELLIDO MODIFICADO CORRECTAMENTE\n");
                    }
                break;
                case 2:
                    if(getName("\nIngrese nombre: ","\nNombre invalido\n",MAXIMO_CARACTER,2,3,auxNombre)==0)
                    {
                        strncpy(socios[indiceAmodificar].nombre,auxNombre,MAXIMO_CARACTER);
                        printf("\nNOMBRE MODIFICADO CORRECTAMENTE");
                    }
                    break;
                case 3:
                    if(getSexo("\nIngrese sexo F o M: ","\nSexo invalido",2,1,3,&auxSexo)==0)
                    {
                        socios[indiceAmodificar].sexo=auxSexo;
                        printf("\nSEXO MODIFICADO CORRECTAMENTE");
                    }
                    break;
                case 4:
                    if(getTelefono("\nIngrese telefono: ","Telefono invalido",16,2,3,auxTelefono)==0)
                    {
                        strncpy(socios[indiceAmodificar].telefono,auxTelefono,MAXIMO_CARACTER);
                        printf("\nTELEFONO MODIFICADO CORRECTAMENTE");
                    }
                    break;
                case 5:
                    if(getMail("\nIngrese mail: ","\nMail invalido",MAXIMO_CARACTER,2,3,auxMail)==0)
                    {
                        strncpy(socios[indiceAmodificar].eMail,auxMail,MAXIMO_CARACTER);
                    }
                    break;
                case 6:
                    seguir='n';
                    retorno=0;
                    break;
            }
        }
    }
    return retorno;
}

int soc_bajaSocio(Socio* socios,int limite,int idBaja)
{
    int retorno=-1;
    int indice;///agrego variable

    if(soc_buscaPorId(socios,limite,idBaja,&indice)==0)///y lo utiliza de puntero
    {
        socios[indice].isEmpty=INHABILITADO;
        retorno=0;
    }
    else
    {
        printf("\n ID NO ENCONTRADO");
    }
    return retorno;
}


#endif // SOCIOS_C_INCLUDED
