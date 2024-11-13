#include <iostream>
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

int main ()
{

    node* root = nullptr;
    int n;

    do{
        cout << "(to exit input -1) enter element: ";
        cin >> n;
        if(n == -1) break;
        root = createBST(root, n);
    }while(n>0);

    cout << "displaying the tree (inorder)..." << endl;
    inorder(root);
    cout << endl << endl;

    cout << "enter the element that you want to search: ";
    int el;
    cin >> el;
    node*index = search(root, el);

    if(index != nullptr) cout << "The element is present in the tree.";
    else cout << "The element is not present in the tree";

    root = deleteNode(root, 56);

    return 0;
}