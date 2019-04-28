#define MAXIMO_CARACTER 100

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
                    char arrayUsuario[][MAXIMO_CARACTER]);


