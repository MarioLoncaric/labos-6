#define _CRT_SECURE_NO_WARNINGS
#define _CRT_NONSTDC_NO_DEPRECATE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

// takodjer ovaj zadatak ne zahtjeva koristenje funckija pa se nemora uopce sa funckijama rijesavati moze sve u mainu 
int main() {
    int broj_paketa;
    scanf(" %d", &broj_paketa);

    while (broj_paketa < 1 || broj_paketa > 100) {
        scanf(" %d", &broj_paketa);
    }

    int** kategorije = NULL;
    int* kapaciteti = NULL; // tracker varijabla 
    int* brojevi_paketa = NULL; // tracker varijabla
    int broj_kategorija = 0;

    for (int i = 0; i < broj_paketa; i++) {
        int k, t;
        scanf("%d %d", &k, &t);

        if (k < 1 || k > 50 || t < 1 || t> 5000) {
            continue; // ponovi unos
        }

        // Provjera je li kategorija već postoji
        if (k > broj_kategorija) {
            // Proširenje broja kategorija
            kategorije = (int**)realloc(kategorije, k * sizeof(int*)); // realocimramo memoriju za kategorij
            kapaciteti = (int*)realloc(kapaciteti, k * sizeof(int)); // za kapacitete
            brojevi_paketa = (int*)realloc(brojevi_paketa, k * sizeof(int)); // za brojeve_paketa

            for (int j = broj_kategorija; j < k; j++) {
                kategorije[j] = NULL; // point kategorije postavljamo na NULL
                kapaciteti[j] = 0; // a ove postavimo na 0
                brojevi_paketa[j] = 0; // a ove postavimo na 0
            }
            broj_kategorija = k;
        }

        // Provjera je li kapacitet dovoljno velik
        if (brojevi_paketa[k - 1] >= kapaciteti[k - 1]) {
            int stari_kapacitet = kapaciteti[k - 1]; // ovaj nam vodi briku o kapacitetima za svaki redak 
            kapaciteti[k - 1] += 5; // tu mu kazemo da ce sad taj redak imat 5 kapaciteta
            kategorije[k - 1] = (int*)realloc(kategorije[k - 1], kapaciteti[k - 1] * sizeof(int));
            // sad za kategorije na tom retku realociramo memoriju i prosirimo za kapacitet koji smo dodijelili

            // i sad sve stupce tog retka (kategorije) postavimo na 0
            for (int j = stari_kapacitet; j < kapaciteti[k - 1]; j++) {
                kategorije[k - 1][j] = 0;
            }
        }

        // Dodavanje paketa u kategoriju na prvo slobodno mjesto
        // i povecavamo broj paketa za taj redak 
        kategorije[k - 1][brojevi_paketa[k - 1]++] = t;
    }

    // Pronalaženje reda (kategorije) s najvise paketa
    int max_paketa = 0, max_index = -1;
    for (int i = 0; i < broj_kategorija; i++) {
        if (brojevi_paketa[i] > max_paketa) {
            max_paketa = brojevi_paketa[i];
            max_index = i;
        }
    }

    printf("Redak %d ima najvise paketa (%d).\n", max_index + 1, max_paketa);
    for (int i = 0; i < kapaciteti[max_index]; i++) {
        if (i < brojevi_paketa[max_index])
            printf("%d ", kategorije[max_index][i]);
        else
            printf("_ ");
    }
    printf("\n");


    // oslobodi memoriju
    for (int i = 0; i < broj_kategorija; i++) {
        free(kategorije[i]);
    }
    free(kategorije);
    free(kapaciteti);
    free(brojevi_paketa);

    return 0;
}