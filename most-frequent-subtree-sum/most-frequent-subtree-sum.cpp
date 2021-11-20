
class Solution {
public:
    
    unordered_map<int, int>hash;
    
    int kMost(TreeNode* root){
        if(root==NULL){
            return 0;
        }
        if(root->left==NULL and root->right==NULL){
            hash[root->val]++;
            return root->val;
        }
        
        int a = kMost(root->left);
        int b = kMost(root->right);
        hash[a+b+root->val]++;
        return a+b+root->val;
    }
    
    
    
    vector<int> findFrequentTreeSum(TreeNode* root) {
        vector<int>umap;
        kMost(root);
        int mf = INT_MIN;
        for(auto x : hash){ 
            mf = max(mf, x.second);
        }
        for(auto x : hash){
            if(x.second == mf){
                umap.push_back(x.first);
            }
        }
        return umap;
    }
};