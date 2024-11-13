#include<iostream>
using namespace std;

class node{
    public:
    int data;
    node* left;
    node* right;

    node() : data(0), left(nullptr), right(nullptr) {}
    node(int data1) : data(data1), left(nullptr), right(nullptr) {}
    node(int data1, node* left1, node* right1) : data(data1), left(left1), right(right1) {}

};

node* createBST(node* root, int val){
    if(root == nullptr) return new node(val);

    if(val < root->data){
        root->left = createBST(root->left, val);
    }
    else if(val > root->data){
        root->right = createBST(root->right, val);
    }
    return root;
}

void inorder(node* root){
    if(root == nullptr) return;

    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

node* searchBST(node*root, int target){
    if(root == nullptr){
        cout << "The tree is empty. or target not found/" << endl;
        return nullptr;
    }

    if(target == root->data){
        return root;
    }
    else if(target > root->data){
        return searchBST(root->right, target);
    }
    else return searchBST(root->left, target);
}

node* findMax(node* root){
    if(root == nullptr) return nullptr;

    while(root->right != nullptr){
        root = root->right;
    }
    return root;
}

node* findMin(node* root){
    if(root == nullptr) return nullptr;

    while(root->left != nullptr){
        root = root->left;
    }
    return root;
}

node* deleteNode(node* root, int val){
    if(root == nullptr) return nullptr;

    if(val > root->data){
        root->right = deleteNode(root->right, val);
    }
    else if(val < root->data){
        root->left = deleteNode(root->left, val);
    }
    else{
        //case where root node has no children
        if(root->left == nullptr && root->right == nullptr){
            delete root;
            return nullptr;
        }
        //case where root has one child
        else if(root->left == nullptr){
            node* temp = root->right;
            delete root;
            return temp;
        }
        else if(root->right == nullptr){
            node* temp = root->left;
            delete root;
            return temp;
        }
        //case where root has both children
        node* largest = findMax(root->left);
        root->data = largest->data;
        root->left = deleteNode(root->left, largest->data);
    }
    return root;
}