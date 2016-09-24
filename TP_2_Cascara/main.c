#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funciones.h"
#define C 20

int main()
{
    char seguir='s';
    int opcion=0;
    int i,j,hasta18, de19a35, mayorDe35, flag=0, mayor;


    EPersona registro[C],auxStruct;

    inicioEstado(registro);

    while(seguir=='s')
    {
        opcion = menu("1- Agregar persona\n2- Borrar persona\n3- Imprimir lista ordenada por  nombre\n4- Imprimir grafico de edades\n\n5- Salir\n","Error ingrese nuevamente una opcion entre 1 y 5: ");

        switch(opcion)
        {
            case 1:
                ingreso(registro);
                break;
            case 2:
               borrar(registro);
                break;
           case 3:
                imprimir(registro);
                break;
            case 4:
                hasta18=0;
                de19a35=0;
                mayorDe35=0;
                grafico(registro, hasta18, de19a35, mayorDe35, mayor);
                break;
            case 5:
                seguir = 'n';
                break;
        }
    }
    return 0;
}
