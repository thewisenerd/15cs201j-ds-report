#include <stdio.h>
#include <stdlib.h>

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

void printO(Node* n, int d) {
  if (n == NULL)
    return;

  switch (d) {
    case -1:
      printf("%d ", n->k);
      printO(n->l, -1);
      printO(n->r, -1);
      break;
    case 0:
      printO(n->l, 0);
      printf("%d ", n->k);
      printO(n->r, 0);
      break;
    case 1:
      printO(n->l, 1);
      printO(n->r, 1);
      printf("%d ", n->k);
      break;
  }

}

/* Driver program to test above functions*/
int main()
{
  Node *root  = nN(1);
  root->l  = nN(2);
  root->r = nN(3);

  Node *t = root->l;
  t->l = nN(4);
  t->r = nN(5);

  printf("preorder: ");
  printO(root, -1);
  printf("\n");

  printf("inorder: ");
  printO(root, 0);
  printf("\n");

  printf("postorder: ");
  printO(root, 1);
  printf("\n");

  return 0;
}
