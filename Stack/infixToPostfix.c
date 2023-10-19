#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct stack{
    int size;
    int top;
    char *arr;
};      

int isEmpty(struct stack *s) {

    if(s->top == -1) {
        return 1;
    }
    else { 
        return 0;
    }
}

void push(struct stack *s, char data) {

        s->top ++;
        s->arr[s->top] = data;
        
}

int pop(struct stack *s) {

        int val = s->arr[s->top];
        s->top --;
        return val;
    
}

int precedence(char ch) {
    if(ch == '/' || ch == '*') {
        return 2;
    }
    if(ch == '+' || ch == '-') { 
        return 1;
    }
    else { 
        return 0;
    }
}

int isOperator(char ch) {
    if (ch == '/' || ch == '*' || ch == '+' || ch == '-') {
        return 1;
    }
    else { 
        return 0;
    }
}

char stackTop(struct stack *s) {
    return s->arr[s->top];
}

char *infixToPostfix(char * infix) {
    struct stack *sp = (struct stack *) malloc(sizeof(struct stack));
    sp->size = 100;
    sp->top = -1;
    sp->arr = (char *) malloc(sp->size * sizeof(char));

    char *postfix = (char *) malloc((strlen(infix)+1) * sizeof(char));

    int i=0, j=0; // to track infix and postfix traversal respectively

    while(infix[i] != '\0') {
        
        if (!isOperator(infix[i])) {
            postfix[j] = infix[i];
            j++;
            i++;
        }
        else { 
            if(precedence(infix[i]) > precedence(stackTop(sp))) {
                push(sp, infix[i]);
                i++;
            }
            else { 
                postfix[j] = pop(sp);
                j++;
                // i is not incremented here so that it can be checked again for next elements of stack
            }
        }
    }

    while (!isEmpty(sp)) {
        postfix[j] = pop(sp);
        j++;
    }
    postfix[j] = '\0';
    return postfix;

}

void main() {

    char *infix = "7/3-6+2-3";

    printf("%s", infixToPostfix(infix));
}