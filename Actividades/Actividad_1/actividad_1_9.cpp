/*
GONZALEZ TORRES KEVIN ALEJANDRO

10/23/2023 | 10/26/2023

Algoritmo que lea 3 números y desplegar los 3 números en orden ascendente

KAGT_ACT1_7_932
*/

#include <stdio.h>

int main() {
    int num1, num2, num3;

    printf("Introduce tres números:\n");
    scanf("%d %d %d", &num1, &num2, &num3);

    if (num1 <= num2 && num1 <= num3) {
        if (num2 <= num3) {
            printf("Números en orden ascendente: %d %d %d\n", num1, num2, num3);
        } else {
            printf("Números en orden ascendente: %d %d %d\n", num1, num3, num2);
        }
    } else if (num2 <= num1 && num2 <= num3) {
        if (num1 <= num3) {
            printf("Números en orden ascendente: %d %d %d\n", num2, num1, num3);
        } else {
            printf("Números en orden ascendente: %d %d %d\n", num2, num3, num1);
        }
    } else {
        if (num1 <= num2) {
            printf("Números en orden ascendente: %d %d %d\n", num3, num1, num2);
        } else {
            printf("Números en orden ascendente: %d %d %d\n", num3, num2, num1);
        }
    }

    return 0;
}
