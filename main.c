#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define NUM_ELEVER 5
#define NUM_PROV 13
#define NAMN_MAX 11 

typedef struct {
    char namn[NAMN_MAX];
    int prov[NUM_PROV];
    float medel;
} Elev;


void formatNamn(char* namn) {
    namn[0] = toupper(namn[0]);
    for (int i = 1; namn[i]; i++) {
        namn[i] = tolower(namn[i]);
    }
}


float beraknaMedel(int prov[], int antal) {
    int summa = 0;
    for (int i = 0; i < antal; i++) {
        summa += prov[i];
    }
    return (float)summa / antal;
}

int main() {
    Elev elever[NUM_ELEVER];
    float totalMedel = 0;
    int i, j;

    for (i = 0; i < NUM_ELEVER; i++) {
        scanf("%s", elever[i].namn);
        for (j = 0; j < NUM_PROV; j++) {
            scanf("%d", &elever[i].prov[j]);
        }
        elever[i].medel = beraknaMedel(elever[i].prov, NUM_PROV);
        totalMedel += elever[i].medel;
    }

    
    int indexMax = 0;
    for (i = 1; i < NUM_ELEVER; i++) {
        if (elever[i].medel > elever[indexMax].medel) {
            indexMax = i;
        }
    }

    formatNamn(elever[indexMax].namn);
    printf("%s\n", elever[indexMax].namn);

    
    float medelAlla = totalMedel / NUM_ELEVER;
    for (i = 0; i < NUM_ELEVER; i++) {
        if (elever[i].medel < medelAlla) {
            formatNamn(elever[i].namn);
            printf("%s\n", elever[i].namn);
        }
    }

    return 0;
}