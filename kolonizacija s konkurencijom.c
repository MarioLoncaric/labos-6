#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

void alokacija(char*** matrica, int red, int stupac);
void brojanje_muflona(char** matrica, char** orginalna_matrica, int* maks_muflona, int* lokacija_x, int* lokacija_y, int red,int stupac,int tor);

int main() {
    int red, stupac, tor;
    scanf("%d%d%d", &red, &stupac, &tor);

    char** matrica;
    alokacija(&matrica, red, stupac);

    char** orginalna_matrica;
    alokacija(&orginalna_matrica, red, stupac);

    // Unos matrice
    for (int i = 0; i < red; i++) {
        for (int j = 0; j < stupac; j++) {
            scanf(" %c", &matrica[i][j]);
            orginalna_matrica[i][j] = matrica[i][j]; // Kopiranje originalne matrice
        }
    }

    
    int maks_muflona = 0;
    int lokacija_x = 0;
    int lokacija_y = 0;

    brojanje_muflona(matrica, orginalna_matrica, &maks_muflona, &lokacija_x, &lokacija_y, red, stupac, tor);


    // Ispis rezultata
    printf("Najbolja lokacija je [%d,%d] cime nam ostane ukupno %d muflona\n", lokacija_x, lokacija_y, maks_muflona);

    // Oslobađanje memorije
    for (int i = 0; i < red; i++) {
        free(matrica[i]);
        free(orginalna_matrica[i]);
    }
    free(matrica);
    free(orginalna_matrica);

    return 0;
}

void alokacija(char*** m, int red, int stupac) {
    *m = (char**)calloc(red, sizeof(char*));
    
    for (int i = 0; i < red; i++) {
        (*m)[i] = (char*)calloc(stupac, sizeof(char));
    }
}

void brojanje_muflona(char** matrica, char** orginalna_matrica, int* maks_muflona, int* lokacija_x, int* lokacija_y, int red, int stupac, int tor) {
    // Iteracija kroz sve moguće torove
    for (int i = 0; i <= red - tor; i++) {
        for (int j = 0; j <= stupac - tor; j++) {
            int broj_muflona = 0;

            // Označavanje torova s 'T'
            for (int r = i; r < i + tor; r++) {
                for (int c = j; c < j + tor; c++) {
                    matrica[r][c] = 'T';
                }
            }

            // Brojanje muflona ('M') u ostatku matrice
            for (int z = 0; z < red; z++) {
                for (int g = 0; g < stupac; g++) {
                    if (matrica[z][g] == 'M') {
                        broj_muflona++;
                    }
                }
            }

            // Provjera maksimalnog broja muflona
            if (broj_muflona > *maks_muflona) {
                *maks_muflona = broj_muflona;
                *lokacija_x = i + 1;
                *lokacija_y = j + 1;
            }

            // Resetiranje matrice na početno stanje
            for (int r = 0; r < red; r++) {
                for (int c = 0; c < stupac; c++) {
                    matrica[r][c] = orginalna_matrica[r][c];
                }
            }
        }
    }
}
