///Gestionar dinamicamente la memoria,estaran declaradas en otra zona de la memoria (Gip)
///Funciones para crear memoria:
///                   -Malloc:siempre da bloques de memoria continuos= malloc()
///                                  Le tengo q decir cuantos bits quiero -->sizeof de int por ejemplo
///                                  Malloc es un puntero boid(generico),para q no tire warning pEntero=(*int) malloc(sizeof(int))
///                   -Realloc:realocacion de memoria.redimenciona-devuelven el puntero a la direccion de memoria que reserve, y Null cuando no.
///                             Tiene un parametro mas. realloc(pEntero,sizeof(int)*1000) Devuelve el espacio de memoria que me consiguio
///                             NO IGUALAR EL REALLOC XQ SINO DEJA UN NULL EN LA MEMORIA Q YA TENIA.PRIMERO LO DEJO EN UN AUXILIAR
///                   -Free:libera. free(pEntero)--->libera la memoria
///     THIS = contexto
/// el Set me deja cargar/escribir datos en ese campo- el get me da la informacion que tiene ese campo,obteniendo el dato
#include <stdio.h>
#include <stdlib.h>

int main()
{
    printf("Hello world!\n");
    return 0;
}
