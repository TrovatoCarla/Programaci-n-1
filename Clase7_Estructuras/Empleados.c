




int emp_initArray(Empleado* arrayEmp,int limite)
{
    int i;

    for(i=0;i<limite;i++)
    {
        strncpy(arrayEmp[i].isEmpty,"1",MAXIMO_CARACTER);
    }

    return 0;
}
