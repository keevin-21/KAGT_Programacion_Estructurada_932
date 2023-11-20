#include "kewvyValidates.h"
#define MAX_REGISTERS 5000
#define ADD_REGISTERS 100

typedef int TKEY;

typedef struct _worker
{
    int status;
    TKEY id;
    char fatherLastname[30];
    char motherLastname[30];
    char name[30];
    char jobPosition[20];
    int age;
    char gender[10];
} Tworker;

int msges();
void menu();
Tworker autoDataReg();
void readTextFile(Tworker array[], int *size);
int linearSearch(Tworker array[], int size, int searchNumber);
int binarySearch(Tworker array[], int left, int right, int number);
int selectionSort(Tworker array[], int size);
void swap(Tworker array[], int i, int j);
int partition(Tworker array[], int low, int high);
void quicksort(Tworker array[], int low, int high);
void counterRegisters();
void printRegister(Tworker array[], int i);
void writeTextFile(Tworker array[], int size);
void writeDeletedTextFile(Tworker array[], int size);
void printTextFile(Tworker array[], int i);
void createBinaryFile(Tworker array[], int size);
int readBinaryFile(Tworker array[], int size);
void printDeleted(Tworker array[], int i);

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
    printf("\n\t1.- Add registers (100)");
    printf("\n\t2.- Edit register");
    printf("\n\t3.- Delete register");
    printf("\n\t4.- Search registers");
    printf("\n\t5.- Sort registers");
    printf("\n\t6.- Print registers");
    printf("\n\t7.- Create .txt file");
    printf("\n\t8.- See .txt file");
    printf("\n\t9.- Create binary file");
    printf("\n\t10.- Load binary file");
    printf("\n\t11.- Print deleted registers");
    printf("\n\t0.- Exit\n\n");
    printf("Select an option: ");
    option = validate(0, 9);
    return option;
}

void menu()
{
    int option, sorted, i, search, found, remove;
    Tworker workerArray[MAX_REGISTERS], temp;
    i = 0; // Start registers in zero
    sorted = 0;

    do
    {
        option = msges();
        system("CLS");

        switch (option)
        {
        case 1:
            for (int j = 0; j < ADD_REGISTERS; j++)
            {
                if (j + 1 > MAX_REGISTERS)
                {
                    printf("Register full\n");
                }
                else
                {
                    temp = autoDataReg();
                    while (linearSearch(workerArray, i, temp.id) != -1)
                    {
                        temp.id = randomNumber(300000, 399999);
                    }
                    workerArray[i++] = temp;
                }
            }
            break;
        case 2:
            printf("Enter the ID of the worker you want to edit: ");
            search = validate(100000, 199999);
            found = linearSearch(workerArray, i, search);
            if (found == -1)
            {
                printf("The ID [%i] was not found.\n", search);
            }
            else
            {
                printf("The ID [%i] was found.\n", search);
                printRegister(workerArray, found);
                printf("Enter the new data:\n");
                workerArray[found] = autoDataReg();
            }
            break;

        case 3:
            printf("Enter the ID of the worker you want to delete: ");
            search = validate(100000, 199999);
            found = linearSearch(workerArray, i, search);
            if (found == -1)
            {
                printf("The ID [%i] was not found.\n", search);
            }
            else
            {
                printf("The ID [%i] was found.\n", search);
                printRegister(workerArray, found);
                printf("Are you sure you want to delete this register? (1 = Yes, 0 = No): ");
                remove = validate(0, 1);
                if (remove == 1)
                {
                    workerArray[found].status = 0;
                    printf("The register was deleted.\n");
                }
                else
                {
                    printf("The register was not deleted.\n");
                }
            }
            break;

        case 4:
            printf("Enter the ID of the worker you want to search: ");
            search = validate(100000, 199999);
            found = linearSearch(workerArray, i, search);
            if (sorted == 0)
            {
                found = linearSearch(workerArray, i, search);
            }
            else
            {
                found = binarySearch(workerArray, 300000, 399999, search);
            }
            if (found == -1)
            {
                printf("The ID [%i] was not found.\n", search);
            }
            else
            {
                printf("The ID [%i] was found.\n", search);
                printRegister(workerArray, found);
            }
            break;

        case 5:
            printf("Sorting...\n");
            if (sorted == 0)
            {
                if (i <= 500)
                {
                    sorted = selectionSort(workerArray, i);
                }
                else
                {
                    quicksort(workerArray, 0, i);
                    printf("Register is now sorted.");
                }
            }
            else
            {
                printf("Register already sorted.");
            }
            break;

        case 6:
            printRegister(workerArray, i);
            break;

        case 7:
            writeTextFile(workerArray, i);
            break;

        case 8:
            printTextFile(workerArray, i);
            break;

        case 9:
            createBinaryFile(workerArray, i);
            break;

        case 10:
            readBinaryFile(workerArray, i);
            break;

        case 11:
            printDeleted(workerArray, i);
            break;
        }

        system("PAUSE");
    } while (option != 0);
}

