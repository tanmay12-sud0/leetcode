class Solution {
public:
    vector<int>hash;
    
    void inorder(TreeNode* root){
        if(root == NULL){
            return;
        }
        inorder(root->left);
        hash.push_back(root->val);
        inorder(root->right);
        return;
    }
    int kthSmallest(TreeNode* root, int k) {
        inorder(root);
        return hash[k-1];
    }
};