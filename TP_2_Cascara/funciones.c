#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funciones.h"
#define C 20


void inicioEstado(EPersona registro[])
{
    int i;
    for(i=0; i<C; i++)
    {
        registro[i].estado=0;
    }
}

int menu(char mensaje[],char error[])
{
    int op,aux;
    printf("%s",mensaje);
    aux=scanf("%d",&op);
    fflush(stdin);
    while(aux==0 ||(op<1||op>5))
    {
        printf("%s",error);
        fflush(stdin);
        aux=scanf("%d",&op);
    }
    return op;
}

void ingreso(EPersona registro[])
{
    int i,aux;
    for(i=0; i<C; i++)
    {
        if(registro[i].estado==0)
        {
            registro[i].estado=1;
            printf("Ingrese nombre: ");
            fflush(stdin);
            gets(registro[i].nombre);
            printf("Ingrese edad :");
            fflush(stdin);
            aux=scanf("%d",&registro[i].edad);
            while(aux==0 || (registro[i].edad<1 || registro[i].edad>100))
            {
                printf("Ingrese edad nuevamente: ");
                fflush(stdin);
                aux=scanf("%d",&registro[i].edad);
            }
            printf("Ingrese DNI :");
            fflush(stdin);
            aux=scanf("%d",&registro[i].dni);
            while(aux==0)
            {
                printf("Ingrese DNI nuevamente: ");
                fflush(stdin);
                aux=scanf("%d",&registro[i].dni);
            }
            break;
        }
    }
}

int borrar(EPersona registro[])
{
    int i,flag=0;
    int borrar;
    char pregBorrar;
    printf("Ingrese DNI de la persona a borrar: ");
    fflush(stdin);
    scanf("%d",&borrar);
    for(i=0; i<C; i++)
    {
        if(registro[i].dni==borrar)
        {
            printf("Esta seguro que desea borrar a %s (s/n)\n",registro[i].nombre);
            pregBorrar=getche();
            printf("\n");
            if(pregBorrar == 's')
            {
                registro[i].estado=0;

            }
            else
            {
                printf("Accion cancelada\n");
            }
            flag=1;
            break;
        }
    }
    if(flag==0)
    {
        printf("No existe persona con ese DNI!\n");

    }
    return registro[i].estado;
}

void imprimir(EPersona registro[])
{
    EPersona auxStruct;
    int i,j;
    for(i=0; i<C-1; i++)
    {
        for(j=i+1; j<C; j++)
        {
            if(stricmp(registro[i].nombre,registro[j].nombre)>0)
            {
                auxStruct = registro[j];
                registro[j]= registro[i];
                registro[i]= auxStruct;
            }
        }
    }
    for(i=0; i<C; i++)
    {
        if(registro[i].estado==1)
        {
            printf("%s---%d---%d\n",registro[i].nombre,registro[i].edad,registro[i].dni);
        }
    }
}

void grafico(EPersona registro[],int a, int b,int c,int d)
{
    int i,flag;
    for(i=0; i<C; i++)
    {
        flag=0;
        if(registro[i].estado==1)
        {
            if(registro[i].edad<=18)
            {
                a++;
            }
            else
            {
                if(registro[i].edad>35)
                {
                    c++;
                }
                else
                {
                    b++;
                }
            }
        }
    }
    if(a >= b && a >= c)
    {
        d = a;
    }
    else
    {
        if(b >= a && b >= c)
        {
            d = b;
        }
        else
        {
            d = c;
        }
    }
    for(i=d; i>0; i--)
    {
        if(i<10)
        {
            printf("%02d|",i);
        }
        else
            printf("%02d|",i);

        if(i<= a)
        {
            printf("*");
        }
        if(i<= b)
        {
            flag=1;
            printf("\t*");
        }
        if(i<= c)
        {
            if(flag==0)
            {
                printf("\t\t*");
            }
            if(flag==1)
            {
                printf("\t*");
            }
        }
        printf("\n");
    }
    printf("--+-----------------");
    printf("\n  |<18\t19-35\t>35");
}
