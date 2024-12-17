#define _CRT_SECURE_NO_WARNINGS
#define _CRT_NONSTDC_NO_DEPRECATE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

void ispisiPolje(char** polje, int r, int c) {
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            printf("%c", polje[i][j]);
        }
        printf("\n");
    }
}

int mozePasti(char** polje, int r, int c, int startRow, int startCol) {
    if (startRow + 2 < r) {
        if (polje[startRow + 2][startCol + 1] == '.') {
            return 1;
        }
    }
    return 0;
}

char* spustiElement(char** polje, int r, int c, int startRow, int startCol) {
    char* ptr = NULL; // Ispravljeno sa int* na char*
    while (mozePasti(polje, r, c, startRow, startCol)) {
        // Obrisati trenutni oblik
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < 3; j++) {
                polje[startRow + i][startCol + j] = '.';
            }
        }

        // Spusti za jedan red
        startRow++;

        // Dodati oblik u novi red
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < 3; j++) {
                if (!i) {
                    polje[startRow + i][startCol + j] = '#';
                }
                else {
                    polje[startRow + i][startCol + j + 1] = '#';
                    ptr = &polje[startRow + i][startCol + j + 1];
                    break;
                }
            }
        }
    }
    return ptr;
}

int provjeriSpustanje(char* a) {
    if (*(a + 1) == '#' && *(a - 1) == '#') {
        return 1;
    }
    return 0;
}

int main() {
    int r, c;
    scanf("%d %d", &r, &c);

    char** polje = (char**)calloc(r, sizeof(char*));
    for (int i = 0; i < r; i++) {
        polje[i] = (char*)calloc((c + 1), sizeof(char));
        scanf("%s", polje[i]);
    }

    int startRow = 0, startCol = -1;
    for (int j = 0; j < c - 2; j++) {
        if (polje[0][j] == '#' && polje[0][j + 1] == '#' && polje[0][j + 2] == '#') {
            startCol = j;
            break;
        }
    }

    char* spusteniVrh = spustiElement(polje, r, c, startRow, startCol); // Ispravljeno

    if (provjeriSpustanje(spusteniVrh)) {
        ispisiPolje(polje, r, c);
        printf("Uspjesno spustanje!\n");
    }
    else {
        ispisiPolje(polje, r, c);
        printf("Neuspjesno spustanje!\n");
    }

    for (int i = 0; i < r; i++) {
        free(polje[i]);
    }
    free(polje);

    return 0;
}
