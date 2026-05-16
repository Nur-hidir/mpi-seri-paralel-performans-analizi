#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void Quick(int *dizi, int sol, int sag) {
    int i, j, pivot, temp;

    if (sol<sag) {
        pivot=sol;
        i=sol;
        j=sag;
        while (i<j) {
            while (dizi[i]<=dizi[pivot] && i<sag) {
                i++;
            }
              while (dizi[j]>dizi[pivot]) {
                j--;
            }
        if (i<j) {
            temp =dizi[i];
            dizi[i]=dizi[j];
            dizi[j]=temp;
            }
        }



    temp=dizi[pivot];
    dizi[pivot]=dizi[j];
    dizi[j]=temp;
    Quick(dizi, sol, j - 1);
    Quick(dizi, j + 1, sag);
    }
}

int main() {
    int n=1000000;
    int *sayi=(int *)malloc(n * sizeof(int));
    int x;
    clock_t t1, t2;
    float fark, sure;

    srand(time(NULL));

    for (x = 0; x< n; x++) {
        sayi[x]=rand()%1000000;
    }

    t1=clock();
    Quick(sayi, 0, n - 1);
    t2=clock();
    fark=t2-t1;
    sure=fark/CLOCKS_PER_SEC;

    printf("sure: %.4f saniye\n", sure);
    free(sayi);


    return 0;
}
