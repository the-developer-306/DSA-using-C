#include<stdio.h>
#include<stdlib.h>

struct Node {
    int val;
    struct Node *next;  // self refrencing pointer
};

struct Node * deleteAlternate(struct Node *head) {

    struct Node *temp = head;

    while (temp->next != NULL) { 

        // condition for even number of nodes in a linked list
        if(temp->next->next == NULL) {
            temp->next = NULL;
        }
        else {
            struct Node *newNode = temp->next;
            temp->next = temp->next->next;          //  temp->next = newNode->next;
            free(newNode);
            temp = temp->next;
        }
    }

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
    struct Node *fourth = (struct Node*) malloc(sizeof(struct Node));

    head->val = 1;  // (*head).val = 1
    head->next = thorax;

    thorax->val = 2;
    thorax->next = abdomen;

    abdomen->val = 3;
    abdomen->next = fourth;

    fourth->val = 4;
    fourth->next = NULL;

    head = deleteAlternate(head);

    printList(head);
    
}