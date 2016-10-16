// C program to demonstrate insert operation in binary search tree
#include<stdio.h>
#include<stdlib.h>

typedef struct node {
  int k;
  void* l;
  void* r;
} Node;

Node* nN(int n) {
  Node* t = malloc(sizeof(Node));
  t->k = n;
  t->l = t->r = NULL;

  return t;
}

void printO(Node* n) {
  if (n == NULL)
    return;

  printO(n->l);
  printf("%d ", n->k);
  printO(n->r);

}

Node *insert(Node *n, int k) {
  if (n == NULL) return nN(k);

  if (k < n->k)
    n->l = insert(n->l, k);
  else if (k > n->k)
    n->r = insert(n->r, k);

  return n;
}

Node *search(Node *r, int k) {
  if (r == NULL || r->k == k)
    return r;

  if (r->k < k)
    return search(r->r, k);

  return search(r->l, k);
}

Node *minvn(Node *n) {
  Node *c = n;
  while (c->l != NULL)
    c = c->l;
  return c;
}

Node *deleteNode(Node *r, int k) {
  if (r == NULL) return r;

  if (k < r->k)
    r->l = deleteNode(r->l, k);
  else if (k > r->k)
    r->r = deleteNode(r->r, k);
  else {
    if (r->l == NULL) { // left node empty
      Node *t = r->r;
      free(r);
      return t;
    } else if (r->r == NULL) {
      Node *t = r->l;
      free(r);
      return t;
    }
    Node *t = minvn(r->r);
    r->k = t->k;
    r->r = deleteNode(r->r, t->k);
  }
  return r;
}

// Driver Program to test above functions
int main()
{
    /* Let us create following BST
              50
           /     \
          30      70
         /  \    /  \
       20   40  60   80 */
    Node *r = NULL, *t;
    r = insert(r, 50);
    insert(r, 30);
    insert(r, 20);
    insert(r, 40);
    insert(r, 70);
    insert(r, 60);
    insert(r, 80);

    printf("inorder: ");
    printO(r);
    printf("\n");

    printf("searching 30: ");
    t = search(r, 30);
    if (t == NULL)
      printf("not exists!\n");
    else
      printf("%d exists\n", t->k);

    printf("searching 90: ");
    t = search(r, 90);
    if (t == NULL)
      printf("not exists!\n");
    else
      printf("%d exists\n", t->k);

    printf("delete 50\n");
    r = deleteNode(r, 50);

    printf("inorder: ");
    printO(r);
    printf("\n");


    return 0;
}
