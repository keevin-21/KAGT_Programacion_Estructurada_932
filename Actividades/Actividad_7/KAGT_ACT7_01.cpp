/*
Kevin Alejandro Gonzalez Torres - 372354

Creado el: 19 de Septiembre del 2023 / Modificado el 24 de Septiembre del 2023

Actividad 7 - Parte 1:
    1.- This function takes a string as input and converts it to uppercase.

    2.- This function takes a string as input and reverses it.

    3.- This function takes a string as input and displays each character of the string one by one in uppercase.

    4.- This function takes a string as input and displays each character of the reversed string one by one in uppercase.

    5.- This function takes a string as input, converts it to uppercase, and displays it in a "stair" pattern.

    6.- This function takes a string as input, converts it to uppercase, reverses it, and displays the reversed string in a "stair" pattern.

    7.- It takes a string as input, converts it to uppercase, and displays it in a "stair" pattern starting with the first letter of the string.

    8.- It takes a string as input, converts it to uppercase, reverses ir, and displays it in a "stair" pattern starting with the first letter of the string.

    9.-

    10.-
*/

#include <stdio.h>
#include <string.h>

void menu(char *);
char *uppercaseString(char *);
char *reversedString(char *);
void lettbylettString(char *);
void lettbylettReverseString(char *);
void ladderString(char *);
void ladderReverseString(char *);
void ladderString_2(char *);
void ladderReverseString_2(char *);
void consonantString(char *);
void vocalString(char *);

int main()
{
    char string[100];

    printf("Enter the string: ");
    fflush(stdin);
    gets(string);
    menu(string);
    return 0;
}

void menu(char string[])
{
    int option;

    printf("MENU:\n");
    printf("\t1.- Uppercase String\n\t2.- Reverse String\n\t3.- Uppercase letter by letter\n\t4.- Reverse letter by letter\n\t5.- Ladder string\n");
    printf("\t6.- Ladder reverse string\n\t7.-Ladder string *\n\t8.- Ladder reverse string *\n\t9.- \n\t10.- \n");
    printf("Select an option: ");
    scanf("%i", &option);

    switch (option)
    {
    case 1:
        uppercaseString(string);
        printf("Entered uppercase string is: %s", string);
        break;
    case 2:
        reversedString(string);
        printf("Entered reverse string is: %s", string);
        break;
    case 3:
        lettbylettString(string);
        break;
    case 4:
        lettbylettReverseString(string);
        break;
    case 5:
        ladderString(string);
        break;
    case 6:
        ladderReverseString(string);
        break;
    case 7:
        ladderString_2(string);
        break;
    case 8:
        ladderReverseString_2(string);
        break;
    case 9:
        consonantString(string);
        break;
    case 10:
        vocalString(string);
        break;
    default:
        break;
    }
}

char *uppercaseString(char string[])
{
    int i;

    for (i = 0; string[i] != '\0'; i++)
    {
        if (string[i] >= 'a' && string[i] <= 'z')
        {
            string[i] -= 32;
        }
    }

    return (string);
}

char *reversedString(char string[])
{
    int length = 0, reverse = 0, i = 0;
    char temp = 0;

    while (string[length++] != '\0')
        ;

    length--;
    length--;

    while (reverse < length)
    {
        temp = string[reverse];
        string[reverse] = string[length];
        string[length] = temp;
        reverse++;
        length--;
    }
    uppercaseString(string);
    return (string);
}

void lettbylettString(char string[])
{
    int i;

    printf("Entered string letter by letter is:");

    uppercaseString(string);

    for (i = 0; string[i] != '\0'; i++)
    {
        printf("%c\n", string[i]);
    }
}

void lettbylettReverseString(char string[])
{
    int i = 0;
    printf("Entered reverse string letter by letter is:");

    reversedString(string);
    uppercaseString(string);
    for (i = 0; string[i] != '\0'; i++)
    {
        printf("%c\n", string[i]);
    }
}

void ladderString(char string[])
{
    int length = 0;

    uppercaseString(string);

    printf("The string in \"stair\" order is: ");
    while (string[length++] != '\0')
        ;

    for (int i = 0; i < length; i++)
    {
        for (int j = 0; j < length - i; j++)
        {
            printf("%c", string[j]);
        }
        printf("\n");
    }
}

void ladderReverseString(char string[])
{
    int length = 0;

    uppercaseString(string);
    reversedString(string);

    printf("The reverse string in \"stair\" order is: ");
    while (string[length++] != '\0')
        ;

    for (int i = 0; i < length; i++)
    {
        for (int j = 0; j < length - i; j++)
        {
            printf("%c", string[j]);
        }
        printf("\n");
    }
}

void ladderString_2(char string[])
{
    int i, j;
    int length = 0;
    uppercaseString(string);

    while (string[length++] != '\0')
        ;
    printf("The string in \"stair\" order is: ");
    puts(string);
    while (length > 1)
    {
        for (int i = 0; i < length - 1; i++)
        {
            string[i] = string[i + 1];
        }
        length--;
        string[length] = '\0';
        printf("%s\n", string);
    }
}

void ladderReverseString_2(char string[])
{
    int i, j;
    int length = 0;
    uppercaseString(string);
    reversedString(string);

    while (string[length++] != '\0')
        ;
    printf("The reverse string in \"stair\" order is: ");
    puts(string);
    while (length > 1)
    {
        for (int i = 0; i < length - 1; i++)
        {
            string[i] = string[i + 1];
        }
        length--;
        string[length] = '\0';
        printf("%s\n", string);
    }
}

void consonantString(char string[])
{
    int i;

    uppercaseString(string);
    for (i = 0; string[i] != '\0'; i++)
    {
        char character = string[i];

        if ((character >= 'A' && character <= 'Z') && (character != 'A' && character != 'E' && character != 'I' && character != 'O' && character != 'U'))
        {
            printf("%c", string[i]);
        }
    }
}

void vocalString(char string[])
{
    int i;

    uppercaseString(string);
    for (i = 0; string[i] != '\0'; i++)
    {
        char character = string[i];

        if ((character >= 'A' && character <= 'Z') && (character == 'A' || character == 'E' || character == 'I' || character == 'O' || character == 'U'))
        {
            printf("%c", string[i]);
        }
    }
}