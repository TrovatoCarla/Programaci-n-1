#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_ID 10
#define MAX_CARACTER 50
#include "Pantalla.h"
#include "Publicidad.h"


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

    Pantalla pantallas[MAX_ID];

    if(initArrayPantalla(pantallas,MAX_ID)==0)
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
                if(buscaVacio(pantallas,MAX_ID,&lugarLibre)!=0)
                {
                   printf("No hay lugar disponible\n ");
                }
                else
                {
                    pan_alta(pantallas,"ERROR",MAX_ID,lugarLibre);
                    printf("\n          ALTA EXISTOSA");
                    pantallas[lugarLibre].idPantalla=auxID;
                    auxID++;
                }
                break;

            case 2:
                pan_modificacion(pantallas,MAX_ID);
                break;

            case 3:
                if(pan_baja(pantallas,MAX_ID)==0)
                {
                    printf("\n          BAJA EXITOSA!!!");
                }
                muestraArrayPantalla(pantallas,MAX_ID);
                break;




        }

    }
//muestraArray(prueba,MAX_ID,"Error");
    return 0;
}





