#include <stdio.h>
#include <stdlib.h>


struct node {
    int data;
    struct node* left;
    struct node* right;
};

struct node* createNode(int value) {
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}


struct node* insert(struct node* root, int value) {
    if (root == NULL) 
    {  
        return createNode(value);
    }

    if (value < root->data) {
        
        root->left = insert(root->left, value);

    } else if (value > root->data) {
        
        root->right = insert(root->right, value);
    }

    return root; 
}



int main() {
    struct node* root = NULL;

    int nodes[] = {15, 18, 13, 8, 14, 4, 16, 9, 19};
    int size = sizeof(nodes) / sizeof(nodes[0]);

    for (int i = 0; i < size; i++) {
        root = insert(root, nodes[i]);
    }



    return 0;
}
