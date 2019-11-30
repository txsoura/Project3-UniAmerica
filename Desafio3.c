#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>

typedef struct acc
{
    int injury, day, month;
    float lon, lat;
    char country[30], airport[5], damage[13], category[13], broad[13];
} ACCIDENT;

//número máximo de linhas que o ficheiro terá
#define MAX_LINE 300
//nodo do ficheiro
#define FILE_NAME "ntsb.txt"

ACCIDENT vacc[MAX_LINE];

void menu(), devloper(), injuryavg(int ls), findCoord(int ls), bigSmall(int ls), access(), view(int ls);
int textfile();

//método principal
void main()
{
    system("cls");
    menu();
}

//método que imprime e valida as opções do menu
void menu()
{
    int opc = 0, ls = 0, blk = 0;

    do
    {
        printf("\n1. Read file\n2. Calculate  average of accident deaths per year  \n3. Search by coordenates \n4. Bigger and smaller date\n5. View file\n6. About developer \n7. Exit\n****************************\n");
        scanf("%d", &opc);

        switch (opc)
        {
        //opcao 1
        case 1:
            system("cls");
            ls = textfile();
            blk = 1;
            break;
        //opcao 2
        case 2:
            if (blk == 1)
            {
                system("cls");
                injuryavg(ls);
            }
            else
            {
                access();
            }
            break;
        //opcao 3
        case 3:
            if (blk == 1)
            {
                system("cls");
                findCoord(ls);
            }
            else
            {
                access();
            }
            break;
        //opcao 4
        case 4:
            if (blk == 1)
            {
                system("cls");
                bigSmall(ls);
            }
            else
            {
                access();
            }
            break;
        //opcao 5
        case 5:
            if (blk == 1)
            {
                system("cls");
                view(ls);
            }
            else
            {
                access();
            }
            break;
        //opcao 6
        case 6:
            system("cls");
            devloper();
            break;
        //opcao 7
        case 7:
            exit(0);
            break;
        default:
            printf("\nXXXXXXXXXXXXXXXXXXXXXXX Choose from 1 to 7 XXXXXXXXXXXXXXXXXXXXXXX\n");
            break;
        }

    } while (opc != 7);
}

//método para imprimir dados do devloper
void devloper()
{
    printf("______  Developer  ______\nName: Victor Tesoura Junior\nVersion: 1.0\nUniAmerica: Challenge 3 (semester 1)\n____________________________\n");
}

//método para mensagem de erro, caso não se tenha lido o ficheiro
void access()
{
    printf("XXXXXXXXXXXXXXXXXXXXXXX Access denied. Please, open de menu option 1 and try again! XXXXXXXXXXXXXXXXXXXXXXX\n");
}

//método para fazer leirura do ficheiro de texto e armazenar no vetor
int textfile()
{
    FILE *file;
    char line[93];
    char *pstr;

    int i = 0;

    file = fopen(FILE_NAME, "r");
    if (!file)
    {
        printf("Error opening file\n");
        printf("%s\n", "****************************************************************************************************************************");
    }

    //salta a primeira lnha do textfile
    fseek(file, 93, SEEK_SET);

    while ((fgets(line, 93, file) != NULL) && (i < MAX_LINE))
    {
        pstr = strtok(line, ",");
        vacc[i].month = atoi(pstr);

        pstr = strtok(NULL, ",");
        vacc[i].day = atoi(pstr);

        pstr = strtok(NULL, ",");
        strcpy(vacc[i].country, pstr);

        pstr = strtok(NULL, ",");
        strcpy(vacc[i].airport, pstr);

        pstr = strtok(NULL, ",");
        vacc[i].injury = atoi(pstr);

        pstr = strtok(NULL, ",");
        strcpy(vacc[i].damage, pstr);

        pstr = strtok(NULL, ",");
        strcpy(vacc[i].category, pstr);

        pstr = strtok(NULL, ",");
        strcpy(vacc[i].broad, pstr);

        pstr = strtok(NULL, ",");
        vacc[i].lon = atof(pstr);

        pstr = strtok(NULL, ",");
        vacc[i].lat = atof(pstr);

        ++i;
    }

    fclose(file);

    printf("File read successfully!");

    return i;
}

//metodo para visualizar o vetor
void view(int ls)
{
    printf("%5s%30s%8s%8s%13s%13s%13s%13s%13s\n", "Date", " Country", "Airport", "Injury", "Damage", "Category", "Broad phase", "Longitude", "Latitude");
    printf("%s\n", "-----------------------------------------------------------------------------------------------------------------------");

    for (int j = 0; j < ls; j++)
    {

        printf("%2d", vacc[j].month);
        printf("%1s", "/");
        printf("%2d", vacc[j].day);
        printf("%30s", vacc[j].country);
        printf("%8s", vacc[j].airport);
        printf("%8d", vacc[j].injury);
        printf("%13s", vacc[j].damage);
        printf("%13s", vacc[j].category);
        printf("%13s", vacc[j].broad);
        printf("%1s", " ");
        printf("%5.8f", vacc[j].lon);
        printf("%1s", " ");
        printf("%5.8f\n", vacc[j].lat);
    }
    printf("%s\n", "-----------------------------------------------------------------------------------------------------------------------");
    getch();
}
//metodo para calcular o nnumero de mortes e sua media
void injuryavg(int ls)
{
    int inj = 0;
    float md = 0;
    for (int i = 0; i < ls; i++)
    {
        inj += vacc[i].injury;
    }

    md = inj / ls;

    printf("Death's: %d fatal\n", inj);
    printf("Average: %.1f fatal per year", md);
}

//metodo para procurar pelas coordenadas
void findCoord(int ls)
{
    float ln, lt;

    printf("Type the longitude\n");
    scanf("%f", &ln);
    printf("Type the latitude\n");
    scanf("%f", &lt);

    for (int i = 0; i < ls; i++)
    {
        if (vacc[i].lon == ln && vacc[i].lat == lt)
        {
            printf("%2d", vacc[i].month);
            printf("%1s", "/");
            printf("%2d", vacc[i].day);
            printf("%30s", vacc[i].country);
            printf("%8s", vacc[i].airport);
            printf("%8d", vacc[i].injury);
            printf("%13s", vacc[i].damage);
            printf("%13s", vacc[i].category);
            printf("%13s", vacc[i].broad);
            printf("%1s", " ");
            printf("%5.8f", vacc[i].lon);
            printf("%1s", " ");
            printf("%5.8f\n", vacc[i].lat);
        }
    }
}

//metodo para mostrar o maior e menor
void bigSmall(int ls)
{
    int bmonth = 0, bday = 0, smonth = 13, sday = 32;

    for (int i = 0; i < ls; i++)
    {

        if (vacc[i].month > bmonth)
        {
            bmonth = vacc[i].month;
        }
        if (vacc[i].month < smonth)
        {
            smonth = vacc[i].month;
        }
        if (vacc[i].day > bday)
        {
            bday = vacc[i].day;
        }
        if (vacc[i].day < sday)
        {
            sday = vacc[i].day;
        }
    }
    printf("Bigger date: %2d/%2d\n", bmonth, bday);
    printf("Smaller date: %2d/%2d", smonth, sday);
}