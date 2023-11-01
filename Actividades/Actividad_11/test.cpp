#include <stdio.h>

int main() {
    // Abre un archivo en modo escritura
    FILE *archivoSalida = freopen("G:\\My Drive\\UABC\\TercerSemestre\\KAGT_Programacion_Estructurada_932\\Actividades\\Actividad_11\\registers.txt", "w", stdout);

    // Ahora, cualquier cosa que se imprima con printf se redirigirá al archivo de destino
    printf("Hola, esto se imprimirá en el archivo.\n");
    printf("Otra línea en el archivo.\n");

    // Cierra el archivo de destino
    fclose(archivoSalida);

    return 0;
}
