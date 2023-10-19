#include<stdio.h>
#include<stdlib.h>

struct node {
    int val;
    struct node *next;  // self refrencing pointer
};

void traversal(struct node *head) {

    struct node *temp = head;

    // we have used a do while loop because the condition is already false at first iteration 
    // so it wants a kick start
    do{
        printf("element is: %d \n", temp->val);
        temp = temp->next;
    }while(temp != head);

}

struct node *insertAtFirst(struct node *head, int data) { 

    struct node *newNode = (struct node *) malloc(sizeof(struct node));
    newNode->val = data;

    struct node *temp = head->next;

    // this loop takes us to the node which is just behind head or we can say last one
    while(temp->next != head) {
        temp = temp->next;
    }

    temp->next = newNode;
    newNode->next = head;

    return newNode;
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
    abdomen->next = head;

    traversal(head);

    printf("\n");

    head = insertAtFirst(head, 50);

    traversal(head);

}