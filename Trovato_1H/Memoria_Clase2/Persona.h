#ifndef PERSONA_H_INCLUDED
#define PERSONA_H_INCLUDED

typedef struct
{
    int estado;
    int id;
    char nombre[30];
    char apellido[30];

}Persona;

Persona* Per_new(void);///siempre. me devuelve un puntero a la identidad.para el q me consiguio lugar

int Per_delete(Persona* this);

int Per_setId(Persona* this, int id);
int Per_getId(Persona* this, int* resultado);
int Per_setNombre(Persona* this, char *nombre);
int Per_getNombre(Persona* this, char* resultado);
int Per_setEstado(Persona* this, int estado);
int Per_getEstado(Persona* this, int* resultado);
int Per_setApellido(Persona* this, char *nombre);
int Per_getApellido(Persona* this, char* resultado);


#endif // PERSONA_H_INCLUDED
