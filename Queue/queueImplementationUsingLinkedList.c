#include<stdio.h>
#include<stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

struct Node *f = NULL;
struct Node *r = NULL;

int isFull(struct Node *newNode) {
    if (newNode == NULL) { 
        return 1;
    }
    else { 
        return 0;
    }
}

int isEmpty() {
    if (f == NULL) { 
        return 1;
    }
    else { 
        return 0;
    }
}

void traversal() {
    while (f != NULL) {
        printf("Element is: %d\n", f->data);
        f = f->next;
    }
}

void enqueue(int val) {
    struct Node *newNode = (struct Node *) malloc(sizeof(struct Node));
    if(isFull(newNode)) {
        printf("Queue is full");
    }
    else { 
        newNode->data = val;
        newNode->next = NULL;
        if (f == NULL) { 
            f = r = newNode;
        }
        else {
            r->next = newNode;
            r = newNode;
        }
        
    }
}

int dequeue() {
    int a = -1;
    struct Node *temp = f;

    if (isEmpty()) {
        printf("Queue is Empty");
    }
    else { 
        f = f->next;
        a = temp->data;
        free(temp);
    }
    return a;
}

void main() {

    enqueue(1);
    enqueue(2);
    enqueue(3);

    printf("dequeued element is: %d \n", dequeue());

    traversal();
}