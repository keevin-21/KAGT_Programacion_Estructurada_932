#include <stdio.h>

int main() {
    FILE *archivo;  // Declarar un puntero a FILE

    archivo = fopen("G:\\My Drive\\UABC\\TercerSemestre\\KAGT_Programacion_Estructurada_932\\Actividades\\Actividad_12\\datos.txt", "r");  // Abrir el archivo en modo lectura ("r")

    if (archivo == NULL) {
        // Verificar si la apertura del archivo fue exitosa
        printf("No se pudo abrir el archivo.\n");
        return 1;  // Salir del programa con un código de error
    }

    int numero;
    char nombre[50];
    char apellido1[50];
    char apellido2[50];
    int edad;
    char genero[20];

    char linea[100];  // Un búfer para almacenar las líneas del archivo

    while (fgets(linea, sizeof(linea), archivo) != NULL) {
        int elementosLeidos = sscanf(linea, "%d.- %d %s %s %s %d %s",
                                     &numero, &numero, nombre, apellido1, apellido2, &edad, genero);

        if (elementosLeidos == 7) {
            // Imprime los valores asignados a las variables
            printf("Número: %d\n", numero);
            printf("Nombre: %s\n", nombre);
            printf("Primer apellido: %s\n", apellido1);
            printf("Segundo apellido: %s\n", apellido2);
            printf("Edad: %d\n", edad);
            printf("Género: %s\n", genero);
        } else {
            printf("Error al analizar la línea: %s", linea);
        }
    }

    fclose(archivo);  // Cierra el archivo cuando hayas terminado de usarlo

    return 0;  // Salir del programa con éxito
}
