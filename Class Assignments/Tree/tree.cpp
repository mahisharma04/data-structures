#include <iostream>
#include <climits>
using namespace std;

class node{
    public:
        int data;
        node* left;
        node* right;

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

    if(val < root->data)
    {
        root->left = createBST(root->left , val);
    }
    else if(val > root->data)
    {
        root->right = createBST(root->right, val);
    }
    return root;
}

node* search(node* root, int val)
{
    if(root == nullptr) return nullptr;
    if(val == root->data)
    {
        return root;
    }
    else if(val > root->data)
    {
        return search(root->right, val);
    }
    else
    {
        return search(root->left, val);
    }
}

void inorder(node* root)
{
    if(root == nullptr) return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

void preorder(node* root)
{
    if(root == nullptr) return;
    cout << root->data << "->";
    preorder(root->left);
    preorder(root->right);
}

void postorder(node* root)
{
    if(root == nullptr) return;
    postorder(root->left);
    postorder(root->right);
    cout << root->data << "->";
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
    while(root->left != nullptr)
    {
        root = root->left;
    }
    return root;
}

node* deleteNode(node* root, int val)
{
    if(root == nullptr) return root;

    if(val < root->data){
        root->left = deleteNode(root->left , val);
    }
    else if( val > root->data){
        root->right = deleteNode(root->right, val);
    }
    else{
        //this case is for deleting the root itself and there are multiple cases under this case.
        if(root->left == nullptr && root->right == nullptr)
        {
            delete root;
            return nullptr;
        }

        //case 2: node having one child
        else if(root->left == nullptr)
        {
            node* temp = root->right;
            delete root;
            return temp;
        }
        else if(root->right == nullptr)
        {
            node*temp = root->left;
            delete root;
            return temp;
        }

        //case 3 : node is having 2 children
        node* largest = findMax(root->left);
        root->data = largest->data;
        root->left = deleteNode(root->left , largest->data);

    }

}

int height(node* root)
{
    if(root == nullptr) return -1;

    int heightLeft = height(root->left);
    int heightRight = height(root->right);

    return max(heightLeft, heightRight) + 1;
}

int balanceFactor(node* root)
{
    if(root == nullptr) return 0;

    return height(root->left)-height(root->right);
}

int countNodes(node* root)
{
    if(root == nullptr) return 0;
    int leftCnt = countNodes(root->left);
    int rightCnt = countNodes(root->right);

    return(leftCnt + rightCnt) +1;
}

bool isBST(node* root, int min, int max)
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

bool validateBST(node* root)
{
    return isBST(root, INT_MIN, INT_MAX);
}

bool isBalanced(node* root)
{
    if(root == nullptr) return true;

    int leftHeight = height(root->left);
    int rightHeight = height(root->right);

    bool rootBalance = abs(leftHeight - rightHeight) <= 1;
    bool leftBalance = isBalanced(root->left) ;
    bool rightBalance = isBalanced(root->right);

    return (rootBalance && leftBalance && rightBalance);
}

int main ()
{

    node* root = nullptr;
    root = createBST(root, 55);
    root = createBST(root, 66);
    root = createBST(root, 77);
    root = createBST(root, 15);
    root = createBST(root, 11);
    root = createBST(root, 33);
    root = createBST(root, 22);


    // int hT = height(root);
    // cout << "height of the node: " << hT << endl;

    node* givenNode = search(root, 22);

    int bF = balanceFactor(givenNode);
    cout << "balance factor of the node: " << bF << endl;

    return 0;
}