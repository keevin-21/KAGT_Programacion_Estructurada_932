#include "kewvyValidates.h"
#include "fullnames.h"
#include "listas.h"
#define MAX_REGISTERS 2000

typedef struct _fullnames
{
    char fatherLastname[30];
    char motherLastname[30];
    char name[30];
} Tfullnames;

typedef struct _birthDate
{
    int year;
    int month;
    int day;
} TbirthDate;

typedef struct _students
{
    int status;
    int enrolment;
    Tfullnames fullname;
    int lastnameOption1;
    int lastnameOption2;
    TbirthDate birthDate;
    int age;
    int gender;
    char state[2];
    char curp[19];
} Tstudents;

int msges();
void menu();
Tstudents autoDataReg();
Tstudents manualDataReg();
void curp(Tstudents student);
int linearSearch(Tstudents array[], int size, int searchNumber);
int binarySearch(Tstudents array[], int left, int right, int number);
void printOneRegister(Tstudents student);
int selectionSort(Tstudents array[], int size);
void swap(Tstudents array[], int i, int j);
int partition(Tstudents array[], int low, int high);
void quicksort(Tstudents array[], int low, int high);
void printRegister(Tstudents array[], int size);
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
    printf("\n\t1.- Add registers");
    printf("\n\t2.- Delete register");
    printf("\n\t3.- Search register");
    printf("\n\t4.- Sort registers");
    printf("\n\t5.- Print Registers");
    printf("\n\t6.- Create .txt file");
    printf("\n\t0.- Exit\n\n");
    printf("Select an option: ");
    option = validate(0, 6);
    return option;
}

int msges2()
{
    int subOption;

    printf("SUB-MENU TO ADD REGISTERS");
    printf("\n\t1.- Automatic register (100)");
    printf("\n\t2.- Manual register (1)");
    printf("\n\t3.- Return to main menu\n\n");
    printf("Select an option: ");
    subOption = validate(1, 3);
    return subOption;
}

