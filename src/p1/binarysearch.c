#include <stdio.h>
#include <inttypes.h>

void swap(uint32_t *a, uint32_t *b) {
  uint32_t t = *a;
  *a = *b;
  *b = t;
}

void bubblesort(uint32_t a[], size_t n) {
  for (size_t i = (n - 1); i > 0; i--)
    for(size_t j = 1; j <= i; j++)
      if (a[j-1] > a[j])
        swap(&a[j-1], &a[j]);
}

size_t binarysearch(uint32_t x, uint32_t a[], size_t n) {
  size_t lower = 0;
  size_t upper = n-1;
  size_t mid;

  while(lower < upper) {
    mid = (lower + upper) / 2;
    if (x == a[mid])
      return mid;
    else if (x < a[mid])
      upper = mid - 1;
    else
      lower = mid + 1;
  }

  return -1;
}

int main() {
  size_t i;

  uint32_t a[] = {37, 1, 18, 36, 0, 44, 34, 4, 47, 13};
  uint32_t s[] = {49, 34, 21, 37, 13};

  size_t l_a = sizeof(a)/sizeof(a[0]);
  size_t l_s = sizeof(s)/sizeof(s[0]);

  bubblesort(a, l_a);
  printf("sorted array: ");
  for (i = 0; i < l_a; i++) printf("%02"PRIu32" ", a[i]);
  printf("\n");

  for(i = 0; i < l_s; i++) {
    size_t t = binarysearch(s[i], a, l_a);
    printf("search [%02"PRIu32"]\t: ", s[i]);
    if (t == -1)
      printf("not found!\n");
    else
      printf("found at [%02zu]\n", t);
  }

  return 0;
}
