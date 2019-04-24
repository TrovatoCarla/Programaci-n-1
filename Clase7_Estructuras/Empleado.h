#ifndef EMPLEADO_H_INCLUDED
#define EMPLEADO_H_INCLUDED

typedef struct

{
    int idEmpleado;
    int isEmpty;// 1 si esta vacio y 0 si esta cargado
    char nombre[50];
}Empleado;

int emp_initArray(Empleado* arrayEmp,int limite);// siempre va a recirbir el array y el limite
int emp_lugarLibre(Empleado* arrayEmp,int limite,int* indice);
int emp_alta(Empleado* arrayEmp,int limite,int id);
int emp_baja(Empleado* arrayEmp,int limite);
int emp_buscarPorNombre(Empleado* arrayEmp,int limite,char* nombre,int* indice);
int emp_ordenarPorNombre(Empleado* arrayEmp,int limite);
int emp_muestra(Empleado *arrayEmp,int limite);

#endif // EMPLEADO_H_INCLUDED


