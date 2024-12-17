#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

void napadaj(char** matrica, int red, int stupac);
void ispis_matrice(char** matrica, int red, int stupac);

int main() {
    int red, stupac, broj_slojeva;

    // Unos dimenzija matrice i broja slojeva snega
    scanf("%d %d %d", &red, &stupac, &broj_slojeva);

    // Dinamička alokacija matrice
    char** matrica = (char**)calloc(red, sizeof(char*));
    for (int i = 0; i < red; i++) {
        matrica[i] = (char*)calloc(stupac, sizeof(char));
    }

    // Unos matrice
    for (int i = 0; i < red; i++) {
        for (int j = 0; j < stupac; j++) {
            scanf(" %c", &matrica[i][j]);
        }
    }

    // Dodavanje slojeva snega
    for (int i = 0; i < broj_slojeva; i++) {
        napadaj(matrica, red, stupac);
    }

    // Ispis rezultata
    printf("\n");
    ispis_matrice(matrica, red, stupac);

    // Oslobađanje memorije
    for (int i = 0; i < red; i++) {
        free(matrica[i]);
    }
    free(matrica);

    return 0;
}

void napadaj(char** matrica, int red, int stupac) {
    for (int j = 0; j < stupac; j++) { // Iteriramo kroz stupce
        int prepreka_pronadjena = 0; // Indikator da li je pronađena prepreka
        int prvi_sneg = red; // Lokacija gde snijeg može stati

        for (int i = red - 1; i >= 0; i--) { // Krećemo odozdo prema gore
            if (matrica[i][j] == '#') {
                prepreka_pronadjena = 1;
                prvi_sneg = i; // Postavljamo snijeg iznad prepreke
                break;
            }
        }

        if (prepreka_pronadjena) {
            // Postavljanje snijega iznad prepreke
            for (int i = prvi_sneg - 1; i >= 0; i--) {
                if (matrica[i][j] == '.') {
                    matrica[i][j] = '*';
                    break;
                }
            }
        }
        else {
            // Ako nema prepreka, dodajemo snijeg odozdo prema gore
            for (int i = red - 1; i >= 0; i--) {
                if (matrica[i][j] == '.') {
                    matrica[i][j] = '*';
                    break;
                }
            }
        }
    }
}

void ispis_matrice(char** matrica, int red, int stupac) {
    for (int i = 0; i < red; i++) {
        for (int j = 0; j < stupac; j++) {
            printf("%c ", matrica[i][j]);
        }
        printf("\n");
    }
}
