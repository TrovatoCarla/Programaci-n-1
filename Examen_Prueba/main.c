#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_ID 10
#define MAX_CARACTER 50
#include "Pantalla.h"


int main()
{
    char seguir='s';
    int opcion;
    int lugarLibre;
    int auxID=0;

    char auxiliarNombre[MAX_CARACTER];
    char auxiliarDireccion[MAX_CARACTER];
    float auxiliarPrecio=0;
    char auxiliarTipo[5];

    Pantalla prueba[MAX_ID];

    if(initArray(prueba,MAX_ID)==0)
    {
        printf("Inicializacion correcta");
    }

  while(seguir=='s')
  {
        printf("\n\n MENU\n");
        printf("\n 1 ALTA");
        printf("\n 2 BAJA");
        printf("\n 3 MUESTRA");
        printf("\n 3 MODIFICACION");
        printf("\n 4 SALIR\n");

        do
        {
            printf("\n Ingrese una opcion: ");
            scanf("%d",&opcion);
        }while(opcion<1 || opcion>4);

        switch(opcion)
        {
            case 1:
                if(buscaVacio(prueba,MAX_ID,&lugarLibre)!=0)
                {
                   printf("No hay lugar disponible\n ");
                }
                else
                {
                    if(pan_alta(prueba,"ERROR",MAX_ID,&lugarLibre)==0)
                    {
                        printf("alta exitosa");
                    }
                    auxID++;
                }
                break;

            case 3:
                muestraArray(prueba,MAX_ID,"EROOR?");
                break;
        }

    }

    return 0;
}

