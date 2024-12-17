#define _CRT_SECURE_NO_WARNINGS
#define _CRT_NONSTDC_NO_DEPRECATE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>


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

int sumaLatKvadrata(int n) {
    return (n * (n + 1)) / 2; //zbroj prvih n prirodnih brojeva
}

void ispuniLatKvadrat(int** p, int* n) {
    for (int i = 0; i < n; i++) {
        int* point = NULL;
        int zbroj = sumaLatKvadrata(n);
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

int provjeraLatKvadrata(int** p, int n, int check) {
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

    ispuniLatKvadrat(p, n);
    int check = provjeraLatKvadrata(p, n, sumaLatKvadrata(n));
    if (!check) {
        printf("Ovo nije latinski kvadrat");
        return 0;
    }
    ispis(p, n);



    return 0;
}