/*
GONZALEZ TORRES KEVIN ALEJANDRO

10/23/2023 | 10/26/2023 

Algoritmo que lea 3 calificaciones calcule el promedio del
alumno para desplegar un texto dependiendo la calificacion

KAGT_ACT1_6_932
*/

#include <stdio.h>

int main()
{
    int cal_1, cal_2, cal_3;
    float prom;
    printf("Introduce las 3 calificaciones\n\n");

    printf("Calificacion #1: \n");
    scanf("%i", &cal_1);
    printf("Calificacion #2: \n");
    scanf("%i", &cal_2);
    printf("Calificacion #3: \n");
    scanf("%i", &cal_3);

    prom = (cal_1 + cal_2 + cal_3) / 3;

    if (prom < 30)
    {
        printf("REPETIR");
    }
    else
    {
        if (prom < 60)
        {
            printf("EXTRAORDINARIO");
        }
        else
        {
            if (prom < 70)
            {
                printf("SUFICIENTE");
            }
            else
            {
                if (prom < 80)
                {
                    printf("REGULAR");
                }
                else
                {
                    if (prom < 90)
                    {
                        printf("BIEN");
                    }
                    else
                    {
                        if (prom < 98)
                        {
                            printf("MUY BIEN");
                        }
                        else
                        {
                            if (prom <= 100)
                            {
                                printf("EXCELENTE");
                            }
                            else
                            {
                                printf("ERROR EN PROMEDIO");
                            }
                        }
                    }
                }
            }
        }
    }
}
