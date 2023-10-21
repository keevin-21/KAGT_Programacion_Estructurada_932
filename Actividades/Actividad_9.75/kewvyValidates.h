#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <stdbool.h>

int validate(int ri, int rf);
int randomNumber(int ri, int rf);
bool validateString(char string[], int max_length);
void uppercaseString(char string[]);

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
    int range = (rf - ri + 1);

    return rand() % range + ri;
}

void validateAlpha(char string[])
{
    for (int i = 0; string[i] != '\0'; i++)
    {
        if (string[i] == 'Á')
        {
            string[i] = 'A';
        }
        else
        {
            if (string[i] == 'É')
            {
                string[i] = 'E';
            }
            else
            {
                if (string[i] == 'Í')
                {
                    string[i] = 'I';
                }
                else
                {
                    if (string[i] == 'Ó')
                    {
                        string[i] = 'O';
                    }
                    else
                    {
                        if (string[i] == 'Ú')
                        {
                            string[i] = 'U';
                        }
                    }
                }
            }
        }
    }
}

bool validateString(char string[], int max_length)
{
    int invalid = 0;
    int i;

    do
    {
        invalid = 0;
        fflush(stdin);
        gets(string);
        uppercaseString(string);
        validateAlpha(string);
        if (string[0] == ' ')
        {
            invalid = 1;
        }

        for (i = 0; string[i] != '\0'; i++)
        {
            if (string[i] == ' ' && string[i + 1] == ' ')
            {
                invalid = 1;
                printf("The text cannot contain double spaces\n");
            }

            if (!isalpha(string[i]))
            {
                string[i] = 'X';
            }
        }

        if (i > max_length)
        {
            printf("The entered text has more than [%d] characters.\n", max_length);
            invalid = 1;
        }

        if (invalid == 1)
        {
            printf("Please write a different text: \n");
        }

    } while (invalid == 1);

    return true;
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