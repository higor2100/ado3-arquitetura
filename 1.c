#include<omp.h>
#include<stdio.h>
#include <stdlib.h>
#include <math.h>

#define ARR_SIZE 4

int reduce(int *vet, int ini, int fim){
  if(fim - ini >= 1){
    int meio = (ini + fim) / 2;
    return reduce(vet, ini, meio) + reduce(vet, meio + 1, fim);
  } else if(fim - ini == 0){
    return vet[ini];
  }
}

int main(){

  int i, j, tid, numt, sum = 0, local_sum;
  double t1, t2;
  int a[ARR_SIZE];

  t1 = omp_get_wtime();
  #pragma omp parallel num_threads(4)
  {
    for(i = 0; i < ARR_SIZE; i++){
      a[i] = rand() % 10;
      numt = omp_get_num_threads();
    }
    sum = reduce(a, 0, ARR_SIZE-1);
  }
  t2 = omp_get_wtime();
  for(i = 0; i < ARR_SIZE; i++){
    printf("%d\n", a[i]);
  }
  printf("Soma = %d. Tempo = %g. Numt = %d\n", sum, t2-t1, numt);
}