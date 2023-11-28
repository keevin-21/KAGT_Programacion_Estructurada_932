#include "junior.h"

typedef int Tkey;

typedef struct _Wrkr
{
    int status;
    Tkey enrollment;
    char name[30];
    char lastName1[50];
    char lastName2[50];
    char sex[15];
    char jobPosition[30];
    char state[30];
    int age;
    Tkey cellphone;
} TWrkr;

typedef struct _Index
{
    Tkey key;
    int index;
} TIndex;

int obtenerCantidadRegistros(FILE *archivoBinario)
{
    fseek(archivoBinario, 0, SEEK_END);
    int tamano = ftell(archivoBinario);
    rewind(archivoBinario);

    return tamano / sizeof(TWrkr);
}

void cargarIndicesDesdeArchivo(FILE *archivoBinario, TIndex *indices, int *cantidadRegistros)
{
    *cantidadRegistros = obtenerCantidadRegistros(archivoBinario);

    int tamanoVectorIndices = (*cantidadRegistros) + (*cantidadRegistros / 4);

    TWrkr trabajador;
    int indice = 0;

    while (fread(&trabajador, sizeof(TWrkr), 1, archivoBinario) == 1)
    {
        if (trabajador.status == 1)
        {
            indices[indice].key = trabajador.enrollment;
            indices[indice].index = indice;
            indice++;
        }
    }
}

int linearSearch(TIndex array[], int size, int searchNumber)
{
    int i;

    for (i = 0; i < size; i++)
    {
        if (array[i].key == searchNumber)
        {
            return i;
        }
    }
    return -1;
}

