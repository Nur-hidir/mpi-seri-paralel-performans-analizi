#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <mpi.h>

void kabarcik(int *dizi, int uzunluk) {
    int i, j, temp;
    for(i = 0; i < uzunluk - 1; i++) {
        for(j = 0; j < uzunluk - i - 1; j++) {
            if(dizi[j] > dizi[j + 1]) {
                temp = dizi[j];
                dizi[j] = dizi[j + 1];
                dizi[j + 1] = temp;
            }
        }
    }
}

int main(int argc, char **argv) {
    int n = 1000000;
    int id, p;
    int *sayi = NULL;
    int *parca = NULL;
    int parca_boyutu;
    double t1, t2;
    int x;
    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &id);
    MPI_Comm_size(MPI_COMM_WORLD, &p);
    parca_boyutu = n / p;
    parca = (int *)malloc(parca_boyutu * sizeof(int));
    if(id == 0) {
        sayi = (int *)malloc(n * sizeof(int));
        srand(time(NULL));
        for(x = 0; x < n; x++) {
            sayi[x] = rand() % 1000000;
        }
        printf("mpi ile siralama basladi...\n");
        t1 = MPI_Wtime();
    }
    MPI_Scatter(sayi, parca_boyutu, MPI_INT, parca, parca_boyutu, MPI_INT, 0, MPI_COMM_WORLD);
    kabarcik(parca, parca_boyutu);
    MPI_Gather(parca, parca_boyutu, MPI_INT, sayi, parca_boyutu, MPI_INT, 0, MPI_COMM_WORLD);
    if(id == 0) {
        kabarcik(sayi, n);
        t2 = MPI_Wtime();
        printf("siralama bitti\n");
        printf("gecen sure: %.4f saniye\n", t2 - t1);
        free(sayi);
    }
    free(parca);
    MPI_Finalize();
    return 0;
}
