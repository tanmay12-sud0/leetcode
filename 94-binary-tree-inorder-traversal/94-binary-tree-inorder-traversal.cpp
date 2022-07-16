class Solution {
public:
    
    void inorder(TreeNode* root, vector<int>&hash){
        if(root == NULL){
            return;
        }
        inorder(root->left, hash);
        hash.push_back(root->val);
        inorder(root->right, hash);
        return;
    }
    
    
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int>hash;
        inorder(root, hash);
        return hash;
    }
};