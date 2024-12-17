#define _CRT_SECURE_NO_WARNINGS
#define _CRT_NONSTDC_NO_DEPRECATE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include <stdint.h>

void provjera_simetrije(char** matrica,int dimenzija,int* tocnost);
void umetanje_slova(char**  matrica,int dimenzija);

int main() {
	int dimenzija;
	scanf("%d", &dimenzija);

	while (dimenzija < 1 || dimenzija > 9) {
		scanf("%d", &dimenzija);
	}

	char** matrica = (char**)calloc(dimenzija, sizeof(char*));
	for (int i = 0; i < dimenzija; i++){
		matrica[i] = (char*)calloc(dimenzija, sizeof(char));
	}

	for (int i = 0; i < dimenzija; i++) {
		for (int j = 0; j < dimenzija; j++) {
			scanf(" %c", &matrica[i][j]);
		}
	}
	
	int brojanje_crtica = 0;
	for (int i = 0; i < dimenzija; i++) {
		for (int j = 0; j < dimenzija; j++) {
			if (matrica[i][j] == '-') {
				brojanje_crtica++;
			}

		}
	}

	if (brojanje_crtica > 0) {
		umetanje_slova(matrica, dimenzija);
		
	}
	
	int tocnost = 0;
	provjera_simetrije(matrica, dimenzija, &tocnost);
	
	printf("\n");

	if (tocnost) {
		printf("ovo nije simetricna krizaljka");
	}
	else if (!tocnost) {
		for (int i = 0; i < dimenzija; i++) {
			for (int j = 0; j < dimenzija; j++) {
				printf("%c", matrica[i][j]);
			}
			printf("\n");
		}
	}
	
	for (int i = 0; i < dimenzija; i++) {
		free(matrica[i]);
	}
	free(matrica);
	return 0;
}

void umetanje_slova(char** matrica, int dimenzija) {
	for (int i = 0; i < dimenzija; i++) {
		for (int j = 0; j < dimenzija; j++) {
			if (matrica[i][j] == '-') {
				matrica[i][j] = matrica[j][i];
			}
		}
	}
}

void provjera_simetrije(char** matrica, int dimenzija, int* tocnost) {
	
	for (int i = 0; i < dimenzija; i++) {
		for (int j = 0; j < dimenzija; j++) {
			if (matrica[i][j] != matrica[j][i]) {
				*tocnost = 1;
			}
		}
	}
}