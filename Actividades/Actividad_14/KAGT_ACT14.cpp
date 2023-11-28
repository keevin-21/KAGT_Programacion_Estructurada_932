/*
Kevin Alejandro Gonzalez Torres - 372354

Creado el: 26 de Noviembre del 2023 / Modificado el 28 de Noviembre del 2023
*/

#include "junior.h"

typedef int TKey;

typedef struct _Worker
{
    int status;
    TKey enrollment;
    char name[30];
    char lastName1[50];
    char lastName2[50];
    char sex[15];
    char jobPosition[30];
    char state[30];
    int age;
    TKey cellphone;
} TWorker;

typedef struct _Index
{
    TKey key;
    int index;
} TIndex;

int getNumberOfRecords(FILE *binaryFile)
{
    fseek(binaryFile, 0, SEEK_END);
    int size = ftell(binaryFile);
    rewind(binaryFile);

    return size / sizeof(TWorker);
}

void loadIndicesFromFile(FILE *binaryFile, TIndex *indices, int *numberOfRecords)
{
    *numberOfRecords = getNumberOfRecords(binaryFile);

    int sizeOfIndexArray = (*numberOfRecords) + (*numberOfRecords / 4);

    TWorker worker;
    int index = 0;

    while (fread(&worker, sizeof(TWorker), 1, binaryFile) == 1)
    {
        if (worker.status == 1)
        {
            indices[index].key = worker.enrollment;
            indices[index].index = index;
            index++;
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

TWorker autoDataRecord()
{
    char femaleNames[][30] = {"MARIA", "ANA", "LAURA", "ISABEL", "CAROLINA", "GABRIELA", "ELENA", "PATRICIA", "VALENTINA", "CAMILA", "SOFIA", "ADRIANA", "RAQUEL", "JULIA", "CLARA", "BEATRIZ", "LUCIA", "LORENA", "NATALIA", "AURORA"};
    char maleNames[][30] = {"ALEJANDRO", "JAVIER", "ANDRES", "LUIS", "DANIEL", "MARTIN", "SERGIO", "DIEGO", "EDUARDO", "FRANCISCO", "CARLOS", "JUAN", "RAFAEL", "MARCO", "HECTOR", "GUILLERMO", "JOSE", "ANTONIO", "PEDRO", "MIGUEL"};
    char lastNames[][50] = {"PEREZ", "GONZALEZ", "RODRIGUEZ", "LOPEZ", "MARTINEZ", "SANCHEZ", "RAMIREZ", "TORRES", "FERNANDEZ", "GARCIA", "DIAZ", "CRUZ", "ROMERO", "HERNANDEZ", "ALVAREZ", "MORENO", "VARGAS", "SUAREZ", "JIMENEZ", "MENDOZA", "SILVA", "ORTEGA", "MARTIN", "RUIZ", "CASTILLO", "ROJAS", "GOMEZ", "FLORES", "MORALES", "SANTOS", "CASTRO", "FERNANDEZ", "RIVERA", "MIRANDA", "NAVARRO", "ARIAS", "GUTIERREZ", "VIDAL"};
    char jobPositions[][30] = {"HR_MANAGER", "MARKETING_ANALYST", "SOFTWARE_ENGINEER", "TECH_SUPPORT", "NETWORK_ADMIN", "WEB_DESIGNER", "QA_ENGINEER", "CORP_FINANCE", "DATA_ANALYST", "LEGAL_ADVISOR", "RETAIL_SALES", "GRAPHIC_DESIGNER", "LOGISTICS", "CUSTOMER_SERVICE", "EVENT_MANAGER", "SYS_ADMIN", "SALES_MANAGER", "RECRUITER", "EXECUTIVE", "MARKETING_MANAGER", "APP_DEVELOPER", "TECH_TRAINER", "SOCIAL_MEDIA", "SUPPLY_CHAIN"};
    char states[][3] = {"AG", "BC", "BS", "CM", "CS", "CH", "CL", "CM", "DG", "GT", "GR", "HG", "JC", "MC", "MN", "MS", "NA", "NL", "OA", "PU", "QE", "QR", "SL", "SI", "SO", "TB", "TM", "TS", "VZ", "YN", "ZS"};

    TWorker worker;

    worker.status = 1;

    worker.enrollment = randomNumber(100000, 199999);

    strcpy(worker.lastName1, lastNames[randomNumber(0, 19)]);
    puts(worker.lastName1);
    strcpy(worker.lastName2, lastNames[randomNumber(0, 19)]);
    puts(worker.lastName2);
    strcpy(worker.jobPosition, jobPositions[randomNumber(0, 23)]);

    if (randomNumber(0, 1) == 1)
    {
        strcpy(worker.name, maleNames[randomNumber(0, 19)]);
        strcpy(worker.sex, "MALE");
    }
    else
    {
        strcpy(worker.name, femaleNames[randomNumber(0, 19)]);
        strcpy(worker.sex, "FEMALE");
    }

    strcpy(worker.state, states[randomNumber(0, 31)]);

    worker.age = randomNumber(18, 45);

    worker.cellphone = randomNumber(1000000, 1999999);

    return worker;
}

void addRecord(FILE *binaryFile, TIndex *indices, int *numberOfRecords)
{
    TWorker record = autoDataRecord();

    for (int i = 0; i < *numberOfRecords; i++)
    {
        if (indices[i].key == record.enrollment)
        {
            printf("Error: The enrollment already exists. The record cannot be added.\n");
            return;
        }
    }

    fseek(binaryFile, 0, SEEK_END);
    fwrite(&record, sizeof(TWorker), 1, binaryFile);

    indices[*numberOfRecords].key = record.enrollment;
    indices[*numberOfRecords].index = *numberOfRecords;

    (*numberOfRecords)++;

    printf("Record added successfully.\n");
}

void deleteRecord(FILE *binaryFile, TIndex *indices, int *numberOfRecords)
{
    int enrollmentToDelete;

    printf("Enter the enrollment to delete: ");
    enrollmentToDelete = validate(300000, 399999);

    int foundIndex = -1;

    for (int i = 0; i < *numberOfRecords; i++)
    {
        if (indices[i].key == enrollmentToDelete)
        {
            foundIndex = i;
        }
    }

    if (foundIndex == -1)
    {
        printf("No record found with the specified enrollment.\n");
    }

    fseek(binaryFile, indices[foundIndex].index * sizeof(TWorker), SEEK_SET);
    TWorker recordToDelete;
    fread(&recordToDelete, sizeof(TWorker), 1, binaryFile);

    printf("Record found:\n");
    printf("Enrollment: %d\n", recordToDelete.enrollment);
    printf("Name: %s %s %s\n", recordToDelete.name, recordToDelete.lastName1, recordToDelete.lastName2);
    printf("Sex: %s\n", recordToDelete.sex);
    printf("Job Position: %s\n", recordToDelete.jobPosition);
    printf("State: %s\n", recordToDelete.state);
    printf("Age: %d\n", recordToDelete.age);
    printf("Cellphone: %d\n\n", recordToDelete.cellphone);

    char response;
    printf("Do you want to delete this record? (Y/N): ");
    scanf(" %c", &response);

    if (response == 'Y' || response == 'y')
    {
        recordToDelete.status = 0;
        fseek(binaryFile, indices[foundIndex].index * sizeof(TWorker), SEEK_SET);
        fwrite(&recordToDelete, sizeof(TWorker), 1, binaryFile);

        printf("Record deleted successfully.\n");
    }
    else
    {
        printf("Record not deleted.\n");
    }
}

void searchRecord(FILE *binaryFile, TIndex *indices, int numberOfRecords, bool sorted)
{
    int enrollmentToSearch;
    TWorker recordFound;

    printf("Enter the enrollment to search: ");
    scanf("%d", &enrollmentToSearch);

    int foundIndex = -1;

    if (sorted)
    {
        foundIndex = binarySearch(indices, 0, numberOfRecords - 1, enrollmentToSearch);
    }
    else
    {
        foundIndex = linearSearch(indices, numberOfRecords, enrollmentToSearch);
    }

    if (foundIndex != -1 || recordFound.status == 1)
    {
        fseek(binaryFile, indices[foundIndex].index * sizeof(TWorker), SEEK_SET);

        fread(&recordFound, sizeof(TWorker), 1, binaryFile);

        printf("Record found:\n");
        printf("Enrollment: %d\n", recordFound.enrollment);
        printf("Name: %s %s %s\n", recordFound.name, recordFound.lastName1, recordFound.lastName2);
        printf("Sex: %s\n", recordFound.sex);
        printf("Job Position: %s\n", recordFound.jobPosition);
        printf("State: %s\n", recordFound.state);
        printf("Age: %d\n", recordFound.age);
        printf("Cellphone: %d\n", recordFound.cellphone);
    }
    else
    {
        printf("No record found with the specified enrollment.\n");
    }
}

void sortArray(TIndex *indices, int numberOfRecords)
{
    int sortingOption;

    printf("Select the sorting method:\n");
    printf("1. Selection Sort\n");
    printf("2. Quick Sort\n");
    scanf("%d", &sortingOption);

    switch (sortingOption)
    {
    case 1:
        selectionSort(indices, numberOfRecords);
        printf("The array has been sorted successfully using Selection Sort.\n");
        break;

    case 2:
        quicksort(indices, 0, numberOfRecords - 1);
        printf("The array has been sorted successfully using Quick Sort.\n");
        break;

    default:
        printf("Invalid sorting option.\n");
    }
}

void printRecords(FILE *binaryFile, TIndex *indices, int numberOfRecords)
{
    TWorker worker;

    for (int i = 0; i < numberOfRecords; i++)
    {
        fseek(binaryFile, indices[i].index * sizeof(TWorker), SEEK_SET);
        fread(&worker, sizeof(TWorker), 1, binaryFile);

        if (worker.status == 1)
        {
            printf("%2d || %4d || %9s || %16s || %16s || %12s || %16s || %4d || %3s || %10d\n", i + 1, worker.enrollment, worker.name, worker.lastName1, worker.lastName2,
                   worker.sex, worker.jobPosition, worker.age, worker.state, worker.cellphone);
        }
    }
    printf("\n");
}

int compareRecords(const void *a, const void *b)
{
    return ((TIndex *)a)->key - ((TIndex *)b)->key;
}

void printSortedRecords(FILE *binaryFile, TIndex *indices, int numberOfRecords)
{
    TWorker worker;

    qsort(indices, numberOfRecords, sizeof(TIndex), compareRecords);

    for (int i = 0; i < numberOfRecords; i++)
    {
        fseek(binaryFile, indices[i].index * sizeof(TWorker), SEEK_SET);
        fread(&worker, sizeof(TWorker), 1, binaryFile);

        if (worker.status == 1)
        {
            printf("%2d || %4d || %9s || %16s || %16s || %12s || %16s || %4d || %3s || %10d\n", i + 1, worker.enrollment, worker.name, worker.lastName1, worker.lastName2,
                   worker.sex, worker.jobPosition, worker.age, worker.state, worker.cellphone);
        }
    }
    printf("\n");
}

void generateTxtFile(FILE *binaryFile, TIndex *indices, int numberOfRecords)
{
    FILE *textFile;
    char fileName[50];
    char option;

    printf("Enter the name of the text file: ");
    scanf("%s", fileName);

    strcat(fileName, ".txt");

    printf("Do you want to sort the records? (Y/N): ");
    scanf(" %c", &option);

    textFile = fopen(fileName, "w");
    if (textFile == NULL)
    {
        printf("Error opening the text file.\n");
        return;
    }

    if (option == 'Y' || option == 'y')
    {
        qsort(indices, numberOfRecords, sizeof(TIndex), compareRecords);

        for (int i = 0; i < numberOfRecords; i++)
        {
            fseek(binaryFile, indices[i].index * sizeof(TWorker), SEEK_SET);
            TWorker worker;
            fread(&worker, sizeof(TWorker), 1, binaryFile);

            fprintf(textFile, "%2d || %4d || %9s || %16s || %16s || %12s || %16s || %4d || %10d\n", i + 1, worker.enrollment, worker.name, worker.lastName1,
                    worker.lastName2, worker.sex, worker.jobPosition, worker.age, worker.cellphone);
        }
    }
    else
    {
        for (int i = 0; i < numberOfRecords; i++)
        {
            fseek(binaryFile, indices[i].index * sizeof(TWorker), SEEK_SET);
            TWorker worker;
            fread(&worker, sizeof(TWorker), 1, binaryFile);

            fprintf(textFile, "%2d || %4d || %9s || %16s || %16s || %12s || %16s || %4d || %10d\n", i, worker.enrollment, worker.name, worker.lastName1,
                    worker.lastName2, worker.sex, worker.jobPosition, worker.age, worker.cellphone);
        }
    }

    fclose(textFile);
    printf("Text file generated successfully.\n");
}

void packageRecords()
{
    FILE *doc = fopen("data.dat", "rb");
    ;
    FILE *backup = fopen("data.bak", "wb");

    TWorker record;

    if (doc)
    {
        while (fread(&record, sizeof(TWorker), 1, doc))
        {
            if (record.status == 1)
            {
                fwrite(&record, sizeof(TWorker), 1, backup);
            }
        }
    }

    fclose(doc);
    fclose(backup);
}

int messages()
{
    int option;
    printf("--- MENU ---\n");
    printf("\t1. Add record\n");
    printf("\t2. Delete record\n");
    printf("\t3. Search record\n");
    printf("\t4. Sort record\n");
    printf("\t5. Print records\n");
    printf("\t6. Print sorted records\n");
    printf("\t7. Generate text file\n");
    printf("\t8. Package records\n");
    printf("\t9. Exit\n\n");
    printf("Select an option: ");
    option = validate(0, 9);
    return option;
}

void menu()
{
    FILE *binaryFile;
    binaryFile = fopen("datos.dat", "rb");

    if (binaryFile == NULL)
    {
        printf("Error opening the data.dat file\n");
        return;
    }

    int RECORDS = getNumberOfRecords(binaryFile);
    int MAX_RECORDS = RECORDS * 1.25;
    printf("Number of records: %d\n", RECORDS);
    printf("Number of indices: %d\n", MAX_RECORDS);
    TIndex indices[MAX_RECORDS];
    TWorker records[MAX_RECORDS];
    int numberOfRecords = 0;

    loadIndicesFromFile(binaryFile, indices, &MAX_RECORDS);

    int option;
    bool sorted = false;

    do
    {
        option = messages();

        switch (option)
        {
        case 1:
            addRecord(binaryFile, indices, &MAX_RECORDS);
            break;
        case 2:
            deleteRecord(binaryFile, indices, &MAX_RECORDS);
            break;
        case 3:
            searchRecord(binaryFile, indices, MAX_RECORDS, sorted);
            break;

        case 4:
            sortArray(indices, MAX_RECORDS);
            sorted = true;
            break;

        case 5:
            printRecords(binaryFile, indices, MAX_RECORDS);
            break;

        case 6:
            printSortedRecords(binaryFile, indices, MAX_RECORDS);
            break;

        case 7:
            generateTxtFile(binaryFile, indices, MAX_RECORDS);
            break;

        case 8:
            packageRecords();
            break;

        case 9:
            printf("Exiting the program...\n");
            fclose(binaryFile);
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
