#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Persona.h"

int main()
{
    Persona *pArrayPersona[1000];
    int ultimoElementoArrayPersona = 0;
    int indiceActual;
    int auxInt;
    char auxApellido[20];
    char auxNombre[20];
    indiceActual = ultimoElementoArrayPersona;
    pArrayPersona[indiceActual] =  Per_new();

        if(pArrayPersona[indiceActual] != NULL)
    {
        ultimoElementoArrayPersona++;
        //printf("OK");
        if(!Per_setId(pArrayPersona[indiceActual],14))
        {
            Per_getId(pArrayPersona[indiceActual],&auxInt);
            printf("\n El id es %d",auxInt);

        }

        if(!Per_setNombre(pArrayPersona[indiceActual],"carla"))
        {
            Per_getNombre(pArrayPersona[indiceActual],auxNombre);
            printf("\n El nombre es %s",auxNombre);
        }

        if(!Per_setApellido(pArrayPersona[indiceActual],"Trovato"))
        {
            Per_getApellido(pArrayPersona[indiceActual],auxApellido);
            printf("\n El nombre es %s",auxApellido);
        }


}

    return 0;
}

///Dentro de un archivo binario puede haber texto guardado o cualquier otra cosa,
///                 *ventajas se puede recorrer array y guardar en archivo binario--->
///                 *desventaja,es tiene archivos no compartibles con otras personas.

///Los archivos de texto















