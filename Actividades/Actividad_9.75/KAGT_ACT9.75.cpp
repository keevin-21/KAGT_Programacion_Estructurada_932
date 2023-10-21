#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "kewvyValidates.h"
#include "listas.h"

char obtenerPrimeraVocal(char *cadena)
{
    char vocal = 'X';
    while (*cadena)
    {
        if (strchr("AEIOUaeiou", *cadena))
        {
            vocal = toupper(*cadena);
            break;
        }
        cadena++;
    }
    return vocal;
}

char obtenerSegundaConsonante(const char *cadena)
{
    int contadorConsonantes = 0;
    while (*cadena)
    {
        char caracter = *cadena;
        if (isalpha(caracter) && !strchr("AEIOU", caracter))
        {
            contadorConsonantes++;
            if (contadorConsonantes == 2)
            {
                return caracter;
            }
        }
        cadena++;
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

int validarEntidad(char *cadena, char entidades[][3], int numEntidades)
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

int validarAntisonante(char *cadena, char antisonantes[][5], int numAntisonantes)
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

void obtenerSegundoNombre(char *nombre)
{
    char *segundoNombre = NULL;

    // Encuentra el segundo nombre separando la cadena por espacios
    strtok(nombre, " "); // Ignora el primer nombre
    segundoNombre = strtok(NULL, " ");

    if (segundoNombre != NULL && segundoNombre[0] != '\0')
    {
        nombre[0] = segundoNombre[0];
    }
    else
    {
        nombre[0] = 'X';
    }
}

void omitirNombres(char nombre[], const char partes[][6])
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
            noSpacesString(nombre);
        }
    }
}

void omitirPartes(char apellido[], const char partes[][4])
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
            noSpacesString(apellido);
        }
    }
}

void omitirEnie(char cadena[])
{
    if (cadena[0] == -91 || cadena[0] == -92)
    {
        cadena[0] = 'X';
    }
}

int main()
{
    srand(time(NULL));

    char nombre[50];
    char primer_apellido[50];
    int opcionApellido;
    char segundo_apellido[50];
    int banderaApellidoMat;
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
    char curp[19];

    printf("Generador de CURP\n");
    printf("Ingrese los siguientes datos:\n");

    printf("Nombre: ");
    validateString(nombre, sizeof(nombre));
    omitirNombres(nombre, nombresCortos);
    omitirEnie(nombre);
    system("CLS");

    printf("Apellido Paterno: ");
    validateString(primer_apellido, sizeof(primer_apellido));
    omitirPartes(primer_apellido, partes);
    omitirEnie(primer_apellido);
    system("CLS");

    printf("Apellido Materno: ");
    validateString(segundo_apellido, sizeof(segundo_apellido));
    omitirPartes(segundo_apellido, partes);
    omitirEnie(segundo_apellido);
    system("CLS");

    printf("Ano: ");
    anio = validate(1910, 2023);
    sprintf(canio, "%d", anio);
    system("CLS");

    printf("Mes: ");
    mes = validate(1, 12);
    sprintf(cmes, "%d", mes);
    system("CLS");

    printf("Dia: ");
    if (mes == 2 && esBisiesto(anio) == 1)
    {
        dia = validate(1, 29);
    }
    else
    {
        if (mes == 2 && esBisiesto(anio) == 0)
        {
            dia = validate(1, 28);
        }
        else
        {
            if (mes == 1 || mes == 3 || mes == 5 || mes == 7 || mes == 8 || mes == 10 || mes == 12)
            {
                dia = validate(1, 31);
            }
            else
            {
                if (mes == 4 || mes == 6 || mes == 9 || mes == 11)
                {
                    dia = validate(1, 30);
                }
            }
        }
    }
    sprintf(cdia, "%d", dia);
    system("CLS");

    printf("Género (H o M): ");
    validateString(genero, sizeof(genero));
    while (genero[0] != 'H' && genero[0] != 'M')
    {
        printf("Error - Letra no aceptada, solo H o M.\n");
        printf("Género (H o M): ");
        validateString(genero, sizeof(genero));
    }
    system("CLS");

    printf("Aguascalientes (AG)\n");
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
    validateString(entidad_nacimiento, sizeof(entidad_nacimiento));
    while (validarEntidad(entidad_nacimiento, estados, sizeof(estados) / sizeof(estados[0])) == 0)
    {
        printf("Entidad no válida. Ingresa una abreviatura válida.\n");
        printf("Entidad de Nacimiento: ");
        validateString(entidad_nacimiento, sizeof(entidad_nacimiento));
    }
    system("CLS");

    curp[0] = toupper(primer_apellido[0]);
    curp[1] = obtenerPrimeraVocal(primer_apellido);
    curp[2] = toupper(segundo_apellido[0]);
    curp[3] = toupper(nombre[0]);
    curp[4] = canio[2];
    curp[5] = canio[3];
    if (mes < 10)
    {
        curp[6] = '0';
        curp[7] = cmes[0];
    }
    else
    {
        curp[6] = cmes[0];
        curp[7] = cmes[1];
    }
    if (dia < 10)
    {
        curp[8] = '0';
        curp[9] = cdia[0];
    }
    else
    {
        curp[8] = cdia[0];
        curp[9] = cdia[1];
    }

    curp[10] = toupper(genero[0]);
    curp[11] = entidad_nacimiento[0];
    curp[12] = entidad_nacimiento[1];
    curp[13] = obtenerSegundaConsonante(primer_apellido);
    curp[14] = obtenerSegundaConsonante(segundo_apellido);
    curp[15] = obtenerSegundaConsonante(nombre);
    if (anio < 2000)
    {
        curp[16] = canio[2];
    }
    else
    {
        if (anio >= 2000 && anio < 2010)
        {
            curp[16] = 'A';
        }
        else
        {
            if (anio >= 2010)
            {
                curp[16] = 'B';
            }
        }
    }
    ultimoDigito = randomNumber(0, 9);
    sprintf(cultimoDigito, "%d", ultimoDigito);
    curp[17] = cultimoDigito[0];
    curp[18] = '\0';

    if (validarAntisonante(curp, antisonantes, sizeof(antisonantes) / sizeof(antisonantes[0])))
    {
        curp[1] = 'X';
    }

    printf("La CURP generada es: %s\n", curp);

    return 0;
}