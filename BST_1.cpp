// Binary search tree - Implementation in C++
// Also includes searching for a no in the tree

#include <iostream>
using namespace std;

struct BstNode
{
    int data;
    struct BstNode *left;
    struct BstNode *right;
};

BstNode *GetNewNode(int data)
{
    BstNode *newNode = new BstNode();
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

BstNode *Insert(BstNode *root, int data)
{
    if (root == NULL) // Empty tree
    {
        root = GetNewNode(data);
    }
    else if (data <= root->data)
    {
        root->left = Insert(root->left, data);
    }
    else
    {
        root->right = Insert(root->right, data);
    }
    return root;
}

bool search(BstNode *root, int data)
{
    if (root == NULL)
    {
        return false;
    }
    else if (root->data == data)
    {
        return true;
    }
    else if (root->data > data)
    {
        return search(root->left, data);
    }
    else if (root->data < data)
    {
        return search(root->right, data);
    }
}

int main()
{
    BstNode *root = NULL; // Creating an empty tree
    /*Code to test the logic*/
    root = Insert(root, 15);
    root = Insert(root, 10);
    root = Insert(root, 20);
    root = Insert(root, 25);
    root = Insert(root, 8);
    root = Insert(root, 12);

    int num;
    // Asking user to enter a number
    cout << "Enter a no to check if it is in BST: ";
    cin >> num;
    if (search(root, num) == true)
        cout << "found";
    else
        cout << "not found";

    return 0;
}