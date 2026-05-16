#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <mpi.h>

void takas(int *a,int *b){
int gecici=*a;
  *a=*b;
    *b=gecici;
}

void bitonik_birlestir(int *dizi,int bas,int sayi,int yon){
  if(sayi>1){
    int k=sayi/2;
      int i;
    for(i=bas;i<bas+k;i++){
            if(yon==(dizi[i]>dizi[i+k])){
          takas(&dizi[i],&dizi[i+k]);
        }
    }
      bitonik_birlestir(dizi,bas,k,yon);
    bitonik_birlestir(dizi,bas+k,k,yon);
  }
}

void bitonik_sirala(int *dizi,int bas,int sayi,int yon){
    if(sayi>1){
      int k=sayi/2;
        bitonik_sirala(dizi,bas,k,1);
      bitonik_sirala(dizi,bas+k,k,0);
        bitonik_birlestir(dizi,bas,sayi,yon);
    }
}

int main(int argc,char **argv){
int n=1048576;
  int id,p;
    int *sayi=NULL;
  int *parca=NULL;
int boyut;
    double t1,t2;
  int x;

  MPI_Init(&argc,&argv);
    MPI_Comm_rank(MPI_COMM_WORLD,&id);
  MPI_Comm_size(MPI_COMM_WORLD,&p);

boyut=n/p;
  parca=(int *)malloc(boyut*sizeof(int));

    if(id==0){
      sayi=(int *)malloc(n*sizeof(int));
        srand(time(NULL));
      for(x=0;x<n;x++){
        sayi[x]=rand()%1000000;
        }

                t1=MPI_Wtime();
    }




  MPI_Scatter(sayi,boyut,MPI_INT,parca,boyut,MPI_INT,0,MPI_COMM_WORLD);
bitonik_sirala(parca,0,boyut,1);

MPI_Gather(parca,boyut,MPI_INT,sayi,boyut,MPI_INT,0,MPI_COMM_WORLD);

    if(id==0){
      bitonik_sirala(sayi,0,n,1);
        t2=MPI_Wtime();

        printf("gecen sure: %.4f saniye\n",t2-t1);
      free(sayi);
    }

  free(parca);
    MPI_Finalize();



  return 0;
}
