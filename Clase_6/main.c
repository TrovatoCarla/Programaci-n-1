#include <stdio.h>
#include <stdlib.h>
#include <string.h>// en esta biblioteca esta strncpy

int main()
{
    char nombre[257]={'H','O','L','A','\0'};//ESPACIO PARA 256,DECLARO UNO MAS POR EL /0. asi inicializo
    char nombre2[257]="HOLA";// asi inicializo

    //NOOOOOOOOOO nombre="Juan";

    strncpy(nombre,nombre2,sizeof(nombre)/*257*/);//le doy el tamaño del origen-asi no la quiere ver escrita la funcion
    fgets(nombre,sizeof(nombre),stdin);//va a leer un string desde un archivo,y dejo de usar scanf
    printf("\n%s",nombre);

    return 0;
}
