#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int jugador, computadora;
    int resultado;


    srand(time(NULL));

    computadora = rand() % 3;

    printf("Juguemos al Piedra, Papel o Tijera:\n");
    printf("0 - Piedra\n");
    printf("1 - Papel\n");
    printf("2 - Tijera\n");
    printf("Tu elección: ");
    scanf("%d", &jugador);

    if (jugador < 0 || jugador > 2) {
        printf("Selección no válida. Por favor, elige 0, 1 o 2.\n");
        return 1;
    }

    printf("La computadora elige: %d\n", computadora);

    if (jugador == computadora) {
        resultado = 0;
    } else if ((jugador == 0 && computadora == 2) || (jugador == 1 && computadora == 0) || (jugador == 2 && computadora == 1)) {
        resultado = 1;
    } else {
        resultado = -1;
    }

    if (resultado == 0) {
        printf("¡Empate!\n");
    } else if (resultado == 1) {
        printf("¡Ganaste!\n");
    } else {
        printf("¡La computadora gana!\n");
    }

    return 0;
}
