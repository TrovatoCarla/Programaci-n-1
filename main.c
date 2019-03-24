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

    for(i=0;i<5;i++)
    {
        printf("Ingrese un numero: ");
        scanf("%d",&numeroIngresado);
        acumulador=acumulador+numeroIngresado;
    }
    promedio=(float)acumulador/i;
    printf("\nEl promedio es: %.2f",promedio);
    return promedio;
}
