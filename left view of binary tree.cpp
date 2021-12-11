/*
    Given a Binary Tree, print Left view of it. Left view of a Binary Tree is set of nodes visible when 
    tree is visited from Left side. The task is to complete the function leftView(), which accepts root of the 
    tree as argument.
    Left view of following tree is 1 2 4 8.

    LinK: https://practice.geeksforgeeks.org/problems/left-view-of-binary-tree/1#

*/ 
vector<int> leftView(Node *root){
    if(!root) return {};
    
    vector<int> ans;

    queue<Node*> q;
    q.push(root);
    while(!q.empty()){
        int len = q.size();
        for(int i = 0; i < len; i++){
            if(i == 0){
                ans.push_back(q.front()->data);
            }
            Node* node = q.front();
            q.pop();
            
            if(node->left) q.push(node->left);
            if(node->right) q.push(node->right);
        }
    }
    
    return ans;
}