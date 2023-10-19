#include<stdio.h>
#include<stdlib.h>
#include<string.h>

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

void push(struct stack *s, int data) {

        s->top ++;
        s->arr[s->top] = data;
    
}

int pop(struct stack *s) {

        int val = s->arr[s->top];
        s->top --;
        return val;
    
}

int isOperator(char ch) {
    if (ch == '/' || ch == '*' || ch == '+' || ch == '-') {
        return 1;
    }
    else { 
        return 0;
    }
}

int result(char op, int n1, int n2) {
    switch (op)
    {
        case '/':
            return n1/n2;
            break;
        case '*':
            return n1*n2;
            break;
        case '+':
            return n1+n2;
            break;
        case '-':
            return n1-n2;
            break;
    }
}

int evaluate(char * postfix) {
    struct stack *sp = (struct stack *) malloc(sizeof(struct stack));
    sp->size = 100;
    sp->top = -1;
    sp->arr = (int *) malloc(sp->size * sizeof(int));

    int i = 0;

    while (postfix[i] != '\0')
    {
        if (!isOperator(postfix[i])) {
            push(sp, postfix[i]-'0');   // postfix[i]-'0' gives us the integral value.
            i++;
        }
        else { 
            int n2 =  pop(sp);
            int n1 =  pop(sp);
            push(sp,  result(postfix[i], n1, n2));
            i++;
        }
    }

    return pop(sp);
    
}


void main() {

    char *postfix = "73/6-2+3-";

    printf("%d", evaluate(postfix));
}