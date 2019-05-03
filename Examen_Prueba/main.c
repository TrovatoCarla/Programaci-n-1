#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_ID 10
#define MAX_CARACTER 50
#include "Pantalla.h"
#include "Publicidad.h"

int ordenarPorPrecio(Pantalla* pantallas,int limite);
int pidePantalla(Pantalla* pantallas,int limite,int auxId,int lugarPantalla);

int main()
{
    char seguir='s';
    int opcion;
    int lugarLibre;
    int auxID;

   /*char auxiliarNombre[MAX_CARACTER];
    char auxiliarDireccion[MAX_CARACTER];
    float auxiliarPrecio=0;
    char auxiliarTipo[5];*/

    Pantalla pantallas[MAX_ID];
    Publicidad publicidades[MAX_ID];

    if((initArrayPantalla(pantallas,MAX_ID)==0) && (initArrayPublicidad(publicidades,MAX_ID)==0))
    {
        printf("Inicializacion correcta");
    }

    strncpy(pantallas[0].nombre,"Carla0",MAX_CARACTER);
    pantallas[0].isEmpty=0;
    strncpy(pantallas[0].direccion,"Nogoya 0",MAX_CARACTER);
    strncpy(pantallas[0].tipo,"LED0",MAX_CARACTER);
    pantallas[0].precio=32000;
    pantallas[0].idPantalla=0;

    strcpy(publicidades[0].cuit,"20-12345678-0");
    strcpy(publicidades[0].archivo,"Video0");
    publicidades[0].dias=10;
    publicidades[0].isEmpty=0;
    publicidades[0].idPublicidad=0;
    publicidades[0].idPantalla=0;

    strncpy(pantallas[1].nombre,"Fabian1",MAX_CARACTER);
    pantallas[1].isEmpty=0;
    strncpy(pantallas[1].direccion,"Nogoya 1",MAX_CARACTER);
    strncpy(pantallas[1].tipo,"LED1",MAX_CARACTER);
    pantallas[1].precio=20000;
    pantallas[1].idPantalla=1;

    strcpy(publicidades[1].cuit,"20-12345678-1");
    strcpy(publicidades[1].archivo,"Video1");
    publicidades[1].dias=20;
    publicidades[1].isEmpty=0;
    publicidades[1].idPublicidad=1;
    publicidades[1].idPantalla=1;

    strncpy(pantallas[2].nombre,"Caro2",MAX_CARACTER);
    pantallas[2].isEmpty=0;
    strncpy(pantallas[2].direccion,"Nogoya 2",MAX_CARACTER);
    strncpy(pantallas[2].tipo,"LED2",MAX_CARACTER);
    pantallas[2].precio=50000;
    pantallas[2].idPantalla=2;

    strcpy(publicidades[2].cuit,"20-12345678-2");
    strcpy(publicidades[2].archivo,"Video2");
    publicidades[2].dias=30;
    publicidades[2].isEmpty=0;
    publicidades[2].idPublicidad=2;
    publicidades[2].idPantalla=2;

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
            case 4:
                if(pub_alta(publicidades,pantallas,MAX_ID,lugarLibre)==0)
                {
                    printf("\n Contratacion exitosa");
                }
            case 5:
                muestraArrayPantalla(pantallas,MAX_ID);
                //muestraArrayPublicidad(publicidades,MAX_ID);
                break;
            case 6:
                ordenarPorPrecio(pantallas,MAX_ID);
                muestraArrayPantalla(pantallas,MAX_ID);
                break;
            case 7:
                pidePantalla(pantallas,MAX_ID,auxID,lugarLibre);
                break;



        }

    }
    return 0;
}

int ordenarPorPrecio(Pantalla* pantallas,int limite)
{
    int i;
    int j;
    int flag;
    Pantalla auxPantallas;

    do
    {
        flag=0;
           for(i=0;i<MAX_ID-1;i++)
            {
                j=i+1;
                if(pantallas[i].precio>pantallas[j].precio)
                {
                    auxPantallas=pantallas[i];
                    pantallas[i]=pantallas[j];
                    pantallas[j]=auxPantallas;
                    flag=1;
                }
                else if(pantallas[i].precio==pantallas[j].precio)
                {
                    if(strncmp(pantallas[i].nombre,pantallas[j].nombre,MAX_CARACTER)>0)
                    {
                    auxPantallas=pantallas[i];
                    pantallas[i]=pantallas[j];
                    pantallas[j]=auxPantallas;
                    flag=1;
                    }
                }
            }
    }while(flag);

    return 0;
}

int pidePantalla(Pantalla* pantallas,Publicidad* publicidades,int limite,int auxId,int lugarPantalla)
{
    int retorno=-1;

    if(!buscarPantallaPorID(pantallas,MAX_ID,"\nIngrese ID de pantalla a buscar: ","Error,ID erroneo",100,0,3,&lugarPantalla))
    {

        printf("\n\nPosicion %d : NOMBRE: %s",pantallas[lugarPantalla].idPantalla,pantallas[lugarPantalla].nombre);
        printf("\n\n            : DIRECCION: %s",pantallas[lugarPantalla].direccion);
        printf("\n\n            : PRECIO: %.2f",pantallas[lugarPantalla].precio);
        printf("\n\n            : TIPO DE PANTALLA: %s",pantallas[lugarPantalla].tipo);
        retorno=0;
    }
    return retorno;
}

int menoresA10Dias(Pantalla* pantallas,Publicidad* publicidades,int limite)
{
    for(i=0;i<MAX_ID;i++)
    {
        if(publicidades[i].dias<=10)
        {
            printf("\nNOMBRE: %s",pantallas[i].nombre);
            printf("\nDOMICILIO: %s",pantallas[i].direccion);
            printf("\nTIPO: %s",pantallas[i].tipo);
            printf("\PRECIO: %f",pantallas[i].precio);
            printf("NOMBRE: %s",pantallas[i].nombre);

        }
    }


}




