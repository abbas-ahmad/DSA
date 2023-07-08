/*
    Given a binary tree, find the largest subtree which is a Binary Search Tree (BST),
    where largest means subtree with largest number of nodes in it.
    Link: https://www.youtube.com/watch?v=X0oXMdtUDwo&list=PLgUwDviBIf0q8Hkd7bK2Bpryj2xVJk8Vk
    
    Approach:
    - we traverse the tree in top-down manner and do BST test for every node. 
    If we traverse the tree in bottom-up manner, then we can pass information about 
    subtrees to the parent. The passed information can be used by the parent to do BST
     test (for parent node) only in constant time (or O(1) time). A left subtree need 
     to tell the parent whether it is BST or not and also needs to pass maximum value 
     in it. So that we can compare the maximum value with the parent’s data to check the 
     BST property. Similarly, the right subtree need to pass the minimum value up the 
     tree. The subtrees need to pass the following information up the tree for the
      finding the largest BST. 
        1) Whether the subtree itself is BST or not (In the following code, 
        is_bst_ref is used for this purpose) 
        2) If the subtree is left subtree of its parent, then maximum value in it. 
        And if it is right subtree then minimum value in it. 
        3) Size of this subtree if this subtree is BST (In the following code, 
        return value of largestBSTtil() is used for this purpose)
        max_ref is used for passing the maximum value up the tree and min_ptr is 
        used for passing minimum value up the tree. 
*/

#include<bits/stdc++.h>
using namespace std;
class TreeNode{
    public:
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int v){
        val = v;
    }
};
class NodeValue{
    public:
    int size;
    int min;
    int max;

    NodeValue(int s, int min, int max){
        this->max = max;
        this->min = min;
        this->size = size;
    }
};

NodeValue largestBSTHelper(TreeNode* node){
    if(!node){
        return NodeValue(0, INT_MIN, INT_MAX);
    }

    NodeValue left = largestBSTHelper(node->left);
    NodeValue right = largestBSTHelper(node->right);

    if(left.max < node->val and right.min > node->val){
        return NodeValue(left.size + right.size + 1, min(left.min, node->val), max(right.max, node->val));
    }

    return NodeValue(max(left.size, right.size), INT_MIN, INT_MAX);
}

int largestBST(TreeNode *root){
    return largestBSTHelper(root).size;
}


/// Brute-force
int largestBST(struct node *root)
{
  // Base Case
  if(root == NULL)
    return 0;
   
   if (isBST(root))
     return size(root);
   else
    return max(largestBST(root->left), largestBST(root->right));
}