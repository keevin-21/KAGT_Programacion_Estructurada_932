/*

*/

#include "kewvyValidates.h"

typedef struct _students
{
    int status;
    int enrolment; // matricula
    char fatherLastname[30];
    char motherLastname[30];
    char name[30];
    int age;
    int gender;
} Tstudents;

char femaleNames[][20] = {"María", "Ana", "Laura", "Isabel", "Carolina", "Gabriela", "Elena", "Patricia", "Valentina", "Camila", "Sofía", "Adriana", "Raquel", "Julia", "Clara", "Beatriz", "Lucía", "Lorena", "Natalia", "Aurora"};
char maleNames[][20] = {"Alejandro", "Javier", "Andrés", "Luis", "Daniel", "Martín", "Sergio", "Diego", "Eduardo", "Francisco", "Carlos", "Juan", "Rafael", "Marco", "Héctor", "Guillermo", "José", "Antonio", "Pedro", "Miguel"};
char lastnames[][20] = {"Pérez", "González", "Rodríguez", "López", "Martínez", "Sánchez", "Ramírez", "Torres", "Fernández", "García", "Díaz", "Cruz", "Romero", "Hernández", "Álvarez", "Moreno", "Vargas", "Suárez", "Jiménez", "Mendoza"};

int msges();
void menu();
Tstudents autoDataReg();
Tstudents manualDataReg();
int linearSearch(Tstudents array[], int size, int searchNumber);
int binarySearch(Tstudents array[], int left, int right, int number);
int sortVector(Tstudents array[], int size);
void printRegister(Tstudents array[], int size);

int main()
{
    srand(time(NULL));
    menu();
    return 0;
}

int msges()
{
    int option;

    printf("MENU");
    printf("\n\t1.- Fill Automatic Register (10)");
    printf("\n\t2.- Fill Manual Register");
    printf("\n\t3.- Remove a Register");
    printf("\n\t4.- Sort Register");
    printf("\n\t0.- Exit\n\n");
    printf("Select an option: ");
    option = validate(0, 6);
    return option;
}

void menu()
{
    int option, sorted, i, remove, search, found;
    Tstudents studentArray[500], temp;
    i = 0; // Start registers in zero
    do
    {
        option = msges();
        system("CLS");

        switch (option)
        {

        case 1:
            sorted = 0; // Verify if it is sorted or not

            for (int j = 0; j < 10; j++)
            {
                temp = autoDataReg();
                while (linearSearch(studentArray, i, temp.enrolment) != -1)
                {
                    temp.enrolment = randomNumber(300000, 399999);
                }
                studentArray[i++] = temp;
            }
            break;

        case 2:
            sorted = 0;
            temp = manualDataReg();

            while (linearSearch(studentArray, i, temp.enrolment) != -1)
            {
                printf("Repeated enrolment - Please enter a different one.");
                temp.enrolment = validate(300000, 399999);
            }
            studentArray[i++] = temp;
            break;

        case 3:
            printf("Enrolment to be removed:");
            remove = validate(0, 500);
            if (studentArray[remove].enrolment == 0)
            {
                printf("Enrolment already removed.");
            }
            else
            {
                printf("Now the enrolment %i has been removed.", remove);
            }
            break;

        case 4:
            printf("Search enrolment: ");
            search = validate(300000, 399999);

            if (sorted == 0)
            {
                found = linearSearch(studentArray, i, search);
            }
            else
            {
                found = binarySearch(studentArray, 300000, 399999, search);
            }

            if (found != -1)
            {
                printf("Enrolment found in register number %i.", found);
            }
            else
            {
                printf("Enrolment not found.");
            }
            break;

        case 5:
            if (sorted == 0)
            {
                sorted = sortVector(studentArray, i);
                printf("Register is now sorted.");
            }
            else
            {
                printf("Register already sorted.");
            }
            break;

        case 6:
            printRegister(studentArray, i);
            break;

        case 0:
            return;
        default:
            printf("Error - Please select a valid option.");
            break;
        }
        system("PAUSE");
    } while (option != 0);
}

Tstudents manualDataReg()
{
    Tstudents student;
    // system("CLS");

    printf("\nStatus:\n");
    student.status = validate(0, 1);
    printf("\nEnrolment:\n");
    student.enrolment = validate(300000, 399999);
    printf("\nFather Lastname:\n");
    gets(student.fatherLastname);
    printf("\nMother Lastname:\n");
    gets(student.motherLastname);
    printf("\nName:\n");
    gets(student.name);
    printf("\nAge:\n");
    student.age = validate(17, 30);
    printf("\nGender:\n");
    student.gender = validate(0, 1);
    return student;
}

Tstudents autoDataReg()
{
    Tstudents student;
    student.status = randomNumber(0, 1);

    student.enrolment = randomNumber(300000, 399999);

    strcpy(student.fatherLastname, lastnames[randomNumber(0, 19)]);
    strcpy(student.motherLastname, lastnames[randomNumber(0, 19)]);

    if (randomNumber(0, 1) == 1)
    {
        strcpy(student.name, maleNames[randomNumber(0, 19)]);
        student.gender = 1;
    }
    else
    {
        strcpy(student.name, femaleNames[randomNumber(0, 19)]);
        student.gender = 0;
    }

    student.age = randomNumber(17, 30);
    
    return student;
}

int linearSearch(Tstudents array[], int size, int searchNumber)
{
    int i;

    for (i = 0; i < size; i++)
    {
        if (array[i].enrolment == searchNumber)
        {
            return i;
        }
    }
    return -1;
}

int binarySearch(Tstudents array[], int left, int right, int number)
{
    while (left <= right)
    {
        int medium = left + (right - left) / 2;

        // Check if number is present at mid
        if (array[medium].enrolment == number)
            return medium;

        // If number greater, ignore left half
        if (array[medium].enrolment < number)
            left = medium + 1;

        // If number is smaller, ignore right half
        else
            right = medium - 1;
    }

    // If we reach here, then element was not present
    return -1;
}

int sortVector(Tstudents array[], int size)
{
    Tstudents temp;

    for (int i = 0; i < size - 1; i++)
    {
        for (int j = i + 1; j < size; j++)
        {
            if (array[j].enrolment < array[i].enrolment)
            {
                temp = array[i];
                array[i] = array[j];
                array[j] = temp;
            }
        }
    }
    return 1;
}

void printRegister(Tstudents array[], int size)
{
    int i;

    printf("STATUS  ENROLMENT   NAME                           FATHER LN                            MOTHER LN                            AGE   GENDER  \n\n");
    for (i = 0; i < size; i++)
    {
        if (array[i].status == 1)
        {
            printf("%-3d   %-9d   %-30s   %-30s   %-30s   %-4d   \n", array[i].status, array[i].enrolment, array[i].name, array[i].fatherLastname, array[i].motherLastname, array[i].age, array[i].gender);
        }
    }
}