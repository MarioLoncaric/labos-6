#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

void logika_igre(char** matrica, int red, int stupac, int* odrediste);
void ispis(char** matrica, int red, int stupac, int odrediste);

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

    int odrediste = 1; // Indikator uspeha
    logika_igre(matrica, red, stupac, &odrediste);

    ispis(matrica, red, stupac, odrediste);

    // Oslobađanje memorije
    for (int i = 0; i < red; i++) {
        free(matrica[i]);
    }
    free(matrica);

    return 0;
}

void logika_igre(char** matrica, int red, int stupac, int* odrediste) {
    int pocetna_lokacija_x = -1;
    int pocetna_lokacija_y = -1;

    // Pronalazak početne pozicije 'M'
    for (int i = 0; i < red; i++) {
        for (int j = 0; j < stupac; j++) {
            if (matrica[i][j] == 'M') {
                pocetna_lokacija_x = i;
                pocetna_lokacija_y = j;
                break;
            }
        }
        if (pocetna_lokacija_x != -1) break; // Ako je pronađena početna pozicija
    }

  

    // Logika kretanja kroz matricu
    while (1) {
        // Provera da li je stigao na ciljnu poziciju
        if (pocetna_lokacija_x == red - 2 && pocetna_lokacija_y == stupac - 1) {
            break; // Uspeh
        }

        int brojac_kraja = 0;

        // Kretanje dole
        if (pocetna_lokacija_x + 1 < red && matrica[pocetna_lokacija_x + 1][pocetna_lokacija_y] == '.') {
            pocetna_lokacija_x++;
            matrica[pocetna_lokacija_x][pocetna_lokacija_y] = 'M';
            continue;
        }
        else {
            brojac_kraja++;
        }

        // Kretanje desno
        if (pocetna_lokacija_y + 1 < stupac && matrica[pocetna_lokacija_x][pocetna_lokacija_y + 1] == '.') {
            pocetna_lokacija_y++;
            matrica[pocetna_lokacija_x][pocetna_lokacija_y] = 'M';
            continue;
        }
        else {
            brojac_kraja++;
        }

        // Ako nema više mogućnosti kretanja
        if (brojac_kraja == 2) {
            *odrediste = 0; // Neuspeh
            break;
        }
    }
}

void ispis(char** matrica, int red, int stupac, int odrediste) {
    for (int i = 0; i < red; i++) {
        for (int j = 0; j < stupac; j++) {
            printf("%c ", matrica[i][j]);
        }
        printf("\n");
    }

    if (odrediste) {
        printf("Uspjeh\n");
    }
    else {
        printf("Fail\n");
    }
}
