




class Solution {
public:
    vector<vector<int>>bighash;
    
    void preorder(TreeNode* root, int targetSum, vector<int>hash, int currentsum){
        if(root == NULL){
            return;
        }
        if(root->left==NULL and root->right==NULL and currentsum+root->val == targetSum){
            hash.push_back(root->val);
            bighash.push_back(hash);
        }
        
        hash.push_back(root->val);
        
        preorder(root->left, targetSum, hash, currentsum+root->val);
        preorder(root->right, targetSum, hash, currentsum+root->val);
        
        hash.pop_back();
        
    }

    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<int>hash;
        int currentsum = 0;
        preorder(root, targetSum, hash, currentsum);
        return bighash;
    }
};