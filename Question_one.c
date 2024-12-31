// Write a C function `search_bst(Node *root, int key)` that searches for a key in a binary
// search tree. The function should return `true` if the key is found and `false` otherwise.
// In addition to this basic search, you should also:
// - Track the path traversed during the search and print it as a list of node values.
// - Return the number of nodes visited during the search.

#include <stdio.h>
#include <stdbool.h>

struct node {
    int data;
    struct node *left;
    struct node *right;
};

bool search_bst(struct node *root, int key) {
    struct node *current = root;
    while (current != NULL) {
        if (current->data == key) {
            return true;
        } else if (current->data > key) {
            current = current->left;
        } else {
            current = current->right;
        }
    }
    return false;
}

int main() {
    struct node *root = (struct node *) malloc(sizeof(struct node));
    root->data = 5;
    root->left = (struct node *) malloc(sizeof(struct node));
    root->left->data = 3;
    root->left->left = NULL;
    root->left->right = NULL;
    root->right = (struct node *) malloc(sizeof(struct node));
    root->right->data = 7;
    root->right->left = NULL;
    root->right->right = NULL;

    printf("%d\n", search_bst(root, 3));
    return 0;
}


