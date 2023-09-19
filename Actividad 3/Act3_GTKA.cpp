#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void menu();
void grades();
void ifRSP();
void switchRSP();
void higherNumber();
void middleNumber();
void ascendingNumbers();
void horoscope();

int main()
{
    menu();
    return 0;
}

void menu()
{
    int option;
    printf("MENU:\n");
    printf("\t1.- Calificaciones\n");
    printf("\t2.- Piedra, papel o tijera (if)\n");
    printf("\t3.- Piedra, papel o tijera (switch)\n");
    printf("\t4.- Numero mayor\n");
    printf("\t5.- Numero medio\n");
    printf("\t6.- Orden ascendente\n");
    printf("\t7.- Horoscopo\n");
    printf("\t0.- SALIR \n");
    printf("ESCOGE UNA OPCION: ");
    scanf("%i", &option);

    switch (option)
    {
    case 1:
        grades();
        break;

    case 2:
        ifRSP();
        break;

    case 3:
        switchRSP();
        break;

    case 4:
        higherNumber();
        break;

    case 5:
        middleNumber();
        break;

    case 6:
        ascendingNumbers();
        break;

    case 7:
        horoscope();
        break;

    case 0:

        break;
    default:
        printf("ERROR - OPCION NO VALIDA");
        break;
    }
}

void grades()
{
    float cal1, cal2, cal3;
    float promedio;

    printf("Ingrese la primera calificación: ");
    scanf("%f", &cal1);
    printf("Ingrese la segunda calificación: ");
    scanf("%f", &cal2);
    printf("Ingrese la tercera calificación: ");
    scanf("%f", &cal3);

    promedio = (cal1 + cal2 + cal3) / 3;

    if (promedio < 80)
    {
        if (promedio < 60)
        {
            if (promedio < 30)
            {
                printf("Calificación: Repetir\n");
            }
            else
            {
                printf("Calificación: Extraordinario\n");
            }
        }
        else
        {
            printf("Calificación: Suficiente\n");
        }
    }
    else
    {
        if (promedio < 98)
        {
            if (promedio < 90)
            {
                printf("Calificación: Bien\n");
            }
            else
            {
                printf("Calificación: Muy Bien\n");
            }
        }
        else
        {
            printf("Calificación: Excelente\n");
        }
    }
}

void ifRSP()
{
    int jugador, computadora;
    int resultado;

    srand(time(NULL));

    computadora = rand() % 3;
start:
    printf("Juguemos al Piedra, Papel o Tijera:\n");
    printf("0 - Piedra\n");
    printf("1 - Papel\n");
    printf("2 - Tijera\n");
    printf("Tu elección: ");
    scanf("%i", &jugador);

    if (jugador < 0 || jugador > 2)
    {
        printf("Selección no válida. Por favor, elige 0, 1 o 2.\n");
        goto start;
    }

    printf("La computadora elige: %i\n", computadora);

    if (jugador == computadora)
    {
        resultado = 0;
    }
    else if ((jugador == 0 && computadora == 2) || (jugador == 1 && computadora == 0) || (jugador == 2 && computadora == 1))
    {
        resultado = 1;
    }
    else
    {
        resultado = -1;
    }

    if (resultado == 0)
    {
        printf("¡Empate!\n");
    }
    else if (resultado == 1)
    {
        printf("¡Ganaste!\n");
    }
    else
    {
        printf("¡La computadora gana!\n");
    }
}

void switchRSP()
{
    int player, computer;

    srand(time(NULL));
    computer = rand() % 3 + 1;
    printf("Respuesta de la computadora generada\n\n");
    printf("Selecciona tu opcion\n\t1.- Piedra\n\t2.- Papel\n\t3.-Tijeras\n\n");
    printf("Opcion: ");
    scanf("%i", &player);

    switch (player - computer)
    {
    case 0:
        printf("Empate");
        break;
    case -1:
    case 2:
        printf("Ganaste!");
        break;
    case -2:
    case 1:
        printf("Perdiste!");
        break;
    default:
        printf("Error - Selecciona una opcion valida");
        break;
    }
}

void higherNumber()
{
    int num1, num2, num3;

    printf("Ingrese el primer número: ");
    scanf("%i", &num1);

    printf("Ingrese el segundo número: ");
    scanf("%i", &num2);

    printf("Ingrese el tercer número: ");
    scanf("%i", &num3);

    if (num1 >= num2 && num1 >= num3)
    {
        printf("El primer número (%i) es el mayor.\n", num1);
    }
    else if (num2 >= num1 && num2 >= num3)
    {
        printf("El segundo número (%i) es el mayor.\n", num2);
    }
    else
    {
        printf("El tercer número (%i) es el mayor.\n", num3);
    }
}

void middleNumber()
{
    int num1, num2, num3;

    printf("Ingrese el primer número: ");
    scanf("%i", &num1);

    printf("Ingrese el segundo número: ");
    scanf("%i", &num2);

    printf("Ingrese el tercer número: ");
    scanf("%i", &num3);

    if ((num1 >= num2 && num1 <= num3) || (num1 <= num2 && num1 >= num3))
    {
        printf("El número del medio es: %i\n", num1);
    }
    else if ((num2 >= num1 && num2 <= num3) || (num2 <= num1 && num2 >= num3))
    {
        printf("El número del medio es: %i\n", num2);
    }
    else
    {
        printf("El número del medio es: %i\n", num3);
    }
}

