#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>
#include <stdbool.h>

typedef struct _node {
  uint32_t data;
  void *next;
} Node;

typedef struct _list {
  void *lastNode;
} List;

List list;

void* getnewnode(uint32_t data) {
  Node* t = malloc(sizeof(Node));
  t->next = NULL;
  t->data = data;
  return t;
}

void insertafter(Node *node, Node *newNode) {
  if (node == NULL)
    newNode->next = newNode;
  else {
    newNode->next = node->next;
    node->next = newNode;
  }
}

void insert(size_t pos, uint32_t data) {
  Node *newNode, *iter, *t;
  size_t i;

  t = list.lastNode;
  newNode = getnewnode(data);

  if (pos == 1) {
    insertafter(list.lastNode, newNode);
    if (list.lastNode == NULL)
      list.lastNode = newNode;
    return;
  }

  if (list.lastNode == NULL) {
    printf("invalid position!\n");
    return;
  }

  iter = t->next;
  i = 2;
  while (iter != NULL && i++ < pos) iter = iter->next;
  insertafter(iter, newNode);
  if (iter == list.lastNode) list.lastNode = newNode;
}

void deletebeginning() {
  Node *lastNode, *firstNode;
  lastNode = list.lastNode;
  if (lastNode == NULL) return;
  firstNode = lastNode->next;

  lastNode->next = firstNode->next;

  free(firstNode);
}

void deleteafter(Node *node) {
  Node *t = node->next;
  if (t == NULL) return;
  node->next = t->next;
  if (t == list.lastNode) {
    list.lastNode = node;
    node->next = t->next;
  }
  free(t);
}

void delete(size_t pos) {
  Node *iter, *t;
  size_t i;

  if (pos == 1) {
    deletebeginning();
    return;
  }

  t = list.lastNode;
  iter = t->next;
  i = 2;
  while (iter != NULL && i++ < pos) iter = iter->next;
  deleteafter(iter);
}

void traverse(List list) {
  Node *first, *iter, *t;

  if (list.lastNode == NULL) {
    printf("list empty!\n");
    return;
  }

  t = list.lastNode;
  first = iter = t->next;

  do {
    printf("%02"PRIu32, iter->data);
    printf("%s", (iter->next == first) ? "\n" : " -> ");
    iter = iter->next;
  } while (iter != first);
}

bool search(List list, uint32_t data) {
  Node *first, *iter, *t;

  if (list.lastNode == NULL) return false;

  t = list.lastNode;
  first = iter = t->next;

  do {
    if (iter->data == data)
      return true;
    iter = iter->next;
  } while (iter != first);

  return false;
}

int main() {

  list.lastNode = NULL;

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

  printf("insert at [4]: 67\n");
  insert(6, 67);


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
