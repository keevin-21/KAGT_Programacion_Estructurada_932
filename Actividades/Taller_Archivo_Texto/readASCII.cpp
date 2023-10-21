#include <stdio.h>
#include <stdlib.h>

void readTextFile();

int main()
{
    readTextFile();
    return 0;
}

void readTextFile(void)
{
    FILE *file;
    char character;

    file = fopen("G:\\My Drive\\UABC\\TercerSemestre\\KAGT_Programacion_Estructurada_932\\Actividades\\Taller_Archivo_Texto\\ascii.txt", "r");

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
    }
}