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
    subOption = validate(0, 3);
    return subOption;
}

void menu()
{
    int option, sorted, i;
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
                        if (j + 1 > MAX_REGISTERS)
                        {
                            printf("Register full\n");
                        }
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
                }
            } while (subOption != 3);
            break;

        case 5:
            printRegister(studentArray, i);
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
    // int randomIndex = rand() % (sizeof(estados) / sizeof(estados[0]));

    student.status = 1;

    student.enrolment = randomNumber(300000, 399999);

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

    student.gender = randomNumber(0, 1);

    strcpy(student.state, estados[randomNumber(0, 32)]);

    return student;
}

Tstudents manualDataReg()
{
    Tstudents student;
    int opcionApellido1;
    int opcionApellido2;

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
    system("CLS");

    printf("¿Tienes apellido paterno?\n");
    printf("[1] Si\n[2] No\nOpcion: ");
    opcionApellido1 = validate(1, 2);
    if (opcionApellido1 == 1)
    {
        printf("Apellido Paterno: ");
        validateString(student.fullname.fatherLastname, sizeof(student.fullname.fatherLastname));
        omitirPartes(student.fullname.fatherLastname, partes);
        omitirPartes(student.fullname.fatherLastname, partes);
        noSpacesString(student.fullname.fatherLastname);
        puts(student.fullname.fatherLastname);
    }
    system("CLS");

    printf("¿Tienes apellido materno?\n");
    printf("[1] Si\n[2] No\nOpcion: ");
    opcionApellido2 = validate(1, 2);
    if (opcionApellido2 == 1)
    {
        printf("Apellido Materno: ");
        validateString(student.fullname.motherLastname, sizeof(student.fullname.motherLastname));
        omitirPartes(student.fullname.motherLastname, partes);
        omitirPartes(student.fullname.motherLastname, partes);
        noSpacesString(student.fullname.motherLastname);
    }
    system("CLS");

    printf("Year: ");
    student.birthDate.year = validate(1910, 2023);
    system("CLS");

    printf("Month: ");
    student.birthDate.month = validate(1, 12);
    system("CLS");

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
    system("CLS");

    printf("Género\n[0] Mujer\n[1] Hombre: ");
    student.gender = validate(0, 1);
    system("CLS");

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
    system("CLS");

    return student;
}

Tstudents curp(Tstudents student)
{
    Tstudents reg;
    reg = student;

    int opcionApellido1;
    int opcionApellido2;
    char cdia[3];
    char cmes[3];
    char canio[6];
    int ultimoDigito;
    char cultimoDigito[1];

    sprintf(cdia, "%d", student.birthDate.day);
    sprintf(cmes, "%d", student.birthDate.month);
    sprintf(canio, "%d", student.birthDate.year);

    if (opcionApellido1 == 1)
    {
        reg.curp[0] = toupper(student.fullname.fatherLastname[0]);
        reg.curp[1] = obtenerPrimeraVocal(student.fullname.fatherLastname);
    }
    else
    {
        if (opcionApellido1 == 2)
        {
            reg.curp[0] = 'X';
            reg.curp[1] = 'X';
        }
    }
    if (opcionApellido2 == 1)
    {
        reg.curp[2] = toupper(student.fullname.motherLastname[0]);
    }
    else
    {
        if (opcionApellido2 == 2)
        {
            reg.curp[2] = 'X';
        }
    }

    reg.curp[3] = toupper(student.fullname.motherLastname[0]);
    reg.curp[4] = canio[2];
    reg.curp[5] = canio[3];
    if (student.birthDate.month < 10)
    {
        reg.curp[6] = '0';
        reg.curp[7] = cmes[0];
    }
    else
    {
        reg.curp[6] = cmes[0];
        reg.curp[7] = cmes[1];
    }
    if (student.birthDate.day < 10)
    {
        reg.curp[8] = '0';
        reg.curp[9] = cdia[0];
    }
    else
    {
        reg.curp[8] = cdia[0];
        reg.curp[9] = cdia[1];
    }

    if (student.gender == 1)
    {
        reg.curp[10] = 'H';
    }
    else
    {
        reg.curp[10] = 'M';
    }

    reg.curp[11] = student.state[0];
    reg.curp[12] = student.state[1];
    if (!obtenerSegundaConsonante(student.fullname.fatherLastname) || opcionApellido1 == 2)
    {
        reg.curp[13] = 'X';
    }
    else
    {
        reg.curp[13] = obtenerSegundaConsonante(student.fullname.fatherLastname);
    }
    if (!obtenerSegundaConsonante(student.fullname.motherLastname) || opcionApellido2 == 2)
    {
        reg.curp[14] = 'X';
    }
    else
    {
        reg.curp[14] = obtenerSegundaConsonante(student.fullname.motherLastname);
    }

    if (!obtenerSegundaConsonante(student.fullname.name))
    {
        reg.curp[15] = 'X';
    }
    else
    {
        reg.curp[15] = obtenerSegundaConsonante(student.fullname.name);
    }
    if (student.birthDate.year < 2000)
    {
        reg.curp[16] = '0';
    }
    else
    {
        if (student.birthDate.year >= 2000 && student.birthDate.year < 2010)
        {
            reg.curp[16] = 'A';
        }
        else
        {
            if (student.birthDate.year >= 2010)
            {
                reg.curp[16] = 'B';
            }
        }
    }
    ultimoDigito = randomNumber(0, 9);
    sprintf(cultimoDigito, "%d", ultimoDigito);
    reg.curp[17] = cultimoDigito[0];
    reg.curp[18] = '\0';

    if (validarAntisonante(reg.curp, antisonantes, sizeof(antisonantes) / sizeof(antisonantes[0])))
    {
        reg.curp[1] = 'X';
    }

    return reg;
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
            return medium;

        if (array[medium].enrolment < number)
            left = medium + 1;

        else
            right = medium - 1;
    }

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
    for (int i = 0; i < size; i++)
    {
        if (array[i].status == 1)
        {
            printf("Enrolment: %i", array[i].enrolment);
            printf("Name: %s", array[i].fullname.name);
            printf("Father Lastname: %s", array[i].fullname.fatherLastname);
            printf("Mother Lastname: %s", array[i].fullname.motherLastname);
            printf("Birthday: %i-%i-%i", array[i].birthDate.day, array[i].birthDate.month, array[i].birthDate.year);
            printf("Age: %i", array[i].age);
            printf("Gender: %i", array[i].gender);
            printf("Birthplace: %s", array[i].state);
            printf("CURP: %s", array[i].curp);
            printf("\n");
        }
    }
}
