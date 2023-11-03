#include <bits/stdc++.h>

using namespace std;

struct node {
  int data;
  struct node * left, * right;
};


struct node * newNode(int data) {
  struct node * node = (struct node * ) malloc(sizeof(struct node));
  node -> data = data;
  node -> left = NULL;
  node -> right = NULL;

  return (node);
}

void inOrderTrav(node * curr, int& count) {
  if (curr == NULL)
    return;

  count++;
  inOrderTrav(curr -> left, count);
  inOrderTrav(curr -> right, count);
}

int main() {

  struct node * root = newNode(1);
  root -> left = newNode(2);
  root -> right = newNode(3);
  root -> left -> left = newNode(4);
  root -> left -> right = newNode(5);
  root -> right -> left = newNode(6);

  int count = 0;
  inOrderTrav(root, count);

  cout <<count;
  return 0;
}