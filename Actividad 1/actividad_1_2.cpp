/*
GONZALEZ TORRES KEVIN ALEJANDRO

10/23/2023 | 10/26/2023 

Algoritmo que lea un número entero, y desplegar si el número es “PAR” o “IMPAR”

KAGT_ACT1_2_932
*/

#include<stdio.h>

int main()
{
    int num;
    printf("ESCRIBE UN NUMERO: ");
    scanf("%i", &num);
    if (num % 2 == 0)
    {
        printf("\nEL NUMERO ESCRITO ES PAR");
    }
    else
    {
        printf("\nEL NUMERO ESCRITO ES IMPAR");
    }
    
}