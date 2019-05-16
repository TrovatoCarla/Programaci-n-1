#ifndef PRESTAMO_H_INCLUDED
#define PRESTAMO_H_INCLUDED
#include "Socios.h"

typedef struct
{
    int isEmpty;
    int codigoPrestamo;
    int codigoLibro;
    int codigoSocio;

}Prestamo;


int pre_Inicializar(Prestamo* prestamos, int limite);
int pre_buscarEmpty(Prestamo* prestamos, int limite, int* posicion);
int pre_buscarID(Prestamo* prestamos, int limite, int valorBuscado, int* posicion);
int pre_buscarIdSocio(Prestamo* prestamos, int limite, int valorBuscado, int* posicion);
int pre_alta(Prestamo* prestamos,Socio* socios,Libro* libros,Autor* autores,
                int limitePrestamos,int limiteSocios,int limiteLibros,int limiteAutores,int* contadorID);
int pre_baja(Prestamo* prestamos, int limite);
int pre_modificar(Prestamo* prestamos, int limite);
int pre_listar(Prestamo* prestamos, int limite);


#endif // PRESTAMO_H_INCLUDED
