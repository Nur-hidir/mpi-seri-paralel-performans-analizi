# MPI ile Seri ve Paralel Algoritma Performans Analizi

Bu proje, C programlama dili ve **MPI (Message Passing Interface)** kütüphanesi kullanılarak geliştirilmiş 5 farklı algoritmanın seri (ardışık) ve paralel çalışma performanslarını karşılaştırmalı olarak analiz eder. Proje kapsamında algoritmaların işlemci çekirdek sayılarına göre hızlanma (**Speedup**) ve verimlilik (**Efficiency**) oranları incelenmiştir.

##  Projede Yer Alan Algoritmalar
Proje kapsamında hem geleneksel (seri) yöntemle hem de MPI ile paralel olarak kodlanan 5 algoritma:
1. [1. Algoritmanın Adı - Örn: Matris Çarpımı]
2. [2. Algoritmanın Adı - Örn: Quick Sort]
3. [3. Algoritmanın Adı - Örn: Sayısal Entegrasyon (Pi Sayısı Hesabı)]
4. [4. Algoritmanın Adı - Örn: Prims Algoritması]
5. [5. Algoritmanın Adı - Örn: Arama Algoritması]

##  Kullanılan Teknolojiler
* **Dil:** C
* **Paralel Programlama:** MPI (OpenMPI / MPICH)
* **Geliştirme Ortamı:** Visual Studio / VS Code

 

### Gereksinimler
Sisteminizde bir MPI dağıtımının (örneğin OpenMPI) kurulu olması gerekmektedir.

### Derleme
Seri ve paralel kodları derlemek için terminalde aşağıdaki komutları kullanabilirsiniz:

```bash
# Seri kodu derleme
gcc -o seri_program seri/main.c

# MPI paralel kodu derleme
mpicc -o paralel_program mpi/main.c
