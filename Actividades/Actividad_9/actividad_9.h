#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int validate(int ri, int rf);
void fillVectorRandom(int vector[], int size, int ri, int rf);
void printVector(int vector[], int size);
void fillMatrixRandom(int matrix[][5], int vector[], int r, int c);
void printMatrix(int matrix[][5], int size);
void sortVector(int vector[], int size);
int linearSearch(int vector[], int size, int searchNumber);

int validate(int ri, int rf)
{
    char string[50];
    int num;

    do
    {
        fflush(stdin);
        gets(string);
        num = atoi(string);
    } while (num < ri || num > rf);

    return num;
}

void fillVectorRandom(int vector[], int size, int ri, int rf)
{
    int checkRepeated;

    srand(time(NULL));
    for (int i = 0; i < size; i++)
    {
        // function to avoid repeated number
        do
        {
            checkRepeated = 0; // initialize to assume the number is not repeated
            vector[i] = rand() % (rf - ri + 1) + ri;

            // check if the random number already exists in the vector
            for (int j = 0; j < i; j++)
            {
                if (vector[j] == vector[i])
                {
                    checkRepeated = 1; // set to 1 if the number is repeated
                }
            }
        } while (checkRepeated); // repeat until a unique number is generated
    }
}

void printVector(int vector[], int size)
{
    printf("Vector elements: {");
    for (int i = 0; i < size; i++)
    {
        printf("%d", vector[i]);
        if (i < size - 1) // separates each number with a comma
        {
            printf(", ");
        }
    }
    printf("}\n");
}

void fillMatrixRandom(int matrix[][5], int vector[], int r, int c)
{
    int k = 0;
    fillVectorRandom(vector, 16, 1, 16);
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            matrix[i][j] = vector[k++];
        }
    }
}

void printMatrix(int matrix[][5], int size) // doesnt avoid repeated numbers
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

void sortVector(int vector[], int size)
{
    int temp;

    for (int i = 0; i < size - 1; i++)
    {
        for (int j = i + 1; j < size; j++)
        {
            if (vector[j] < vector[i])
            {
                temp = vector[i];
                vector[i] = vector[j];
                vector[j] = temp;
            }
        }
    }
}

int linearSearch(int vector[], int size, int searchNumber)
{
    int i;

    for (i = 0; i < size; i++)
    {
        if (vector[i] == searchNumber)
        {
            return i;
        }
    }
    return -1;
}
