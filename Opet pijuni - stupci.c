#define _CRT_SECURE_NO_WARNINGS
#define _CRT_NONSTDC_NO_DEPRECATE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include <stdint.h>

void ispis(char** matrica,int redak,int stupac);
void brojanje_pijuna(char** matrica, int redak, int stupac, int* niz);

int main() {
	int redak, stupac, broj_pijuna;
	scanf("%d%d%d", &redak, &stupac, &broj_pijuna);

	char** matrica = (char**)calloc(redak, sizeof(char*));
	for (int i = 0; i < redak; i++){
		matrica[i] = (char*)calloc(stupac, sizeof(char));
	}

	for (int i = 0; i < redak; i++) {
		for (int j = 0; j < stupac; j++) {
			matrica[i][j] = '.';
		}
	}

	int lokacija1, lokacija2;
	for (int i = 0; i < broj_pijuna; i++) {
		scanf("%d%d", &lokacija1, &lokacija2);
		matrica[lokacija1-1][lokacija2-1] = 'P';
	}

	ispis(matrica, redak, stupac);

	int* niz = (int*)calloc(stupac, sizeof(int));
	brojanje_pijuna(matrica, redak, stupac, niz);
	printf("\n");

	printf("Brojanje po stupacima: ");
	for (int i = 0; i < stupac; i++) {
		printf("%d ", niz[i]);
	}
	
	for (int i = 0; i < redak; i++) {
		free(matrica[i]);
	}
	free(matrica);
	free(niz);
	return 0;
}

void ispis(char** matrica, int redak, int stupac) {
	for (int i = 0; i < redak; i++) {
		for (int j = 0; j < stupac; j++) {
			printf("%c ", matrica[i][j]);
		}
		printf("\n");
	}
}

void brojanje_pijuna(char** matrica, int redak, int stupac, int* niz) {
	for (int j = 0; j < stupac; j++) {
		for (int i = 0; i < redak; i++) {
			if (matrica[i][j] == 'P') {
				niz[j]++;
			}
		}
	}
}