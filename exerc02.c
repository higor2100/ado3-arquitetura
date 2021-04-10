#include<omp.h>
#include<stdio.h>
#include <stdlib.h>
#include <math.h>

#define ARR_SIZE 8

int main(){

  int i, j, tid, numt;
  double t1, t2;
  int a[ARR_SIZE];
  int b[ARR_SIZE][ARR_SIZE];
  int x[ARR_SIZE];

  omp_set_num_threads(4);
  t1 = omp_get_wtime();

  #pragma omp parallel for 
  for(i = 0; i < ARR_SIZE; i++){
    a[i] = rand() % 5;
    printf("%d\n", a[i]);
    numt = omp_get_num_threads();
  }

  #pragma omp parallel for 
  for(i = 0; i < ARR_SIZE; i++){
    for(j = 0; j < ARR_SIZE; j++){
      b[i][j] = rand() % 10;
      printf("%d ", b[i][j]);
      numt = omp_get_num_threads();
    }
    printf("\n");
  }


  #pragma omp for
  for(i = 0; i < ARR_SIZE; i++){
    for(j = 0; j < ARR_SIZE; j++){  
        x[i] += a[j] * b[i][j];
        numt = omp_get_num_threads();
    }
  }

  for(i = 0; i < ARR_SIZE; i++){
    printf("%d\n", x[i]);
  }

  t2 = omp_get_wtime();
  printf("Tempo = %g. Numt = %d\n", t2-t1, numt);

}

