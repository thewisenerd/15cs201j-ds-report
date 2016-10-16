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

  st.s[++st.top] = n;

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

  return st.s[st.top--];
}

void display() {
  int i;
  printf("display: ");
  if (stempty())
    printf("stack empty!\n");
  else
    for (i = st.top; i >= 0; i--)
      printf("%d%s", st.s[i], i?" -> ":"\n");
}

int main() {
  int i = 0;

  st.top = -1;

  while (i++ < 6)
    push(i);

  display();

  i = 6;
  while(i--) {
    printf("pop: %d\n", pop());
  }

  display();

  return 0;
}
