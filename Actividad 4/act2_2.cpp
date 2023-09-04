#include <stdio.h>

int main() {
    float opc, inch, cm, miles, feet, km;

    printf("- MENU DE OPCIONES -\n");
    printf("===========================\n");
    printf("1.- CENTIMETROS A PULGADAS\n");
    printf("2.- CENTIMETROS A PIES\n");
    printf("3.- KILOMETROS A MILLAS\n");
    printf("4.- PULGADAS A CENTIMETROS\n");
    printf("5.- PIES A CENTIMETROS\n");
    printf("6.- MILLAS A CENTIMETROS\n");
    printf("===========================\n");
    printf("ELIGE UNA OPCION: ");
    scanf("%f", &opc);

    switch ((int)opc) {
        case 1:
            printf("CENTIMETROS A PULGADAS\n");
            printf("========================\n");
            printf("Centimetros: ");
            scanf("%f", &cm);
            inch = cm * 0.393701;
            printf("Tu medida en pulgadas es de: %.2f\n", inch);
            break;

        case 2:
            printf("CENTIMETROS A PIES\n");
            printf("========================\n");
            printf("Centimetros: ");
            scanf("%f", &cm);
            feet = cm * 0.0328084;
            printf("Tu medida en pies es de: %.2f\n", feet);
            break;

        case 3:
            printf("KILOMETROS A MILLAS\n");
            printf("========================\n");
            printf("Kilometros: ");
            scanf("%f", &km);
            miles = km * 0.621371;
            printf("Tu medida en millas es de: %.2f\n", miles);
            break;

        case 4:
            printf("PULGADAS A CENTIMETROS\n");
            printf("========================\n");
            printf("Pulgadas: ");
            scanf("%f", &inch);
            cm = inch * 2.54;
            printf("Tu medida en centimetros es de: %.2f\n", cm);
            break;

        case 5:
            printf("PIES A CENTIMETROS\n");
            printf("========================\n");
            printf("Pies: ");
            scanf("%f", &feet);
            cm = feet * 30.48;
            printf("Tu medida en centimetros es de: %.2f\n", cm);
            break;

        case 6:
            printf("MILLAS A CENTIMETROS\n");
            printf("========================\n");
            printf("Millas: ");
            scanf("%f", &miles);
            cm = miles * 160934;
            printf("Tu medida en centimetros es de: %.2f\n", cm);
            break;

        default:
            printf("ERROR - ESTA NO ES UNA OPCION VALIDA\n");
    }

    return 0;
}
