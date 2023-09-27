

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int menu();
void fillVector1(int vector[], int size);
void fillVector2(int vector[], int size);
void fillVector3(int vector[], int vector1[], int vector2[], int size);
void fillMatrix(int matrix[][5], int size);
void printVector(int vector[], int size);
void printMatrix(int matrix[][5], int size);

int main()
{
    menu();
    return 0;
}

int menu()
{
    int option;
    int vector1[10];
    int vector2[10];
    int vector3[20];
    int matrix[5][5];

    printf("ARRAYS MENU");
    printf("\n\t1.- Fill Vector 1\n\t2.- Fill Vector 2\n\t3.- Fill Vector 3*\n\t4.- Print Vectors*\n\t5.- Fill Matrix 4x4\n\t6.- Print Matrix\n\t0.- Close Program\n");
    printf("Select an option: ");
    scanf("%i", &option);

    switch (option)
    {
    case 1:
        fillVector1(vector1, 10);
        break;
    case 2:
        fillVector2(vector2, 10);
        break;
    case 3:
        fillVector3(vector3, vector1, vector2, 10);
        printVector(vector3, 10);
        break;
    case 4:
        printf("\n");
        printVector(vector1, 10);
        printf("\n");
        printVector(vector2, 10);
        printf("\n");
        printVector(vector3, 20);
        break;
    case 5:
        fillMatrix(matrix, 4);
        break;
    case 6:
        printMatrix(matrix, 4);
        break;
    case 0:
        printf("Thanks for using this program. Come back soon!");
        return 1;
        break;
    default:
        printf("Invalid option. Select another one.");
        break;
    }
}

void fillVector1(int vector[], int size)
{
    printf("Fill it only with numbers between 30 to 70\n");

    for (int i = 0; i < size; i++)
    {
        printf("Vector[%i]: ", i);
        scanf("%i", &vector[i]);

        if (vector[i] < 30 || vector[i] > 70)
        {
            printf("Value out of range. Please enter another number.\n");
            i--; // repeat last (incorrect) index
        }
    }
    menu();
}

void fillVector2(int vector[], int size)
{
    printf("Vector filled with random numbers between 1 to 20");

    int checkRepeated;

    srand(time(NULL));
    for (int i = 0; i < size; i++)
    {
        // function to avoid repeated number
        do
        {
            checkRepeated = 0; // initialize to assume the number is not repeated
            vector[i] = rand() % 20 + 1;

            // check if the random number already exists in the vector
            for (int j = 0; j < i; j++)
            {
                if (vector[j] == vector[i])
                {
                    checkRepeated = 1; // set to 1 if the number is repeated
                    break;
                }
            }
        } while (checkRepeated); // repeat until a unique number is generated
    }
    menu();
}

void fillVector3(int vector[], int vector1[], int vector2[], int size)
{
    for (int i = 0; i < size; i++)
    {
        vector[i] = vector1[i];
        vector[i + 10] = vector2[i];
    }
    menu();
}

void fillMatrix(int matrix[][5], int size)
{
    for (int r = 0; r < size; r++)
    {
        for (int c = 0; c < size; c++)
        {
            printf("Matrix[%i, %i]: ", r, c);
            scanf("%i", &matrix[r][c]);
        }
    }
    menu();
}

void printVector(int vector[], int size)
{
    printf("Vector elements: {");
    for (int i = 0; i < size; i++)
    {
        printf("%d", vector[i]);
        if (i < size - 1)
        {
            printf(", ");
        }
    }
    printf("}");
}

void printMatrix(int matrix[][5], int size)
{
    int r, c;

    printf("Matrix elements: \n{\n");
    for (r = 0; r < size; r++)
    {
        for (c = 0; c < size; c++)
        {
            printf("%d\t", matrix[r][c]);
        }
        printf("\n");
    }
    printf("}");
}