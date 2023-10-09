/*
Kevin Alejandro Gonzalez Torres - 372354

Creado el: 2 de Octubre del 2023 / Modificado el  de Octubre del 2023

Actividad 9:
    1.- LLENAR VECTOR:
        Llenar vector con 15 números, los números generados aleatoriamente, los números entre el rango de 100 al 200 (no repetidos).

    2.- LLENAR MATRIZ:
        Llenar la matriz de 4x4 con con números generados aleatoriamente, números entre el rango de 1 al 16  (no repetidos).

    3.- IMPRIMIR VECTOR:
        Imprime el vector que se envíe, donde la función recibe como parámetro el vector,tamaño, nombre del vector.

    4.- IMPRIMIR MATRIZ:
        Imprime la matriz sin importar el tamaño de la matriz recibiendo como parámetros la matriz, la cantidad
        de renglones y columnas, así como nombre que se le dará a la matriz.

    5.- ORDENAR VECTOR:
        Usar función que ordene el vector por el método de ordenación de la Burbuja mejorada.

    6.- BUSCAR VALOR EN EL VECTOR:
        Buscar un valor en el vector usando el método de búsqueda secuencial.
*/

int msges();
void menu();
void searchNumber(int vector[]);

#include "actividad_9.h"

int main()
{
    menu();

    return 0;
}

int msges()
{
    int option;

    printf("ARRAYS MENU");
    printf("\n\t1.- Fill Vector");
    printf("\n\t2.- Fill Matrix");
    printf("\n\t3.- Print Vector");
    printf("\n\t4.- Print Matrix");
    printf("\n\t5.- Sort Vector");
    printf("\n\t6.- Find value in vector");
    printf("\n\t0.- Exit\n\n");
    printf("Select an option: ");
    option = validate(0, 6);
    return option;
}

void menu()
{
    int option, num;
    int vector[100];
    int matrix[5][5];

    do
    {
        option = msges();
        system("CLS");
        switch (option)
        {
        case 1:
            printf("Random vector filled properly\n\n");
            fillVectorRandom(vector, 15, 100, 200);
            break;
        case 2:
            printf("Random matrix filled properly\n\n");
            fillMatrixRandom(matrix, vector, 4, 4);
            break;
        case 3:
            printVector(vector, 15);
            break;
        case 4:
            printMatrix(matrix, 4);
            break;
        case 5:
            printf("Vector properly sorted\n\n");
            sortVector(vector, 15);
            break;
        case 6:
            searchNumber(vector);
            break;
        case 0:
            return;
        default:
            printf("Error - Please select a valid option.");
            break;
        }
        system("PAUSE");
    } while (option != 0);
}

void searchNumber(int vector[])
{
    int number, count;

    printf("What number are you looking for?\n");
    printf("Number: ");
    number = validate(100, 200);
    count = linearSearch(vector, 15, number);
    if (count != -1)
    {
        printf("\nNumber %i is in position %i.\n", number, count);
    }
    else
    {
        printf("\nNumber %i is not in the vector.", number);
    }
    
}