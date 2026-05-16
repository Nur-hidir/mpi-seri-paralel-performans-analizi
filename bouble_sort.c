#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void kabarcik(int *sayi, int eleman_sayisi) {
    int i, j;
    int yedek;
    for (i = 0; i<eleman_sayisi-1; i++) {
        for (j = 0; j<eleman_sayisi-i - 1; j++) {
            if (sayi[j]>sayi[j + 1]) {
                yedek=sayi[j];
                sayi[j]=sayi[j + 1];
                sayi[j + 1]=yedek;
            }
        }
    }
    }

int main() {
    int n=1000000, x;
    int *sayi=(int *)malloc(n * sizeof(int));
    clock_t t1, t2;
    float fark, sure;
    srand(time(NULL));
    for (x=0; x<n; x++) {

        sayi[x]=rand()%1000000;
    }





t1=clock();
kabarcik(sayi, n);
t2=clock();
fark=t2 - t1;

    sure=fark / CLOCKS_PER_SEC;

    printf("gecen sure: %.4f saniye\n", sure);
free(sayi);


    return 0;
}
