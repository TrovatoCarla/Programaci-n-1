#ifndef PRESTAMO_C_INCLUDED
#define PRESTAMO_C_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdio_ext.h>
#include "Autores.h"
#include "funcionesUTN.h"
#include "misValid.h"
#include "Libros.h"
#include "Prestamo.h"
#include "Socios.h"

/** \brief  Inicializa todo el array en 1
* \param array Prestamo Array Prestamo
* \param limite tamaño del array
* \return int Retorna (-1) si hay error [Invalid length or NULL pointer] - (0) Si Ok
*
*/
int pre_Inicializar(Prestamo* prestamos, int limite)
{
    int retorno=-1;
    if(prestamos!= NULL && limite>0)
    {
        for(;limite>0;limite--)
        {
            prestamos[limite-1].isEmpty=1;
        }
        retorno=0;
    }
    return retorno;
}

/** \brief Busca el primer lugar vacio del array Prestamo
* \param array prestamos . Array Prestamos
* \param limite int Tamaño del array
* \param posicion int* Puntero a la posicion del array donde se encuentra el valor buscado
* \return int Return (-1) si no encuentra un lugar vacio o Error [Invalid length or NULL pointer] - (0) si encuentra una posicion vacia
*
*/
int pre_buscarEmpty(Prestamo* prestamos, int limite, int* posicion)
{
    int retorno=-1;
    int i;
    if(prestamos!= NULL && limite>=0 && posicion!=NULL)
    {
        for(i=0;i<limite;i++)
        {
            if(prestamos[i].isEmpty==1)
            {
                retorno=0;
                *posicion=i;
                break;
            }
        }
    }
    return retorno;
}

/** \brief Busca un ID en un array y devuelve la posicion en que se encuentra
* \param array fantasma Array de fantasma
* \param limite int Tamaño del array
* \param posicion int* Puntero a la posicion del array donde se encuentra el valor buscado
* \return int Return (-1) si no encuentra el valor buscado o Error [Invalid length or NULL pointer] - (0) si encuentra el valor buscado
*
*/
int pre_buscarID(Prestamo* prestamos, int limite, int valorBuscado, int* posicion)
{
    int retorno=-1;
    int i;
    if(prestamos!= NULL && limite>=0)
    {
        for(i=0;i<limite;i++)
        {
            if(prestamos[i].isEmpty==1)
                continue;
            else if(prestamos[i].codigoPrestamo==valorBuscado)
            {
                retorno=0;
                *posicion=i;
                break;
            }
        }
    }
    return retorno;
}

/** \brief Busca Id de socio en el array y devuelve la posicion en que se encuentra
* \param array prestamos Array de prestamos
* \param limite int Tamaño del array
* \param posicion int* Puntero a la posicion del array donde se encuentra el valor buscado
* \return int Return (-1) si no encuentra el valor buscado o Error [Invalid length or NULL pointer] - (0) si encuentra el valor buscado
*
*/
int pre_buscarIdSocio(Prestamo* prestamos, int limite, int valorBuscado, int* posicion)                    //cambiar prestamos
{
    int retorno=-1;
    int i;
    if(prestamos!= NULL && limite>=0)
    {
        for(i=0;i<limite;i++)
        {
            if(prestamos[i].isEmpty==1)
                continue;
            else if(prestamos[i].codigoSocio==valorBuscado)
            {
                retorno=0;
                *posicion=i;
                break;
            }
        }
    }
    return retorno;
}

int pre_alta(Prestamo* prestamos,Socio* socios,Libro* libros,Autor* autores,
                int limitePrestamos,int limiteSocios,int limiteLibros,int limiteAutores,int* contadorID)
{
    int retorno=-1;
    int posicion;
    int idSocioAbuscar;
    int posicionSocio;
    int idLibroAbuscar;
    int posicionLibro;

    if(prestamos!=NULL && (limitePrestamos>0) && socios!=NULL && (limiteSocios>0) && libros!=NULL && (limiteLibros>0)&& autores!=NULL && (limiteAutores>0) && contadorID!=NULL)
    {
        if(pre_buscarEmpty(prestamos,limitePrestamos,&posicion)==-1)
        {
            printf("\nNo hay lugares vacios");
        }
        else
        {
            (*contadorID)++;
            prestamos[posicion].codigoPrestamo=*contadorID;
            prestamos[posicion].isEmpty=0;
            soc_listar(socios,MAX_ARRAY);
            getInt("\nIngrese Id del socio: ","\nId invalido",sizeof(int),1,2,&idSocioAbuscar);
            if(soc_buscaPorId(socios,MAX_ARRAY,idSocioAbuscar,&posicionSocio)!=0)
            {
                printf("\nId de socio inexistente");
            }
            else
            {
                lib_muestraLibros(libros,autores,MAX_ARRAY);
                getInt("\nIngrese Id del libro: ","\nId invalido",sizeof(int),1,2,&idLibroAbuscar);
                if(lib_buscaPorId(libros,MAX_ARRAY,idLibroAbuscar,&posicionLibro)!=0)
                {
                    printf("\nId libro inexistente");

                }
                else
                {
                    prestamos[posicion].codigoSocio=idSocioAbuscar;
                    prestamos[posicion].codigoLibro=idLibroAbuscar;
                    printf("\nPOSICION: %d\n ID PRESTAMO: %d\n ID SOCIO: %d\n ID LIBRO: %d\n",
                        posicion,prestamos[posicion].codigoPrestamo,prestamos[posicion].codigoSocio,prestamos[posicion].codigoLibro);
                retorno=0;
                }
            }

        }
    }
    return retorno;
}

