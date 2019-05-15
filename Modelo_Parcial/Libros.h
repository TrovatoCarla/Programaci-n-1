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
int lib_alta(Libro* libros,Autor* autores,int limite,int* contadorID);
int lib_buscaPorId(Libro* libros,int limite,int idBusqueda,int* indice);
int lib_buscaPosicionLibre(Libro* libros,int len,int* posicionLibre);
int lib_modificar(Libro* libros,Autor* autores,int limite);
int lib_bajaLibros(Libro* libros,Autor* autores, int limite);
int lib_muestraLibros(Libro* libros,Autor* autores,int limite);
int lib_ordenaPorTitulo(Libro* libros,int limite,int orderFirst,int orderSecond) ;




#endif // LIBROS_H_INCLUDED
