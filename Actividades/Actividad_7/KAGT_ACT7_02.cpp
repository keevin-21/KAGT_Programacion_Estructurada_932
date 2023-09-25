/*
Kevin Alejandro Gonzalez Torres - 372354

Creado el: 19 de Septiembre del 2023 / Modificado el 24 de Septiembre del 2023

Actividad 7 - Parte 1:
    1.- This function takes a string as input and converts it to uppercase.

    2.- This function takes a string as input and converts all uppercase characters in the string to lowercase.
    
    3.- This function capitalizes the first letter of each word in the input string.

    4.- This function calculates and returns the length (number of characters) of the input string.

    5.- This function reverses the characters in the input string in-place.

    6.- This function removes spaces (' ') from the input string in-place.

    7.- This function removes all non-alphabetical characters (except spaces) from the input string in-place.

    8.- 

    9.- This function checks if the input string is a palindrome (reads the same forwards and backwards).
*/

#include <stdio.h>
#include <string.h>

// Function prototypes
void menu(char *);
char *uppercaseString(char *);
void lowercaseString(char *);
void capitalString(char *);
int lengthString(char *);
char *reversedString(char *);
void noSpacesString(char *);
void alphabeticalString(char *);
void manyFunctions(char *);
int isPalindrome(char *);

int main()
{
    char string[100];

    printf("Enter the string: ");
    gets(string);
    menu(string);
    return 0;
}

void menu(char string[])
{
    int option;

    printf("MENU:\n");
    printf("\t1.- Uppercase\n\t2.- Lowercase\n\t3.- Capitalized\n\t4.- Length\n\t5.- Reversed\n");
    printf("\t6.- Non spaces\n\t7.- Alphabetical w/ spaces\n\t8.- Many functions\n\t9.- Palindrome\n");
    printf("Select an option: ");
    scanf("%i", &option);

    switch (option)
    {
    case 1:
        uppercaseString(string);
        printf("Entered uppercase string is: %s\n", string);
        break;
    case 2:
        lowercaseString(string);
        printf("Entered lowercase string is: %s\n", string);
        break;
    case 3:
        capitalString(string);
        printf("Entered string capitalized is: %s\n", string);
        break;
    case 4:
        printf("Number of characters in %s string: %d\n", string, lengthString(string));
        break;
    case 5:
        reversedString(string);
        printf("Entered reversed string is: %s\n", string);
        break;
    case 6:
        noSpacesString(string);
        printf("String with spaces removed: %s\n", string);
        break;
    case 7:
        alphabeticalString(string);
        printf("Alphabetical string with spaces: %s\n", string);
        break;
    case 8:
        manyFunctions(string);
        break;
    case 9:
        if (isPalindrome(string))
        {
            printf("The string is a palindrome.\n");
        }
        else
        {
            printf("The string is not a palindrome.\n");
        }
        break;
    default:
        printf("Invalid option\n");
        break;
    }
}

char *uppercaseString(char string[])
{
    for (int i = 0; string[i] != '\0'; i++)
    {
        if (string[i] >= 'a' && string[i] <= 'z')
        {
            string[i] -= 32;
        }
    }

    return string;
}

void lowercaseString(char string[])
{
    for (int i = 0; string[i] != '\0'; i++)
    {
        if (string[i] >= 'A' && string[i] <= 'Z')
        {
            string[i] += 32;
        }
    }
}

void capitalString(char string[])
{
    if (string[0] >= 'a' && string[0] <= 'z')
    {
        string[0] -= 32;
    }

    for (int i = 1; string[i] != '\0'; i++)
    {
        if (string[i - 1] == ' ')
        {
            if (string[i] >= 'a' && string[i] <= 'z')
            {
                string[i] -= 32;
            }
        }
        else
        {
            if (string[i] >= 'A' && string[i] <= 'Z')
            {
                string[i] += 32;
            }
        }
    }
}

int lengthString(char string[])
{
    int length = 0;
    while (string[length] != '\0')
    {
        length++;
    }
    return length;
}

char *reversedString(char string[])
{
    int length = strlen(string);
    int reverse = 0;
    char temp;

    for (int i = 0; i < length / 2; i++)
    {
        temp = string[i];
        string[i] = string[length - i - 1];
        string[length - i - 1] = temp;
    }

    return string;
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

    string[no_space_count] = '\0'; // Null-terminate the new string
}

void alphabeticalString(char string[])
{
    int i, asd = 0;
    for (i = 0; string[i] != '\0'; i++)
    {
        if ((string[i] >= 'a' && string[i] <= 'z') || string[i] == ' ')
        {
            string[asd++] = string[i];
        }
    }
    string[asd] = '\0'; // Null-terminate the new string
}

void manyFunctions(char string[])
{
    uppercaseString(string);
    printf("Entered uppercase string is: %s\n", string);
    lowercaseString(string);
    printf("Entered lowercase string is: %s\n", string);
    capitalString(string);
    printf("Entered string capitalized is: %s\n", string);
    noSpacesString(string);
    printf("String with spaces removed: %s\n", string);
    reversedString(string);
    printf("Entered reversed string is: %s\n", string);
}
int isPalindrome(char string[])
{
    noSpacesString(string);
    int length = lengthString(string);
    int left = 0;
    int right = length - 1;

    while (left < right)
    {
        if (string[left] != string[right])
        {
            return 0; // Not a palindrome
        }
        left++;
        right--;
    }

    return 1; // Palindrome
}
