#ifndef ABM_H_INCLUDED
#define ABM_H_INCLUDED

int bajaDeUsuario(char* mensaje,
                    char*msjError,
                    char* msjErrNoExisteUsuario,
                    int maximo,
                    int minimo,
                    int reintentos,
                    char arrayUsuario[] [MAXIMO_CARACTER]);

int modificacionDeUsuario(char* mensaje,
                    char* mensajeError,
                    char* msjErrNoExisteUsuario,
                    char modificacion[MAXIMO_CARACTER],
                    int maximo,
                    int minimo,
                    int reintentos,
                    char arrayUsuario[] [MAXIMO_CARACTER]);

int altaDeUsuario(char* mensaje,
                    char* mensajeError,
                    char* errorNombreExistente,
                    char* errorNoHayPosVacia,
                    int maximo,
                    int minimo,
                    int reintentos,
                    char arrayUsuario[EMPLEADOS][MAXIMO_CARACTER]);


#endif // ABM_H_INCLUDED
