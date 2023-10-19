#include<stdio.h>
#include<stdlib.h>

struct Node {
    int val;
    struct Node *next;  // self refrencing pointer
};

struct Node * addAtFirst(struct Node *head, int data) {
    struct Node *newNode = (struct Node *) malloc(sizeof(struct Node));
    newNode->val = data;

    newNode->next = head;
    
    return newNode;
}

struct Node * addAtIndex(struct Node *head, int data, int index) {

    struct Node *newNode = (struct Node *) malloc(sizeof(struct Node));
    newNode->val = data;

    // making a temporary traversal variable
    struct Node *temp = head;
    int i = 0;

    //through this loop we have traversed till the desired node after which insertion is to be done
    while (i != index-1) {
        temp = temp->next;
        i++;
    }
    
    // now linking new node to next of desired node and desired node to new node
    newNode->next = temp->next;
    temp->next = newNode;

    return head;
}

struct Node * addAtLast(struct Node *head, int data) {
    struct Node *newNode = (struct Node *) malloc(sizeof(struct Node));
    newNode->val = data;
    
    // making a temporary traversal variable
    struct Node *temp = head;
    
    //through this loop we have traversed till the end node after which insertion is to be done
    while (temp->next != NULL) {
        temp = temp->next;
    }

    temp->next = newNode;
    newNode->next = NULL;
    
    return head;
}

struct Node * addAfterNode(struct Node *head, struct Node *prevNode, int data) {
    struct Node *newNode = (struct Node *) malloc(sizeof(struct Node));
    newNode->val = data;
    
    newNode->next = prevNode->next;
    prevNode->next = newNode;
    
    return head;
}

void printList(struct Node *a) {
    while (a != NULL) {
        printf("Element is: %d\n", a->val);
        a = a->next;
    }
}

void main() {

    struct Node *head = (struct Node*) malloc(sizeof(struct Node));
    struct Node *thorax = (struct Node*) malloc(sizeof(struct Node));
    struct Node *abdomen = (struct Node*) malloc(sizeof(struct Node));

    head->val = 1;
    head->next = thorax;

    thorax->val = 2;
    thorax->next = abdomen;

    abdomen->val = 3;
    abdomen->next = NULL;

    head = addAtFirst(head, 0);

    head = addAtIndex(head, 23, 2);

    head = addAtLast(head, 56);

    head = addAfterNode(head, thorax, 101);

    printList(head);
    

}