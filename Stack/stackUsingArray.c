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
    if(s->top == 79) {
        return 1;
    } 
    else { 
        return 0;
    }
}

void main() {
    struct stack *s;
    s->size = 80;
    s->top = -1;
    s->arr = (int *) malloc(s->size * sizeof(int));

    int val2 = isEmpty(s);
    int val = isFull(s);

    printf("%d %d", val2, val);
}