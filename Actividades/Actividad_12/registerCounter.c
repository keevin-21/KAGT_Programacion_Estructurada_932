#include <stdio.h>
#include <string.h>

int main(int args, char *arg[])
{
    FILE *file;
    int size = 0;
    char fileName[50];
    int x;
    int enrolment;
    char name[20], fatherLastname[20], motherLastname[20];
    int age;
    char gender[10];
    char line[100];

    strcpy(fileName, arg[1]);
    strcat(fileName, ".txt");

    file = fopen(fileName, "r");
    if (file)
    {
        while (fgets(line, sizeof(line), file) != NULL)
        {

            int variablesRead;

            variablesRead = sscanf(line, "%i.- %i %s %s %s %i %s",
                                   &x, &enrolment, name, fatherLastname, motherLastname, &age, gender);

            if (variablesRead)
            {
                size++;
            }
        }
        fclose(file);
        return size - 1;
    }
    else
    {
        return -1;
    }
    return 0;
}