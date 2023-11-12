#include <stdio.h>
#include <string.h>

int main(int args, char *arg[])
{
    FILE *fa;
    int position = 0;
    char fileName[50];
    int tempNum;
    int tempNum2;
    char name[20], fatherLastname[20], motherLastname[20];
    int age;
    char gender[10];

    strcpy(fileName, arg[1]);
    strcat(fileName, ".txt");

    fa = fopen(fileName, "r");
    if (fa)
    {
        do
        {
            fscanf(fa, "%d.- %d %s %s %s %d %s",
                   &tempNum, &tempNum2, name, fatherLastname, motherLastname, &age, gender);
            position++;
        } while (!feof(fa));
        fclose(fa);
        return position - 1;
    }
    else
    {
        return -1;
    }
    return 0;
}