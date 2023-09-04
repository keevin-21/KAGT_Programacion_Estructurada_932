/*
GONZALEZ TORRES KEVIN ALEJANDRO

10/23/2023 | 10/26/2023

Algoritmo que sirva para desplegar el Total de una llamada telefónica
donde se pide como datos de entrada los ​ minutos​ y el ​ tipo de llamada​

KAGT_ACT1_7_932
*/

#include <stdio.h>

int main() {
    float horas, salarioph, salariot, salarioe2, salarioe3;

    printf("Horas semanales trabajadas: ");
    scanf("%f", &horas);

    printf("Salario por hora: ");
    scanf("%f", &salarioph);

    if (horas > 0 && horas <= 40) {
        salariot = horas * salarioph;

        printf("============================\n");
        printf("Horas trabajadas: %.2f\n", horas);
        printf("Salario por hora: %.2f\n", salarioph);
        printf("Salario extra: 0\n");
        printf("Su salario total es de: %.2f\n", salariot);
        printf("============================\n");
    } else {
        if (horas > 40 && horas <= 49) {
            salarioe2 = (horas - 40) * (2 * salarioph);
            salariot = horas * salarioph + salarioe2;

            printf("============================\n");
            printf("Horas trabajadas: %.2f\n", horas);
            printf("Salario por hora: %.2f\n", salarioph);
            printf("Salario sin extra: %.2f\n", salariot - salarioe2);
            printf("Salario extra al doble: %.2f\n", salarioe2);
            printf("Su salario total es de: %.2f\n", salariot);
            printf("============================\n");
        } else {
            if (horas >= 50) {
                salarioe2 = (horas - 41) * (2 * salarioph);
                salarioe3 = (horas - 49) * (3 * salarioph);
                salariot = (horas * salarioph) + salarioe2 + salarioe3;

                printf("============================\n");
                printf("Horas trabajadas: %.2f\n", horas);
                printf("Salario por hora: %.2f\n", salarioph);
                printf("Salario sin extra: %.2f\n", salariot - salarioe2 - salarioe3);
                printf("Salario extra al doble: %.2f\n", salarioe2);
                printf("Salario extra al triple: %.2f\n", salarioe3);
                printf("Salario extra total: %.2f\n", salarioe2 + salarioe3);
                printf("Su salario total es de: %.2f\n", salariot);
                printf("============================\n");
            } else {
                printf("ERROR - NO PUEDE HABER HORAS NEGATIVAS\n");
            }
        }
    }

    return 0;
}
