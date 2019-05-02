#ifndef PUBLICIDAD_C_INCLUDED
#define PUBLICIDAD_C_INCLUDED
#define MAX_ID 10
#define MAX_CARACTER 50
#include "Publicidad.h"
#include "Pantalla.h"

int pub_alta(Publicidad* publicidades,char* msjError,int limite,int posicionLibre)
{
    int retorno=1;
   // int auxID=0;

    if(getInt("\nIngrese ID de la pantalla que desea contratar","\nError,ID inexistente",1,100,3,publicidades[posicionLibre].idPublicidad))
    {
        if(getName("\n Ingrese su nombre: ","\nERROR, no es un nombre",2,50,3,publicidades[posicionLibre].)==0)
        {
            if(getString("\n Ingrese su direccion: ","Error",5,250,3,pantallas[posicionLibre].direccion)==0)
            {
                if(getFloat("\n Ingrese precio: ","Error",0,5000,3,&pantallas[posicionLibre].precio)==0)
                {
                    if(getString("\n Ingrese tipo de pantalla LCD o Led: ","Error",3,6,3,pantallas[posicionLibre].tipo)==0)
                    {
                        pantallas[posicionLibre].isEmpty=0;
                        //pantallas[posicionLibre].idPantalla=auxID;
                        retorno=0;
                    }
                     else
                    {
                        printf("Error,no se pudo cargar");
                    }

                }
            }
        }
    }
    return retorno;
}


int pub_baja(Publicidad* publicidades,char limite)
{

    int posicionAdarDeBaja;
    int retorno=-1;
    muestraArray(publicidades,MAX_ID);

    switch (buscarId(publicidades,MAX_ID,"\nIngrese el ID a dar de baja ","\nError,ID incorrecto",1000,0,3,&posicionAdarDeBaja))
    {
        case 0:
            publicidades[posicionAdarDeBaja].isEmpty=1;
            retorno=0;
            break;
        case 1:
            printf("\n      ID NO ENCONTRADO PARA LA BAJA");
            break;
    }
    return retorno;
}

int pub_modificacion(Publicidad* publicidades,char limite)
{
    int retorno=1;
    int i;
    int bufferId;
    int opcion;
    char seguir='s';
    char auxNuevoCuit[MAX_CARACTER];
    char auxNuevoArchivo[MAX_CARACTER];
    int auxNuevosDias;

    muestraArray(publicidades,MAX_ID);


    if(buscarId(publicidades,MAX_ID,"\nIngrese el ID a modificar ","\nError,ID incorrecto",1000,0,3,&bufferId)==0)
    {
        i=bufferId;
        while(seguir=='s')
        {
            printf("\n 1- Cuit");
            printf("\n 2- Dias de contratacion");
            printf("\n 3- Archivo");
            printf("\n 4- Salir de Modificaciones");
            do
            {
                printf("\n\n       INDIQUE EL DATO QUE DESEA MODIFICAR: ");
                scanf("%d",&opcion);
            }while(opcion<1 || opcion>4);

                switch(opcion)
                {
                    case 1:
                        if(getCuit("\n\n   Ingrese el nuevo Cuit: ","Error",10,20,3,auxNuevoCuit)==0)
                        {
                            strncpy(publicidades[i].cuit,auxNuevoCuit,MAX_CARACTER);
                            printf("\n      CUIT MODIFICADO CORRECTAMENTE\n");
                            break;
                        }
                    case 2:
                        if(getInt("\n\n  Ingrese dias de contratacion: ","Error",0,1000,3,auxNuevosDias)==0)
                        {
                            publicidades[i].dias=auxNuevosDias;
                            printf("\n\n      DIAS MODIFICADOS CORRECTAMENTE\n");
                            break;
                        }
                    case 3:
                        if(getString("\n\n    Ingrese archivo: ","Error",1,999999,3,auxNuevoArchivo)==0)
                        {
                            strncpy(publicidades[i].archivo,auxNuevoArchivo,MAX_CARACTER);
                            printf("\n\n      ARCHIVO MODIFICADO CORRECTAMENTE\n");
                            break;
                        }
                    case 4:
                        seguir='n';
                        break;
                }
        }
             retorno=0;
    }
    return retorno;
}

int initArray(Publicidad* publicidades,int limite)
{
    int i;

    for(i=0;i<limite;i++)
    {
        publicidades[i].isEmpty=1;
    }
    return 0;
}

int getCuil(char* msj,char* msjError,char minimo,char maximo,int reintentos,char* cuil)
{
    int i;
    char bufferCuit[20];


    if(msj!=NULL && msjError!=NULL && minimo<maximo && reintentos>=0 && cuil!=NULL)
    {
        for(i=0;i<reintentos;i++)
        {
            if(!getString(msg,msgError,minimo,maximo,reintentos,bufferCuit))
            {
                if(isValidCuit(bufferCuit)==1)
                {
                    strncpy(cuil,bufferCuit,MAX_CARACTER);
                    retorno=0;
                    break;
                }
                else
                    printf("\n\nCuil invaldio");
            }
        }

    }
    return retorno;
}

int isValidCuit(char cadena[])
{
    int i=0;
    int retorno=-1;
    int contadorGuiones=0;

    while(cadena[i]!= '\0')
    {
        if((cadena[i]!=' ') && (cadena[i]<'0' || cadena[i]>'9') && (cadena[i]<'a' || cadena[i]>'z'))
        {
            retorno=0;
        }
        if(cadena[i]=='-')
        {
            contadorGuiones++;
        }
     i++;
    }
       if(contadorGuiones==2)
        {
            retorno=1;
        }
        return retorno;
}

int getString (char* msg, char* msgError, int minimo, int maximo, int reintentos, char* resultado)
{
    int retorno = -1;
    char bufferStr[4096];
    if(msg != NULL && msgError != NULL && minimo < maximo && reintentos>=0 && resultado != NULL)
    {
        do
        {
            printf("%s",msg);
            fgets(bufferStr,sizeof(bufferStr),stdin);
            bufferStr[strlen(bufferStr)-1] = '\0';
            if(strlen(bufferStr)>=minimo && strlen(bufferStr) <maximo)
            {
                strncpy(resultado,bufferStr,maximo);
                retorno = 0;
                break;
            }
            reintentos--;
           /// printf("%s",msgError);
        }while(reintentos>=0);
    }
    return retorno;
}

void muestraArray(Publicidad* publicidades,int limite)
{
    int i;

     for(i=0;i<limite;i++)
     {
        if(publicidades[i].isEmpty==0)
        {
            printf("\n\nPosicion %d : CUIT: %s",i,publicidades[i].cuit);
            printf("\n\n            : DIAS: %s",publicidades[i].dias);
            printf("\n\n            : ARCHIVO: %f",publicidades[i].archivo);
            printf("\n\n            : ID: %d\n",publicidades[i].idPublicidades);
            printf("\n\n            : ID PANTALLAS: %s",pantallas[i].idPantalla);
        }
    }
    //return 0;
}
#endif // PUBLICIDAD_C_INCLUDED
