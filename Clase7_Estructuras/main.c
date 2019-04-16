#include <stdio.h>
#include <stdlib.h>

#include <stdio.h>
#include <stdlib.h>
#include "funcionesUTN.h"
#include "misValid.h"

int main()
{
    char auxName[500] = "test";

    char arrayNombres[QTY_EMPLEADOS][50];

    strncpy(arrayNombres[0],"JUAN",50);


    if(getName( "Nombre?: ",
                "Error",
                2,
                5,
                2,
                auxName) == 0)
    {
        printf("OK: %s",auxName);
    }
    else
    {
        printf("ER: %s",auxName);
    }
    return 0;
}
