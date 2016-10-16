#include <stdio.h>

#define MAX 5

int qa[MAX];

int r = -1, f = -1, i;

void enq(int n) {
  if (r - f == MAX-1) {
    printf("enq: overflow!\n");
    return;
  }
  printf("enq: %d\n", n);
  if (f == -1) f = 0;
  r = r + 1;
  qa[r] = n;
}

void deq() {
  if (f == -1 || f > r) {
    printf("deq: underflow!\n");
    return;
  }

  printf("deq: %d\n", qa[f]);
  f = f + 1;
}

void display() {
  printf("display: ");
  if (f == -1) {
    printf("queue empty!\n");
    return;
  }

  for (i = f; i <= r; i++)
    printf("%d ", qa[i]);
  printf("\n");
}

int main() {

  enq(1);
  enq(2);
  enq(3);
  enq(4);
  enq(5);
  enq(6);

  display();

  deq();
  deq();

  display();

  printf("size of queue: %d\n", r - f + 1);
  printf("first elem: %d\n", qa[f]);

  deq();
  deq();
  deq();
  deq();

  return 0;
}
