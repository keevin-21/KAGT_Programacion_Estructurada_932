#include<stdio.h>

int main()
{
    float num1, num2;
    int opt;

    printf("Introduce un numero: ");
    scanf("%f", &num1);
    printf("Introduce otro numero: ");
    scanf("%f", &num2);

    printf("Operacion a realizar\n");
    printf("\t1.- Suma\n\t2.- Resta\n\t3.- Multiplicacion\n\t4.- Division\n");
    printf("Selecciona tu opcion: ");
    scanf("%i", &opt);

    if (opt==1)
    {

        printf("La suma de los dos numeros es: %.2f", num1+num2);
    }
    else
    {
        if (opt==2)
        {
            printf("La resta de los dos numeros es: %.2f", num1-num2);
        }
        else
        {
            if (opt==3)
            {
                printf("La multiplicacion de los dos numeros es: %.2f", num1*num2);
            }
            else
            {
                if (opt==4)
                {
                    if (num2 != 0)
                    {
                        printf("La division de los dos numeros es: %.2f", num1/num2);
                    }
                    else
                    {
                        printf("ERROR - NO SE PUEDE DIVIDIR ENTRE");
                    }
                }
                
            }
            
        }
        
    }
}