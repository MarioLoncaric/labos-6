#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>


void ispis(char** matrica,int red,int stupac);
void logika_igre(char** matrica, int red, int stupac, int lokacija1, int lokacija2, int duljina_eksplozije);

int main() {
    int red, stupac, duljina_eksplozije;
    scanf("%d%d%d", &red, &stupac, &duljina_eksplozije);

    // Dinamička alokacija matrice
    char** matrica = (char**)calloc(red, sizeof(char*));
    for (int i = 0; i < red; i++) {
        matrica[i] = (char*)calloc(stupac + 1, sizeof(char));
    }

    // Unos matrice
    for (int i = 0; i < red; i++) {
        scanf("%s", matrica[i]);
    }

    // Pronalazak lokacije 'B'
    int lokacija1 = 0, lokacija2 = 0;
    for (int i = 0; i < red; i++) {
        for (int j = 0; j < stupac; j++) {
            if (matrica[i][j] == 'B') {
                lokacija1 = i;
                lokacija2 = j;
            }
        }
    }

    logika_igre(matrica, red, stupac, lokacija1, lokacija2, duljina_eksplozije);

    int pronalazak_igraca = 0;
    for (int i = 0; i < red; i++) {
        for (int j = 0; j < stupac; j++) {
            if (matrica[i][j] == 'I') {
                pronalazak_igraca = 1;
            }
        }
    }

    printf("\n");
    ispis(matrica, red, stupac);
    
   
    

    if (!pronalazak_igraca) {
        printf("Game over");
    }

    // Oslobađanje memorije
    for (int i = 0; i < red; i++) {
        free(matrica[i]);
    }
    free(matrica);

    return 0;
}

void logika_igre(char** matrica, int red, int stupac, int lokacija1, int lokacija2, int duljina_eksplozije) {
    // Eksplozija levo
    for (int j = lokacija2; j >= 0 && j >= lokacija2 - duljina_eksplozije; j--) {
        if (matrica[lokacija1][j] == '#') break; // Prepreka
        matrica[lokacija1][j] = 'X';
    }

    // Eksplozija desno
    for (int j = lokacija2; j < stupac && j <= lokacija2 + duljina_eksplozije; j++) {
        if (matrica[lokacija1][j] == '#') break; // Prepreka
        matrica[lokacija1][j] = 'X';
    }

    // Eksplozija gore
    for (int i = lokacija1; i >= 0 && i >= lokacija1 - duljina_eksplozije; i--) {
        if (matrica[i][lokacija2] == '#') break; // Prepreka
        matrica[i][lokacija2] = 'X';
    }

    // Eksplozija dole
    for (int i = lokacija1; i < red && i <= lokacija1 + duljina_eksplozije; i++) {
        if (matrica[i][lokacija2] == '#') break; // Prepreka
        matrica[i][lokacija2] = 'X';
    }
}

void ispis(char** matrica, int red, int stupac){
    for (int i = 0; i < red; i++) {
        for (int j = 0; j < stupac; j++) {
            printf(" %c", matrica[i][j]);
        }
        printf("\n");
    }
}