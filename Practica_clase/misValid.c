
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
