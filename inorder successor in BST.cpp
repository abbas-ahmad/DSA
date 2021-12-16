/*
    Given a BST, and a reference to a Node x in the BST. 
    Find the Inorder Successor of the given node in the BST.

    Link: https://practice.geeksforgeeks.org/problems/inorder-successor-in-bst/1#

    Idea: we can traverse the BST using BST property
    - if we find a node whose value is greater than the target than it can be possible succ
    - we store it and continue our search in left part to find imm succ
    - if we found any node whise value is larger than or equal to target node than our succ will lies towards right
    - so we will go towards right
*/


// Recursive
// we need to pass the succ pointer a ref othwerwise its changes will not be reflected in main/other fn
void solve(Node* node, int val, Node* &succ){
    if(!node) return;
    
    if(node->data > val){
        succ = node;
        solve(node->left, val, succ);
    }
    else solve(node->right, val, succ);
}
// returns the inorder successor of the Node x in BST (rooted at 'root')
Node * inOrderSuccessor(Node *root, Node *x){
    if(!root) return NULL;
    Node* succ = NULL;
    solve(root, x->data, succ);
    
    return succ;
}

// iterative
Node * inOrderSuccessor(Node *root, Node *x){
    if(!root) return NULL;
    Node* succ = NULL;

    Node *cur = root;
    while(cur){
        if (cur->data > x->data){
            succ = cur;
            cur = cur->left;
        }
        else{
            cur = cur->right;
        }
    }
    return succ;
}
