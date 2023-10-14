#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

int validate(int ri, int rf);
int randomNumber(int ri, int rf);
bool validateString(char string[]);

int validate(int ri, int rf)
{
    char string[50];
    int num;

    do
    {
        fflush(stdin);
        gets(string);
        num = atoi(string);
        if (num < ri || num > rf)
        {
            printf("Out of range - Please enter a valid number: ");
        }
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

bool validateString(char string[])
{
    // Validate if the string starts with a space
    if (string[0] == ' ')
    {
        return false;
    }

    // Validate if the string contains double spaces
    for (int i = 0; string[i] != '\0'; i++)
    {
        if (string[i] == ' ' && string[i + 1] == ' ')
        {
            return false;
        }
    }

    // Validate if the string contains numbers
    for (int i = 0; string[i] != '\0'; i++)
    {
        if (string[i] >= '0' && string[i] <= '9')
        {
            return false;
        }
    }

    // Validate if the string contains accents
    for (int i = 0; string[i] != '\0'; i++)
    {
        char c = string[i];
        if ((c >= 128 && c <= 165) || (c >= 192 && c <= 255))
        {
            return false;
        }
    }

    // If no issues are found, the string is valid
    return true;
}
