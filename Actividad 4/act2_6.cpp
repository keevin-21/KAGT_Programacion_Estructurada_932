#include <stdio.h>

int main() {
    float m3, subtotal, iva, total;

    printf("M3 de agua consumidos este mes: ");
    scanf("%f", &m3);

    if (m3 >= 0 && m3 <= 4) {
        printf("Subtotal: 50\n");
        printf("IVA: %.2f\n", 50 * 0.16);
        printf("Total: %.2f\n", 50 * 1.16);
    } else {
        if (m3 >= 5 && m3 <= 15) {
            subtotal = m3 * 8;
            iva = subtotal * 0.16;
            total = subtotal + iva;

            printf("=================\n");
            printf("Subtotal: %.2f\n", subtotal);
            printf("IVA (16%%): %.2f\n", iva);
            printf("Total: %.2f\n", total);
            printf("=================\n");
        } else {
            if (m3 >= 16 && m3 <= 50) {
                subtotal = m3 * 10;
                iva = subtotal * 0.16;
                total = subtotal + iva;

                printf("=================\n");
                printf("Subtotal: %.2f\n", subtotal);
                printf("IVA (16%%): %.2f\n", iva);
                printf("Total: %.2f\n", total);
                printf("=================\n");
            } else {
                if (m3 >= 51) {
                    subtotal = m3 * 11;
                    iva = subtotal * 0.16;
                    total = subtotal + iva;

                    printf("=================\n");
                    printf("Subtotal: %.2f\n", subtotal);
                    printf("IVA (16%%): %.2f\n", iva);
                    printf("Total: %.2f\n", total);
                    printf("=================\n");
                } else {
                    printf("ERROR - LOS M3 CONSUMIDOS NO PUEDEN SER NEGATIVOS\n");
                }
            }
        }
    }

    return 0;
}
