#define _CRT_SECURE_NO_WARNINGS
#define _CRT_NONSTDC_NO_DEPRECATE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include <stdint.h>

void alokacija(char*** matrica, int red, int stupac);
void unos_matrice(char** matrica,int red,int stupac);
void provjera_redova(char** matrica, int red, int stupac,int* pobjednik_x,int* pobjednik_o);
void provjera_stupaca(char** matrica, int red, int stupac, int* pobjednik_x, int* pobjednik_o);

int main() {
    int red, stupac;
    scanf("%d%d", &red, &stupac);

    char** matrica;
    alokacija(&matrica, red, stupac);

    unos_matrice(matrica, red, stupac);
    

    int pobjednik_x = 0, pobjednik_o = 0;

    provjera_redova(matrica, red, stupac, &pobjednik_x, &pobjednik_o);
    

    provjera_stupaca(matrica, red, stupac, &pobjednik_x, &pobjednik_o);

    // Odlučivanje o ishodu
    if (pobjednik_x && pobjednik_o) {
        printf("Nemoguca situacija\n");
    }
    else if (pobjednik_x) {
        printf("Pobjednik je x\n");
    }
    else if (pobjednik_o) {
        printf("Pobjednik je o\n");
    }
    else {
        printf("Nema pobjednika\n");
    }

    // Oslobađanje memorije
    for (int i = 0; i < red; i++) {
        free(matrica[i]);
    }
    free(matrica);

    return 0;
}

void alokacija(char*** matrica, int red, int stupac) {
    *matrica = (char**)calloc(red, sizeof(char*));
    for (int i = 0; i < red; i++) {
        (*matrica)[i] = (char*)calloc(stupac, sizeof(char));
    }
}

void unos_matrice(char** matrica, int red, int stupac) {
    for (int i = 0; i < red; i++) {
        for (int j = 0; j < stupac; j++) {
            scanf(" %c", &matrica[i][j]);
        }
    }
}

void provjera_redova(char** matrica, int red, int stupac, int* pobjednik_x, int* pobjednik_o) {
    for (int i = 0; i < red; i++) {
        for (int j = 0; j <= stupac - 4; j++) {
            if (matrica[i][j] == 'x' && matrica[i][j + 1] == 'x' && matrica[i][j + 2] == 'x' && matrica[i][j + 3] == 'x') {
                *pobjednik_x = 1;
            }
            if (matrica[i][j] == 'o' && matrica[i][j + 1] == 'o' && matrica[i][j + 2] == 'o' && matrica[i][j + 3] == 'o') {
                *pobjednik_o = 1;
            }
        }
    }
}

void provjera_stupaca(char** matrica, int red, int stupac, int* pobjednik_x, int* pobjednik_o) {
    for (int j = 0; j < stupac; j++) {
        for (int i = 0; i <= red - 4; i++) {
            if (matrica[i][j] == 'x' && matrica[i + 1][j] == 'x' && matrica[i + 2][j] == 'x' && matrica[i + 3][j] == 'x') {
                *pobjednik_x = 1;
            }
            if (matrica[i][j] == 'o' && matrica[i + 1][j] == 'o' && matrica[i + 2][j] == 'o' && matrica[i + 3][j] == 'o') {
                *pobjednik_o = 1;
            }
        }
    }
}