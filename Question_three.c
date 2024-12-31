// Write a C function `pre_order_iterative_with_sum(Node *root, int *sum)` to perform an
// iterative pre-order traversal and calculate the sum of all node values during the traversal.
// - The traversal should use a stack.
// - While performing the traversal, calculate the sum of all node values visited.

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