#include<stdio.h>
#include<stdlib.h>

struct Node {
    int val;
    struct Node *next;  // self refrencing pointer
};

struct Node * deleteAtFirst(struct Node *head) {

    struct Node *newNode = head;
    head = head->next;
    free(newNode);
    return head;

}

struct Node * deleteAtIndex(struct Node *head, int index) {
   
    // making a temporary traversal variable
    struct Node *temp = head;
    int i = 0;

    //through this loop we have traversed till the desired node after which deletion is to be done
    while (i != index-1) {
        temp = temp->next;
        i++;
    }
    
    struct Node *newNode = temp->next;
    temp->next = newNode->next;
    free(newNode);

    return head;
}

struct Node * deleteAtLast(struct Node *head) {
        
    // making a temporary traversal variable
    struct Node *temp = head;
    
    //through this loop we have traversed till the second last node after which insertion is to be done
    while (temp->next->next != NULL) {
        temp = temp->next;
    }

    struct Node *newNode = temp->next;
    temp->next = NULL;
    free(newNode);
    
    return head;
}

struct Node * deleteAGivenNode(struct Node *head, struct Node *givenNode) {
    
    struct Node *temp = head;

    // with this temp has traversed till the previous node to the node which is to be deleted
    while (temp->next != givenNode) {
        temp = temp->next;
    }

    temp->next = givenNode->next;
    free(givenNode);

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

    head->val = 1;  // (*head).val = 1
    head->next = thorax;

    thorax->val = 2;
    thorax->next = abdomen;

    abdomen->val = 3;
    abdomen->next = NULL;

    // head = deleteAtFirst(head);

    // head = deleteAtIndex(head, 1);

    // head = deleteAtLast(head);

    head = deleteAGivenNode(head, thorax);

    printList(head);
    
}