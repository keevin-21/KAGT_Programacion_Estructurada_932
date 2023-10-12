#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void randomNameAndLastname()
{
    char names[][20] = {"Alejandro", "Javier", "Andrés", "Luis", "Daniel", "Martín", "Sergio", "Diego", "Eduardo", "Francisco", "Carlos", "Juan", "Rafael", "Marco", "Héctor", "Guillermo", "José", "Antonio", "Pedro", "Miguel"};
    char lastnames[][20] = {"García", "Martínez", "López", "Rodríguez", "Pérez", "Fernández", "González", "Ramírez", "Sánchez", "Torres"};

    srand(time(NULL));

    int randomNameIndex = rand() % (sizeof(names) / sizeof(names[0]));
    int randomFatherLastnameIndex = rand() % (sizeof(lastnames) / sizeof(lastnames[0]));
    int randomMotherLastnameIndex = rand() % (sizeof(lastnames) / sizeof(lastnames[0]));
    printf("Nombre aleatorio: %s %s %s\n", names[randomNameIndex], lastnames[randomFatherLastnameIndex], lastnames[randomMotherLastnameIndex]);
}

int main()
{
    randomNameAndLastname();
    return 0;
}
