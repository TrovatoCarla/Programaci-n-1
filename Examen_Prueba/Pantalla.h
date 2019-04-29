#ifndef PANTALLA_H_INCLUDED
#define PANTALLA_H_INCLUDED
#include <string.h>
#define MAX_ID 10
#define MAX_CARACTER 50

typedef struct
{
    int idPantalla;
    int isEmpty;
    char nombre[50];
    char direccion[250];
    float precio;
    char tipo [5];
}Pantalla;

typedef struct
{
    int idPublicidad;
    int isEmpty;
    char cuit[20];
    int dias;
    char archivo[250];
    int idPantalla;
}Publicidad;

int initArray(Pantalla* pantallas,int limite);
int buscaVacio(Pantalla* pantallas,int limite,int* posicionVacia);
void muestraArray(Pantalla* pantallas,int limite,char* mensajeError);
int buscarId(Pantalla* pantallas,int limite,char* msj,char* msjError,int maximo,int minimo,int reintentos,int* idEncontrado);
int getInt(char *message, char *errorMessage, int minimum, int maximum, int retries, int *input);
int isValidInt(int number, int minimum, int maximum);
int isValidNombre(char *cadena);
int isValidFloat(float number, float minimum, float maximum);
int getName (char* msg, char* msgError, int minimo, int maximo, int reintentos, char* resultado);
int getString (char* msg, char* msgError, int minimo, int maximo, int reintentos, char* resultado);
int getFloat(char *message, char *errorMessage, float minimum, float maximum, int retries, float *input);
int pan_alta(Pantalla* pantallas,char* msjError,int limite,int posicionLibre);


#endif // PANTALLA_H_INCLUDED
