#include <stdio.h>
#include <stdlib.h>

float PedirNumerosySacarPromedio ();//PROTOTIPO

int main()
{
    PedirNumerosySacarPromedio();
}

float PedirNumerosySacarPromedio ()
{
    int numeroIngresado;
    int acumulador=0;
    float promedio;
    int i;
    int maximo;
    int minimo;

    for(i=0;i<5;i++)
    {
        printf("Ingrese un numero: ");
        scanf("%d",&numeroIngresado);
        if(i==0)
        {
            maximo=numeroIngresado;
            minimo=numeroIngresado;
        }
        else
        {
            if(numeroIngresado>maximo)
            {
                maximo=numeroIngresado;
            }
            if(numeroIngresado<minimo)
            {
                minimo=numeroIngresado;
            }
        }

        acumulador=acumulador+numeroIngresado;
    }
    promedio=(float)acumulador/i;
    printf("\nEl promedio es: %.2f",promedio);
    printf("\nEl numero minimo es:%d",minimo);
    printf("\nEl numero maximo es:%d",maximo);
    return 0;
}
