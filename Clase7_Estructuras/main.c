#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funcionesUTN.h"
#include "misValid.h"
#define EMPLEADOS 3
#define MAXIMO_CARACTER 500
#define TRUE 1
#define FALSE 0

int muestraArray(char arrayStr[][50],int limite);//cada uno de los elements puede tener 50 caracteres
int iniciarlizarArrays(char arrayStr [] [50], int limite);
int encuentraPosVacia(char arrayStr [] [MAXIMO_CARACTER],int* posicionDisponible, int limite);
int buscaSiYaExiste(char arrayStr [] [MAXIMO_CARACTER],char* nombre,int* posicionNombreExistente,int limite);

int main()
{
    char arrayUsuario[EMPLEADOS][MAXIMO_CARACTER];
    char nombre[50];
    int posicionDisponible;
    int posicionNombreExistente;
    //iniciarlizarArrays(arrayUsuario,EMPLEADOS);

    encuentraPosVacia(arrayUsuario,&posicionDisponible,EMPLEADOS);
    if(posicionDisponible!=-1)
    {
        getName("Ingrese nombre: ","ERROR",50,2,3,nombre);
        buscaSiYaExiste(arrayUsuario,nombre,&posicionNombreExistente,EMPLEADOS);
        if(posicionNombreExistente!=-1)
        {
            strncpy(arrayUsuario[posicionDisponible],nombre,MAXIMO_CARACTER);
            printf("%s",arrayUsuario[posicionDisponible]);
        }
        else
        {
            printf("Nombre existente");
        }
    }
    else
    {
        printf("Sin lugar disponible");
    }
    return 0;
}









int altaDeUsuario(char* )

