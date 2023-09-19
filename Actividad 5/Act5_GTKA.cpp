#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void menu();
void descendingOrder();
void randomNumbers();
void higher_minusNumber();
void timesTables();

int main()
{
    srand(time(NULL));
    menu();
    return 0;
}

void menu()
{
    int option;
    printf("MENU:\n");
    printf("\t1.- ORDEN DESCENDENTE\n");
    printf("\t2.- NUMEROS PARES O IMPARES\n");
    printf("\t3.- DIGITOS\n");
    printf("\t4.- TABLAS DE MULTIPLICAR\n");
    printf("\t0.- SALIR \n");
    printf("ESCOGE UNA OPCION: ");
    scanf("%i", &option);

    switch (option)
    {
    case 1:
        descendingOrder();
        break;
    
    case 2:
        randomNumbers();
        break;

    case 3:
        higher_minusNumber();
        break;

    case 4:
        timesTables();
        break;

    default:
        printf("ERROR - OPCION NO VALIDA");
        break;
    }
}

void descendingOrder()
{
    int number, i;
    printf("Escribe un numero entero positivo:");
    scanf("%i", &number);

    for (i = number; i >= 0; i--)
    {
        printf("%i\n", i);
    }
}

void randomNumbers()
{
    int random, par, odd, i;

    par = 0;
    odd = 0;
    for (i = 0; i < 40; i++)
    {
        random = rand() % 200;

        if (random % 2 == 0)
        {
            printf("%i es un numero par\n", random);
            par = par + 1;
        }
        else
        {
            printf("%i es un numero impar\n", random);
            odd = odd + 1;
        }
    }

    printf("\nEl total de numeros pares es: %i", par);
    printf("\nEl total de numeros impares es: %i", odd);
}

void higher_minusNumber()
{
    int random, i, higher, minor;
    
    higher = -1000;
    minor = 1000;
    
    srand(time(NULL));
    
    for (i = 0; i < 35; i++)
    {
        random = rand() % 100 + 101;

        if (random > higher)
        {
            higher = random;
        }
        if (random < minor)
        {
            minor = random;
        }
    }

    printf("El numero mayor de los numeros generados es: %i\n", higher);
    printf("El numero menor de los numeros generados es: %i\n", minor);
}


void timesTables()
{
    int number, i;
    printf("Tabla de multiplicar a mostrar (1 al 20): ");
    scanf("%i", &number);

    printf("Mostrando tabla del %i", number);
    for (i = 1; i <= 10; i++)
    {
        if(number <= 20)
        {
            printf("%i x %i = %i\n", i, number, i * number);
        }
        else
        {
            printf("NUMERO NO VALIDO - INTENTA DE NUEVO");
        }
    }
}
