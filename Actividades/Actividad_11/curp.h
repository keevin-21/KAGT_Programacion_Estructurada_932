#include "kewvyValidates.h"

char obtenerPrimeraVocal(const char cadena[])
{
    char vocalEncontrada = 'X';

    for (int i = 1; cadena[i] != '\0'; i++)
    {
        char c = toupper(cadena[i]);
        if (c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U')
        {
            vocalEncontrada = c;
            break;
        }
    }
    return vocalEncontrada;
}

char obtenerSegundaConsonante(char cadena[])
{
    int i = 1;

    while (cadena[i] != '\0')
    {
        char caracter = cadena[i];
        if (strchr("AEIOUaeiou", caracter) == NULL)
        {
            return caracter;
        }
        i++;
    }
    return '\0';
}

int esBisiesto(int anio)
{
    if ((anio % 4 == 0 && anio % 100 != 0) || (anio % 400 == 0))
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int validarEntidad(char cadena[], char entidades[][3], int numEntidades)
{
    for (int i = 0; i < numEntidades; i++)
    {
        if (strcmp(cadena, entidades[i]) == 0)
        {
            return 1;
        }
    }
    return 0;
}

int validarAntisonante(char cadena[], char antisonantes[][5], int numAntisonantes)
{
    char subcadena[5];

    strncpy(subcadena, cadena, 4);
    subcadena[4] = '\0';

    for (int i = 0; i < numAntisonantes; i++)
    {
        if (strcmp(subcadena, antisonantes[i]) == 0)
        {
            return 1;
        }
    }

    return 0;
}

void omitirNombres(char nombre[], char partes[][7])
{
    for (int i = 0; partes[i][0] != '\0'; i++)
    {
        char *encontrado = strstr(nombre, partes[i]);
        while (encontrado != NULL)
        {
            int longitudParte = strlen(partes[i]);
            int longitudRestante = strlen(encontrado + longitudParte);

            for (int j = 0; j <= longitudRestante; j++)
            {
                encontrado[j] = encontrado[j + longitudParte];
            }

            encontrado = strstr(encontrado, partes[i]);
        }
    }
}

void omitirPartes(char apellido[], char partes[][6])
{
    for (int i = 0; partes[i][0] != '\0'; i++)
    {
        char *encontrado = strstr(apellido, partes[i]);
        while (encontrado != NULL)
        {
            int longitudParte = strlen(partes[i]);
            int longitudRestante = strlen(encontrado + longitudParte);

            for (int j = 0; j <= longitudRestante; j++)
            {
                encontrado[j] = encontrado[j + longitudParte];
            }

            encontrado = strstr(encontrado, partes[i]);
        }
    }
}