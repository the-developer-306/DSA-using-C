#include<stdio.h>
#include<stdlib.h>

struct stack{
    int size;
    int top;
    int *arr;
};

int isEmpty(struct stack *s) {

    if(s->top == -1) {
        return 1;
    } 
    else { 
        return 0;
    }
}

int isFull(struct stack *s) {

    if(s->top == 9) {
        return 1;
    } 
    else { 
        return 0;
    }
}

void push(struct stack *s, int data) {

    if (isFull(s)) {
        printf("Stack Overflow !!! \n");
    }
    else { 
        s->top ++;
        s->arr[s->top] = data;
    }
}

int pop(struct stack *s) {

    if (isEmpty(s)) {
        printf("Stack Underflow !!! \n");
        return -1;
    }
    else { 
        int val = s->arr[s->top];
        s->top --;
        return val;
    }
}

int peak(struct stack *s, int posFromTop) {

    int arrayIndex = s->top - posFromTop + 1;
    if (arrayIndex < 0) {
        printf("Not a valid position given for stack ☹️☹️☹️ \n");
        return -1;
    }
    else { 
        int val = s->arr[arrayIndex];
        return val;
    }
}

void main() {

    // stack creation
    struct stack *s = (struct stack *) malloc(sizeof(struct stack));
    s->size = 10;
    s->top = -1;
    s->arr = (int *) malloc(s->size * sizeof(int));

    push(s, 1);    push(s, 2);    push(s, 3);    push(s, 4);    push(s, 5);

    push(s, 6);    push(s, 7);    push(s, 8);    push(s, 9);

    push(s, 10);    // 10 elements pushed

    push(s, 11);    // stack overflow

    printf("peaked value: %d \n", peak(s, 7));
    printf("poped value: %d \n", pop(s));
    printf("poped value: %d \n", pop(s));
    printf("is Full: %d \n", isFull(s));
    


}