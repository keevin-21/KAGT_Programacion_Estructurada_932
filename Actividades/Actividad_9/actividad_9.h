#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void fillVectorRandom(int vector[], int size);
void printVector(int vector[], int size);
void fillMatrixRandom(int matrix[][5], int size);
void printMatrix(int matrix[][5], int size);
void sortVector(int vector[], int size);
int linearSearch(int vector[], int size, int searchNumber);

void fillVectorRandom(int vector[], int size)
{
    int checkRepeated;

    srand(time(NULL));
    for (int i = 0; i < size; i++)
    {
        // function to avoid repeated number
        do
        {
            checkRepeated = 0; // initialize to assume the number is not repeated
            vector[i] = rand() % 101 + 100;

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
        if (i < size - 1) //separates each number with a comma
        {
            printf(", ");
        }
    }
    printf("}\n");
}

void fillMatrixRandom(int matrix[][5], int size) 
{
    int r, c;

    srand(time(NULL));
    for(r = 0; r < size; r++)
    {
        for(c = 0; c < size; c++)
        {
            matrix[r][c] = rand() % 17;
        }
    }    
}

void printMatrix(int matrix[][5], int size) //doesnt avoid repeated numbers
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

    for (int i = 0; i < size- 1; i++)
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

