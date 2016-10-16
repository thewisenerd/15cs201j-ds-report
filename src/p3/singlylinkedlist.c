#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>
#include <stdbool.h>

typedef struct _node {
  uint32_t data;
  void *next;
} Node;

typedef struct _list {
  void *firstNode;
} List;

List list;

void* getnewnode(uint32_t data) {
  Node* t = malloc(sizeof(Node));
  t->next = NULL;
  t->data = data;
  return t;
}

void insertbeginning(uint32_t data) {
  Node* newnode = getnewnode(data);
  newnode->next = list.firstNode;
  list.firstNode = newnode;
}

void insertafter(Node *node, Node *newNode) {
  newNode->next = node->next;
  node->next = newNode;
}

void insert(size_t pos, uint32_t data) {
  Node *newNode, *iter;
  size_t i;

  if (pos == 1) {
    insertbeginning(data);
    return;
  }

  iter = list.firstNode;
  newNode = getnewnode(data);
  i = 2;

  while (iter != NULL && i++ < pos) iter = iter->next;
  insertafter(iter, newNode);
}

void deletebeginning() {
  Node *t = list.firstNode;
  if (t == NULL) return;
  list.firstNode = t->next;
  free(t);
}

void deleteafter(Node *node) {
  Node *t = node->next;
  if (t == NULL) return;
  node->next = t->next;
  free(t);
}

void delete(size_t pos) {
  Node *iter;
  size_t i;

  if (pos == 1) {
    deletebeginning();
    return;
  }

  iter = list.firstNode;
  i = 2;

  while (iter != NULL && i++ < pos) iter = iter->next;
  deleteafter(iter);
}


void traverse(List list) {
  Node* node = list.firstNode;
  while (node != NULL) {
    printf("%02"PRIu32, node->data);
    printf("%s", (node->next == NULL) ? "\n" : " -> ");
    node = node->next;
  }
}

bool search(List list, uint32_t data) {
  Node *node = list.firstNode;
  while (node != NULL) {
    if (node->data == data) return true;
    node = node->next;
  }
  return false;
}

int main() {

  list.firstNode = NULL;

  printf("insert at head: 37, 60, 85\n");
  insert(1, 37);
  insert(1, 60);
  insert(1, 85);

  printf("traverse: ");
  traverse(list);

  printf("insert at [2]: 11\n");
  insert(2, 11);

  printf("insert at [3]: 23\n");
  insert(3, 23);

  printf("traverse: ");
  traverse(list);

  printf("delete at beginning.\n");
  delete(1);

  printf("traverse: ");
  traverse(list);

  printf("delete at 3.\n");
  delete(3);

  printf("traverse: ");
  traverse(list);

  printf("search for 13: ");
  printf("%sfound\n", search(list, 13) ? "" : "not ");

  printf("search for 37: ");
  printf("%sfound\n", search(list, 37) ? "" : "not ");

  return 0;
}
