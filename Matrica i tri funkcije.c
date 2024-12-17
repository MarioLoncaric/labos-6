#define _CRT_SECURE_NO_WARNINGS
#define _CRT_NONSTDC_NO_DEPRECATE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

void ispis(int** matrica, int dimenzija);
void zbroj(int** matrica,int dimenzija, int* zbroj_elemenata);
void najmanje(int** matrica, int dimenzija, int* lokacija_x, int* lokacija_y, int* najmanji_element);

int main() {
	int dimenzija;
	scanf("%d", &dimenzija);

	int** matrica = (int**)calloc(dimenzija, sizeof(int*));
	for (int i = 0; i < dimenzija; i++) {
		matrica[i] = (int*)calloc(dimenzija, sizeof(int));
	}

	for (int i = 0; i < dimenzija; i++) {
		for (int j = 0; j < dimenzija; j++) {
			scanf("%d", &matrica[i][j]);
		}
	}
	printf("\n");

	ispis(matrica, dimenzija);

	int zbroj_elemenata = 0;
	zbroj(matrica, dimenzija, &zbroj_elemenata);
	
	int lokacija_x = 0;
	int lokacija_y = 0;
	int najmanji_element = 15000;
	najmanje(matrica, dimenzija, &lokacija_x, &lokacija_y, &najmanji_element);

	printf("\n");
	printf("Zbroj neparnih elemenata glavne dijagonale je %d.\n", zbroj_elemenata);

	printf("Najmanji neparni element matrice je %d, na lokaciji [%d,%d].\n", najmanji_element, lokacija_x, lokacija_y);

	for (int i = 0; i < dimenzija; i++) {
		free(matrica[i]);
	}
	free(matrica);

	return 0;
}

void ispis(int** matrica, int dimenzija) {
	for (int i = 0; i < dimenzija; i++) {
		for (int j = 0; j < dimenzija; j++) {
			printf("%3d", matrica[i][j]);
		}
		printf("\n");
	}
}

void zbroj(int** matrica, int dimenzija, int* zbroj_elemenata) {
	int zbroj = 0;
	for (int i = 0; i < dimenzija; i++) {
		for (int j = i; j < i + 1; j++) {
			if (matrica[i][j] % 2 == 1) {
				*zbroj_elemenata += matrica[i][j];
			}
		}
	}
}

void najmanje(int** matrica, int dimenzija, int* lokacija_x, int* lokacija_y, int* najmanji_element) {
	int broj = 0;
	for (int i = 0; i < dimenzija; i++) {
		for (int j = 0; j < dimenzija; j++) {
			broj = 0;
			if (matrica[i][j] % 2 == 1) {
				broj = matrica[i][j];
				if (broj < najmanji_element) {
					*najmanji_element = broj;
					*lokacija_x = i+1;
					*lokacija_y = j+1;
				}
			}
		}
	}
}