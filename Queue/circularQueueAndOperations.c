/*  The main disadvantage of linear queue is that when we enqueue to its fullest and
    then dequeue, the front and rear pointers reach at the end of queue. So no new
    enqueue operation can be performed. */

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
    //matching the next of rear to the front of queue
    if ((q->r+1)%q->size == q->f) { 
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
        q->r = (q->r+1)%q->size;    // circular updation
        q->arr[q->r] = data;
    }
}

int dequeue(struct Queue *q) {
    int a = -1;
    if(isEmpty(q)) {
        printf("Queue is Empty \n");
    }
    else {
       q->f = (q->f+1)%q->size;
       a = q->arr[q->f];
    }
    return a;
}

void main() {
    struct Queue q;
    q.size = 4;

    // here no need of taking -1 index as this is circular queue
    q.f = 0;
    q.r = 0;
    // but due to this we cannot use this zeroth block of memory

    q.arr = (int *) malloc(q.size * sizeof(int));

    enqueue(&q, 1);
    enqueue(&q, 2);
    enqueue(&q, 3);
    
    printf("dequeued element is: %d \n", dequeue(&q));
    printf("dequeued element is: %d \n", dequeue(&q));
    printf("dequeued element is: %d \n", dequeue(&q));
    
    enqueue(&q, 4);
    enqueue(&q, 5);
    enqueue(&q, 6);

    printf("dequeued element is: %d \n", dequeue(&q));
    printf("dequeued element is: %d \n", dequeue(&q));
    printf("dequeued element is: %d \n", dequeue(&q));
    

}