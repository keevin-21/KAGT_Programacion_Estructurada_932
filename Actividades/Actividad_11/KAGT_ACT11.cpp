#include "kewvyValidates.h"
#include "fullnames.h"
#include "curp.h"
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
    printf("\n\t1.- Manual register (1)");
    printf("\n\t2.- Automatic register (100)");
    printf("\n\t3.- Return to main menu");

    subOption = validate(0, 3);
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

            subOption = msges2();
            switch (subOption)
            {
            case 1:
                /* code */
                break;

            default:
                break;
            }
            break;
        case 0:
            return;
            break;
        default:
            printf("Error - Please select a valid option.");
            break;
        }
    } while (option != 0);
}

Tstudents autoDataReg()
{
    Tstudents student;

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
    if (student.birthDate.month == 2 /*&& esBisiesto(student.birthDate.year) == 1*/)
    {
        student.birthDate.day = validate(1, 29);
    }
    else
    {
        if (student.birthDate.month == 2 /*&& esBisiesto(student.birthDate.year) == 0*/)
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

    student.curp = curp();

        return student;
}

char obtenerPrimeraVocal(const char cadena[])
{
    char vocalEncontrada = 'X';

    for (int i = 1; cadena[i] != '\0'; i++)
    {
        char c = toupper(cadena[i]);
        if (c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U')
        {
            vocalEncontrada = c;
            break;
        }
    }
    return vocalEncontrada;
}

char obtenerSegundaConsonante(char cadena[])
{
    int i = 1;

    while (cadena[i] != '\0')
    {
        char caracter = cadena[i];
        if (strchr("AEIOUaeiou", caracter) == NULL)
        {
            return caracter;
        }
        i++;
    }
    return '\0';
}

int esBisiesto(int anio)
{
    if ((anio % 4 == 0 && anio % 100 != 0) || (anio % 400 == 0))
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int validarEntidad(char cadena[], char entidades[][3], int numEntidades)
{
    for (int i = 0; i < numEntidades; i++)
    {
        if (strcmp(cadena, entidades[i]) == 0)
        {
            return 1;
        }
    }
    return 0;
}

int validarAntisonante(char cadena[], char antisonantes[][5], int numAntisonantes)
{
    char subcadena[5];

    strncpy(subcadena, cadena, 4);
    subcadena[4] = '\0';

    for (int i = 0; i < numAntisonantes; i++)
    {
        if (strcmp(subcadena, antisonantes[i]) == 0)
        {
            return 1;
        }
    }

    return 0;
}

void omitirNombres(char nombre[], char partes[][7])
{
    for (int i = 0; partes[i][0] != '\0'; i++)
    {
        char *encontrado = strstr(nombre, partes[i]);
        while (encontrado != NULL)
        {
            int longitudParte = strlen(partes[i]);
            int longitudRestante = strlen(encontrado + longitudParte);

            for (int j = 0; j <= longitudRestante; j++)
            {
                encontrado[j] = encontrado[j + longitudParte];
            }

            encontrado = strstr(encontrado, partes[i]);
        }
    }
}

void omitirPartes(char apellido[], char partes[][6])
{
    for (int i = 0; partes[i][0] != '\0'; i++)
    {
        char *encontrado = strstr(apellido, partes[i]);
        while (encontrado != NULL)
        {
            int longitudParte = strlen(partes[i]);
            int longitudRestante = strlen(encontrado + longitudParte);

            for (int j = 0; j <= longitudRestante; j++)
            {
                encontrado[j] = encontrado[j + longitudParte];
            }

            encontrado = strstr(encontrado, partes[i]);
        }
    }
}

Tstudents curp()
{
    Tstudents student;
    char nombre[50];
    char primer_apellido[50];
    int opcionApellido1;
    int opcionApellido2;
    char segundo_apellido[50];
    int dia;
    char cdia[3];
    int mes;
    char cmes[3];
    int anio;
    char canio[6];
    char genero[2];
    char entidad_nacimiento[3];
    int ultimoDigito;
    char cultimoDigito[1];

    printf("Ingrese los siguientes datos:\n");

    printf("Nombre: ");
    validateString(student.fullname.name, sizeof(nombre));
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

    printf("Ano: ");
    anio = validate(1910, 2023);
    sprintf(canio, "%d", student.birthDate.year);
    system("CLS");

    printf("Mes: ");
    mes = validate(1, 12);
    sprintf(cmes, "%d", student.birthDate.month);
    system("CLS");

    printf("Dia: ");
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
    sprintf(cdia, "%d", student.birthDate.day);
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

    if (opcionApellido1 == 1)
    {
        student.curp[0] = toupper(student.fullname.fatherLastname[0]);
        student.curp[1] = obtenerPrimeraVocal(student.fullname.fatherLastname);
    }
    else
    {
        if (opcionApellido1 == 2)
        {
            student.curp[0] = 'X';
            student.curp[1] = 'X';
        }
    }
    if (opcionApellido2 == 1)
    {
        student.curp[2] = toupper(student.fullname.motherLastname[0]);
    }
    else
    {
        if (opcionApellido2 == 2)
        {
            student.curp[2] = 'X';
        }
    }

    student.curp[3] = toupper(student.fullname.motherLastname[0]);
    student.curp[4] = canio[2];
    student.curp[5] = canio[3];
    if (student.birthDate.month < 10)
    {
        student.curp[6] = '0';
        student.curp[7] = cmes[0];
    }
    else
    {
        student.curp[6] = cmes[0];
        student.curp[7] = cmes[1];
    }
    if (student.birthDate.day < 10)
    {
        student.curp[8] = '0';
        student.curp[9] = cdia[0];
    }
    else
    {
        student.curp[8] = cdia[0];
        student.curp[9] = cdia[1];
    }

    if (student.gender == 1)
    {
        student.curp[10] = 'H';
    }
    else
    {
        student.curp[10] = 'M';
    }
    
    student.curp[11] = student.state[0];
    student.curp[12] = student.state[1];
    if (!obtenerSegundaConsonante(student.fullname.fatherLastname) || opcionApellido1 == 2)
    {
        student.curp[13] = 'X';
    }
    else
    {
        student.curp[13] = obtenerSegundaConsonante(student.fullname.fatherLastname);
    }
    if (!obtenerSegundaConsonante(student.fullname.motherLastname) || opcionApellido2 == 2)
    {
        student.curp[14] = 'X';
    }
    else
    {
        student.curp[14] = obtenerSegundaConsonante(student.fullname.motherLastname);
    }

    if (!obtenerSegundaConsonante(student.fullname.name))
    {
        student.curp[15] = 'X';
    }
    else
    {
        student.curp[15] = obtenerSegundaConsonante(student.fullname.name);
    }
    if (anio < 2000)
    {
        student.curp[16] = '0';
    }
    else
    {
        if (anio >= 2000 && anio < 2010)
        {
            student.curp[16] = 'A';
        }
        else
        {
            if (anio >= 2010)
            {
                student.curp[16] = 'B';
            }
        }
    }
    ultimoDigito = randomNumber(0, 9);
    sprintf(cultimoDigito, "%d", ultimoDigito);
    student.curp[17] = cultimoDigito[0];
    student.curp[18] = '\0';

    if (validarAntisonante(student.curp, antisonantes, sizeof(antisonantes) / sizeof(antisonantes[0])))
    {
        student.curp[1] = 'X';
    }

    return student;
}