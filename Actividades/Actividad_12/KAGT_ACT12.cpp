#include "kewvyValidates.h"
#define MAX_REGISTERS 1500

typedef struct _students
{
    int status;
    int enrolment;
    char fatherLastname[30];
    char motherLastname[30];
    char name[30];
    int age;
    char gender[10];
} Tstudents;

int msges();
void menu();
Tstudents autoDataReg();
void readTextFile(Tstudents array[], int *size);
int linearSearch(Tstudents array[], int size, int searchNumber);
int binarySearch(Tstudents array[], int left, int right, int number);
int selectionSort(Tstudents array[], int size);
void swap(Tstudents array[], int i, int j);
int partition(Tstudents array[], int low, int high);
void quicksort(Tstudents array[], int low, int high);
void counterRegisters();
void printRegister(Tstudents array[], int i);
void writeTextFile(Tstudents array[], int size);

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
    printf("\n\t1.- Load file");
    printf("\n\t2.- Add register");
    printf("\n\t3.- Delete register");
    printf("\n\t4.- Search registers");
    printf("\n\t5.- Sort registers");
    printf("\n\t6.- Print registers");
    printf("\n\t7.- Create .txt file");
    printf("\n\t8.- Cantidad de registros en Archivo");
    printf("\n\t9.- Mostrar Borrados");
    printf("\n\t0.- Exit\n\n");
    printf("Select an option: ");
    option = validate(0, 9);
    return option;
}

void menu()
{
    int option, sorted, i, search, found, loaded;
    Tstudents studentArray[MAX_REGISTERS], temp;
    i = 0; // Start registers in zero
    loaded = 0;
    sorted = 0;
    int j;

    do
    {
        option = msges();
        system("CLS");

        switch (option)
        {
        case 1:
            if (loaded == 0)
            {
                readTextFile(studentArray, &i);
                printf("Now the file is loaded.\n");
                loaded++;
            }
            else
            {
                printf("File already loaded, you only can load the file once.");
            }
            break;

        case 2:
            for (int j = 0; j < 10; j++)
            {
                if (j + 1 > MAX_REGISTERS)
                {
                    printf("Register full\n");
                }
                else
                {
                    temp = autoDataReg();
                    while (linearSearch(studentArray, i, temp.enrolment) != -1)
                    {
                        temp.enrolment = randomNumber(300000, 399999);
                    }
                    studentArray[i++] = temp;
                }
            }
            break;

        case 3:
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
                printf("Enrolment found in register number %i.\n\n", found + 1);
            }
            else
            {
                printf("Enrolment not found.");
            }
            break;

        case 4:

            break;

        case 5:
            if (sorted == 0)
            {
                if (i <= 500)
                {
                    sorted = selectionSort(studentArray, i);
                }
                else
                {
                    quicksort(studentArray, 0, i);
                    printf("Register is now sorted.");
                }
            }
            else
            {
                printf("Register already sorted.");
            }
            break;

        case 6:
            printRegister(studentArray, i);
            break;

        case 7:
            writeTextFile(studentArray, i);
            break;

        case 8:
            counterRegisters();
            break;
        }
        system("PAUSE");
    } while (option != 0);
}

