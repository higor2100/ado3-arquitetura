#include<omp.h>
#include<stdio.h>
#include <stdlib.h>
#include <math.h>

#define ARR_SIZE 4

int main(){

  int i, j, k, tid, numt;
  double t1, t2;
  int a[ARR_SIZE][ARR_SIZE];
  int b[ARR_SIZE][ARR_SIZE];
  int x[ARR_SIZE][ARR_SIZE];

  omp_set_num_threads(4);
  t1 = omp_get_wtime();

  #pragma omp parallel for 
  for(i = 0; i < ARR_SIZE; i++){
    for(j = 0; j < ARR_SIZE; j++){
      a[i][j] = rand() % 5;
      printf("%d ", a[i][j]);
      numt = omp_get_num_threads();
    }
    printf("\n");
  }
    printf("\n");


  for(i = 0; i < ARR_SIZE; i++){
    for(j = 0; j < ARR_SIZE; j++){
      b[i][j] = rand() % 5;
      printf("%d ", b[i][j]);
      numt = omp_get_num_threads();
    }
    printf("\n");
  }


  #pragma omp for
  for(i = 0; i < ARR_SIZE; i++){
    for(j = 0; j < ARR_SIZE; j++){ 
      x[i][j] = 0;
        for(k = 0; k < ARR_SIZE; k++){ 
        x[i][j] += a[i][k] * b[k][j];
        numt = omp_get_num_threads();
      }
    }
  }
  printf("\n");

  for(i = 0; i < ARR_SIZE; i++){
    for(j = 0; j < ARR_SIZE; j++){
      printf("%d ", x[i][j]);
    }
    printf("\n");
  }
  t2 = omp_get_wtime();
  printf("Tempo = %g. Numt = %d\n", t2-t1, numt);

}

