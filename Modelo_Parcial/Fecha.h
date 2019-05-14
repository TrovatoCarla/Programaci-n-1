#ifndef FECHA_H_INCLUDED
#define FECHA_H_INCLUDED

typedef struct
{
    int isEmpty;
    int idFecha;
    int dia;
    int mes;
    int anio;
}Fecha;

int fec_alta(Fecha* fechas,int limite,int posicionLibre,int id);
int fec_bajaAutor(Fecha* fechas,int limite,int idBaja);
int fec_modificar(Fecha* fechas,int limite,int idAmodificar);
int fec_initArray(Fecha* fechas,int limite);
int fec_buscaPosicionLibre(Fecha* fechas,int len,int* posicionLibre);
int fec_buscaPorId(Fecha* fechas,int limite,int idBusqueda,int* indice);
#endif // FECHA_H_INCLUDED
