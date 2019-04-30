#ifndef PUBLICIDAD_C_INCLUDED
#define PUBLICIDAD_C_INCLUDED

int pub_modificacion(Publicidad* publicidades,char limite)
{
    int retorno=1;
    int i;
    int bufferId;
    int opcion;
    char seguir='s';
    char auxNuevoCuit[MAX_CARACTER];
    char auxNuevoArchivo[MAX_CARACTER];
    int auxNuevosDias;

    muestraArray(pantallas,MAX_ID);


    if(buscarId(publicidades,MAX_ID,"\nIngrese el ID a modificar ","\nError,ID incorrecto",1000,0,3,&bufferId)==0)
    {
        i=bufferId;
        while(seguir=='s')
        {
            printf("\n 1- Cuit");
            printf("\n 2- Dias de contratacion");
            printf("\n 3- Archivo");
            printf("\n 4- Salir de Modificaciones");
            do
            {
                printf("\n\n       INDIQUE EL DATO QUE DESEA MODIFICAR: ");
                scanf("%d",&opcion);
            }while(opcion<1 || opcion>4);

                switch(opcion)
                {
                    case 1:
                        if(getCuit("\n\n   Ingrese el nuevo Cuit: ","Error",10,20,3,auxNuevoCuit)==0)
                        {
                            strncpy(publicidades[i].cuit,auxNuevoCuit,MAX_CARACTER);
                            printf("\n      CUIT MODIFICADO CORRECTAMENTE\n");
                            break;
                        }
                    case 2:
                        if(getInt("\n\n  Ingrese dias de contratacion: ","Error",0,1000,3,auxNuevosDias)==0)
                        {
                            strncpy(publicidades[i].dias,auxNuevosDias,MAX_CARACTER);
                            printf("\n\n      DIAS MODIFICADOS CORRECTAMENTE\n");
                            break;
                        }
                    case 3:
                        if(getString("\n\n    Ingrese archivo: ","Error",1,999999,3,&auxNuevoArchivo)==0)
                        {
                            publicidades[i].archivo=auxNuevoArchivo;
                            printf("\n\n      ARCHIVO MODIFICADO CORRECTAMENTE\n");
                            break;
                        }
                    case 4:
                        seguir='n';
                        break;
                }
        }
             retorno=0;
    }
    return retorno;
}

int getCuil(char* msj,char* msjError,char minimo,char maximo,int reintentos)
{
    int i;
    char bufferCuit[20];


    if(msj!=NULL && msjError!=NULL && minimo<maximo && reintentos>=0)
    {
        if(!getString(msg,msgError,minimo,maximo,reintentos,bufferCuit))
        {

        }
    }


}

int isValidCuit(char cadena[])
{
    int i=0;
    int retorno=-1;
    int contadorGuiones=0;

    while(cadena[i]!= '\0')
    {
        if((cadena[i]!=' ') && (cadena[i]<'0' || cadena[i]>'9') && (cadena[i]<'a' || cadena[i]>'z'))
        {
            retorno=0;
        }
        if(cadena[i]=='-')
        {
            contadorGuiones++;
        }
     i++;
    }
       if(contadorGuiones==2)
        {
            retorno=1;
        }
        return retorno;
}

#endif // PUBLICIDAD_C_INCLUDED
