#include <stdio.h>
#include <stdlib.h>
#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

typedef struct {

    char nombre[50];
    int edad;
    int estado;
    int dni;

}EPersona;
/**
 * Inicializa el estado en "0".
 * @param lista el array se pasa como parametro.
 */
void inicioEstado(EPersona registro[]);

/**
 * Toma la opcion ingresada por el usuario.
 * @param Mensaje Menu de opciones.
 * @param Mensaje de Error.
 * @return La opcion que eligio el usuario.
 */
int menu(char mensaje[],char error[]);

void ingreso(EPersona registro[]);

int borrar(EPersona registro[]);

void imprimir(EPersona registro[]);

void grafico(EPersona registro[],int a, int b,int c,int d);

#endif // FUNCIONES_H_INCLUDED
