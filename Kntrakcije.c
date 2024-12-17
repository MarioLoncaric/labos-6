#define _CRT_SECURE_NO_WARNINGS
#define _CRT_NONSTDC_NO_DEPRECATE
#include <stdio.h>
#include <stdlib.h>

// Deklaracija funkcija
void ispis(char** matrica, int red, int stupac);
void upis_matrice(char** matrica, int red, int stupac);
void alokacija_memorije(char*** matrica, int red, int stupac);
void kopiraj_matricu(char** izvor, char** cilj, int red, int stupac);
void kontrakcija(char** original, char** tmp, int red, int stupac, int lokacija1, int lokacija2);

int main() {
    int red, stupac;

    // Unos dimenzija matrice
    scanf("%d%d", &red, &stupac);
    while (red < 1 || red > 100 || stupac < 1 || stupac > 100) {
        scanf("%d%d", &red, &stupac);
    }

    // Alokacija memorije za originalnu matricu i privremenu matricu
    char** matrica;
    char** tmp;
    alokacija_memorije(&matrica, red, stupac);
    alokacija_memorije(&tmp, red, stupac);

    // Unos originalne matrice
    upis_matrice(matrica, red, stupac);

    // Kopiranje originalne matrice u tmp matricu
    kopiraj_matricu(matrica, tmp, red, stupac);

    // Unos broja kontrakcija
    int broj_kontrakcija = 0;
    scanf("%d", &broj_kontrakcija);
    while (broj_kontrakcija < 0 || broj_kontrakcija > 20) {
        scanf("%d", &broj_kontrakcija);
    }

    // Obrada kontrakcija
    for (int i = 0; i < broj_kontrakcija; i++) {
        int lokacija1, lokacija2;
        scanf("%d %d", &lokacija1, &lokacija2);

        // Primeni kontrakciju na osnovu originalne matrice, rezultat piši u tmp
        kontrakcija(matrica, tmp, red, stupac, lokacija1, lokacija2);

        // Kopiraj izmene iz tmp nazad u originalnu matricu
        kopiraj_matricu(tmp, matrica, red, stupac);
    }

    // Ispis rezultujuće tmp matrice
    ispis(tmp, red, stupac);

    // Oslobađanje memorije
    for (int i = 0; i < red; i++) {
        free(matrica[i]);
        free(tmp[i]);
    }
    free(matrica);
    free(tmp);

    return 0;
}

// Funkcija za alokaciju memorije za matricu
void alokacija_memorije(char*** matrica, int red, int stupac) {
    *matrica = (char**)calloc(red, sizeof(char*));
    for (int i = 0; i < red; i++) {
        (*matrica)[i] = (char*)calloc(stupac, sizeof(char));
    }
}

// Funkcija za unos matrice
void upis_matrice(char** matrica, int red, int stupac) {
    for (int i = 0; i < red; i++) {
        for (int j = 0; j < stupac; j++) {
            scanf(" %c", &matrica[i][j]);
        }
    }
}

// Funkcija za kopiranje matrice
void kopiraj_matricu(char** izvor, char** cilj, int red, int stupac) {
    for (int i = 0; i < red; i++) {
        for (int j = 0; j < stupac; j++) {
            cilj[i][j] = izvor[i][j];
        }
    }
}

// Funkcija za ispis matrice
void ispis(char** matrica, int red, int stupac) {
    for (int i = 0; i < red; i++) {
        for (int j = 0; j < stupac; j++) {
            printf("%c", matrica[i][j]);
        }
        printf("\n");
    }
}

// Funkcija za primenu kontrakcije
void kontrakcija(char** original, char** tmp, int red, int stupac, int lokacija1, int lokacija2) {
    int brojac_ikseva = 0;

    // Ako je centralno polje tačka, nema promene
    if (original[lokacija1][lokacija2] == '.') {
        return;
    }

    // Provera koso susednih polja
    if ((lokacija1 - 1 >= 0) && (lokacija2 - 1 >= 0) && (original[lokacija1 - 1][lokacija2 - 1] == 'x')) {
        tmp[lokacija1 - 1][lokacija2 - 1] = '.';
    }
    else {
        brojac_ikseva++;
    }

    if ((lokacija1 - 1 >= 0) && (lokacija2 + 1 < stupac) && (original[lokacija1 - 1][lokacija2 + 1] == 'x')) {
        tmp[lokacija1 - 1][lokacija2 + 1] = '.';
    }
    else {
        brojac_ikseva++;
    }

    if ((lokacija1 + 1 < red) && (lokacija2 + 1 < stupac) && (original[lokacija1 + 1][lokacija2 + 1] == 'x')) {
        tmp[lokacija1 + 1][lokacija2 + 1] = '.';
    }
    else {
        brojac_ikseva++;
    }

    if ((lokacija1 + 1 < red) && (lokacija2 - 1 >= 0) && (original[lokacija1 + 1][lokacija2 - 1] == 'x')) {
        tmp[lokacija1 + 1][lokacija2 - 1] = '.';
    }
    else {
        brojac_ikseva++;
    }

    // Ako nema susednih 'x', brišemo centralni 'x'
    if (brojac_ikseva == 4) {
        tmp[lokacija1][lokacija2] = '.';
    }
}
