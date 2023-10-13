#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

int validate(int ri, int rf);
int randomNumber(int ri, int rf);

/*
int linearSearch(int vector[], int size, int searchNumber);
int binarySearch(int array[], int left, int right, int number);
*/

int validate(int ri, int rf)
{
    char string[50];
    int num;

    do
    {
        fflush(stdin);
        gets(string);
        num = atoi(string);
        //printf("Out of range - Please enter a valid number: ");
    } while (num < ri || num > rf);

    return num;
}

int randomNumber(int ri, int rf)
{   
    // Enter final range and initial range
    int range = (rf - ri + 1);

    // Returns random number
    return rand() % range + ri;
}

/*
int binarySearch(int array[], int left, int right, int number)
{
    while (left <= right) {
        int medium = left + (right - left) / 2;
 
        // Check if number is present at mid
        if (array[medium] == number)
            return medium;
 
        // If number greater, ignore left half
        if (array[medium] < number)
            left = medium + 1;
 
        // If number is smaller, ignore right half
        else
            right = medium - 1;
    }
 
    // If we reach here, then element was not present
    return -1;
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
*/