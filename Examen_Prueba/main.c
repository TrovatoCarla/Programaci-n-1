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