int binarySearch(TIndex array[], int left, int right, int number)
{
    while (left <= right)
    {
        int medium = left + (right - left) / 2;

        if (array[medium].key == number)
        {
            return medium;
        }
        if (array[medium].key < number)
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

int selectionSort(TIndex array[], int size)
{
    TIndex temp;

    for (int i = 0; i < size - 1; i++)
    {
        for (int j = i + 1; j < size; j++)
        {
            if (array[j].key < array[i].key)
            {
                temp = array[i];
                array[i] = array[j];
                array[j] = temp;
            }
        }
    }
    return 1;
}

void swap(TIndex array[], int i, int j)
{
    TIndex temp = array[i];
    array[i] = array[j];
    array[j] = temp;
}

int partition(TIndex array[], int low, int high)
{
    TIndex pivot;
    pivot.key = array[high].key;
    int i = low - 1;

    for (int j = low; j <= high - 1; j++)
    {
        if (array[j].key <= pivot.key)
        {
            i++;
            swap(array, i, j);
        }
    }
    swap(array, i + 1, high);
    return i + 1;
}

void quicksort(TIndex array[], int low, int high)
{
    if (low < high)
    {
        int pi = partition(array, low, high);

        quicksort(array, low, pi - 1);
        quicksort(array, pi + 1, high);
    }
}

TWrkr autoDataReg()
{
    char femaleNames[][30] = {"MARIA", "ANA", "LAURA", "ISABEL", "CAROLINA", "GABRIELA", "ELENA", "PATRICIA", "VALENTINA", "CAMILA", "SOFIA", "ADRIANA", "RAQUEL", "JULIA", "CLARA", "BEATRIZ", "LUCIA", "LORENA", "NATALIA", "AURORA"};
    char maleNames[][30] = {"ALEJANDRO", "JAVIER", "ANDRES", "LUIS", "DANIEL", "MARTIN", "SERGIO", "DIEGO", "EDUARDO", "FRANCISCO", "CARLOS", "JUAN", "RAFAEL", "MARCO", "HECTOR", "GUILLERMO", "JOSE", "ANTONIO", "PEDRO", "MIGUEL"};
    char lastnames[][50] = {"PÉREZ", "GONZÁLEZ", "RODRÍGUEZ", "LÓPEZ", "MARTÍNEZ", "SÁNCHEZ", "RAMÍREZ", "TORRES", "FERNÁNDEZ", "GARCÍA", "DÍAZ", "CRUZ", "ROMERO", "HERNÁNDEZ", "ÁLVAREZ", "MORENO", "VARGAS", "SUÁREZ", "JIMÉNEZ", "MENDOZA", "SILVA", "ORTEGA", "MARTÍN", "RUIZ", "CASTILLO", "ROJAS", "GÓMEZ", "FLORES", "MORALES", "SANTOS", "CASTRO", "FERNÁNDEZ", "RIVERA", "MIRANDA", "NAVARRO", "ARIAS", "GUTIÉRREZ", "VIDAL"};
    char jobPositions[][30] = {"HRMANAGER", "MARKETINGANALYST", "SOFTWAREENG", "TECHSUPPORT", "NETADMIN", "WEBDESIGNER", "QAENGINEER", "CORPFINANCE", "DATANALYST", "LEGALADVISOR", "RETAILSALES", "GRAPHICDES", "LOGISTICS", "CUSTOMERSERV", "EVENTMGR", "SYSADMIN", "SALESMANAGER", "RECRUITER", "EXECUTIVE", "MARKETINGMNGR", "APPDEV", "TECHTRAINER", "SOCIALMEDIA", "SUPPLYCHAIN"};
    char states[][30] = {"AGUASCALIENTES", "BAJA CALIFORNIA", "BAJA CALIFORNIA SUR", "CAMPECHE", "CHIAPAS", "CHIHUAHUA", "COAHUILA", "COLIMA", "DURANGO", "GUANAJUATO", "GUERRERO", "HIDALGO", "JALISCO", "MEXICO", "MICHOACAN", "MORELOS", "NAYARIT", "NUEVO LEON", "OAXACA", "PUEBLA", "QUERETARO", "QUINTANA ROO", "SAN LUIS POTOSI", "SINALOA", "SONORA", "TABASCO", "TAMAULIPAS", "TLAXCALA", "VERACRUZ", "YUCATAN", "ZACATECAS"};

    TWrkr worker;

    worker.status = 1;

    worker.enrollment = randomNumber(100000, 199999);

    strcpy(worker.lastName1, lastnames[randomNumber(0, 19)]);
    puts(worker.lastName1);
    strcpy(worker.lastName2, lastnames[randomNumber(0, 19)]);
    puts(worker.lastName2);
    strcpy(worker.jobPosition, jobPositions[randomNumber(0, 23)]);

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

void addRegister(FILE *archivoBinario, TIndex *indices, int *cantidadRegistros)
{
    TWrkr reg = autoDataReg();

    for (int i = 0; i < *cantidadRegistros; i++)
    {
        if (indices[i].key == reg.enrollment)
        {
            printf("Error: El enrollment ya existe. No se puede agregar el registro.\n");
            return;
        }
    }

    fseek(archivoBinario, 0, SEEK_END);
    fwrite(&reg, sizeof(TWrkr), 1, archivoBinario);

    indices[*cantidadRegistros].key = reg.enrollment;
    indices[*cantidadRegistros].index = *cantidadRegistros;

    (*cantidadRegistros)++;

    printf("Registro agregado con éxito.\n");
}

void deleteRegister(FILE *archivoBinario, TIndex *indices, int *cantidadRegistros)
{
    int enrollmentToDelete;

    printf("Ingrese el enrollment a eliminar: ");
    enrollmentToDelete = validate(300000, 399999);

    int indiceEncontrado = -1;

    for (int i = 0; i < *cantidadRegistros; i++)
    {
        if (indices[i].key == enrollmentToDelete)
        {
            indiceEncontrado = i;
        }
    }

    if (indiceEncontrado == -1)
    {
        printf("No se encontró un registro con el enrollment especificado.\n");
    }

    fseek(archivoBinario, indices[indiceEncontrado].index * sizeof(TWrkr), SEEK_SET);
    TWrkr workerToDelete;
    fread(&workerToDelete, sizeof(TWrkr), 1, archivoBinario);

    printf("Registro encontrado:\n");
    printf("Enrollment: %d\n", workerToDelete.enrollment);
    printf("Nombre: %s %s %s\n", workerToDelete.name, workerToDelete.lastName1, workerToDelete.lastName2);
    printf("Sexo: %s\n", workerToDelete.sex);
    printf("Puesto: %s\n", workerToDelete.jobPosition);
    printf("Estado: %s\n", workerToDelete.state);
    printf("Edad: %d\n", workerToDelete.age);
    printf("Teléfono: %d\n\n", workerToDelete.cellphone);

    char respuesta;
    printf("¿Desea eliminar este registro? (S/N): ");
    scanf(" %c", &respuesta);

    if (respuesta == 'S' || respuesta == 's')
    {

        workerToDelete.status = 0;
        fseek(archivoBinario, indices[indiceEncontrado].index * sizeof(TWrkr), SEEK_SET);
        fwrite(&workerToDelete, sizeof(TWrkr), 1, archivoBinario);

        printf("Registro eliminado con éxito.\n");
    }
    else
    {
        printf("Registro no eliminado.\n");
    }
}

void searchRegister(FILE *archivoBinario, TIndex *indices, int cantidadRegistros, bool sorted)
{
    int enrollmentToSearch;
    TWrkr workerFound;

    printf("Ingrese el enrollment a buscar: ");
    scanf("%d", &enrollmentToSearch);

    int indiceEncontrado = -1;

    if (sorted)
    {
        indiceEncontrado = binarySearch(indices, 0, cantidadRegistros - 1, enrollmentToSearch);
    }
    else
    {
        indiceEncontrado = linearSearch(indices, cantidadRegistros, enrollmentToSearch);
    }

    if (indiceEncontrado != -1 && workerFound.status == 1)
    {
        fseek(archivoBinario, indices[indiceEncontrado].index * sizeof(TWrkr), SEEK_SET);

        fread(&workerFound, sizeof(TWrkr), 1, archivoBinario);

        printf("Registro encontrado:\n");
        printf("Enrollment: %d\n", workerFound.enrollment);
        printf("Nombre: %s %s %s\n", workerFound.name, workerFound.lastName1, workerFound.lastName2);
        printf("Sexo: %s\n", workerFound.sex);
        printf("Puesto: %s\n", workerFound.jobPosition);
        printf("Estado: %s\n", workerFound.state);
        printf("Edad: %d\n", workerFound.age);
        printf("Teléfono: %d\n", workerFound.cellphone);
    }
    else
    {
        printf("No se encontró un registro con el enrollment especificado.\n");
    }
}

void sortVector(TIndex *indices, int cantidadRegistros)
{
    int opcionOrdenamiento;

    printf("Selecciona el método de ordenamiento:\n");
    printf("1. Selection Sort\n");
    printf("2. Quick Sort\n");
    scanf("%d", &opcionOrdenamiento);

    switch (opcionOrdenamiento)
    {
    case 1:
        selectionSort(indices, cantidadRegistros);
        printf("El vector se ha ordenado con éxito usando Selection Sort.\n");
        break;

    case 2:
        quicksort(indices, 0, cantidadRegistros - 1);
        printf("El vector se ha ordenado con éxito usando Quick Sort.\n");
        break;

    default:
        printf("Opción de ordenamiento no válida.\n");
    }
}

void printRegisters(FILE *archivoBinario, TIndex *indices, int cantidadRegistros)
{
    TWrkr trabajador;

    for (int i = 0; i < cantidadRegistros; i++)
    {
        fseek(archivoBinario, indices[i].index * sizeof(TWrkr), SEEK_SET);
        fread(&trabajador, sizeof(TWrkr), 1, archivoBinario);

        if (trabajador.status == 1)
        {
            printf("%2d || %4d || %9s || %16s || %16s || %12s || %16s || %4d || %10d\n", i + 1, trabajador.enrollment, trabajador.name, trabajador.lastName1, trabajador.lastName2,
                   trabajador.sex, trabajador.jobPosition, trabajador.age, trabajador.cellphone);
        }
    }
    printf("\n");
}

int compareRegisters(const void *a, const void *b)
{
    return ((TIndex *)a)->key - ((TIndex *)b)->key;
}

void printSortedRegisters(FILE *archivoBinario, TIndex *indices, int cantidadRegistros)
{
    TWrkr trabajador;

    qsort(indices, cantidadRegistros, sizeof(TIndex), compareRegisters);

    for (int i = 0; i < cantidadRegistros; i++)
    {
        fseek(archivoBinario, indices[i].index * sizeof(TWrkr), SEEK_SET);
        fread(&trabajador, sizeof(TWrkr), 1, archivoBinario);

        if (trabajador.status == 1)
        {
            printf("%2d || %4d || %9s || %16s || %16s || %12s || %16s || %4d || %10d\n", i + 1, trabajador.enrollment, trabajador.name, trabajador.lastName1, trabajador.lastName2,
                   trabajador.sex, trabajador.jobPosition, trabajador.age, trabajador.cellphone);
        }
    }
    printf("\n");
}

void generateTxtFile(FILE *archivoBinario, TIndex *indices, int cantidadRegistros)
{
    FILE *archivoTxt;
    char nombreArchivo[50];
    char opcion;

    printf("Ingrese el nombre del archivo de texto: ");
    scanf("%s", nombreArchivo);

    printf("¿Desea ordenar los registros? (S/N): ");
    scanf(" %c", &opcion);

    archivoTxt = fopen(nombreArchivo, "w");
    if (archivoTxt == NULL)
    {
        printf("Error al abrir el archivo de texto.\n");
        return;
    }

    if (opcion == 'S' || opcion == 's')
    {
        qsort(indices, cantidadRegistros, sizeof(TIndex), compareRegisters);

        for (int i = 0; i < cantidadRegistros; i++)
        {
            fseek(archivoBinario, indices[i].index * sizeof(TWrkr), SEEK_SET);
            TWrkr trabajador;
            fread(&trabajador, sizeof(TWrkr), 1, archivoBinario);

            fprintf(archivoTxt, "%2d || %4d || %9s || %16s || %16s || %12s || %16s || %4d || %10d\n", i + 1, trabajador.enrollment, trabajador.name, trabajador.lastName1,
                    trabajador.lastName2, trabajador.sex, trabajador.jobPosition, trabajador.age, trabajador.cellphone);
        }
    }
    else
    {
        for (int i = 0; i < cantidadRegistros; i++)
        {
            fseek(archivoBinario, indices[i].index * sizeof(TWrkr), SEEK_SET);
            TWrkr trabajador;
            fread(&trabajador, sizeof(TWrkr), 1, archivoBinario);

            fprintf(archivoTxt, "%2d || %4d || %9s || %16s || %16s || %12s || %16s || %4d || %10d\n", i, trabajador.enrollment, trabajador.name, trabajador.lastName1,
                    trabajador.lastName2, trabajador.sex, trabajador.jobPosition, trabajador.age, trabajador.cellphone);
        }
    }

    fclose(archivoTxt);
    printf("Archivo de texto generado con éxito.\n");
}

void packageRegisters()
{
    FILE *doc = fopen("datos.dat", "rb");
    ;
    FILE *fa = fopen("datos.bak", "wb");

    TWrkr reg;

    if (doc)
    {
        while (fread(&reg, sizeof(TWrkr), 1, doc))
        {
            if (reg.status == 1)
            {
                fwrite(&reg, sizeof(TWrkr), 1, fa);
            }
        }
    }

    fclose(doc);
    fclose(fa);
}

int msges()
{
    int option;
    printf("--- MENU ---\n");
    printf("\t1. Add register\n");
    printf("\t2. Delete register\n");
    printf("\t3. Search register\n");
    printf("\t4. Sort register\n");
    printf("\t5. Print registers\n");
    printf("\t6. Print sorted registers\n");
    printf("\t7. Generate txt file\n");
    printf("\t8. Package registers\n");
    printf("\t9. Exit\n\n");
    printf("Select an option: ");
    option = validate(0, 9);
    return option;
}

void menu()
{
    FILE *archivoBinario;
    archivoBinario = fopen("datos.dat", "rb");

    if (archivoBinario == NULL)
    {
        printf("Error al abrir el archivo de registros.dat\n");
        return;
    }

    int REGISTERS = obtenerCantidadRegistros(archivoBinario);
    int MAX_REGISTERS = REGISTERS * 1.25;
    printf("Number of registers: %d\n", REGISTERS);
    printf("Number of indices: %d\n", MAX_REGISTERS);
    TIndex indices[MAX_REGISTERS];
    TWrkr registros[MAX_REGISTERS];
    int cantidadRegistros = 0;

    cargarIndicesDesdeArchivo(archivoBinario, indices, &MAX_REGISTERS);

    int option;
    bool sorted = false;

    do
    {
        option = msges();

        switch (option)
        {
        case 1:
            addRegister(archivoBinario, indices, &MAX_REGISTERS);
            break;
        case 2:
            deleteRegister(archivoBinario, indices, &MAX_REGISTERS);
            break;
        case 3:
            searchRegister(archivoBinario, indices, MAX_REGISTERS, sorted);
            break;

        case 4:
            sortVector(indices, MAX_REGISTERS);
            sorted = true;
            break;

        case 5:
            printRegisters(archivoBinario, indices, MAX_REGISTERS);
            break;

        case 6:
            printSortedRegisters(archivoBinario, indices, MAX_REGISTERS);
            break;

        case 7:
            generateTxtFile(archivoBinario, indices, MAX_REGISTERS);
            break;

        case 8:
            packageRegisters();
            break;

        case 9:
            printf("Saliendo del programa...\n");
            fclose(archivoBinario);
            break;

        default:
            printf("Invalid option. Select another one.\n");
        }
        system("PAUSE");
    } while (option != 9);
}

int main()
{
    srand(time(NULL));
    menu();
    return 0;
}