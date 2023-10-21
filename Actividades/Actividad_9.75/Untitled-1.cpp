#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>

void replaceAccentedChars(char string[]) {
    for (int i = 0; string[i] != '\0'; i++) {
        if (string[i] == 'Á') {
            string[i] = 'A';
        } else if (string[i] == 'É') {
            string[i] = 'E';
        } else if (string[i] == 'Í') {
            string[i] = 'I';
        } else if (string[i] == 'Ó') {
            string[i] = 'O';
        } else if (string[i] == 'Ú') {
            string[i] = 'U';
        }
    }
}

bool validateString(char string[], int max_length) {
    int invalid = 0;
    int i;
    int string_length = 0;

    do {
        invalid = 0;
        printf("Enter a string: ");
        fgets(string, max_length, stdin);

        // Remove trailing newline character, if present
        string_length = strlen(string);
        if (string_length > 0 && string[string_length - 1] == '\n') {
            string[string_length - 1] = '\0';
        }

        replaceAccentedChars(string);

        if (string[0] == ' ') {
            invalid = 1;
        }

        for (i = 0; string[i] != '\0'; i++) {
            if (string[i] == ' ' && string[i + 1] == ' ') {
                invalid = 1;
                printf("The text cannot contain double spaces\n");
            }

            if (!isalpha(string[i])) {
                string[i] = 'X'; // Replace non-alphabetic characters with 'X'
            }
        }

        if (i > max_length) {
            printf("The entered text has more than [%d] characters.\n", max_length);
            invalid = 1;
        }

        if (invalid == 1) {
            printf("Please write a different text: \n");
        }

    } while (invalid == 1);

    return true;
}

int main() {
    char inputString[256] = "ÁÁÁÁÉÉÉÉÉÍÍÍÍÍ"; // Adjust the size as needed
    int maxLength = 255;  // Adjust the maximum length as needed

    if (validateString(inputString, maxLength)) {
        printf("Valid input: %s\n", inputString);
    }

    return 0;
}