Tworker autoDataReg()
{
    char femaleNames[][20] = {"MARIA", "ANA", "LAURA", "ISABEL", "CAROLINA", "GABRIELA", "ELENA", "PATRICIA", "VALENTINA", "CAMILA", "SOFIA", "ADRIANA", "RAQUEL", "JULIA", "CLARA", "BEATRIZ", "LUCIA", "LORENA", "NATALIA", "AURORA"};
    char maleNames[][20] = {"ALEJANDRO", "JAVIER", "ANDRES", "LUIS", "DANIEL", "MARTIN", "SERGIO", "DIEGO", "EDUARDO", "FRANCISCO", "CARLOS", "JUAN", "RAFAEL", "MARCO", "HECTOR", "GUILLERMO", "JOSE", "ANTONIO", "PEDRO", "MIGUEL"};
    char lastnames[][40] = {"PÉREZ", "GONZÁLEZ", "RODRÍGUEZ", "LÓPEZ", "MARTÍNEZ", "SÁNCHEZ", "RAMÍREZ", "TORRES", "FERNÁNDEZ", "GARCÍA", "DÍAZ", "CRUZ", "ROMERO", "HERNÁNDEZ", "ÁLVAREZ", "MORENO", "VARGAS", "SUÁREZ", "JIMÉNEZ", "MENDOZA", "SILVA", "ORTEGA", "MARTÍN", "RUIZ", "CASTILLO", "ROJAS", "GÓMEZ", "FLORES", "MORALES", "SANTOS", "CASTRO", "FERNÁNDEZ", "RIVERA", "MIRANDA", "NAVARRO", "ARIAS", "GUTIÉRREZ", "VIDAL"};
    char jobPositions[][20] = {"HRMANAGER", "MARKETINGANALYST", "SOFTWAREENG", "TECHSUPPORT", "NETADMIN", "WEBDESIGNER", "QAENGINEER", "CORPFINANCE", "DATANALYST", "LEGALADVISOR", "RETAILSALES", "GRAPHICDES", "LOGISTICS", "CUSTOMERSERV", "EVENTMGR", "SYSADMIN", "SALESMANAGER", "RECRUITER", "EXECUTIVE", "MARKETINGMNGR", "APPDEV", "TECHTRAINER", "SOCIALMEDIA", "SUPPLYCHAIN"};
    Tworker worker;

    worker.status = 1;

    worker.id = randomNumber(100000, 199999);

    strcpy(worker.fatherLastname, lastnames[randomNumber(0, 19)]);
    strcpy(worker.motherLastname, lastnames[randomNumber(0, 19)]);

    strcpy(worker.jobPosition, jobPositions[randomNumber(0, 23)]);

    if (randomNumber(0, 1) == 1)
    {
        strcpy(worker.name, maleNames[randomNumber(0, 19)]);
        strcpy(worker.gender, "MASCULINO");
    }
    else
    {
        strcpy(worker.name, femaleNames[randomNumber(0, 19)]);
        strcpy(worker.gender, "FEMENINO");
    }

    worker.age = randomNumber(18, 45);

    return worker;
}

int linearSearch(Tworker array[], int size, int searchNumber)
{
    int i;

    for (i = 0; i < size; i++)
    {
        if (array[i].id == searchNumber)
        {
            return i;
        }
    }
    return -1;
}

int binarySearch(Tworker array[], int left, int right, int number)
{
    while (left <= right)
    {
        int medium = left + (right - left) / 2;

        if (array[medium].id == number)
        {
            return medium;
        }
        if (array[medium].id < number)
        {
            left = medium + 1;
        }
        else
        {
            right = medium - 1;
        }
    }

    return -1;
}

/*selection sort*/
int selectionSort(Tworker array[], int size)
{
    Tworker temp;

    for (int i = 0; i < size - 1; i++)
    {
        for (int j = i + 1; j < size; j++)
        {
            if (array[j].id < array[i].id)
            {
                temp = array[i];
                array[i] = array[j];
                array[j] = temp;
            }
        }
    }
    return 1;
}

/*2nd method, quick sort*/
void swap(Tworker array[], int i, int j)
{
    Tworker temp = array[i];
    array[i] = array[j];
    array[j] = temp;
}

int partition(Tworker array[], int low, int high)
{
    Tworker pivot;
    pivot.id = array[high].id;
    int i = low - 1;

    for (int j = low; j <= high - 1; j++)
    {
        if (array[j].id <= pivot.id)
        {
            i++;
            swap(array, i, j);
        }
    }
    swap(array, i + 1, high);
    return i + 1;
}

