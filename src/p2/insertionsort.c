#include <stdio.h>
#include <inttypes.h>

void swap(uint32_t *a, uint32_t *b) {
  uint32_t t = *a;
  *a = *b;
  *b = t;
}

void insertionsort(uint32_t a[], size_t l) {
  for (size_t i = 1; i < l; i++) {
    uint32_t x = a[i];
    size_t j;
    for (j = i-1; j >=0 && a[j] > x; j--)
      a[j+1] = a[j];
    a[j+1] = x;

    printf("pass %02zu\t\t: ", i);
    for (size_t t = 0; t < l; t++) printf("%02"PRIu32" ", a[t]);
    printf("\n");
  }
}

int main() {
  size_t i;

  uint32_t a[] = {37, 1, 18, 36, 0, 44, 34, 4, 47, 13};

  size_t l_a = sizeof(a)/sizeof(a[0]);

  printf("un-sorted array\t: ");
  for (i = 0; i < l_a; i++) printf("%02"PRIu32" ", a[i]);
  printf("\n");

  insertionsort(a, l_a);

  printf("sorted array\t: ");
  for (i = 0; i < l_a; i++) printf("%02"PRIu32" ", a[i]);
  printf("\n");

  return 0;
}
