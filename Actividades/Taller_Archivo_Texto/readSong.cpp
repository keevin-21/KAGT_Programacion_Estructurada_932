#include <stdio.h>
#include <stdlib.h>

void readTextFile();

int main()
{
    printf("m y . l i f e\nJ. Cole, 21 Savage, Morray\n\n");
    readTextFile();
    return 0;
}

void readTextFile(void)
{
    FILE *file;
    char character;

    file = fopen("G:\\My Drive\\UABC\\TercerSemestre\\KAGT_Programacion_Estructurada_932\\Actividades\\Taller_Archivo_Texto\\cancion.txt", "r");

    if (file == NULL)
    {
        printf("No se pudo abrir el archivo.\n");
    }
    else
    {
        do
        {
            character = fgetc(file);
            printf("%c", character);
        } while (!feof(file));
        fclose(file);

        printf("\n\nQUE BUENA ROLA ALV");
    }
}