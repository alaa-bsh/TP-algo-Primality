#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define n 1000
long long data[n];
int result;
char result_str[10];
int taille = 0;

void lire_fichier(const char *nom_fichier)
{
    FILE *fichier = fopen(nom_fichier, "r");
    if (fichier == NULL)
        return;

    taille = 0;

    while (taille < sizeof(data) / sizeof(data[0]) &&
           fscanf(fichier, "%lld", &data[taille]) == 1)
    {
        taille++;
    }

    fclose(fichier);
}

double calcule_temps(clock_t debut, clock_t fin)
{
    return (double)(fin - debut) * 1000 / CLOCKS_PER_SEC;
}

int A1()
{
    clock_t debut, fin;
    double temps;

    for (int j = 0; j < taille; j++)
    {
        result = 1;

        debut = clock();

        for (int i = 2; i < data[j]; i++)
        {
            if (data[j] % i == 0)
            {
                result = 0;
                break;
            }
        }

        fin = clock();
        temps = calcule_temps(debut, fin);
        if (result == 1)
        {
            strcpy(result_str, "premier");
        }
        else
        {
            strcpy(result_str, "pas premier");
        }

        printf("%d/%lld : %s | Temps : %.3f ms\n",
               j, data[j], result_str, temps);
    }

    return 0;
}

int A2()
{
    for (int j = 0; j < taille; j++)
    {
        result = 1;
        clock_t debut = clock();
        for (int i = 2; i <= data[j] / 2; i++)
        {
            if (data[j] % i == 0)
            {
                result = 0;
                break;
            }
        }

        clock_t fin = clock();
        double temps = calcule_temps(debut, fin);
        if (result == 1)
        {
            strcpy(result_str, "premier");
        }
        else
        {
            strcpy(result_str, "pas premier");
        }
        printf("%d/%lld : %s | Temps : %.3f ms\n", j, data[j], result_str, temps);
    }

    return 0;
}

int A3()
{
    for (int j = 0; j < taille; j++)
    {
        result = 1;
        clock_t debut = clock();
        for (int i = 2; i * i <= data[j]; i++)
        {
            if (data[j] % i == 0)
            {
                result = 0;
                break;
            }
        }

        clock_t fin = clock();
        double temps = calcule_temps(debut, fin);
        if (result == 1)
        {
            strcpy(result_str, "premier");
        }
        else
        {
            strcpy(result_str, "pas premier");
        }
        printf("%d/%lld : %s | Temps : %.3f ms\n", j, data[j], result_str, temps);
    }

    return 0;
}

int A4()
{
    for (int j = 0; j < taille; j++)
    {
        result = 1;

        clock_t debut = clock();
        if (data[j] > 2 && data[j] % 2 == 0)
        {
            result = 0;
        }
        else if (data[j] < 2)
        {
            result = 0;
        }
        else
        {
            for (int i = 3; i * i <= data[j]; i += 2)
            {
                if (data[j] % i == 0)
                {
                    result = 0;
                    break;
                }
            }
        }
        clock_t fin = clock();
        double temps = calcule_temps(debut, fin);
        if (result == 1)
        {
            strcpy(result_str, "premier");
        }
        else
        {
            strcpy(result_str, "pas premier");
        }
        printf("%d/%lld : %s | Temps : %.3f ms\n", j, data[j], result_str, temps);
    }

    return 0;
}

int main()
{

    char chemain[100];
    int c;
    printf("choisir un fichier\n");
    scanf("%d", &c);
    switch (c)
    {
    case 1:
        strcpy(chemain, "../data/Random100.csv");
        break;
    case 2:
        strcpy(chemain, "../data/Random1000.csv");

        break;
    case 3:
        strcpy(chemain, "../data/test-1.csv");
        break;
    case 4:
        strcpy(chemain, "../data/test-2.csv");
        break;
    case 5:
        strcpy(chemain, "../data/test-3.csv");
        break;
    default:
        printf("choix invalide\n");
        return 1;
    }
    lire_fichier(chemain);
    printf("choisir un algorithme\n");
    scanf("%d", &c);
    switch (c)
    {
    case 1:
        A1();
        break;
    case 2:
        A2();
        break;
    case 3:
        A3();
        break;
    case 4:
        A4();
        break;
    default:
        printf("choix invalide\n");
        return 1;
    }

    return 0;
}
