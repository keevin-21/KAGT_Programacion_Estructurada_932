#include <stdio.h>
#include <string.h>

void omitirNombres(char nombre[], const char partes[][7])
{
    for (int i = 0; partes[i][0] != '\0'; i++)
    {
        char *encontrado = strstr(nombre, partes[i]);
        int ocurrencias = 0; // Contador de ocurrencias de la palabra

        while (encontrado != NULL)
        {
            int longitudParte = strlen(partes[i]);
            int longitudRestante = strlen(encontrado + longitudParte);

            for (int j = 0; j < longitudParte; j++)
            {
                encontrado[j] = 'X'; // Reemplaza cada carácter de la palabra con 'X'
            }

            for (int j = longitudParte; j <= longitudRestante; j++)
            {
                encontrado[j] = encontrado[j + longitudParte];
            }

            ocurrencias++;
            encontrado = strstr(encontrado, partes[i]);
        }

        if (ocurrencias == 1)
        {
            encontrado = strstr(nombre, "X"); // Busca la 'X' generada
            while (encontrado != NULL)
            {
                if (encontrado[0] == 'X')
                {
                    encontrado[0] = ' '; // Si encuentra una 'X', la reemplaza con espacio en blanco
                }
                encontrado = strstr(encontrado + 1, "X"); // Busca la siguiente 'X'
            }
        }
    }
}

int main() {
    char nombre[] = "MAX JUAN M MARIA JOSE MARIA";
    char nombresCortos[][7] = {"MARIA ", "MAX ", "MA ", "MX ", "M ", "JOSE ", "JX ", "J "};

    omitirNombres(nombre, nombresCortos);
    printf("%s\n", nombre); // Imprime "XXX JUAN X X MARIA"
    return 0;
}
