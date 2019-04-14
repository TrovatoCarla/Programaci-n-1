#define TRUE 1
#define FALSE 0


int isValidInt(int numero, int maximo, int minimo)
{
    if(numero >= minimo && numero <=maximo)
    {
        return 1;
    }
        return 0;
}

int isValidFloat(float numero, float maximo, float minimo)
{
    if(numero >= minimo && numero <= maximo)
    {
        return 1;
    }

    return 0;
}

int isValidChar(char letra, char maximo, char minimo)
{
    if(letra >= minimo && letra <= maximo)
    {
        return 1;
    }
    return 0;
}

int isValidNombre(char *cadena)
{
    int retorno= TRUE;
    int i;

    for(i=0;cadena[i]!= '\0';i++)
    {
        if((cadena[i] <'A' || cadena[i] >'Z') && (cadena[i] <'a' || cadena[i] >'z'))
        {
            if(cadena[i]<= '9' && cadena[i]>='0')
            {
                retorno= FALSE;
            }
        }

    }
    return retorno;

}

int isValidApellido(char* cadena)
{
    int retorno= TRUE;
    int i;

    for(i=0;cadena[i]!= '\0';i++)
    {
        if((cadena[i]<'a' || cadena[i]>'z')&&(cadena[i]<'A' || cadena[i]>'Z'))
        {
            if(cadena[i]<'0' &&  cadena[i]>'9')
            {
                retorno=FALSE;
            }
        }
    }
    return retorno;
}
