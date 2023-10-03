/*
Kevin Alejandro Gonzalez Torres - 372354

Creado el: 2 de Octubre del 2023 / Modificado el  de Octubre del 2023

Actividad 9:
    1.-

    2.-

    3.-

    4.-

    5.-

    6.-
*/

int msges();
void menu();

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
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
    scanf("%i", &option);
    return option;
}

void menu()
{
    int option, size, searchNumber, result;
    int vector[100];
    int matrix[5][5];

    do
    {
        option = msges();
        //system("CLS");
        switch (option)
        {
        case 1:
            printf("Random vector filled properly\n\n");
            fillVectorRandom(vector, 15);
            break;
        case 2:
            printf("Random matrix filled properly\n\n");
            fillMatrixRandom(matrix, 4);
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
            printf("What number are you looking for?\n");
            printf("Number: ");
            scanf("%i", &searchNumber);
            printf("\n\nNumber %i is in position %i.\n", searchNumber, linearSearch(vector, 15, searchNumber));
            break;
        case 0:
            break;
        default:
            printf("Error - Please select a valid option.");
            break;
        }
        system("PAUSE");
    } while (option != 0);
}
