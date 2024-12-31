// Write a C function `delete_node_with_rotation(Node *root, int key)` to delete a node from
// the binary search tree while performing tree rotations when necessary.
// - You need to handle the three cases of deletion:
// 1. No children (leaf node).
// 2. One child.
// 3. Two children (use the in-order successor and possibly perform rotations).

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
      struct  Node *current = stack[top--];
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
      struct   Node *current = stack[top--];
        if (current->right != NULL) {
            stack[++top] = current->right;
        }
        if (current->left != NULL) {
            stack[++top] = current->left;
        }
    }
    return 0;
}

struct Node *find_min(struct Node *root) {
   struct  Node *current = root;
    while (current->left != NULL) {
        current = current->left;
    }
    return current;
}

struct Node *delete_node_with_rotation(struct Node *root, int key) {
    if (root == NULL) {
        return root;
    }
    if (key < root->data) {
        root->left = delete_node_with_rotation(root->left, key);
    } else if (key > root->data) {
        root->right = delete_node_with_rotation(root->right, key);
    } else {
        if (root->left == NULL) {
           struct Node *temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            struct Node *temp = root->left;
            free(root);
            return temp;
        }
        struct Node *temp = find_min(root->right);
        root->data = temp->data;
        root->right = delete_node_with_rotation(root->right, temp->data);
    }
    return root;
}

int main() {
    struct Node *root = (struct Node *) malloc(sizeof(struct Node));
    root->data = 5;
    root->left = (struct Node *) malloc(sizeof(struct Node));
    root->left->data = 3;
    root->left->left = NULL;
    root->left->right = NULL;
    root->right = (struct Node *) malloc(sizeof(struct Node));
    root->right->data = 7;
    root->right->left = NULL;
    root->right->right = NULL;

    delete_node_with_rotation(root, 3);
    printf("%d\n", search_bst(root, 3)); 
    return 0;
}