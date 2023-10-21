#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>

// Función para reemplazar caracteres especiales por 'X'
void sanitizeString(char string[]) {
    for (int i = 0; string[i] != '\0'; i++) {
        if (!isalpha(string[i])) {
            string[i] = 'X';
        }
    }
}

bool validateString(char string[], int max_length) {
    int invalid = 0;
    int i;

    do {
        invalid = 0;
        fflush(stdin);
        gets(string);

        for (i = 0; string[i] != '\0'; i++) {
            string[i] = toupper(string[i]);
        }

        if (string[0] == ' ') {
            invalid = 1;
        }

        // Llama a la función para reemplazar caracteres especiales
        sanitizeString(string);

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
    char input[100]; // Puedes ajustar el tamaño según tus necesidades

    printf("Enter a valid string (only letters, uppercase or lowercase, and special characters will be replaced by 'X'):\n");
    
    if (validateString(input, 99)) {
        printf("Valid input: %s\n", input);
    }

    return 0;
}
