#include<stdio.h>
#include<stdlib.h>

struct Node {
    int val;
    struct Node *next;  // self refrencing pointer
    struct Node *prev;
};


void forwardTraversal(struct Node *a) {
    while (a != NULL) {
        printf("Element is: %d\n", a->val);
        a = a->next;
    }
}

void backwardTraversal(struct Node *a) {
    while (a != NULL) {
        printf("Element is: %d\n", a->val);
        a = a->prev;
    }
}

struct Node * insertAtGivenNode(struct Node *n1, struct Node *givenNode, int data) {
    
    struct Node *newNode = (struct Node*) malloc(sizeof(struct Node));
    newNode->val = data;

    newNode->next = givenNode->next;
    givenNode->next = newNode;
    newNode->next->prev = newNode;
    newNode->prev = givenNode;

    return n1;
}

void main() {

    struct Node *n1 = (struct Node*) malloc(sizeof(struct Node));
    struct Node *n2 = (struct Node*) malloc(sizeof(struct Node));
    struct Node *n3 = (struct Node*) malloc(sizeof(struct Node));

    n1->val = 1;
    n1->next = n2;
    n1->prev = NULL;


    n2->val = 2;
    n2->next = n3;
    n2->prev = n1;

    n3->val = 3;
    n3->next = NULL;
    n3->prev = n2;

    n1 = insertAtGivenNode(n1, n2, 56);
    
    forwardTraversal(n1);
    
    printf("\n");

    backwardTraversal(n3);
    

}