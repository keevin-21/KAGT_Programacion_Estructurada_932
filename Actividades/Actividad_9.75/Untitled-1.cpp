#include <stdio.h>
#include <string.h>

void reemplazarIniciales(char *cadena, const char reemplazo)
{
    if (cadena[0] == 'Ñ' || cadena[0] == 'ñ')
    {
        cadena[0] = reemplazo;
    }
}

int main()
{
    char nombre[] = "Ñame";
    char apellido[] = "ñez";

    reemplazarIniciales(nombre, 'X');
    reemplazarIniciales(apellido, 'X');

    printf("Nombre: %s\n", nombre);
    printf("Apellido: %s\n", apellido);

    return 0;
}
