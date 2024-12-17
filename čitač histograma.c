#define _CRT_SECURE_NO_WARNINGS
#define _CRT_NONSTDC_NO_DEPRECATE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include <stdint.h>

void alokacija(char*** matrica,int redak,int stupac);
void prebrojavanje(char** matrica, int redak, int stupac, int* broj_stupca, int* najveca_vrijednost);

int main() {
	int redak, stupac;
	scanf("%d%d", &redak, &stupac);

	char** matrica;
	alokacija( &matrica, redak, stupac);

	for (int i = 0; i < redak; i++) {
		for (int j = 0; j < stupac; j++) {
			scanf(" %c", &matrica[i][j]);
		}
	}
	int broj_stupca = 0;
	int najveca_vrijednost = 0;
	prebrojavanje(matrica, redak, stupac, &broj_stupca, &najveca_vrijednost);

	printf("Najveca vrijednost (%d) je u stupcu %d.", najveca_vrijednost, broj_stupca+1);
	
	for (int i = 0; i < redak; i++) {
		free(matrica[i]);
	}
	free(matrica);

	return 0;
}

void alokacija(char*** matrica, int redak, int stupac) {
	*matrica = (char**)calloc(redak, sizeof(char*)); 
	for (int i = 0; i < redak; i++) {
		(*matrica)[i] = (char*)calloc(stupac, sizeof(char));
	}
}

void prebrojavanje(char** matrica, int redak, int stupac, int* broj_stupca, int* najveca_vrijednost) {
	int brojac = 0;
	for (int j = 0; j < stupac; j++) {
		brojac = 0;
		for (int i = 0; i < redak; i++) {
			if (matrica[i][j] == 'x') {
				brojac++;
			}
		}
		if (brojac > *najveca_vrijednost) {
			*najveca_vrijednost = brojac;
			*broj_stupca = j;
		}
	}



}