// Write a C function `post_order_iterative_with_deletion_count(Node *root, int *delete_count)`
// to perform an iterative post-order traversal while counting the number of leaf nodes
// deleted.
// - Use two stacks to implement the iterative post-order traversal.
// - Count how many leaf nodes are deleted during the traversal.

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
   struct  Node *stack[1000];
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
    struct Node *stack[1000];
    int top = -1;
    stack[++top] = root;
    while (top != -1) {
       struct  Node *current = stack[top--];
        if (current->right != NULL) {
            stack[++top] = current->right;
        }
        if (current->left != NULL) {
            stack[++top] = current->left;
        }
    }
    return 0;
}

int post_order_iterative_with_deletion_count(struct Node *root, int *delete_count) {
    if (root == NULL) {
        return 0;
    }
   struct  Node *stack1[1000];
   struct  Node *stack2[1000];
    int top1 = -1;
    int top2 = -1;
    stack1[++top1] = root;
    while (top1 != -1) {
        struct Node *current = stack1[top1--];
        stack2[++top2] = current;
        if (current->left != NULL) {
            stack1[++top1] = current->left;
        }
        if (current->right != NULL) {
            stack1[++top1] = current->right;
        }
    }
    while (top2 != -1) {
        struct Node *current = stack2[top2--];
        if (current->left == NULL && current->right == NULL) {
            (*delete_count)++;
        }
    }
    return *delete_count;
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

    int delete_count = 0;
    printf("%d\n", post_order_iterative_with_deletion_count(root, &delete_count)); 
    return 0;
}