void quicksort(Tworker array[], int low, int high)
{
    if (low < high)
    {
        int pi = partition(array, low, high);

        quicksort(array, low, pi - 1);
        quicksort(array, pi + 1, high);
    }
}
/*===================*/

void printRegister(Tworker array[], int i)
{
    int status = 0;
    int page = 0;
    int tam = 0;
    int j;

    while (tam < i)
    {
        system("CLS");

        printf("REGISTER LIST\n");
        printf("NO. REGISTER || ENROLMENT || FATHER LASTNAME || MOTHER LASTNAME || NAME(S) ||  AGE  ||     GENDER     ||\n");
        printf("======================================================================================================================\n");

        for (j = page * 40; j < (page + 1) * 40; j++)
        {
            if (tam < i)
            {
                if (array[j].status == 1)
                {
                    printf("%12i %9i %16s %16s %9s %10i %12s", j + 1, array[j].id, array[j].fatherLastname, array[j].motherLastname, array[j].name, array[j].age, array[j].gender);
                    printf("\n");

                    status++;
                    tam++;
                }
            }
        }
        page++;

        if (tam < i)
        {
            printf("PRESS ENTER TO SEE MORE REGISTERS\n");
            getchar();
        }
    }
}

void writeTextFile(Tworker array[], int size)
{
    char fileName[50];
    printf("File's name: ");
    validateString(fileName, sizeof(fileName));
    strcat(fileName, ".txt");

    FILE *outputFile = freopen(fileName, "w", stdout);

    for (int i = 0; i < size; i++)
    {
        if (array[i].status == 1)
        {
            printf("%12i %9i %16s %16s %9s %12s %10i %12s", i + 1, array[i].id, array[i].fatherLastname, array[i].motherLastname, array[i].name, array[i].jobPosition, array[i].age, array[i].gender);
            printf("\n");
        }
    }

    fclose(outputFile);

    printf("Archive '%s' correctly generated.\n", fileName);

    return;
}

void printTextFile()
{
    char fileName[50];
    printf("File's name: ");
    validateString(fileName, sizeof(fileName));
    strcat(fileName, ".txt");

    FILE *outputFile = freopen(fileName, "r", stdout);

    if (outputFile == NULL)
    {
        printf("File doesn't exist.\n");
    }
    {
        char c;
        while ((c = fgetc(outputFile)) != EOF)
        {
            printf("%c", c);
        }
    }
}

/*
void createBinaryFile(Tworker array[], int size)
{
    char fileName[50];
    printf("File's name: ");
    validateString(fileName, sizeof(fileName));
    strcat(fileName, ".tmp");

    FILE *outputFile = fopen(fileName, "wb");

    for (int i = 0; i < size; i++)
    {
        fwrite(&array[i], sizeof(Tworker), 1, outputFile);
    }

    fclose(outputFile);

    printf("Archive '%s' correctly generated.\n", fileName);

    return;
}
*/

void createBinaryFile(Tworker array[], int size)
{
    FILE *outputFile;
    char nom[11] = "datos.dll";
    rename("datos.dll", "datos.tmp");
    outputFile = fopen(nom, "wb");
    if (outputFile == NULL)
    {
        printf("No se ha encontrado el archivo\n");
        system("pause");
    }
    else
    {
        fwrite(array, sizeof(Tworker), size, outputFile);
        fclose(outputFile);
    }
}

int readBinaryFile(Tworker array[], int size)
{
    int i = 0;
    FILE *fa;
    fa = fopen("datos.dll", "rb");
    if (fa == NULL)
    {
        printf("No se ha encontrado el archivo\n");
        system("pause");
    }
    else
    {
        while (fread(&array[i], sizeof(Tworker), 1, fa) == 1 && size < MAX_REGISTERS)
        {
            array[i].status = randomNumber(0, 1);
            i++;
        }
        fclose(fa);
        printf("El archivo se ha cargado con exito\n");
        system("pause");
    }
    return i;
}

void printDeleted(Tworker array[], int i)
{
    int status = 0;
    int page = 0;
    int tam = 0;
    int j;

    while (tam < i)
    {
        system("CLS");

        printf("REGISTER LIST\n");
        printf("NO. REGISTER || ENROLMENT || FATHER LASTNAME || MOTHER LASTNAME || NAME(S) ||  AGE  ||     GENDER     ||\n");
        printf("======================================================================================================================\n");

        for (j = page * 40; j < (page + 1) * 40; j++)
        {
            if (tam < i)
            {
                if (array[j].status == 0)
                {
                    printf("%12i %9i %16s %16s %9s %10i %12s", j + 1, array[j].id, array[j].fatherLastname, array[j].motherLastname, array[j].name, array[j].age, array[j].gender);
                    printf("\n");

                    status++;
                    tam++;
                }
            }
        }
        page++;

        if (tam < i)
        {
            printf("PRESS ENTER TO SEE MORE REGISTERS\n");
            getchar();
        }
    }
}