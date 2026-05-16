#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <mpi.h>

void birlestir(int *dizi,int sol,int orta,int sag){
    int uzunluk1=orta-sol+1;
    int uzunluk2=sag-orta;
    int *dizi1=(int *)malloc(uzunluk1*sizeof(int));
    int *dizi2=(int *)malloc(uzunluk2*sizeof(int));
    int i,j,k;
    for(i=0;i<uzunluk1;i++){
        dizi1[i]=dizi[sol+i];
    }
    for(j=0;j<uzunluk2;j++){
        dizi2[j]=dizi[orta+1+j];
    }
    i=0;
    j=0;
    k=sol;
    while(i<uzunluk1&&j<uzunluk2){
        if(dizi1[i]<=dizi2[j]){
            dizi[k]=dizi1[i];
            i++;
            k++;
        }else{
            dizi[k]=dizi2[j];
            j++;
            k++;
        }
    }
    while(i<uzunluk1){
        dizi[k]=dizi1[i];
        i++;
        k++;
    }
    while(j<uzunluk2){
        dizi[k]=dizi2[j];
        j++;
        k++;
    }
    free(dizi1);
    free(dizi2);
}

void sirala(int *dizi,int sol,int sag){
    if(sol<sag){
        int orta=sol+(sag-sol)/2;
        sirala(dizi,sol,orta);
        sirala(dizi,orta+1,sag);
        birlestir(dizi,sol,orta,sag);
    }
}

int main(int argc,char **argv){
    int n=1000000;
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



        printf("mpi birlestirme siralamasi basladi...\n");
        t1=MPI_Wtime();
    }




MPI_Scatter(sayi,boyut,MPI_INT,parca,boyut,MPI_INT,0,MPI_COMM_WORLD);
sirala(parca,0,boyut-1);

MPI_Gather(parca,boyut,MPI_INT,sayi,boyut,MPI_INT,0,MPI_COMM_WORLD);

    if(id==0){


        sirala(sayi,0,n-1);
        t2=MPI_Wtime();
        printf("siralama bitti\n");
        printf("gecen sure: %.4f saniye\n",t2-t1);
        free(sayi);
}

    free(parca);
    MPI_Finalize();



    return 0;
}
