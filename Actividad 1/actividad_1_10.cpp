/*
GONZALEZ TORRES KEVIN ALEJANDRO

10/23/2023 | 10/26/2023

Programa que sirva para calcular el salario semanal de un trabajador donde se obtiene
como dato de entrada las ​ horas semanales​ trabajadas, el ​ salario por hora​ .

KAGT_ACT1_7_932
*/

#include <stdio.h>

int main() {
    float minutos, llamada, minuto_a, minuto_e, iva, total;
    int option;

    printf("Minutos de llamada: ");
    scanf("%f", &minutos);

    printf("Tipo de llamada\n");
    printf("=================\n");
    printf("1.- LLAMADA LOCAL: $3.00 sin límite de tiempo\n");
    printf("2.- LLAMADA NACIONAL: $7.00 por los 3 primeros minutos y $2.00 minuto adicional\n");
    printf("3.- LLAMADA INTERNACIONAL: $9.00 por los 2 primeros minutos y $4.00 minuto adicional\n");
    printf("=================\n");
    printf("ATENCIÓN - SE COBRARÁ IVA (16%%)\n");
    printf("Seleccionar la llamada correspondiente: ");
    scanf("%i", &option);

    switch (option) {
        case 1:
            llamada = minutos * 3;
            iva = llamada * 0.16;
            total = llamada + iva;
            
            printf("=================\n");
            printf("Subtotal: %.2f\n", llamada);
            printf("IVA (16%%): %.2f\n", iva);
            printf("Total: %.2f\n", total);
            printf("=================\n");
            break;

        case 2:
            if (minutos > 0 && minutos <= 3) {
                llamada = minutos * 7;
                iva = llamada * 0.16;
                total = llamada + iva;
                
                printf("=================\n");
                printf("Subtotal: %.2f\n", llamada);
                printf("IVA (16%%): %.2f\n", iva);
                printf("Total: %.2f\n", total);
                printf("=================\n");
            } else {
                if (minutos > 3) {
                    minuto_a = (minutos - 3) * 2;
                    llamada = (minutos - (minutos - 3)) * 7 + minuto_a;
                    iva = llamada * 0.16;
                    total = llamada + iva;
                    
                    printf("=================\n");
                    printf("Subtotal: %.2f\n", llamada);
                    printf("IVA (16%%): %.2f\n", iva);
                    printf("Total: %.2f\n", total);
                    printf("=================\n");
                }
            }
            break;

        case 3:
            if (minutos > 0 && minutos <= 2) {
                llamada = minutos * 9;
                iva = llamada * 0.16;
                total = llamada + iva;
                
                printf("=================\n");
                printf("Subtotal: %.2f\n", llamada);
                printf("IVA (16%%): %.2f\n", iva);
                printf("Total: %.2f\n", total);
                printf("=================\n");
            } else {
                if (minutos > 2) {
                    minuto_a = (minutos - 2) * 4;
                    llamada = (minutos - (minutos - 2)) * 9 + minuto_a;
                    iva = llamada * 0.16;
                    total = llamada + iva;
                    
                    printf("=================\n");
                    printf("Subtotal: %.2f\n", llamada);
                    printf("IVA (16%%): %.2f\n", iva);
                    printf("Total: %.2f\n", total);
                    printf("=================\n");
                }
            }
            break;

        default:
            printf("ERROR - OPCIÓN NO VÁLIDA\n");
    }

    return 0;
}
