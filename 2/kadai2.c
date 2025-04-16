/*
kadai2.c
*/
#include <stdio.h>
#include <stdlib.h>
#define N (4)
int main(void) {
  double a[2 * N] = {6, 2, 1, 4, 2, 3, 4, 6}, *b;
  b = malloc(N * sizeof(double)); //(1)
  /*
  for(int i = 0; i < N; i++){
    b[i] = a[2*i+1];
  }
  */
  for (int i = 0; i < N; i++) {
    b[i] = *(a + 2 * i + 1); //(2)
  }
  for (int i = 0; i < N; i++) {
    printf("%f ", b[i]);
  }
  printf("\n");
  printf("address of a[0] = %p\n", &a[0]);
  printf("address of a[N] = %p\n", &a[N]); //(3)
  return 0;
}