void ascendingNumbers()
{
    int num1, num2, num3;

    printf("Ingrese el primer número: ");
    scanf("%i", &num1);

    printf("Ingrese el segundo número: ");
    scanf("%i", &num2);

    printf("Ingrese el tercer número: ");
    scanf("%i", &num3);

    if (num1 <= num2 && num1 <= num3)
    {
        if (num2 <= num3)
        {
            printf("Los números en forma ascendente son: %i, %i, %i\n", num1, num2, num3);
        }
        else
        {
            printf("Los números en forma ascendente son: %i, %i, %i\n", num1, num3, num2);
        }
    }
    else if (num2 <= num1 && num2 <= num3)
    {
        if (num1 <= num3)
        {
            printf("Los números en forma ascendente son: %i, %i, %i\n", num2, num1, num3);
        }
        else
        {
            printf("Los números en forma ascendente son: %i, %i, %i\n", num2, num3, num1);
        }
    }
    else
    {
        if (num1 <= num2)
        {
            printf("Los números en forma ascendente son: %i, %i, %i\n", num3, num1, num2);
        }
        else
        {
            printf("Los números en forma ascendente son: %i, %i, %i\n", num3, num2, num1);
        }
    }
}

void horoscope()
{
    int mes, dia;
    printf("Escribe (en numero de un solo digito) tu mes de nacimiento: ");
    scanf("%i", &mes);
    printf("Escribe (en un numero de dos digito) tu dia de nacimiento: ");
    scanf("%i", &dia);

    if ((mes == 3 && dia >= 21) || (mes == 4 && dia <= 19))
    {
        printf("Aries\n“Ser el Mejor y el Líder”.\nAries se encuentra en un momento de renovación total y su liderazgo será clave para obtener lo que desea. Su labor humanitaria será importante para todos los signos.\n");
    }
    else
    if ((mes == 4 && dia >= 20) || (mes == 5 && dia <= 20))
    {
        printf("Tauro\n“Determinación y Poder”.\nTauro se encuentra en un momento de reinventarse y sacar lo mejor de sí mismo. La determinación y el poder de decisión serán fundamentales para enfrentar los desafíos y alcanzar el éxito.\n");
    }
    else
    if ((mes == 5 && dia >= 21) || (mes == 6 && dia <= 20))
    {
        printf("Géminis\n“Felicidad y Prosperidad”.\nGéminis tendrá buena suerte de su lado y deberá aprovechar esta racha de abundancia. Es importante hacer cambios necesarios en la vida para brillar aún más y tener cuidado con personas que buscan robar su energía.\n");
    }
    else
    if ((mes == 6 && dia >= 21) || (mes == 7 && dia <= 22))
    {
        printf("Cáncer\n“Madurez y Metamorfosis”.\nCáncer debe aceptar sus errores y comenzar el camino hacia el éxito. La transformación interna será fundamental para dejar atrás los miedos y sabotajes a la felicidad.\n");
    }
    else
    if ((mes == 7 && dia >= 23) || (mes == 8 && dia <= 22))
    {
        printf("Leo\n“Autocontrol y Paciencia”.\nLeo debe buscar la madurez y aprender a esperar. Este es un momento de aprendizaje y de valorar a las personas que lo rodean.\n");
    }
    else
    if ((mes == 8 && dia >= 23) || (mes == 9 && dia <= 22))
    {
        printf("Virgo\n“Pienso y Después Actúo”.\nVirgo debe analizar antes de tomar decisiones radicales en la vida. Consultar con personas de confianza será de gran ayuda para superar las adversidades.\n");
    }
    else
    if ((mes == 9 && dia >= 23) || (mes == 10 && dia <= 22))
    {
        printf("Libra\n“Buscar la Balanza en tu Vida”.\nLibra debe equilibrar su vida y trabajar en su salud y estado psíquico. La meditación y el ejercicio serán clave para mantener la calma y tomar decisiones acertadas.\n");
    }
    else 
    if ((mes == 10 && dia >= 23) || (mes == 11 && dia <= 21))
    {
        printf("Escorpio\n“La Decisión de Enfrentar tus Retos en la Vida”.\nEscorpión se enfrentará a momentos difíciles en lo personal, pero debe tener el carácter necesario para enfrentarlos. Evitar caer en problemas como las adicciones y las deudas será fundamental.\n");
    }
    else
    if ((mes == 11 && dia >= 22) || (mes == 12 && dia <= 21))
    {
        printf("Sagitario\n“Tener el Triunfo”.\nSagitario tiene el éxito a su alcance y debe confiar en su intuición. Será un momento de prosperidad y ayudar a los demás.\n");
    }
    else
    if ((mes == 12 && dia >= 22) || (mes == 1 && dia <= 19))
    {
        printf("Capricornio\n“Reinventarse y Dejar los Rencores Atrás”.\nCapricornio experimentará un crecimiento en todos los aspectos de su vida, especialmente en lo sentimental. Habrá oportunidades de mejora laboral y un cambio positivo en lo personal.\n");
    }
    else
    if ((mes == 1 && dia >= 20) || (mes == 2 && dia <= 18))
    {
        printf("Acuario\n“Comprender lo que te Pasa en tu Vida”.\nAcuario debe valorar lo bueno que lo rodea y no dejarse influenciar por intereses económicos. Será una semana de madurez y defensa de la felicidad propia.\n");
    }
    else
    if ((mes == 2 && dia >= 19) || (mes == 3 && dia <= 20))
    {
        printf("Piscis\n“Tener la Seguridad de tus Acciones”.\nPiscis debe dejar atrás la indecisión y tener seguridad en sus acciones. El crecimiento económico y superar las inseguridades serán temas importantes, especialmente en el amor.\n");
    }
    else
    {
        printf("Fecha de nacimiento no válida.\n");
    }
}