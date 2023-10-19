#include<stdio.h>
#include<stdlib.h>

struct Node {
    int coeff;
    int exponent;
    struct Node *next;
};

struct Node *p1t1;
struct Node *p1t2;
struct Node *p1t3;
struct Node *p1t4;

struct Node *p2t1;
struct Node *p2t2;
struct Node *p2t3;
struct Node *p2t4;

struct Node *p3t1;
// struct Node *p3t2;
// struct Node *p3t3;
// struct Node *p3t4;
// struct Node *p3t5;
// struct Node *p3t6;
// struct Node *p3t7;
// struct Node *p3t8;

void addAtLast(int coe, int pow) {

    struct Node *newNode = (struct Node *) malloc(sizeof(struct Node));
    newNode->coeff = coe;
    newNode->exponent = pow;
    
    // making a temporary traversal variable
    struct Node *temp = p3t1;
    
    //through this loop we have traversed till the end node after which insertion is to be done
    while (temp->next != NULL) {
        temp = temp->next;
    }

    temp->next = newNode;
    newNode->next = NULL;
    
}

void addition() {

    struct Node *temp1 = p1t1;
    struct Node *temp2 = p2t1;

    while (temp1 != NULL || temp2 != NULL) {

        if(temp1->exponent > temp2->exponent) {
            addAtLast(temp1->coeff, temp1->exponent);
            temp1 = temp1->next;            
        }

        if(temp1->exponent < temp2->exponent) {
            addAtLast(temp2->coeff, temp2->exponent);
            temp2 = temp2->next;
        }

        if(temp1->exponent == temp2->exponent) {
            addAtLast((temp1->coeff+temp2->coeff), temp1->exponent);
            temp1 = temp1->next;
            temp2 = temp2->next;
        }
    }
}

void traversal() {
    struct Node *a = p3t1;
    while (a != NULL) {
        printf("%d x ^ %d + \t", a->coeff, a->exponent);
        a = a->next;
    }
}

void main() {

    p1t1 = (struct Node *) malloc(sizeof(struct Node));
    p1t2 = (struct Node *) malloc(sizeof(struct Node));
    p1t3 = (struct Node *) malloc(sizeof(struct Node));
    p1t4 = (struct Node *) malloc(sizeof(struct Node));

    p1t1->coeff = 4;
    p1t1->exponent = 3;
    p1t1->next = p1t2;

    p1t2->coeff = 5;
    p1t2->exponent = 2;
    p1t2->next = p1t3;

    p1t3->coeff = -8;
    p1t3->exponent = 1;
    p1t3->next = p1t4;

    p1t4->coeff = 6;
    p1t4->exponent = 0;
    p1t4->next = NULL;

    p2t1 = (struct Node *) malloc(sizeof(struct Node));
    p2t2 = (struct Node *) malloc(sizeof(struct Node));
    p2t3 = (struct Node *) malloc(sizeof(struct Node));
    p2t4 = (struct Node *) malloc(sizeof(struct Node));

    p2t1->coeff = 67;
    p2t1->exponent = 3;
    p2t1->next = p2t2;

    p2t2->coeff = -59;
    p2t2->exponent = 2;
    p2t2->next = p2t3;

    p2t3->coeff = 22;
    p2t3->exponent = 1;
    p2t3->next = p2t4;

    p2t4->coeff = 677;
    p2t4->exponent = 0;
    p2t4->next = NULL;

    p3t1 = (struct Node *) malloc(sizeof(struct Node));
    p3t1->next = NULL;
    // p3t2 = (struct Node *) malloc(sizeof(struct Node));
    // p3t3 = (struct Node *) malloc(sizeof(struct Node));
    // p3t4 = (struct Node *) malloc(sizeof(struct Node));
    // p3t5 = (struct Node *) malloc(sizeof(struct Node));
    // p3t6 = (struct Node *) malloc(sizeof(struct Node));
    // p3t7 = (struct Node *) malloc(sizeof(struct Node));
    // p3t8 = (struct Node *) malloc(sizeof(struct Node));

    addition();

    traversal();


}