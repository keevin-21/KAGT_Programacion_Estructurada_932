#include<stdio.h>

int main()
{
    int cal1, cal2, cal3, cal4, cal5, menor;
    float prom;

    printf("Calificacion del primer examen: ");
    scanf("%i", &cal1);
    printf("Calificacion del segundo examen: ");
    scanf("%i", &cal2);
    printf("Calificacion del tercer examen: ");
    scanf("%i", &cal3);
    printf("Calificacion del cuarto examen: ");
    scanf("%i", &cal4);
    printf("Calificacion del quinto examen: ");
    scanf("%i", &cal5);

    menor = cal1;

    if (cal2 < menor)
    {
        menor = cal2;
    }
    if (cal3 < menor)
    {
        menor = cal3;
    }
    if (cal4 < menor)
    {
        menor = cal4;
    }
    if (cal5 < menor)
    {
        menor = cal5;
    }

    prom = (cal1 + cal2 + cal3 + cal4 + cal5 - menor) / 4;

    printf("%.2f", prom);
}