#include <stdio.h>
#include <inttypes.h>

size_t linearsearch(uint32_t x, uint32_t a[], size_t n) {
  for (size_t i = 0; i < n; i++)
    if (a[i] == x)
      return i;
  return -1;
}

int main() {
  uint32_t a[] = {37, 1, 18, 36, 0, 44, 34, 4, 47, 13};
  uint32_t s[] = {49, 34, 21, 37, 13};

  size_t l_a = sizeof(a)/sizeof(a[0]);
  size_t l_s = sizeof(s)/sizeof(s[0]);

  for(size_t i = 0; i < l_s; i++) {
    size_t t = linearsearch(s[i], a, l_a);
    printf("search [%02"PRIu32"]\t: ", s[i]);
    if (t == -1)
      printf("not found!\n");
    else
      printf("found at [%02zu]\n", t);
  }

  return 0;
}