/** \brief Borra un elemento del array por ID
* \param array prestamos Array de prestamos
* \param limite int Tamaño del array
* \return int Return (-1) si Error [largo no valido o NULL pointer o no encuentra elementos con el valor buscado] - (0) si se elimina el elemento exitosamente
*
*/
int pre_baja(Prestamo* prestamos, int limite)
{
    int retorno=-1;
    int posicion;
    int id;
    if(prestamos!=NULL && limite>0)
    {
        getInt("\nIngrese ID a cancelar: ","\nError",sizeof(int),1,2,&id); ///cambiar si no se busca por ID
        if(pre_buscarID(prestamos,limite,id,&posicion)==-1)         ///cambiar si no se busca por ID
        {
            printf("\nNo existe este ID");  ///cambiar si no se busca por ID
        }
        else
        {
            prestamos[posicion].isEmpty=1;
            prestamos[posicion].codigoPrestamo=0;            ///cambiar campo id
            prestamos[posicion].codigoLibro=0;             ///cambiar campo auxInt
            prestamos[posicion].codigoSocio=0;           ///cambiar campo auxFloar
            retorno=0;
        }
    }
    return retorno;
}

int pre_modificar(Prestamo* prestamos, int limite)
{
    int retorno=-1;
    int posicion;
    int id;      ///cambiar si no se busca por ID
    int opcion;

    if(prestamos!=NULL && limite>0)
    {
        getInt("\nIngrese ID a modificar: ","\nError",sizeof(int),1,2,&id); ///cambiar si no se busca por ID
        if(pre_buscarID(prestamos,limite,id,&posicion)==-1)  ///cambiar si no se busca por ID
        {
            printf("\nNo existe este ID");///cambiar si no se busca por ID
        }
        else
        {
            do
            {       ///copiar printf de alta
                printf("\nPOSICION: %d\n ID PRESTAMO: %d\n ID SOCIO: %d\n ID LIBRO: %d\n",
                    posicion,prestamos[posicion].codigoPrestamo,prestamos[posicion].codigoSocio,prestamos[posicion].codigoLibro);

                getInt("\nModificar:\n 1-ID PREST\n 2-ID LIBBRO\n 3-ID SOCIO\n 4-(salir)\n","\nError",sizeof(int),1,1,&opcion);
                switch(opcion)
                {
                    case 1:
                        getInt("\nIngrese...: ","\nError",sizeof(int),1,1,&prestamos[posicion].codigoPrestamo);           //mensaje + cambiar campo varInt
                        break;
                    case 2:
                        getInt("\nINgrese...: ","\nError",sizeof(int),1,1,&prestamos[posicion].codigoLibro);             //mensaje + cambiar campo varFloat
                        break;
                    case 3:
                        getInt("\nINgrese...: ","\nError",sizeof(int),1,1,&prestamos[posicion].codigoSocio);                      //mensaje + cambiar campo varString
                        break;
                    case 4:
                        break;
                    default:
                        printf("\nOpcion no valida");
                }
            }while(opcion!=4);
            retorno=0;
        }
    }
    return retorno;
}

int pre_listar(Prestamo* prestamos, int limite)
{
    int retorno=-1;
    int i;
    if(prestamos!=NULL && limite>=0)
    {
        for(i=0;i<limite;i++)
        {
            if(prestamos[i].isEmpty==1)
                continue;
            else
                printf("\nPOSICION: %d\n ID PRESTAMO: %d\n ID SOCIO: %d\n ID LIBRO: %d\n",
                    i,prestamos[i].codigoPrestamo,prestamos[i].codigoSocio,prestamos[i].codigoLibro);
        }
        retorno=0;
    }
    return retorno;
}
#endif // PRESTAMO_C_INCLUDED
