/*
Kevin Alejandro Gonzalez Torres - 372354

Creado el: 16 de Septiembre del 2023 / Modificado el 17 de Septiembre del 2023

Actividad 6 - Parte 1:
    1.- Menú de funciones que ejecutan la serie Fibonacci en cada uno de las 3
        estructuras de ciclos existentes.

    2.- Menú de funciones que ejecutan el codigo de Factorial en cada uno de las 3
        estructuras de ciclos existentes.
    
    3.- Menú de funciones que ejecutan un codigo para contar los digitos de un
        numero en cada uno de las 3 estructuras de ciclos existentes.
*/

#include <stdio.h>

void menu();

void menuFibonacci();
void fibonacciFor();
void fibonacciWhile();
void fibonacciDoWhile();

void menuFactorial();
void factorialFor();
void factorialWhile();
void factorialDoWhile();


void menuDigitCounter();
void digitCounterFor();
void digitCounterWhile();
void digitCounterDoWhile();


int main()
{
    menu();
    
    return 0;
}

void menu()
{
    int option;
    start:
    printf("MENU:\n");
    printf("\t1.- Fibonacci\n");
    printf("\t2.- Factorial\n");
    printf("\t3.- Cantidad de digitos\n");
    scanf("%i", &option);

    switch (option)
    {
    case 1:
        menuFibonacci();
        break;
    case 2:
        menuFactorial();
        break;
    case 3:
        menuDigitCounter();
        break;
    default:
        printf("Error - Selecciona una opcion valida.");
        goto start;
        break;
    }
}

void menuFibonacci()
{
    int option;
    
    start:
    printf("Menu Fibonacci:\n");
    printf("\t1.- For\n");
    printf("\t2.- While\n");
    printf("\t3.- Do While\n");
    printf("Selecciona una opcion: ");
    scanf("%i", &option);

    switch (option)
    {
    case 1:
        fibonacciFor();
        break;
    case 2:
        fibonacciWhile();
        break;
    case 3:
        fibonacciDoWhile();
        break;
    default:
        printf("Error - Opcion no valida.");
        goto start;
        break;
    }
}
void fibonacciFor()
{
    int num;
    int n1 = -1, n2 = 1, aux = n1+n2;
    
    printf("Numero para la serie fibonacci: ");
    scanf("%i", &num);
    for (int i = 0; i < num ; i++)
    {
        aux = n1 + n2;
        n1 = n2;
        n2 = aux;
        printf("%i\n", aux);
    }

}
void fibonacciWhile()
{
    int num;
    int n1 = -1, n2 = 1, aux = n1+n2;
    
    printf("Numero para la serie fibonacci: ");
    scanf("%i", &num);
    
    int i = 0;
    while (i < num)
    {
        aux = n1 + n2;
        n1 = n2;
        n2 = aux;
        printf("%i\n", aux);
        i++;
    }
}
void fibonacciDoWhile()
{
    int num;
    int n1 = -1, n2 = 1, aux = n1+n2;
    
    printf("Numero para la serie fibonacci: ");
    scanf("%i", &num);

    int i = 0;
    do
    {
        aux = n1 + n2;
        n1 = n2;
        n2 = aux;
        printf("%i\n", aux);
        i++;
    } while (i < num);
}


void menuFactorial()
{
    int option;
    
    start:
    printf("Menu Factorial:\n");
    printf("\t1.- For\n");
    printf("\t2.- While\n");
    printf("\t3.- Do While\n");
    printf("Selecciona una opcion: ");
    scanf("%i", &option);

    switch (option)
    {
    case 1:
        factorialFor();
        break;
    case 2:
        factorialWhile();
        break;
    case 3:
        factorialDoWhile();
        break;
    default:
        printf("Error - Opcion no valida.");
        goto start;
        break;
    }
}
void factorialFor()
{
    int result = 1, num;

    printf("Numero a sacar el factorial: ");
    scanf("%i", &num);  

    for (int i = 1; i <= num; i++)
    {
        result = result * i; 
    }

    printf("El factorial del numero %i es %i.", num, result);
}
void factorialWhile()
{
    int result = 1, num;

    printf("Numero a sacar el factorial: ");
    scanf("%i", &num);  

    int i = 1;
    while (i <= num)
    {
        result = result * i;
        i++;
    }

    printf("El factorial del numero %i es %i.", num, result);
}
void factorialDoWhile()
{
    int result = 1, num;

    printf("Numero a sacar el factorial: ");
    scanf("%i", &num);  

    int i = 1;
    do
    {
        result = result * i;
        i++;
    } while (i <= num);

    printf("El factorial del numero %i es %i.", num, result);
}

void menuDigitCounter()
{
    int option;
    
    start:
    printf("Menu Contar Digitos:\n");
    printf("\t1.- For\n");
    printf("\t2.- While\n");
    printf("\t3.- Do While\n");
    printf("Selecciona una opcion: ");
    scanf("%i", &option);

    switch (option)
    {
    case 1:
        digitCounterFor();
        break;
    case 2:
        digitCounterWhile();
        break;
    case 3:
        digitCounterDoWhile();
        break;
    default:
        printf("Error - Opcion no valida.");
        goto start;
        break;
    }
}
void digitCounterFor()
{
    int num, aux, dig;
    int i = 0;
    
    printf("Numero a contar los digitos: ");
    scanf("%i", &num);
    
    aux = num;
    for (i; aux > 0; i++)
    {
        aux = aux / 10;
    }
    
    printf("%i", i);
}
void digitCounterWhile()
{
    int num, aux, dig;
    
    printf("Numero a contar los digitos: ");
    scanf("%i", &num);
    
    aux = num;
    int i = 0;
    while (aux > 0)
    {
        aux = aux / 10;
        i++;
    }

    printf("%i", i);
}
void digitCounterDoWhile()
{
    int num, aux, dig;
    
    printf("Numero a contar los digitos: ");
    scanf("%i", &num);
    
    aux = num;
    int i = 0;
    do
    {
        aux = aux / 10;
        i++;
    } while (aux > 0);

    printf("%i", i);
}