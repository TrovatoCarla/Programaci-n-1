#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_ID 10
#define MAX_CARACTER 50
#include "Pantalla.h"

int pan_modificacion(Pantalla* pantallas,char limite);
int pan_baja(Pantalla* pantallas,char limite);

int main()
{
    char seguir='s';
    int opcion;
    int lugarLibre;
    int auxID=0;

   /*char auxiliarNombre[MAX_CARACTER];
    char auxiliarDireccion[MAX_CARACTER];
    float auxiliarPrecio=0;
    char auxiliarTipo[5];*/

    Pantalla prueba[MAX_ID];

    if(initArray(prueba,MAX_ID)==0)
    {
        printf("Inicializacion correcta");
    }

  while(seguir=='s')
  {
        printf("\n\n MENU\n");
        printf("\n 1 ALTA");
        printf("\n 2 MODIFICACION");
        printf("\n 3 BAJA");
        printf("\n 4 CONTRATAR PUBLICIDAD");
        printf("\n 5 MODIFICAR CONDICIONES DE PUBLICACION");
        printf("\n 6 CANCELAR CONTRATACION");
        printf("\n 7 CONSULTA FACTURACION");
        printf("\n 8 LISTAR CONTRATACIONES");
        printf("\n 9 LISTAR PANTALLAS");
        printf("\n 10 INFORMAR\n");
        do
        {
            printf("\n Ingrese una opcion: ");
            scanf("%d",&opcion);
        }while(opcion<1 || opcion>10);

        switch(opcion)
        {
            case 1:
                if(buscaVacio(prueba,MAX_ID,&lugarLibre)!=0)
                {
                   printf("No hay lugar disponible\n ");
                }
                else
                {
                    pan_alta(prueba,"ERROR",MAX_ID,lugarLibre);
                    printf("\n          ALTA EXISTOSA");
                    prueba[lugarLibre].idPantalla=auxID;
                    auxID++;
                }
                break;

            case 2:
                pan_modificacion(prueba,MAX_ID);
                break;

            case 3:
                if(pan_baja(prueba,MAX_ID)==0)
                {
                    printf("\n          BAJA EXITOSA!!!");
                }
                muestraArray(prueba,MAX_ID);
                break;




        }

    }
//muestraArray(prueba,MAX_ID,"Error");
    return 0;
}

int pan_baja(Pantalla* pantallas,char limite)
{

    int posicionAdarDeBaja;
    int retorno=-1;
    muestraArray(pantallas,MAX_ID);

    switch (buscarId(pantallas,MAX_ID,"\nIngrese el ID a dar de baja ","\nError,ID incorrecto",1000,0,3,&posicionAdarDeBaja))
    {
        case 0:
            pantallas[posicionAdarDeBaja].isEmpty=1;
            retorno=0;
            break;
        case 1:
            printf("\n      ID NO ENCONTRADO PARA LA BAJA");
            break;
    }
    return retorno;
}



int pan_modificacion(Pantalla* pantallas,char limite)
{
    int retorno=1;
    int i;
    int bufferId;
    int opcion;
    char seguir='s';
    char auxNuevoNombre[MAX_CARACTER];
    char auxNuevaDireccion[MAX_CARACTER];
    float auxNuevoPrecio;
    char auxNuevoTipo[10];

    muestraArray(pantallas,MAX_ID);


    if(buscarId(pantallas,MAX_ID,"\nIngrese el ID a modificar ","\nError,ID incorrecto",1000,0,3,&bufferId)==0)
    {
        i=bufferId;
        while(seguir=='s')
        {
            printf("\n 1- Nombre");
            printf("\n 2- Direccion");
            printf("\n 3- Precio");
            printf("\n 4- Tipo de pantalla");
            printf("\n 5- Salir de Modificaciones");
            do
            {
                printf("\n\n       INDIQUE EL DATO QUE DESEA MODIFICAR: ");
                scanf("%d",&opcion);
            }while(opcion<1 || opcion>4);

                switch(opcion)
                {
                    case 1:
                        if(getName("\n\n   Ingrese nombre: ","Error",2,50,3,auxNuevoNombre)==0)
                        {
                            strncpy(pantallas[i].nombre,auxNuevoNombre,MAX_CARACTER);
                            printf("\n      NOMBRE MODIFICADO CORRECTAMENTE\n");
                            break;
                        }
                    case 2:
                        if(getString("\n\n  Ingrese direccion: ","Error",2,50,3,auxNuevaDireccion)==0)
                        {
                            strncpy(pantallas[i].direccion,auxNuevaDireccion,MAX_CARACTER);
                            printf("\n\n      DIRECCION MODIFICADA CORRECTAMENTE\n");
                            break;
                        }
                    case 3:
                        if(getFloat("\n\n    Ingrese precio: ","Error",1,999999,3,&auxNuevoPrecio)==0)
                        {
                            pantallas[i].precio=auxNuevoPrecio;
                            printf("\n\n      PRECIO MODIFICADO CORRECTAMENTE\n");
                            break;
                        }
                    case 4:
                        if(getString("\n\n  Ingrese tipo de pantalla Led o LCD: ","Error",3,6,3,auxNuevoTipo)==0)
                        {
                            strncpy(pantallas[i].tipo,auxNuevoTipo,MAX_CARACTER);
                            printf("\n\n     Tipo de pantalla modificado correctamente\n");
                            break;
                        }
                    case 5:
                        seguir='n';
                        break;
                }
        }
             retorno=0;
    }
    return retorno;
}
