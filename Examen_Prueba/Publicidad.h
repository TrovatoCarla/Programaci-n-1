#define MAX_CARACTER 50

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
int pub_baja(Publicidad* publicidades,char limite);
int pub_modificacion(Publicidad* publicidades,char limite);
int getCuil(char* msj,char* msjError,char minimo,char maximo,int reintentos,char* cuil);
int getString (char* msg, char* msgError, int minimo, int maximo, int reintentos, char* resultado);
void muestraArray(Publicidad* publicidades,int limite);
int initArray(Publicidad* publicidades,int limite);
