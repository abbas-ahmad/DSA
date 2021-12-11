class Solution {
private:
    bool isLeaf(Node* node){
        return !node->left and !node->right;
    }
    
    void leftBoundary(Node* node, vector<int>& ans){
        Node* cur = node;
        
        while(cur){
            if(!isLeaf(cur)) ans.push_back(cur->data);
            else if(cur->left) cur = cur->left;
            else cur = cur->right;
        }
    }
    
    void rightBoundary(Node* node, vector<int>& ans){
        vector<int> temp;
        Node* cur = node;
        
        while(cur){
            if(!isLeaf(cur)) temp.push_back(cur->data);
            else if(cur->right) cur = cur->right;
            else cur = cur->left;
        }
        
        for(int i = temp.size()-1; i >= 0; i--){
            ans.push_back(temp[i]);
        }
    }
    
    void bottomBoundary(Node* node, vector<int>& ans){
        if(isLeaf(node)){
            ans.push_back(node->data);
            return;
        }
        
        if(node->left) bottomBoundary(node->left, ans);
        if(node->right) bottomBoundary(node->right, ans);
    }
    
    
public:
    vector <int> boundary(Node *root){
        vector<int> ans;
        if(!root) return ans;
        ans.push_back(root->data);
        
        if(root->left) leftBoundary(root->left, ans);
        if(!isLeaf(root))bottomBoundary(root, ans);
        if(root->right) rightBoundary(root->right, ans);
        
        return ans;
    }
};