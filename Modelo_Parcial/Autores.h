#ifndef AUTORES_H_INCLUDED
#define AUTORES_H_INCLUDED

#define MAX_ARRAY 50
#define VACIO 1
#define HABILITADO 0
#define INHABILITADO 2
#define MAXIMO_CARACTER 30

typedef struct
{
    int codigoAutor;
    int isEmpty;
    char apellido[31];
    char nombre[31];
}Autor;

int aut_buscaPosicionLibre(Autor* autores,int len,int* posicionLibre);
int aut_alta(Autor* autores,int limite,int posicionLibre,int id);
int aut_buscaPorId(Autor* autores,int limite,int idBusqueda,int* indice);
int aut_modificar(Autor* autores,int limite,int idAmodificar);
int aut_initArray(Autor* autores,int limite);
int aut_bajaAutor(Autor* autores,int limite,int idBaja);
int aut_muestraAutores(Autor* autores,int limite);

#endif // AUTORES_H_INCLUDED
