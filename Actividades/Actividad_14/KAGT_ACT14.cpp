#include "junior.h"
#define REGISTERS_AUTO 1

int msges();
void menu();
int countRegisters(char fileName[]);
bool loadIndex(Tindex index[], int *registers);

int main()
{
    srand(time(NULL));
}

int msges()
{
    int option;
    system("CLS");
    printf("MENU\n");
    printf("\n\t1. Add register");
    printf("\n\t2. Delete register");
    printf("\n\t3. Search register");
    printf("\n\t4. Sort registers");
    printf("\n\t5. Print registers (original file)");
    printf("\n\t6. Print registers (sorted file)");
    printf("\n\t7. Generate text file");
    printf("\n\t8. Package");
    printf("\n\t9. Exit");
    printf("Select an option: ");
    option = validate(0, 9);
    return option;
}

void menu()
{
    int option;
    char fileName[30];
    int i = 0;
    strcpy(fileName, "\n");

    int MAX_REGISTERS = countRegisters("datos");
    MAX_REGISTERS *= 1.25;

    printf("Number of registers: %d\n", MAX_REGISTERS);
    system("PAUSE");

    Tindex index[MAX_REGISTERS];

    loadIndex(index, &i);

    do
    {
        option = msges();
        switch (option)
        {
        case 1:
            printf("Add register\n");
            break;
        case 2:
            printf("Delete register\n");
            break;
        case 3:
            printf("Search register\n");
            break;
        case 4:
            printf("Sort registers\n");
            break;
        case 5:
            printf("Print registers (original file)\n");
            break;
        case 6:
            printf("Print registers (sorted file)\n");
            break;
        case 7:
            printf("Generate text file\n");
            break;
        case 8:
            printf("Package\n");
            break;
        case 9:
            printf("Exit\n");
            break;
        default:
            printf("Invalid option\n");
            break;
        }
        system("PAUSE");
    } while (option != 9);
}

int countRegisters(char fileName[])
{
    int count;
    char cmd[50];

    system("gcc contadorReg.c -o contadorReg");
    sprintf(cmd, "contadorReg.exe %s", fileName);
    count = system(cmd);

    return count;
}

bool loadIndex(Tindex index[], int *registers)
{
    FILE *fa;

    int MAX_REGISTERS = countRegisters("datos");
    MAX_REGISTERS *= 1.25;

    TWrkr array[MAX_REGISTERS];
    TWrkr reg;

    fa = fopen("datos.dat", "rb");

    if (fa)
    {
        while (fread(&reg, sizeof(TWrkr), 1, fa) == 1)
        {
            if (reg.status == 1)
            {
                array[(*registers)++] = reg;

                // Crear indice
                index[(*registers) - 1].key = reg.enrollment;
                index[(*registers) - 1].index = (*registers) - 1;
            }
        }

        fclose(fa);
        return true;
    }

    return false;
}

TWrkr autoDataReg()
{
    char femaleNames[][20] = {"MARIA", "ANA", "LAURA", "ISABEL", "CAROLINA", "GABRIELA", "ELENA", "PATRICIA", "VALENTINA", "CAMILA", "SOFIA", "ADRIANA", "RAQUEL", "JULIA", "CLARA", "BEATRIZ", "LUCIA", "LORENA", "NATALIA", "AURORA"};
    char maleNames[][20] = {"ALEJANDRO", "JAVIER", "ANDRES", "LUIS", "DANIEL", "MARTIN", "SERGIO", "DIEGO", "EDUARDO", "FRANCISCO", "CARLOS", "JUAN", "RAFAEL", "MARCO", "HECTOR", "GUILLERMO", "JOSE", "ANTONIO", "PEDRO", "MIGUEL"};
    char lastnames[][40] = {"PÉREZ", "GONZÁLEZ", "RODRÍGUEZ", "LÓPEZ", "MARTÍNEZ", "SÁNCHEZ", "RAMÍREZ", "TORRES", "FERNÁNDEZ", "GARCÍA", "DÍAZ", "CRUZ", "ROMERO", "HERNÁNDEZ", "ÁLVAREZ", "MORENO", "VARGAS", "SUÁREZ", "JIMÉNEZ", "MENDOZA", "SILVA", "ORTEGA", "MARTÍN", "RUIZ", "CASTILLO", "ROJAS", "GÓMEZ", "FLORES", "MORALES", "SANTOS", "CASTRO", "FERNÁNDEZ", "RIVERA", "MIRANDA", "NAVARRO", "ARIAS", "GUTIÉRREZ", "VIDAL"};
    char jobPositions[][20] = {"HRMANAGER", "MARKETINGANALYST", "SOFTWAREENG", "TECHSUPPORT", "NETADMIN", "WEBDESIGNER", "QAENGINEER", "CORPFINANCE", "DATANALYST", "LEGALADVISOR", "RETAILSALES", "GRAPHICDES", "LOGISTICS", "CUSTOMERSERV", "EVENTMGR", "SYSADMIN", "SALESMANAGER", "RECRUITER", "EXECUTIVE", "MARKETINGMNGR", "APPDEV", "TECHTRAINER", "SOCIALMEDIA", "SUPPLYCHAIN"};
    char states[][20] = {"AGUASCALIENTES", "BAJA CALIFORNIA", "BAJA CALIFORNIA SUR", "CAMPECHE", "CHIAPAS", "CHIHUAHUA", "COAHUILA", "COLIMA", "DURANGO", "GUANAJUATO", "GUERRERO", "HIDALGO", "JALISCO", "MEXICO", "MICHOACAN", "MORELOS", "NAYARIT", "NUEVO LEON", "OAXACA", "PUEBLA", "QUERETARO", "QUINTANA ROO", "SAN LUIS POTOSI", "SINALOA", "SONORA", "TABASCO", "TAMAULIPAS", "TLAXCALA", "VERACRUZ", "YUCATAN", "ZACATECAS"};

    TWrkr worker;

    worker.status = 1;

    worker.enrollment = randomNumber(100000, 199999);

    strcpy(worker.lastName1, lastnames[randomNumber(0, 19)]);
    strcpy(worker.lastName2, lastnames[randomNumber(0, 19)]);

    strcpy(worker.jobPsition, jobPositions[randomNumber(0, 23)]);

    if (randomNumber(0, 1) == 1)
    {
        strcpy(worker.name, maleNames[randomNumber(0, 19)]);
        strcpy(worker.sex, "MASCULINO");
    }
    else
    {
        strcpy(worker.name, femaleNames[randomNumber(0, 19)]);
        strcpy(worker.sex, "FEMENINO");
    }

    strcpy(worker.state, states[randomNumber(0, 31)]);

    worker.age = randomNumber(18, 45);

    worker.cellphone = randomNumber(1000000000, 1410065407);

    return worker;
}

int cargar()
{
    TWrkr temp;
    int i = 0;
    FILE *fa;
    fa = fopen("datos.dat", "rb");
    if (fa == NULL)
    {
        printf("ERROR AL ABRIR ARCHIVO");
    }
    else
    {
        while (fread(&temp, sizeof(TWrkr), 1, fa))
        {
            i++;
        }
    }

    return i;
}