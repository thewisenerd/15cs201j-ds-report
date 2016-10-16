#include <stdio.h>
#include <stdlib.h>

typedef struct node {
  int val;
  void *next;
} Node;

Node *top;

int empty() {
  return (top == NULL);
}

int peek() {
  return top->val;
}

int getStackSize() {
  Node *iter = top;
  if (iter == NULL) {
    printf("stack empty!\n");
    return 0;
  }

  int l = 0;
  while(iter != NULL){
    iter = iter->next;
    l++;
  }
  return l;
}

void push(int n) {
  Node *t;
  printf("pushing %d: ", n);
  t = malloc(sizeof(Node));
  t->val = n;

  t->next = empty() ? NULL : top;
  top = t;
  printf("done!\n");
}

void pop() {
  Node *t = top;
  if (t == NULL) {
    printf("stack empty\n");
    return;
  }

  printf("removed element: %d\n", t->val);
  top = top->next;
  free(t);
}

void printStack() {
  Node *it = top;
  while (it != NULL) {
    printf("%d", it->val);
    if (it->next != NULL) printf(" -> ");
    it = it->next;
  }
  printf("\n");
}

int main() {
  top = NULL;

  push(1);
  push(2);
  push(3);
  push(4);

  printf("size : %d\n", getStackSize(top));

  printf("peek : %d\n", peek());

  printf("print: "); printStack();

  pop();
  pop();
  pop();
  pop();
  pop();
  printf("print: "); printStack();

  return 0;
}
