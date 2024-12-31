#include <stdio.h>
#include <stdlib.h>

 struct Node {
    int data;
    struct Node *left;
    struct Node *right;
};

int find_height_and_diameter(struct Node *root, int *diameter) {
    if (root == NULL) {
        return 0;
    }
    int left_height = find_height_and_diameter(root->left, diameter);
    int right_height = find_height_and_diameter(root->right, diameter);
    *diameter = left_height + right_height + 1 > *diameter ? left_height + right_height + 1 : *diameter;
    return left_height > right_height ? left_height + 1 : right_height + 1;
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

    int diameter = 0;
    find_height_and_diameter(root, &diameter);
    printf("Diameter: %d\n", diameter); 
    return 0;
}
