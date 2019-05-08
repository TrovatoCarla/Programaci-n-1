#ifndef AUTORES_H_INCLUDED
#define AUTORES_H_INCLUDED

typedef struct
{
    int codigoAutor;
    int isEmpty;
    char apellido[31];
    char nombre[31];
}Autor;

int aut_buscaPosicionLibre(Autor* empleado,int len,int* posicionLibre);
int aut_alta(Autor* autores,int limite,int posicionLibre,int id);
int aut_buscaPorId(Autor* autores,int limite,int* idEncontrado);
int aut_modificar(Autor* autores,int limite,int idAmodificar);
int aut_initArray(Autor* autores,int limite);
int aut_bajaAutor(Autor* autores,int limite,int idBaja);
int aut_muestraAutores(Autor* autores,int limite);

#endif // AUTORES_H_INCLUDED
