/*
GONZALEZ TORRES KEVIN ALEJANDRO

10/23/2023 | 10/26/2023 

Algoritmo que a través de opciones (1.- HOMBRE 2.- MUJER ) preguntar al usuario cual
es su SEXO y desplegar la leyenda “HOLA, ERES HOMBRE ”, “ HOLA, ERES MUJER”

KAGT_ACT1_4_932
*/

#include<stdio.h>

int main()
{
    int option;

    printf("ESCOGE TU SEXO:\n\n");
    printf("1.- Hombre\n\n2.-\n\n");
    printf("Opcion: ");
    scanf("%i", &option);
    
    if (option == 1)

        printf("ERES HOMBRE");

    else if (option == 2)
    {
        printf("ERES MUJER");
    }
    else
    {
            printf("ERROR - OPCION NO VALIDA");
    }
    
    
    return 0;
}