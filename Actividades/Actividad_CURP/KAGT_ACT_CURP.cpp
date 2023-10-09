/*

*/

#include "empanadas.h"

void fatherLastName(char string[]);
void motherLastName(char string[]);

int main()
{
    char string[50];
    printf("CLAVE UNICA DE REGISTRO DE POBLACION\n\n");
    fatherLastName(string);
}

void fatherLastName(char string[])
{
    printf("¿Cual es tu apellido paterno?\n");
    printf("Apellido paterno: ");
    gets(string);
    noSpacesString(string);
    uppercaseString(string);
}

void motherLastName(char string[])
{
    printf("¿Cual es tu apellido paterno?\n");
    printf("Apellido materno: ");
    gets(string);
    noSpacesString(string);
    uppercaseString(string);
}

void names(char string[])
{
    printf("¿Cual es/son tus nombres?\n");
    printf("Nombre(s): ");
    gets(string);
    noSpacesString(string);
    uppercaseString(string);
}
