#ifndef SOCIOS_C_INCLUDED
#define SOCIOS_C_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdio_ext.h>
#include "Autores.h"
#include "Libros.h"
#include "Socios.h"
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


#endif // SOCIOS_C_INCLUDED
