class Solution {
public:
    
    void inorder(TreeNode* root, vector<int>&hash,int level){
        if(root == NULL){
            hash.push_back(-1*level);
            return;
        }
        inorder(root->left, hash, level+1);
        hash.push_back(root->val);
        inorder(root->right, hash, level+1);
        return;
    }
    
    
    
    bool isSymmetric(TreeNode* root) {
        vector<int>hash;
        inorder(root, hash, 1);
        int n = hash.size();
        // for(auto x : hash){
        //     cout << x << ", ";
        // }
        // cout << hash[0] << " " << hash[n-1];
        for(int i=0; i<n; i++){
            if(hash[i] != hash[n-i-1]){
                return false;
            }
        }
        return true;
    }
};