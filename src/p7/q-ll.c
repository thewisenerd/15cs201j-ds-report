#include <stdio.h>
#include <stdlib.h>

typedef struct node {
  int val;
  void *next;
} Node;

Node *front,*rear,*t,*it;

int count = 0;

void enq(int n) {
  t = malloc(sizeof(Node));
  t->val = n;
  t->next = NULL;

  if (rear == NULL)
    front = rear = t;
  else {
    rear->next = t;
    rear = t;
  }
  count++;
}

void display() {
  it = front;
  if (front == NULL) {
    printf("queue empty!\n");
    return;
  }
  while (it != NULL) {
    printf("%d", it->val);
    if (it->next != NULL) printf(" <- ");
    it = it->next;
  }
  printf("\n");
}

void deq() {
  if (front == NULL) {
    printf("dequeue: empty queue!\n");
    return;
  }

  if (front->next == NULL) {
    free(front);
    front = rear = NULL;
    return;
  }

  t = front;
  front = front->next;
  printf("dequeue: %d\n", t->val);
  free(t);
}

int peek() {
  if (front == NULL) {
    printf("queue empty!");
    return -1;
  }
  return front->val;
}

int size() {
  int s = 0;
  it = front;
  while (it != NULL) {
    it = it->next;
    s++;
  }
  return s;
}

int main() {
  int i = 0;

  front = rear = NULL;

  while(i++ < 5)
    enq(i);

  display();

  deq();
  deq();

  display();


  printf("size of queue: %d\n", size());
  printf("first elem: %d\n", peek());

  i = 4;
  while(i--)
    deq();

  return 0;
}
