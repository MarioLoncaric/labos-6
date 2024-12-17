#define _CRT_SECURE_NO_WARNINGS
#define _CRT_NONSTDC_NO_DEPRECATE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

int sumaMagicKvadrata(int n) {
    int tmp = n * n;
    return ((tmp * (tmp + 1)) / 2) / n;
    // suma prvih n*n brojeva i podijeli se s n
}

void upis(int** p, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf(" %d", &p[i][j]);
        }
    }
}

void ispis(int** p, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%3d", p[i][j]);
        }
        printf("\n");
    }
}

void ispuniMagicniKvadrat(int** p, int* n) {
    for (int i = 0; i < n; i++) {
        int* point = NULL;
        int zbroj = sumaMagicKvadrata(n);
        for (int j = 0; j < n; j++) {
            zbroj -= p[i][j];
            if (!p[i][j]) {
                point = &p[i][j];
            }
        }
        if (point) {
            *point = zbroj;
        }
    }
}

int provjeraMagicnogKvadrata(int** p, int n, int check) {
    // provjera redaka
    for (int i = 0; i < n; i++) {
        int zbroj = 0;
        for (int j = 0; j < n; j++) {
            zbroj += p[i][j];
        }
        if (check != zbroj) {
            return 0;
        }
    }

    // provjera stupaca
    for (int i = 0; i < n; i++) {
        int zbroj = 0;
        for (int j = 0; j < n; j++) {
            zbroj += p[j][i];
        }
        if (check != zbroj) {
            return 0;
        }
    }

    // provjera glavne dijagonale
    int zbroj = 0;
    for (int i = 0; i < n; i++) {
        zbroj += p[i][i];
    }
    if (check != zbroj) {
        return 0;
    }

    // provjera sporedne dijagonale
    zbroj = 0;
    for (int i = 0; i < n; i++) {
        zbroj += p[i][n - i - 1];
    }
    if (check != zbroj) {
        return 0;
    }


    return 1;
}


int main() {
    int n;
    scanf(" %d", &n);
    int** p = (int**)calloc(n, sizeof(int*));
    for (int i = 0; i < n; i++) {
        p[i] = (int*)calloc(n, sizeof(int));
    }
    upis(p, n);

    ispuniMagicniKvadrat(p, n);
    int check = provjeraMagicnogKvadrata(p, n, sumaMagicKvadrata(n));
    if (!check) {
        printf("Ovo nije magicni kvadrat");
        return 0;
    }
    ispis(p, n);

    return 0;
}