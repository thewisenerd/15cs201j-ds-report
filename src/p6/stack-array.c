#include <stdio.h>
#include <stdlib.h>

#define size 5
struct stack {
   int s[size];
   int top;
} st;

int stfull() {
  return (st.top >= size - 1);
}

void push(int n) {
  printf("pushing %d: ", n);
  if (stfull()) {
    printf("stack overflow!\n");
    return;
  }

  st.top++;
  st.s[st.top] = n;

  printf("done!\n");
}

int stempty() {
  return (st.top == -1);
}

int pop() {
  if (stempty()) {
    printf("stack underflow!\n");
    return -1;
  }
  st.top--;

  return st.s[st.top + 1];
}

void display() {
  int i;
  printf("display: ");
  if (stempty())
    printf("stack empty!");
  else {
    for (i = st.top; i >= 0; i--) {
      printf("%d", st.s[i]);
      if (i) printf(" -> ");
    }
  }
  printf("\n");
}

int main() {
  int i;

  st.top = -1;

  push(1);
  push(2);
  push(3);
  push(4);
  push(5);
  push(6);

  display();

  i = 6;
  while(i--) {
    printf("pop: %d\n", pop());
  }

  display();

  return 0;
}