void menu()
{
    int option, sorted, i, remove, search, found;
    Tstudents studentArray[MAX_REGISTERS], temp;
    i = 0; // Start registers in zero

    do
    {
        option = msges();
        system("CLS");

        switch (option)
        {
        case 1:
            int subOption;

            do
            {
                subOption = msges2();
                switch (subOption)
                {
                case 1:
                    sorted = 0; // Verify if it is sorted or not

                    for (int j = 0; j < 100; j++)
                    {
                        temp = autoDataReg();
                        while (linearSearch(studentArray, i, temp.enrolment) != -1)
                        {
                            temp.enrolment = randomNumber(300000, 399999);
                        }
                        studentArray[i++] = temp;
                    }
                    printf("100 automatic registrations have been added.");

                    break;

                case 2:
                    if (i >= MAX_REGISTERS)
                    {
                        printf("\n\nError - Maximum registers reached, you can't add more.\n\n");
                    }
                    else
                    {
                        sorted = 0;

                        temp = manualDataReg();
                        while (linearSearch(studentArray, i, temp.enrolment) != -1)
                        {
                            printf("Repeated enrolment - Please enter a different one.");
                            temp.enrolment = validate(300000, 399999);
                        }
                        studentArray[i++] = temp;
                        printf("Manual registration successfully added.");

                        break;
                    }
                }
                system("PAUSE");
                system("CLS");
            } while (subOption != 3);
            break;

        case 2:
            printf("Enrolment to be removed: ");
            remove = validate(300000, 399999);
            search = linearSearch(studentArray, i, remove);

            if (linearSearch(studentArray, i, remove) != -1)
            {
                printf("Enrolment found...\n");
            }
            else
            {
                printf("Enrolment not found...\n");
            }

            if (studentArray[search].status == 0)
            {
                printf("Enrolment already removed.");
            }
            else
            {
                studentArray[search].status = 0;
                printf("Now the enrolment %i has been removed.", remove);
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
            if (sorted == 0)
            {
                if (i <= 500)
                {
                    // change this to selection sort
                    sorted = selectionSort(studentArray, i);
                }
                else
                {
                    // and this will be the 2nd method, quick sort
                    quicksort(studentArray, 0, i);
                    printf("Register is now sorted.");
                }
            }
            else
            {
                printf("Register already sorted.");
            }
            break;
        case 5:
            printRegister(studentArray, i);
            break;

        case 6:
            printf("Text file is now created.\n");
            writeTextFile(studentArray, i);
            break;
        case 0:
            return;
            break;

        default:
            printf("Error - Please select a valid option.");
            break;
        }
        system("PAUSE");
    } while (option != 0);
}

Tstudents autoDataReg()
{
    Tstudents student;

    student.status = 1;

    student.enrolment = randomNumber(300000, 399999);

    student.lastnameOption1 = 1;
    student.lastnameOption2 = 1;

    strcpy(student.fullname.fatherLastname, lastnames[randomNumber(0, 19)]);
    strcpy(student.fullname.motherLastname, lastnames[randomNumber(0, 19)]);

    if (randomNumber(0, 1) == 1)
    {
        strcpy(student.fullname.name, maleNames[randomNumber(0, 19)]);
        student.gender = 1;
    }
    else
    {
        strcpy(student.fullname.name, femaleNames[randomNumber(0, 19)]);
        student.gender = 0;
    }

    student.birthDate.year = randomNumber(1893, 2023);
    student.birthDate.month = randomNumber(1, 12);
    if (student.birthDate.month == 2 && esBisiesto(student.birthDate.year) == 1)
    {
        student.birthDate.day = randomNumber(1, 29);
    }
    else
    {
        if (student.birthDate.month == 2 && esBisiesto(student.birthDate.year) == 0)
        {
            student.birthDate.day = randomNumber(1, 28);
        }
        else
        {
            if (student.birthDate.month == 1 || student.birthDate.month == 3 || student.birthDate.month == 5 || student.birthDate.month == 7 || student.birthDate.month == 8 || student.birthDate.month == 10 || student.birthDate.month == 12)
            {
                student.birthDate.day = randomNumber(1, 31);
            }
            else
            {
                if (student.birthDate.month == 4 || student.birthDate.month == 6 || student.birthDate.month == 9 || student.birthDate.month == 11)
                {
                    student.birthDate.day = randomNumber(1, 30);
                }
            }
        }
    }

    student.age = 2023 - student.birthDate.year;

    student.gender = randomNumber(0, 1);

    strcpy(student.state, estados[randomNumber(0, 32)]);

    return student;
}

Tstudents manualDataReg()
{
    Tstudents student;

    printf("Ingrese los siguientes datos:\n");

    student.enrolment = 1;

    printf("\nEnrolment:\n");
    student.enrolment = validate(300000, 399999);

    printf("Name: ");
    validateString(student.fullname.name, sizeof(student.fullname.name));
    omitirNombres(student.fullname.name, nombresCortos);
    omitirNombres(student.fullname.name, nombresCortos);
    omitirPartes(student.fullname.name, partes);
    omitirPartes(student.fullname.name, partes);
    noSpacesString(student.fullname.name);

    printf("¿Tienes apellido paterno?\n");
    printf("[1] Si\n[2] No\nOpcion: ");
    student.lastnameOption1 = validate(1, 2);
    if (student.lastnameOption1 == 1)
    {
        printf("Apellido Paterno: ");
        validateString(student.fullname.fatherLastname, sizeof(student.fullname.fatherLastname));
        omitirPartes(student.fullname.fatherLastname, partes);
        omitirPartes(student.fullname.fatherLastname, partes);
        noSpacesString(student.fullname.fatherLastname);
        puts(student.fullname.fatherLastname);
    }

    printf("¿Tienes apellido materno?\n");
    printf("[1] Si\n[2] No\nOpcion: ");
    student.lastnameOption2 = validate(1, 2);
    if (student.lastnameOption2 == 1)
    {
        printf("Apellido Materno: ");
        validateString(student.fullname.motherLastname, sizeof(student.fullname.motherLastname));
        omitirPartes(student.fullname.motherLastname, partes);
        omitirPartes(student.fullname.motherLastname, partes);
        noSpacesString(student.fullname.motherLastname);
    }

    printf("Year: ");
    student.birthDate.year = validate(1893, 2023);

    printf("Month: ");
    student.birthDate.month = validate(1, 12);

    printf("Day: ");
    if (student.birthDate.month == 2 && esBisiesto(student.birthDate.year) == 1)
    {
        student.birthDate.day = validate(1, 29);
    }
    else
    {
        if (student.birthDate.month == 2 && esBisiesto(student.birthDate.year) == 0)
        {
            student.birthDate.day = validate(1, 28);
        }
        else
        {
            if (student.birthDate.month == 1 || student.birthDate.month == 3 || student.birthDate.month == 5 || student.birthDate.month == 7 || student.birthDate.month == 8 || student.birthDate.month == 10 || student.birthDate.month == 12)
            {
                student.birthDate.day = validate(1, 31);
            }
            else
            {
                if (student.birthDate.month == 4 || student.birthDate.month == 6 || student.birthDate.month == 9 || student.birthDate.month == 11)
                {
                    student.birthDate.day = validate(1, 30);
                }
            }
        }
    }

    student.age = 2023 - student.birthDate.year;

    printf("Género\n[0] Mujer\n[1] Hombre: ");
    student.gender = validate(0, 1);

    printf("Aguascalientes (AS)\n");
    printf("Baja California (BC)\n");
    printf("Baja California Sur (BS)\n");
    printf("Campeche (CC)\n");
    printf("Chiapas (CS)\n");
    printf("Chihuahua (CH)\n");
    printf("Coahuila (CO)\n");
    printf("Colima (CL)\n");
    printf("Durango (DG)\n");
    printf("Guanajuato (GT)\n");
    printf("Guerrero (GR)\n");
    printf("Hidalgo (HG)\n");
    printf("Jalisco (JC)\n");
    printf("Estado de México (MC)\n");
    printf("Michoacán (MN)\n");
    printf("Morelos (MS)\n");
    printf("Nayarit (NT)\n");
    printf("Nuevo León (NL)\n");
    printf("Oaxaca (OC)\n");
    printf("Puebla (PL)\n");
    printf("Querétaro (QT)\n");
    printf("Quintana Roo (QR)\n");
    printf("San Luis Potosí (SP)\n");
    printf("Sinaloa (SL)\n");
    printf("Sonora (SR)\n");
    printf("Tabasco (TC)\n");
    printf("Tamaulipas (TS)\n");
    printf("Tlaxcala (TL)\n");
    printf("Veracruz (VZ)\n");
    printf("Yucatán (YN)\n");
    printf("Zacatecas (ZS)\n");
    printf("Ciudad de México (DF)\n");
    printf("Nacido en el Extranjero (NE)\n");
    printf("NOTA: USAR ABREVIACION DE DOS LETRAS.\n");
    printf("Entidad de Nacimiento: ");
    validateString(student.state, sizeof(student.state));
    while (validarEntidad(student.state, estados, sizeof(estados) / sizeof(estados[0])) == 0)
    {
        printf("Entidad no válida. Ingresa una abreviatura válida.\n");
        printf("Entidad de Nacimiento: ");
        validateString(student.state, sizeof(student.state));
    }

    return student;
}

void curp(Tstudents student)
{
    char cdia[3];
    char cmes[3];
    char canio[6];
    int ultimoDigito;
    char cultimoDigito;
    char curp[19];
    sprintf(cdia, "%d", student.birthDate.day);
    sprintf(cmes, "%d", student.birthDate.month);
    sprintf(canio, "%d", student.birthDate.year);

    if (student.lastnameOption1 == 1)
    {
        curp[0] = toupper(student.fullname.fatherLastname[0]);
        curp[1] = obtenerPrimeraVocal(student.fullname.fatherLastname);
    }
    else
    {
        if (student.lastnameOption1 == 2)
        {
            curp[0] = 'X';
            curp[1] = 'X';
        }
    }
    if (student.lastnameOption2 == 1)
    {
        curp[2] = toupper(student.fullname.motherLastname[0]);
    }
    else
    {
        if (student.lastnameOption2 == 2)
        {
            curp[2] = 'X';
        }
    }

    curp[3] = toupper(student.fullname.name[0]);
    curp[4] = canio[2];
    curp[5] = canio[3];
    if (student.birthDate.month < 10)
    {
        curp[6] = '0';
        curp[7] = cmes[0];
    }
    else
    {
        curp[6] = cmes[0];
        curp[7] = cmes[1];
    }
    if (student.birthDate.day < 10)
    {
        curp[8] = '0';
        curp[9] = cdia[0];
    }
    else
    {
        curp[8] = cdia[0];
        curp[9] = cdia[1];
    }

    if (student.gender == 1)
    {
        curp[10] = 'H';
    }
    else
    {
        curp[10] = 'M';
    }

    curp[11] = student.state[0];
    curp[12] = student.state[1];
    if (!obtenerSegundaConsonante(student.fullname.fatherLastname) || student.lastnameOption1 == 2)
    {
        curp[13] = 'X';
    }
    else
    {
        curp[13] = obtenerSegundaConsonante(student.fullname.fatherLastname);
    }
    if (!obtenerSegundaConsonante(student.fullname.motherLastname) || student.lastnameOption2 == 2)
    {
        curp[14] = 'X';
    }
    else
    {
        curp[14] = obtenerSegundaConsonante(student.fullname.motherLastname);
    }

    if (!obtenerSegundaConsonante(student.fullname.name))
    {
        curp[15] = 'X';
    }
    else
    {
        curp[15] = obtenerSegundaConsonante(student.fullname.name);
    }
    if (student.birthDate.year < 2000)
    {
        curp[16] = '0';
    }
    else
    {
        if (student.birthDate.year >= 2000 && student.birthDate.year < 2010)
        {
            curp[16] = 'A';
        }
        else
        {
            if (student.birthDate.year >= 2010)
            {
                curp[16] = 'B';
            }
        }
    }
    ultimoDigito = randomNumber(0, 9);
    sprintf(&cultimoDigito, "%d", ultimoDigito);
    curp[17] = cultimoDigito;
    curp[18] = '\0';

    if (validarAntisonante(curp, antisonantes, sizeof(antisonantes) / sizeof(antisonantes[0])))
    {
        curp[1] = 'X';
    }

    strcpy(student.curp, curp);
    printf("%s", student.curp);
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

void printRegister(Tstudents array[], int i)
{
    int status = 0;
    int page = 0;
    int tam = 0;
    int j;

    while (tam < i)
    {
        system("CLS");

        printf("REGISTROS\n");
        printf("NO. REGISTER || ENROLMENT || FATHER LASTNAME || MOTHER LASTNAME || NAME(S) ||  AGE  ||  GENDER  ||    CURP\n");
        printf("======================================================================================================================\n");

        for (j = page * 40; j < (page + 1) * 40; j++)
        {
            if (tam < i)
            {
                if (array[j].status == 1)
                {
                    printf("%12d || %9d || %16s || %16s || %9s || %6d || ", j + 1, array[j].enrolment, array[j].fullname.fatherLastname, array[j].fullname.motherLastname, array[j].fullname.name, array[j].age);

                    if (array[j].gender == 1)
                    {
                        printf("MALE  || ");
                    }
                    else
                    {
                        if (array[j].gender == 0)
                        {
                            printf("FEMALE   || ");
                        }
                    }

                    curp(array[j]);
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
    FILE *outputFile = freopen("G:\\My Drive\\UABC\\TercerSemestre\\KAGT_Programacion_Estructurada_932\\Actividades\\Actividad_11\\registers.txt", "w", stdout);

    printf("NO. REGISTER || ENROLMENT  || FATHER LASTNAME   || MOTHER LASTNAME   || NAME(S)    || AGE  || GENDER   || CURP\n");
    printf("==========================================================================================================================\n");

    for (int i = 0; i < size; i++)
    {
        if (array[i].status == 1)
        {
            printf("%12d || %11d || %18s || %18s || %10s || %3d  || ", i + 1, array[i].enrolment, array[i].fullname.fatherLastname, array[i].fullname.motherLastname, array[i].fullname.name, array[i].age);

            if (array[i].gender == 1)
            {
                printf("MALE       || ");
            }
            else
            {
                if (array[i].gender == 0)
                {
                    printf("FEMALE   || ");
                }
            }

            curp(array[i]);
            printf("\n");
        }
    }

    fclose(outputFile);

    return;
}

void printOneRegister(Tstudents student)
{
    printf("Enrolment: %i", student.enrolment);
    printf("Name: %s", student.fullname.name);
    printf("Enrolment: %s", student.fullname.fatherLastname);
    printf("Enrolment: %s", student.fullname.motherLastname);
    printf("Enrolment: %i-%i-%i", student.birthDate.day, student.birthDate.month, student.birthDate.year);
    printf("Enrolment: %i", student.age);
    printf("%s\n", student.gender == 1 ? "MALE" : "FEMALE");
    printf("Birthplace: %s", student.state);
    curp(student);
}