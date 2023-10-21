#include <stdio.h>
#include <stdlib.h>

void createTextFile(void);

int main()
{
    createTextFile();
    return 0;
}

void createTextFile(void)
{
    FILE *file;
    char name[100];
    char fatherLastname[100];
    char motherLastname[100];
    char city[100];

    file = fopen("G:\\My Drive\\UABC\\TercerSemestre\\KAGT_Programacion_Estructurada_932\\Actividades\\Taller_Archivo_Texto\\data.txt", "r+");  // Use "r+" mode to read and write

    if (file == NULL) {
        printf("Error opening the file.\n");
    }
    fprintf(file, "NAME\t\tLASTNAMES\t\tCITY\n");
    for (int i = 0; i < 4; i++)
    {
    printf("NAME: ");
    gets(name);
    printf("FATHER LASTNAME: ");
    gets(fatherLastname);
    printf("MOTHER LASTNAME: ");
    gets(motherLastname);
    printf("CITY: ");
    gets(city);
    printf("\n");
    fprintf(file, "%s\t%s\t%s\t%s\n\n", name, fatherLastname, motherLastname, city);
    }
    

    fclose(file);
}
