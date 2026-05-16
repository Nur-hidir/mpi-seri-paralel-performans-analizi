//selecet sort

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int uzunluk = 1000000;
    int *x = (int *)malloc(uzunluk * sizeof(int));
    int min, j, i, temp;
    clock_t t1, t2;
    float fark, sure;

    srand(time(NULL));

    for(i = 0; i<uzunluk; i++) {
        x[i]=rand()%1000000;
    }

    printf("siralama basladi...\n");

    t1=clock();

    for(i=0; i<uzunluk - 1; i++) {
        min = i;
        for (j=i + 1; j<uzunluk; j++) {
            if(x[j] < x[min]) {
                min = j;
            }
        }
        if(min!=i) {
            temp=x[i];
            x[i]=x[min];
            x[min]=temp;
        }
    }

    t2=clock();
    fark=t2 - t1;
    sure=fark / CLOCKS_PER_SEC;

    printf("siralama bitti\n");
    printf("sure: %.4f saniye\n", sure);




    printf("\n");

    free(x);
    return 0;
}
