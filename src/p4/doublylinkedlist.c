#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>
#include <stdbool.h>

typedef struct _node {
  uint32_t data;
  void *next;
  void *prev;
} Node;

typedef struct _list {
  void *firstNode;
  void *lastNode;
} List;

List list;

void* getnewnode(uint32_t data) {
  Node* t = malloc(sizeof(Node));
  t->next = NULL;
  t->prev = NULL;
  t->data = data;
  return t;
}

void insertafter(Node *node, Node *newNode) {
  Node *t = node->next;
  newNode->prev = node;

  if (t == NULL)
    list.lastNode = newNode;
  else {
    newNode->next = t;
    t->prev = newNode;
  }
  node->next = newNode;
}

void insertbefore(Node *node, Node *newNode) {
  Node *t = node->prev;
  newNode->next = node;

  if (t == NULL)
    list.firstNode = newNode;
  else {
    newNode->prev = t;
    t->next = newNode;
  }
  node->prev = newNode;
}

void insertbeginning(uint32_t data) {
  Node *newNode = getnewnode(data);

  if (list.firstNode == NULL) {
    newNode->prev = NULL;
    newNode->next = NULL;
    list.firstNode = newNode;
    list.lastNode = newNode;
  } else {
    insertbefore(list.firstNode, newNode);
  }
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

void deletenode(Node *node) {
  Node *t = node->prev;
  if (t == NULL)
    list.firstNode = node->next;
  else
    t->next = node->next;

  t = node->next;
  if (t == NULL)
    list.lastNode = node->prev;
  else
    t->prev = node->prev;
}

void delete(uint32_t pos) {
  Node* node = list.firstNode;
  size_t p = 1;
  while (node != NULL && p++ != pos) node = node->next;
  deletenode(node);
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
