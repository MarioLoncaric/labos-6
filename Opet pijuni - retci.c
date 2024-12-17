#define _CRT_SECURE_NO_WARNINGS
#define _CRT_NONSTDC_NO_DEPRECATE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include <stdint.h>

void ispis(char** matrica, int redak, int stupac);
void brojanje_pijuna(char** matrica, int redak, int stupac, int* niz);


int main() {
	int redak, stupac, broj_pijuna;
	scanf("%d%d%d", &redak, &stupac, &broj_pijuna);

	char** matrica = (char**)calloc(redak, sizeof(char*));
	for (int i = 0; i < redak; i++) {
		matrica[i] = (char*)calloc(stupac, sizeof(char));
	}

	for (int i = 0; i < redak; i++) {
		for (int j = 0; j < stupac; j++) {
			matrica[i][j] = '.';
		}
	}

	int lokacija_x, lokacija_y;
	for (int i = 0; i < broj_pijuna; i++) {
		scanf("%d %d", &lokacija_x, &lokacija_y);
		matrica[lokacija_x-1][lokacija_y-1] = 'P';
	}

	int* niz = (int*)calloc(redak, sizeof(int));
	brojanje_pijuna(matrica, redak, stupac, niz);
	ispis(matrica, redak, stupac);

	for (int i = 0; i < redak; i++){
		printf("%d ", niz[i]);
	}
	printf("\n");


	for (int i = 0; i < redak; i++) {
		free(matrica[i]);
	}
	free(matrica);
	free(niz);
	return 0;
}


void brojanje_pijuna(char** matrica, int redak, int stupac, int* niz) {
	
	for (int i = 0; i < redak; i++) {
		for (int j = 0; j < stupac; j++) {
			if (matrica[i][j] == 'P') {
				niz[i]++;
			}
		}
	}
}

void ispis(char** matrica, int redak, int stupac) {
	for (int i = 0; i < redak; i++) {
		for (int j = 0; j < stupac; j++) {
			printf("%c ", matrica[i][j]);
		}
		printf("\n");
	}
}