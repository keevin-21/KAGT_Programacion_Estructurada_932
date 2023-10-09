#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int validateNumber(int ri, int rf);
void uppercaseString(char string[]);
void noSpacesString(char string[]);

int validateNumber(int ri, int rf)
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

void uppercaseString(char string[])
{
    for (int i = 0; string[i] != '\0'; i++)
    {
        if (string[i] >= 'a' && string[i] <= 'z')
        {
            string[i] -= 32;
        }
    }
}

void noSpacesString(char string[])
{
    uppercaseString(string);

    int i, no_space_count = 0;

    for (i = 0; string[i] != '\0'; i++)
    {
        if (string[i] != ' ')
        {
            string[no_space_count++] = string[i];
        }
    }

    string[no_space_count] = '\0';
}
