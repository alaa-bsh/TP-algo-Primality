#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define n 1000
long long data[n];
int result;
char result_str[20];
int taille = 0;
double temps_algo[4][n];
int res_algo[4][n];
FILE *sortie = NULL;

void stocker_resultat(int algo, int j, int est_premier, double temps)
{
    res_algo[algo - 1][j] = est_premier;
    temps_algo[algo - 1][j] = temps;
}

void ecrire_tout()
{
    fprintf(sortie, "index,valeur,resultat,A1_ms,A2_ms,A3_ms,A4_ms\n");
    for (int j = 0; j < taille; j++)
    {
        fprintf(sortie, "%d,%lld,%s,%.6f,%.6f,%.6f,%.6f\n",
                j, data[j],
                res_algo[3][j] ? "premier" : "pas premier",
                temps_algo[0][j], temps_algo[1][j],
                temps_algo[2][j], temps_algo[3][j]);
    }
}

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

        for (long long i = 2; i < data[j]; i++)
        {
            if (data[j] % i == 0)
            {
                result = 0;
                break;
            }
        }

        fin = clock();
        temps = calcule_temps(debut, fin);
        stocker_resultat(1, j, result, temps);
        if (result == 1)
        {
            strcpy(result_str, "premier");
        }
        else
        {
            strcpy(result_str, "pas premier");
        }

        printf("%d/%lld : %s | Temps : %.6f ms\n",
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
        for (long long i = 2; i <= data[j] / 2; i++)
        {
            if (data[j] % i == 0)
            {
                result = 0;
                break;
            }
        }

        clock_t fin = clock();
        double temps = calcule_temps(debut, fin);
        stocker_resultat(2, j, result, temps);
        if (result == 1)
        {
            strcpy(result_str, "premier");
        }
        else
        {
            strcpy(result_str, "pas premier");
        }
        printf("%d/%lld : %s | Temps : %.6f ms\n", j, data[j], result_str, temps);
    }

    return 0;
}

int A3()
{
    for (int j = 0; j < taille; j++)
    {
        result = 1;
        clock_t debut = clock();
        for (long long i = 2; i * i <= data[j]; i++)
        {
            if (data[j] % i == 0)
            {
                result = 0;
                break;
            }
        }

        clock_t fin = clock();
        double temps = calcule_temps(debut, fin);
        stocker_resultat(3, j, result, temps);
        if (result == 1)
        {
            strcpy(result_str, "premier");
        }
        else
        {
            strcpy(result_str, "pas premier");
        }
        printf("%d/%lld : %s | Temps : %.6f ms\n", j, data[j], result_str, temps);
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
            for (long long i = 3; i * i <= data[j]; i += 2)
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
        stocker_resultat(4, j, result, temps);
        if (result == 1)
        {
            strcpy(result_str, "premier");
        }
        else
        {
            strcpy(result_str, "pas premier");
        }
        printf("%d/%lld : %s | Temps : %.6f ms\n", j, data[j], result_str, temps);
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
    char nom_sortie[64];
    sprintf(nom_sortie, "../results/resultat_fichier%d.csv", c);
    sortie = fopen(nom_sortie, "w");
    if (sortie == NULL)
    {
        perror("Impossible de creer le fichier de sortie");
        return 1;
    }
    A1();
    A2();
    A3();
    A4();
    ecrire_tout();
    fclose(sortie);
    return 0;
}
