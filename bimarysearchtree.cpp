#include <iostream>
#include <queue>
//#include"bits/stdc++.h"
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;

    Node(int val)
    {
        data = val;
        left = NULL;
        right = NULL;
    }
};
Node *searchbst(Node *root, int key)
{
    if (root->data == key)
    {
        return root;
    }
    //data>key
    if (root->data > key)
    {
        return searchbst(root->left, key);
    }
    //data<key
    return searchbst(root->right, key);
}
int main()
{
    Node *root = new Node(4);
    root->left = new Node(2);
    root->right = new Node(5);
    root->left->left = new Node(1);
    root->left->right = new Node(3);
    root->right->right = new Node(6);
    //     Binarysearchtree()

    //      4
    //     /  \
//     2   5
    //    / \    \
//    1  3    6
    if (searchbst(root, 5) == NULL)
    {
        cout << "key does not exist";
    }
    else
    {
        cout << "key exist";
    }
    return 0;
}
