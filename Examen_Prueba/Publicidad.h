#define MAX_CARACTER 50
#include "Pantalla.h"

typedef struct
{
    int idPublicidad;
    int isEmpty;
    char cuit[20];
    int dias;
    char archivo[250];
    int idPantalla;
}Publicidad;


int isValidCuit(char cadena[]);
int pub_baja(Publicidad* publicidades,Pantalla* pantallas,char limite);
int pub_modificacion(Publicidad* publicidades,Pantalla* pantallas,char limite);
int pub_alta(Publicidad* publicidades,Pantalla* pantallas,int limite,int posicionEncontrada);
int getCuit(char* msj,char* msjError,char minimo,char maximo,int reintentos,char* cuit);
int getString (char* msg, char* msgError, int minimo, int maximo, int reintentos, char* resultado);
void muestraArrayPublicidad(Publicidad* publicidades,int limite);
int initArrayPublicidad(Publicidad* publicidades,int limite);
int buscarPantallaPorID(Pantalla* pantallas,int limite,char* msj,char* msjError,int maximo,int minimo,int reintentos,int* idEncontrado);
