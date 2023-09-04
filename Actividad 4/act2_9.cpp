#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main()
{
    int player, computer;
    
    srand(time(NULL));
    computer = rand() % 3 + 1;
    printf("Respuesta de la computadora generada\n\n");
    printf("Selecciona tu opcion\n\t1.- Piedra\n\t2.- Papel\n\t3.-Tijeras\n\n");
    printf("Opcion: ");
    scanf("%i", &player);
    
    switch (player-computer)
    {
    case 0:
        printf("Empate");
        break;
    case -1: case 2:
        printf("Ganaste!");
        break;
    case -2: case 1:
        printf("Perdiste!");
        break;
    default:
        printf("Error - Selecciona una opcion valida");
        break;
    }
}
