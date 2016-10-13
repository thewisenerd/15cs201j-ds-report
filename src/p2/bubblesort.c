#include <stdio.h>
#include <inttypes.h>

void swap(uint32_t *a, uint32_t *b) {
  uint32_t t = *a;
  *a = *b;
  *b = t;
}

void bubblesort(uint32_t a[], size_t n) {
  for (size_t i = (n - 1); i > 0; i--) {
    for(size_t j = 1; j <= i; j++)
      if (a[j-1] > a[j])
        swap(&a[j-1], &a[j]);

    printf("pass %02zu\t\t: ", n - i);
    for (size_t t = 0; t < n; t++) printf("%02"PRIu32" ", a[t]);
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

  bubblesort(a, l_a);

  printf("sorted array\t: ");
  for (i = 0; i < l_a; i++) printf("%02"PRIu32" ", a[i]);
  printf("\n");

  return 0;
}
