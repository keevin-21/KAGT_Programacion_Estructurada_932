/*
GONZALEZ TORRES KEVIN ALEJANDRO

10/23/2023 | 10/26/2023 

Algoritmo que lea 3 números y desplegar cuál número es del medio y su valor

KAGT_ACT1_8_932
*/

#include <stdio.h>

int main() {
    int num1, num2, num3;

    printf("Introduce tres números:\n");
    scanf("%d %d %d", &num1, &num2, &num3);

    if ((num1 >= num2 && num1 <= num3) || (num1 <= num2 && num1 >= num3)) {
        printf("El número del medio es: %d\n", num1);
    } else if ((num2 >= num1 && num2 <= num3) || (num2 <= num1 && num2 >= num3)) {
        printf("El número del medio es: %d\n", num2);
    } else {
        printf("El número del medio es: %d\n", num3);
    }

    return 0;
}
