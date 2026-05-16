//marge sort
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void birlestir(int *dizi, int sol, int orta, int sag) {
    int i, j, k;
    int n1=orta-sol+1;
    int n2=sag-orta;

int *sol_dizi=(int *)malloc(n1 * sizeof(int));
int *sag_dizi=(int *)malloc(n2 * sizeof(int));


    for (i = 0; i<n1; i++) {
          sol_dizi[i]=dizi[sol+i];
    }
    for (j=0; j<n2; j++) {
        sag_dizi[j] = dizi[orta+1+j];
    }

i=0;
j=0;
k=sol;

    while(i<n1 && j<n2) {
          if (sol_dizi[i]<=sag_dizi[j]) {
            dizi[k]=sol_dizi[i];
            i++;
        } else {
            dizi[k]=sag_dizi[j];
            j++;
        }
   k++;
    }

    while (i < n1) {
        dizi[k] = sol_dizi[i];
        i++;
        k++;
    }

      while(j<n2) {
          dizi[k]=sag_dizi[j];
         j++;
         k++;
    }

free(sol_dizi);
free(sag_dizi);



}

void birlestirme_siralamasi(int *dizi, int sol, int sag) {
    if (sol<sag) {
        int orta=sol+(sag - sol)/2;



        birlestirme_siralamasi(dizi, sol, orta);
        birlestirme_siralamasi(dizi, orta+1, sag);

birlestir(dizi, sol, orta, sag);
    }
}

int main() {
    int n=1000000;
    int *sayi=(int *)malloc(n * sizeof(int));
    int x;
    clock_t t1, t2;
    float fark, sure;

srand(time(NULL));



    for (x=0; x<n; x++) {
        sayi[x]=rand()%1000000;
    }




   t1=clock();


    birlestirme_siralamasi(sayi, 0, n - 1);
  t2=clock();



    fark=t2-t1;
    sure=fark/CLOCKS_PER_SEC;



printf("gecen sure: %.4f saniye\n", sure);


free(sayi);


return 0;
}
