#include<stdio.h>
#include <stdlib.h>

struct Queue {
    int size;
    int f;
    int r;
    int *arr;
};

int isEmpty(struct Queue *q) {
    if (q->f == q->r) {
        return 1;
    }
    else { 
        return 0;
    }
}

int isFull(struct Queue *q) {
    if (q->r == q->size-1) { 
        return 1;
    }
    else { 
        return 0;
    }
}

void enqueue(struct Queue *q, int data) {
    if(isFull(q)) {
        printf("Queue is Full \n");
    }
    else {
        q->r++;
        q->arr[q->r] = data;
    }
}

int dequeue(struct Queue *q) {
    int a = -1;
    if(isEmpty(q)) {
        printf("Queue is Empty \n");
    }
    else {
       q->f++;
       a = q->arr[q->f];
    }
    return a;
}

void main() {
    struct Queue q;
    q.size = 100;
    q.f = -1;
    q.r = -1;
    q.arr = (int *) malloc(q.size * sizeof(int));

    enqueue(&q, 1);
    enqueue(&q, 2);
    enqueue(&q, 3);
    enqueue(&q, 4);
    enqueue(&q, 5);

    printf("dequeued element is: %d \n", dequeue(&q));
    printf("dequeued element is: %d \n", dequeue(&q));
    printf("dequeued element is: %d \n", dequeue(&q));
    printf("dequeued element is: %d \n", dequeue(&q));
    printf("dequeued element is: %d \n", dequeue(&q));
    printf("dequeued element is: %d \n", dequeue(&q));

}