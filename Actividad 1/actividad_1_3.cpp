/*
GONZALEZ TORRES KEVIN ALEJANDRO

10/23/2023 | 10/26/2023 

Algoritmo que lea 4 calificaciones de un alumno, calcular y desplegar
el promedio acompañado de la leyenda APROBADO o REPROBADO

KAGT_ACT1_3_932
*/

#include<stdio.h>

int main()
{
    int i, cal_1, cal_2, cal_3, cal_4;
    float prom;
    printf("Introduce las 4 calificaciones\n\n");
    
    printf("Calificacion #1: \n");
    scanf("%i", &cal_1);
    printf("Calificacion #2: \n");
    scanf("%i", &cal_2);
    printf("Calificacion #3: \n");
    scanf("%i", &cal_3);
    printf("Calificacion #4: \n");
    scanf("%i", &cal_4);

    prom = (cal_1, cal_2, cal_3, cal_4) / 4;
    printf("El promedio de las 4 calificaciones es: %f", prom);

    if (prom >= 60)
    {
        printf("APROBADO");
    }
    else
    {
        printf("REPROBADO");
    }
    
    return 0;
}