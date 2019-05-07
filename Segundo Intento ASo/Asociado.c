///NUEVOOOO

#ifndef ASOCIADO_C_INCLUDED
#define ASOCIADO_C_INCLUDED
#define VACIO 1
#define HABILITADO 2
#define INHABILITADO 3
#define MAX_ARRAY 100


int aso_initArray(Asociado* paciente,int limite)
{
    int i;

    for(i=0;i<limite;i++)
    {
        paciente[i].isEmpty=VACIO;
    }
    return 0;
}

int aso_buscaLugarLibre(Asociado* paciente,int limite,int* PosicionLibre)
{
    int i;
    int retorno=-1;

    for(i=0;i<limite;i++)
    {
        if(paciente[i].isEmpty==VACIO)
        {
            *PosicionLibre=i;
            retorno=0;
        }
    }
    return retorno;
}

int aso_alta(Asociado* paciente,int limite,int posicionDisponible)
{
    int retorno=-1;

    if(aso_buscaLugarLibre(paciente,))

}
#endif // ASOCIADO_C_INCLUDED
