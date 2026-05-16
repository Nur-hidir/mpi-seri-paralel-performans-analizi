#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void takas(int *a, int *b) {
    int gecici = *a;
       *a=*b;
      *b=gecici;

}

void bitonik(int *dizi, int bas, int sayi, int yon) {
    if (sayi>1) {
        int k=sayi/2;
        int i;
        for (i=bas; i<bas+k; i++) {
            if (yon==(dizi[i]>dizi[i + k])) {
                takas(&dizi[i], &dizi[i + k]);
            }
        }
        bitonik(dizi, bas, k, yon);
        bitonik(dizi, bas + k, k, yon);
    }
}

void sirala(int *dizi, int bas, int sayi, int yon) {
    if (sayi>1) {
        int k=sayi/2;

         sirala(dizi, bas, k, 1);
         sirala(dizi, bas + k, k, 0);
        bitonik(dizi, bas, sayi, yon);
    }
}



int main() {
    int n=1048576;
    int *sayi=(int *)malloc(n * sizeof(int));
    int x;
    clock_t t1, t2;
    float fark, sure;

    srand(time(NULL));



  for (x=0; x<n; x++) {
     sayi[x] = rand() % 1000000;
    }



t1=clock();
sirala(sayi, 0, n, 1);


t2=clock();




fark = t2 - t1;
sure = fark / CLOCKS_PER_SEC;





printf("gecen sure: %.4f saniye\n", sure);



free(sayi);
    return 0;
}
