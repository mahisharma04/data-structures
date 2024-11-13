#include <iostream>
#include <climits>
using namespace std;

class node
{
    public:
        int data;
        node* left;
        node* right;

        //constructors
        node(int data1, node* left1, node* right1)
        {
            data = data1;
            left = left1;
            right = right1;
        }
        node(int data1)
        {
            data = data1;
            left = nullptr;
            right = nullptr;
        }
};

node* createBST(node* root, int val)
{
    if(root == nullptr) return new node(val);

    if(val > root->data)
    {
        root->right = createBST(root->right, val);
    }
    if(val < root->data)
    {
        root->left = createBST( root->left , val);
    }

    return root;
}

//traversals
void inorder(node* root)
{
    if(root == nullptr) return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}
void postorder(node* root)
{
    if(root == nullptr) return;
    postorder(root->left);
    postorder(root->right);
    cout << root->data << " ";
}

void preorder(node* root)
{
    if(root == nullptr) return;
    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}

node* searchBST(node* root, int val)
{
    while(root != nullptr && val != root->data)
    {
        root = val < root->data ? root->left : root->right;
    }
    return root;
}

node* findMax(node* root)
{
    while(root->right != nullptr)
    {
        root = root->right;
    }
    return root;
}

node* findMin(node* root)
{
    while(root->left !=nullptr)
    {
        root = root->left;
    }
    return root;
}

//Ceiling : smallest element which is greater than or equal to the key value.
node* findCeiling(node* root, int val)
{
    if(root == nullptr) return nullptr;
    
    node* ceil = nullptr;
    while(root != nullptr)
    {
        if(root->data == val)
        {
            return root;
        }
        else if(root->data > val)
        {
            ceil = root;
            root = root->left;
        }
        else
        {
            root = root->right;
        }
    }
    return ceil;
}

//floor: greatest element that is smaller than or equal to the key element.
node* findFloor(node* root, int val)
{
    if(root == nullptr) return nullptr;

    node* floor = nullptr;
    while(root != nullptr)
    {
        if(root->data == val)
        {
            return root;
        }
        else if(root->data > val)
        {
            root = root->left;
        }
        else
        {
            floor = root;
            root = root->right;
        }
    }
    return floor;
}

bool isBST(node* root, int min, int max )
{
    if(root == nullptr) return true;

    if(root->data > min && root->data < max)
    {
        bool leftBST = isBST(root->left, min, root->data);
        bool rightBST = isBST(root->right, root->data, max);
        return leftBST && rightBST;
    }

    return false;
}

bool validateBST ( node* root)
{
    return isBST(root, INT_MIN, INT_MAX);
}

int main()
{

    node* root = nullptr;
    root = createBST(root, 10);
    root = createBST(root, 5);
    root = createBST(root, 13);
    root = createBST(root, 11);
    root = createBST(root, 14);
    root = createBST(root, 3);
    root = createBST(root, 6);
    root = createBST(root, 2);
    root = createBST(root, 4);
    root = createBST(root, 9);

    if(validateBST(root)){
        cout << "The given tree is a BST.";
    }
    else{
        cout << "The given tree is not a BST.";
    }



    return 0;
}