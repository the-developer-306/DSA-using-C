#include <stdio.h>
#include <stdlib.h>


struct TreeNode {
    int data;
    struct TreeNode* left;
    struct TreeNode* right;
};


struct StackNode {
    struct TreeNode* treeNode;
    struct StackNode* next;
};

struct Stack {
    struct StackNode* top;
};


struct TreeNode* createNode(int data) {
    struct TreeNode* newNode = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}


struct StackNode* createStackNode(struct TreeNode* treeNode) {
    struct StackNode* newNode = (struct StackNode*)malloc(sizeof(struct StackNode));
    newNode->treeNode = treeNode;
    newNode->next = NULL;
    return newNode;
}


struct Stack* createStack() {
    struct Stack* stack = (struct Stack*)malloc(sizeof(struct Stack));
    stack->top = NULL;
    return stack;
}


void push(struct Stack* stack, struct TreeNode* treeNode) {
    struct StackNode* newNode = createStackNode(treeNode);
    newNode->next = stack->top;
    stack->top = newNode;
}


struct TreeNode* pop(struct Stack* stack) {
    if (stack->top == NULL) {
        return NULL;
    }

    struct StackNode* poppedNode = stack->top;
    stack->top = stack->top->next;
    struct TreeNode* treeNode = poppedNode->treeNode;
    free(poppedNode);
    return treeNode;
}


struct TreeNode* buildBinaryTree() {
    struct TreeNode* root = createNode(1);
    struct Stack* stack = createStack();
    push(stack, root);

    while (1) {
        struct TreeNode* currentNode = pop(stack);
        if (!currentNode) {
            break;
        }

        int data;
        printf("Enter left child for %d (0 for NULL): ", currentNode->data);
        scanf("%d", &data);
        if (data != 0) {
            currentNode->left = createNode(data);
            push(stack, currentNode->left);
        }

        printf("Enter right child for %d (0 for NULL): ", currentNode->data);
        scanf("%d", &data);
        if (data != 0) {
            currentNode->right = createNode(data);
            push(stack, currentNode->right);
        }
    }

    return root;
}


void inOrderTraversal(struct TreeNode* root) {
    if (root) {
        inOrderTraversal(root->left);
        printf("%d ", root->data);
        inOrderTraversal(root->right);
    }
}

int main() {
    struct TreeNode* root = buildBinaryTree();
    printf("In-order traversal of the binary tree: ");
    inOrderTraversal(root);
    printf("\n");

    return 0;
}
