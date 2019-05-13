#ifndef LIBROS_H_INCLUDED
#define LIBROS_H_INCLUDED

typedef struct
{
    int isEmpty;
    int codigoAutor;
    char titulo[51];
    int codigoLibro;
}Libro;

int lib_initArray(Libro* libros,int limite);
int lib_alta(Libro* libros,int limite,int posicionLibre,int id);
int lib_buscaPorId(Libro* libros,int limite,int idBusqueda,int* indice);
int lib_buscaPosicionLibre(Libro* libros,int len,int* posicionLibre);
int lib_modificar(Libro* libros,int limite,int idAmodificar);
int lib_bajaLibro(Libro* libros,int limite,int idBaja);
int lib_muestraLibros(Libro* libros,int limite);





#endif // LIBROS_H_INCLUDED
