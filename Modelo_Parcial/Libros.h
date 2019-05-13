#ifndef LIBROS_H_INCLUDED
#define LIBROS_H_INCLUDED

typedef struct
{
    int isEmpty;
    int codigoAutor;
    char titulo[51];
    int codigoLibro;
}Libros;

int lib_initArray(Libros* libro,int limite);
int lib_alta(Libros* libro,int limite,int posicionLibre,int id);
int lib_buscaPorId(Libros* libro,int limite,int idBusqueda,int* indice);
int lib_buscaPosicionLibre(Libros* libro,int len,int* posicionLibre);
int lib_modificar(Libros* libro,int limite,int idAmodificar);
int lib_bajaLibro(Libros* libro,int limite,int idBaja);
int lib_muestraLibros(Libros* libro,int limite);





#endif // LIBROS_H_INCLUDED
