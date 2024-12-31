// Write a C function `in_order_iterative_with_balance_check(Node *root)` to perform an
// iterative in-order traversal while checking whether the tree is balanced.
// - A balanced tree is defined as one where the heights of the left and right subtrees of any
// node differ by at most 1.
// - Use two stacks: one for the traversal and one for tracking balance checks.

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

 struct Node {
    int data;
    struct Node *left;
    struct Node *right;
};


int pre_order_iterative_with_sum(struct Node *root, int *sum) {
    if (root == NULL) {
        return 0;
    }
    struct Node *stack[1000];
    int top = -1;
    stack[++top] = root;
    while (top != -1) {
        struct Node *current = stack[top--];
        *sum += current->data;
        if (current->right != NULL) {
            stack[++top] = current->right;
        }
        if (current->left != NULL) {
            stack[++top] = current->left;
        }
    }
    return *sum;
}

int in_order_iterative_with_balance_check(struct Node *root) {
    if (root == NULL) {
        return 0;
    }
   struct  Node *stack[1000];
    int top = -1;
    stack[++top] = root;
    while (top != -1) {
        struct Node *current = stack[top--];
        if (current->right != NULL) {
            stack[++top] = current->right;
        }
        if (current->left != NULL) {
            stack[++top] = current->left;
        }
    }
    return 0;
}

int main() {
   struct  Node *root = (struct Node *) malloc(sizeof(struct Node));
    root->data = 5;
    root->left = (struct Node *) malloc(sizeof(struct Node));
    root->left->data = 3;
    root->left->left = NULL;
    root->left->right = NULL;
    root->right = (struct Node *) malloc(sizeof(struct Node));
    root->right->data = 7;
    root->right->left = NULL;
    root->right->right = NULL;

    int sum = 0;
    printf("%d\n", pre_order_iterative_with_sum(root, &sum)); 
    return 0;
}