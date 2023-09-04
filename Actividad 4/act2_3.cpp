#include<stdio.h>

int main()
{
    float n1, n2, n3, n4, n5, n6, mayor;
    printf("Numero #1: ");
    scanf("%f", &n1);
    printf("Numero #2: ");
    scanf("%f", &n2);
    printf("Numero #3: ");
    scanf("%f", &n3);
    printf("Numero #4: ");
    scanf("%f", &n4);
    printf("Numero #5: ");
    scanf("%f", &n5);
    printf("Numero #6: ");
    scanf("%f", &n6);

    mayor = n1;

    if (n2 > mayor)
    {
        mayor = n2;
    }
    if (n3 > mayor)
    {
        mayor = n3;
    }
    if (n4 > mayor)
    {
        mayor = n4;
    }
    if (n5 > mayor)
    {
        mayor = n5;
    }
    if (n6 > mayor)
    {
        mayor = n6;
    }
    
    printf("El mayor de todos los numeros es: %.1f", mayor);
}
