/*
kadai1.c --- 要素個数付き可変長変数aについて、
aの要素個数が偶数ならaの前半と後半を入れ替えたものを新たに作って返す
aの要素個数が奇数ならaと同じものを新たに作って返す
*/
#include <stdio.h>
#include <stdlib.h>
void iarray_read(int *a, int n) {
  for (int i = 0; i < n; i++) {
    printf("a[%d]>", i + 1);
    scanf("%d", &a[i + 1]);
  }
}
void iarray_print(int *a, int n) {
  for (int i = 1; i <= n; i++) {
    printf("%2d ", a[i]);
  }
  printf("\n");
}
int *ivec_new(int size) {
  int *a = malloc((size + 1) * sizeof(int));
  a[0] = size;
  return a;
}
int *ivec_create_swap(int *a) {
  int size = a[0];
  int *b = ivec_new(size);
  b[0] = size;
  if (size % 2 == 0) { // 要素数が偶数のとき
    for (int i = 1; i <= size / 2; i++) {
      b[i] = a[i + size / 2];
      b[i + size / 2] = a[i];
    }
  } else { // 要素数が奇数のとき
    for (int i = 1; i <= size; i++) {
      b[i] = a[i];
    }
  }
  return b;
}
int main(void) {
  int n;
  printf("n>");
  scanf("%d", &n);
  int *a = ivec_new(n);
  iarray_read(a, n);
  int *b = ivec_create_swap(a);
  iarray_print(b, b[0]);
  free(a);
  free(b);
  return 0;
}