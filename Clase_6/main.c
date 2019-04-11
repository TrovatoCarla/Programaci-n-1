#include <stdio.h>
#include <stdlib.h>
#include <string.h>// en esta biblioteca esta strncpy
#define MAX 20

int main()
{
    char buffer[MAX];
    char nombre[MAX];
    int i;
    printf("\nIngrese nombre: ");
    fgets(buffer,sizeof(nombre),stdin);//hacer funcion de esta e incluirle strlen(nombre)-1
                                                        //  nombre[strlen(nombre-1]='\0'

    //i=strlen(buffer); cuenta la cantidad de lugares q tiene indice
    //printf("\n %d",i-1);

    for(i=0;i<MAX && buffer[i]!='\0';i++)
    {

        if((buffer[i]<'a' || buffer[i]>'z') && (buffer[i]<'A' || buffer[i]>'Z'))
        {
                printf("Error!!!");
                break;
        }
        else
        {
        strncpy(nombre,buffer,sizeof(nombre));
            printf("%s",nombre);
         }
    }


    return 0;
}



  //  char nombre[257]={'H','O','L','A','\0'};//ESPACIO PARA 256,DECLARO UNO MAS POR EL /0. asi inicializo
  //  char nombre2[257]="HOLA";// asi inicializo

    //NOOOOOOOOOO nombre="Juan";

 //   strncpy(nombre,nombre2,sizeof(nombre)/*257*/);//le doy el tamaño del origen-asi no la quiere ver escrita la funcion
  //  printf("\n%s",nombre);
 //   fgets(nombre,sizeof(nombre),stdin);//va a leer un string desde un archivo,y dejo de usar scanf-sezeof(nombre) hace que
                                        // si escribe mas cantidad de carateres que lo permitido no pase nada,solo toma la
                                        //cantidad permitida
    //NOOO scanf("%s",nombre)
 //   printf("\n%s",nombre);
 //   strlen()

 //   return 0;
