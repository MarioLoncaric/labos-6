#define _CRT_SECURE_NO_WARNINGS
#define _CRT_NONSTDC_NO_DEPRECATE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>


int main() {
    int red, stupac;
    scanf("%d%d", &red, &stupac);

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


    int lokacijax = 0, lokacija1y = 0;
    int lokacija2y = 0;
    int lokacija3y = 0;
    int postojanost_filmova = 0;
    for (int i = 0; i < red; i++) {
        for (int j = 0; j < stupac - 2; j++) {
            if (matrica[i][j] == 'N' && matrica[i][j + 1] == 'N' && matrica[i][j + 2] == 'N') {
                lokacijax = i, lokacija1y = j;
                lokacija2y = j+1;
                lokacija3y = j+2;
                postojanost_filmova = 1;

            }
        }
    }
    if (postojanost_filmova) {
        printf("Posudba filmova : [%d, %d] , [%d, %d] i[%d, %d]", lokacijax+1, lokacija1y+1, lokacijax+1, lokacija2y+1, lokacijax+1, lokacija3y+1);
    }
    else if (!postojanost_filmova) {
        printf("Sve smo skoro pogledali");
    }
       
    
    for (int i = 0; i < red; i++) {
        free(matrica[i]);
    }
    free(matrica);

    return 0;
}