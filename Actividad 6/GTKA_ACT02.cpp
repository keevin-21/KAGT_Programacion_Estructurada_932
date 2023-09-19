/*
Kevin Alejandro Gonzalez Torres - 372354

Creado el: 16 de Septiembre del 2023 / Modificado el 17 de Septiembre del 2023

Actividad 6 - Parte 2:
    1.- En esta función, el programa pedirá las notas de 40 estudiantes, cada estudiante tendrá 5
        notas como entrada. Si la media es inferior a 50, no tendrán derecho a realizar el examen.

    2.- En esta función, el programa imprimirá las tablas de multiplicar del 1 al 10, hará una
        pausa cada tabla y limpiará la pantalla.
    
    3.- En esta función, el programa calculará la suma de los números y la media aritmética en
        un rango de n números dados por el usuario.

    4.- En esta función, el programa pedirá el peso de cada pasajero con un máximo de %15 de sobrepeso,
        mostrará la media de peso y cuál de las 2 condiciones se cumplió

    5.- En esta función, el programa basado en sus 3 exámenes parciales, calcular el promedio y en base a su promedio
        final, un mensaje debe ser enviado al estudiante a repetir el tema, pasar o retirarse temporalmente.
*/

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

void displayMenu();
int getMenuChoice();

void calculateGrade();
void generateMultiplicationTable();
void calculateStatistics();
void calculateAverageWeight();
void asig_grade();

int getInput(char message[], int min, int max);
int askToExit();

int main() {
    displayMenu();
    return 0;
}

void displayMenu() {
    int choice;
    do {
        choice = getMenuChoice();
        switch (choice) {
            case 1:
                calculateGrade();
                break;
            case 2:
                generateMultiplicationTable();
                break;
            case 3:
                calculateStatistics();
                break;
            case 4:
                calculateAverageWeight();
                break;
            case 5:
                asig_grade();
                break;
        }
    } while (choice != 0);
}

int getMenuChoice() {
    int choice;
    system("CLS");
    printf("C U S T O M   M E N U\n");
    printf("1.- Calculate Student Grade\n");
    printf("2.- Generate Multiplication Table\n");
    printf("3.- Calculate Statistics\n");
    printf("4.- Calculate Average Tourist Weight\n");
    printf("5.- 3 Attemps grade\n");
    printf("0.- Exit\n");
    choice = getInput("Select an option: ", 0, 5);
    return choice;
}

void calculateGrade() {
    int score1, score2, score3, average, op;
    do {
        printf("STUDENT GRADE CALCULATOR\n");
        score1 = getInput("Enter the score for the first assignment: ", 0, 100);
        score2 = getInput("Enter the score for the second assignment: ", 0, 100);
        score3 = getInput("Enter the score for the third assignment: ", 0, 100);

        average = (score1 + score2 + score3) / 3;

        if (average >= 60) {
            printf("Passed with an average score of %d\n", average);
        } else {
            printf("Failed with an average score of %d\n", average);
        }

        op = askToExit();
    } while (op != 1);
}

void generateMultiplicationTable() {
    int i, j, result, op;
    do {
        for (i = 1; i <= 10; i++) {
            system("CLS");
            printf("MULTIPLICATION TABLE FOR %d\n", i);
            for (j = 1; j <= 10; j++) {
                result = i * j;
                printf("%d * %d = %d\n", i, j, result);
            }
        }
        op = askToExit();
    } while (op != 1);
}

void calculateStatistics() {
    int n, min, max, num, i, count, sum, op;
    float average;

    do {
        system("CLS");
        printf("STATISTICS CALCULATOR\n");
        n = getInput("Enter the number of values to analyze: ", 0, INT_MAX);
        min = getInput("Enter the minimum value: ", 0, INT_MAX);
        max = getInput("Enter the maximum value: ", 0, INT_MAX);

        for (i = 0, sum = 0, count = 0; i < n; i++) {
            num = getInput("Enter a number: ", 0, INT_MAX);
            if (num >= min && num <= max) {
                sum += num;
                count++;
            }
        }
        if (count > 0) {
            average = (float)sum / count;
            printf("Sum of valid values: %d\n", sum);
            printf("Average of valid values: %.2f\n", average);
        } else {
            printf("No valid numbers found in the range.\n");
        }
        op = askToExit();
    } while (op != 1);
}

void calculateAverageWeight() {
    int numTourists, op;
    float touristWeight, totalWeight, averageWeight;
    do {
        totalWeight = 0;

        numTourists = getInput("Enter the number of tourists on board: ", 0, INT_MAX);

        for (int i = 0; i < numTourists; i++) {
            touristWeight = getInput("Enter the weight of tourist %d: ", 0, INT_MAX);
            totalWeight += touristWeight;
        }

        averageWeight = totalWeight / numTourists;
        printf("Average tourist weight: %.2f kg\n", averageWeight);

        op = askToExit();
    } while (op != 1);
}

void asig_grade()
{
    int calp1, calp2, calp3, average, attempts, op;
    attempts = 0;

    do
    {
        printf("PARTIAL EXAMS\n");
        for (int i = 1; i <= 3; i++)
        {
            calp1 = getInput("Enter the score for the first partial exam: ", 0, 100);
            calp2 = getInput("Enter the score for the second partial exam: ", 0, 100);
            calp3 = getInput("Enter the score for the third partial exam: ", 0, 100);

            average = (calp1 + calp2 + calp3) / 3;

            if (average >= 60)
            {
                if (attempts < 3)
                {
                    printf("Passed with an average score of %d\n", average);
                    break;
                }
                else
                {
                    printf("You have been dismissed for reaching the maximum number of attempts.\n");
                    break;
                }
            }
            else
            {
                if (attempts < 3)
                {
                    printf("You must retake the course with an average score of %d\n", average);
                    attempts++;
                }
                else
                {
                    printf("You have been dismissed for reaching the maximum number of attempts.\n");
                    break;
                }
            }
        }

        op = askToExit();
    } while (op != 1);
}



int getInput(char message[], int min, int max) {
    int num;
    do {
        printf("%s", message);
        fflush(stdin);
        scanf("%d", &num);
    } while (num < min || num > max);
    return num;
}

int askToExit() {
    int op;
    printf("\nDo you want to exit?\n");
    printf("0.- No\n");
    printf("1.- Yes\n");
    op = getInput("Select an option: ", 0, 1);
    return op;
}
