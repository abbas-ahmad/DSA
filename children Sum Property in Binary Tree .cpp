/*
    Given a binary tree, write a function that returns true if the tree satisfies below property. 
    For every node, data value must be equal to sum of data values in left and right children. 
    Consider data value as 0 for NULL children. iNCREMENT OF NODE VALUE IS ALLOWED UT NOT DECREMENT.

    LinK: https://practice.geeksforgeeks.org/problems/left-view-of-binary-tree/1#

    Idea: 
    - simply traverse the tree and at each node, make the sum of the node equal to the sum of left child and right child
    - otherwise incrment the value of both child to this sum and do this for all node
    - after comming out of recursion again take the sum of both child and asign it to the parent,do no do this if it is leaf
*/
#include <bits/stdc++.h>
using namespace std;
struct Node{
    int data;
    Node *left;
    Node *right;

    Node(int val){
        data = val;
        left = NULL;
        right = NULL;
    }
};

void changeTree(Node *root){
    if(!root)
        return;
    int childSum = 0;
    if(root->left)
        childSum += root->left->data;
    if(root->right)
        childSum += root->right->data;

    if(root->data < childSum){
        root->data = childSum;
    }
    else{
        if(root->left)
            root->left->data = childSum;
        if(root->right)
            root->right->data = childSum;
    }
    changeTree(root->left);
    changeTree(root->right);

    int sum = 0;
    if(root->left)
        sum += root->left->data;
    if(root->right)
        sum += root->right->data;

    // asign sum to root
    if(root->left or root->right)
        root->data = sum;
}