#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <mpi.h>

void hizli_sirala(int *dizi,int bas,int son){
    int i,j,pivot,temp;
    if(bas<son){
        pivot=bas;
        i=bas;
        j=son;
        while(i<j){

            while(dizi[i]<=dizi[pivot]&&i<son){
                i++;


            }
    while(dizi[j]>dizi[pivot]){
                j--;}



            if(i<j){

                temp=dizi[i];
                dizi[i]=dizi[j];
                dizi[j]=temp;
            }

            }



    temp=dizi[pivot];
    dizi[pivot]=dizi[j];
    dizi[j]=temp;
    hizli_sirala(dizi,bas,j-1);
    hizli_sirala(dizi,j+1,son);


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


        printf("mpi hizli siralama basladi...\n");
        t1=MPI_Wtime();
    }

MPI_Scatter(sayi,boyut,MPI_INT,parca,boyut,MPI_INT,0,MPI_COMM_WORLD);
hizli_sirala(parca,0,boyut-1);

MPI_Gather(parca,boyut,MPI_INT,sayi,boyut,MPI_INT,0,MPI_COMM_WORLD);



    if(id==0){

        hizli_sirala(sayi,0,n-1);
        t2=MPI_Wtime();
        printf("siralama bitti\n");
        printf("gecen sure: %.4f saniye\n",t2-t1);
        free(sayi);
    }

free(parca);

    MPI_Finalize();



 return 0;
}
