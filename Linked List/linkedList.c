#include<stdio.h>
#include<stdlib.h>

struct node {
    int val;
    struct node *next;  // self refrencing pointer
};

void traversal(struct node *a) {
    while (a != NULL) {
        printf("Element is: %d\n", a->val);
        a = a->next;
    }
}

void main() {

    // malloc allocates size in heap and not in stack
    struct node *head = (struct node*) malloc(sizeof(struct node));
    struct node *thorax = (struct node*) malloc(sizeof(struct node));
    struct node *abdomen = (struct node*) malloc(sizeof(struct node));

    head->val = 1;
    head->next = thorax;

    thorax->val = 2;
    thorax->next = abdomen;

    abdomen->val = 3;
    abdomen->next = NULL;

    traversal(head);

}