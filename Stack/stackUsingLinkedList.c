#include<stdio.h>
#include<stdlib.h>

struct Node {
    int val;
    struct Node *next;  // self refrencing pointer
};

int isEmpty(struct Node * top) {
    if(top == NULL) {
        return 1;
    } 
    else { 
        return 0;
    }
}

int isFull(struct Node *top) {

    // feel is that if memory is not allocated for a new node that means stack is full
    struct Node * temp = (struct Node *) malloc(sizeof(struct Node));
    if(temp == NULL) {
        return 1;
    } 
    else { 
        return 0;
    }
}

struct Node * push(struct Node * top, int data) {
    if (isFull(top)){
        printf("Stack Overflow !!! \n");
    }
    else{
        struct Node *newNode = (struct Node *) malloc(sizeof(struct Node));
        newNode->val = data;

        newNode->next = top;
        return newNode;
    }
}

int pop(struct Node ** top) {

    if (isEmpty(*top)){
        printf("Stack Underflow !!! \n");
    }
    else{

        int element = (*top)->val;

        struct Node *newNode = *top;
        *top = (*top)->next;
        free(newNode);
        return element;
    }
    

}

int * peek(struct Node * top, int pos) {
    struct Node *temp = top;

    for (int i = 0; (i < pos-1 && temp != NULL); i++) { 
        temp = temp->next;
    }
    if(temp != NULL) {
        return temp->val;
    }
    else {
        return -1;
    }
}

void stackTraversal(struct Node *a) {
    while (a != NULL) {
        printf("Element is: %d\n", a->val);
        a = a->next;
    }
}

void main() {

    struct Node *top = NULL;
    top = push(top, 1);
    top = push(top, 2);
    top = push(top, 3);
    top = push(top, 4);
    top = push(top, 5);
    top = push(top, 6);
    top = push(top, 7);
    top = push(top, 8);
    top = push(top, 9);

    // printf("poped value: %d \n", pop(&top));
    // printf("poped value: %d \n", pop(&top));

    printf("peek value: %d \n", peek(top, 9));

    stackTraversal(top);

}