Tstudents autoDataReg()
{
    char femaleNames[][20] = {"MARIA", "ANA", "LAURA", "ISABEL", "CAROLINA", "GABRIELA", "ELENA", "PATRICIA", "VALENTINA", "CAMILA", "SOFIA", "ADRIANA", "RAQUEL", "JULIA", "CLARA", "BEATRIZ", "LUCIA", "LORENA", "NATALIA", "AURORA"};
    char maleNames[][20] = {"ALEJANDRO", "JAVIER", "ANDRES", "LUIS", "DANIEL", "MARTIN", "SERGIO", "DIEGO", "EDUARDO", "FRANCISCO", "CARLOS", "JUAN", "RAFAEL", "MARCO", "HECTOR", "GUILLERMO", "JOSE", "ANTONIO", "PEDRO", "MIGUEL"};
    char lastnames[][40] = {"PÉREZ", "GONZÁLEZ", "RODRÍGUEZ", "LÓPEZ", "MARTÍNEZ", "SÁNCHEZ", "RAMÍREZ", "TORRES", "FERNÁNDEZ", "GARCÍA", "DÍAZ", "CRUZ", "ROMERO", "HERNÁNDEZ", "ÁLVAREZ", "MORENO", "VARGAS", "SUÁREZ", "JIMÉNEZ", "MENDOZA", "SILVA", "ORTEGA", "MARTÍN", "RUIZ", "CASTILLO", "ROJAS", "GÓMEZ", "FLORES", "MORALES", "SANTOS", "CASTRO", "FERNÁNDEZ", "RIVERA", "MIRANDA", "NAVARRO", "ARIAS", "GUTIÉRREZ", "VIDAL"};

    Tstudents student;
    student.status = 1;

    student.enrolment = randomNumber(300000, 399999);

    strcpy(student.fatherLastname, lastnames[randomNumber(0, 19)]);
    strcpy(student.motherLastname, lastnames[randomNumber(0, 19)]);

    if (randomNumber(0, 1) == 1)
    {
        strcpy(student.name, maleNames[randomNumber(0, 19)]);
        strcpy(student.gender, "MASCULINO");
    }
    else
    {
        strcpy(student.name, femaleNames[randomNumber(0, 19)]);
        strcpy(student.gender, "FEMENINO");
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

        if (array[medium].enrolment == number)
        {
            return medium;
        }
        if (array[medium].enrolment < number)
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
int selectionSort(Tstudents array[], int size)
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

/*2nd method, quick sort*/
void swap(Tstudents array[], int i, int j)
{
    Tstudents temp = array[i];
    array[i] = array[j];
    array[j] = temp;
}

int partition(Tstudents array[], int low, int high)
{
    Tstudents pivot;
    pivot.enrolment = array[high].enrolment;
    int i = low - 1;

    for (int j = low; j <= high - 1; j++)
    {
        if (array[j].enrolment <= pivot.enrolment)
        {
            i++;
            swap(array, i, j);
        }
    }
    swap(array, i + 1, high);
    return i + 1;
}

void quicksort(Tstudents array[], int low, int high)
{
    if (low < high)
    {
        int pi = partition(array, low, high);

        quicksort(array, low, pi - 1);
        quicksort(array, pi + 1, high);
    }
}
/*===================*/

void readTextFile(Tstudents array[], int *size)
{
    Tstudents reg;

    FILE *file;
    char line[100];

    file = fopen("G:\\My Drive\\UABC\\TercerSemestre\\KAGT_Programacion_Estructurada_932\\Actividades\\Actividad_12\\datos.txt", "r");

    if (file == NULL)
    {
        printf("Error - Can't open the file.\n");
    }
    else
    {
        *size = 0;
        int x = 0;
        while (fgets(line, sizeof(line), file) != NULL)
        {

            int variablesRead;

            variablesRead = sscanf(line, "%i.- %i %s %s %s %i %s",
                                   &x, &reg.enrolment, reg.name, reg.fatherLastname, reg.motherLastname, &reg.age, reg.gender);

            if (variablesRead)
            {
                reg.status = 1;
                array[(*size)++] = reg;
            }
            else
            {
                printf("Error - In line: %s", line);
            }
        }
        fclose(file);
    }
}

void counterRegisters()
{
    int count;
    char fileName[50];
    char cmd[50];
    printf("Ingrese el nombre del archivo: ");
    validateString(fileName, sizeof(fileName));

    system("mingw32-gcc-6.3.0.exe registerCounter.c -o registerCounter"); // This line compile RegisterCounter.c.
    sprintf(cmd, "RegisterCounter.exe %s", fileName);
    count = system(cmd);

    if (count != -1)
    {
        printf("El archivo %s contiene %d registros\n", fileName, count);
    }
    else
    {
        printf("El archivo no fue encontrado\n");
    }
}

void printRegister(Tstudents array[], int i)
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
                    printf("%12i || %9i || %16s || %16s || %9s || %10i || %12s ||", j + 1, array[j].enrolment, array[j].fatherLastname, array[j].motherLastname, array[j].name, array[j].age, array[j].gender);
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

void writeTextFile(Tstudents array[], int size)
{
    char fileName[50];
    printf("Ingrese el nombre del archivo: ");
    validateString(fileName, sizeof(fileName));
    strcat(fileName, ".txt");

    FILE *outputFile = freopen(fileName, "w", stdout);

    printf("NO. REGISTER || ENROLMENT || FATHER LASTNAME || MOTHER LASTNAME || NAME(S) ||  AGE  ||     GENDER     ||\n");
    printf("======================================================================================================================\n");

    for (int i = 0; i < size; i++)
    {

        if (array[i].status == 1)
        {
            printf("%12i || %9i || %16s || %16s || %9s || %10i || %12s ||", i + 1, array[i].enrolment, array[i].fatherLastname, array[i].motherLastname, array[i].name, array[i].age, array[i].gender);
            printf("\n");
        }
    }

    fclose(outputFile);

    printf("Archive '%s' correctly generated.\n", fileName);

    return;
}

/*
do{

} while (validateString(fileName, sizeof(fileName)) == -1);
*/