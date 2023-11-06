#include <stdio.h>

int main() {
    char linea[] = "0.- 310442 MARIA SOTO PEREZ 33 FEMENINO";  // Ejemplo de una línea de la lista

    int numero; // Variable para almacenar el número
    char nombre[50]; // Variable para almacenar el nombre
    char apellido1[50]; // Variable para el primer apellido
    char apellido2[50]; // Variable para el segundo apellido
    int edad; // Variable para la edad
    char genero[20]; // Variable para el género

    // Utiliza sscanf para asignar los valores de la línea a las variables
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
        printf("Error al analizar la línea.\n");
    }

    return 0;
}
