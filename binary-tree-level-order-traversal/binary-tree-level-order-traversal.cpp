
class Solution {
public:
    
    int depth(TreeNode* root){
        if(root == NULL){
            return 0;
        }
        int h1 = depth(root->left);
        int h2 = depth(root->right);
        return max(h1, h2) + 1;
    }
    
    void printAtDistanceK(TreeNode* root, int k, vector<int>&hash){
        if(root == NULL){
            return;
        }
        if(k==1){
            hash.push_back(root->val);
            
        }
        printAtDistanceK(root->left, k-1, hash);
        printAtDistanceK(root->right, k-1, hash);
        return;
        
    }
    
    vector<vector<int>> printAllLevel(TreeNode* root){
        vector<vector<int>>hash_new;
        vector<int>hash;
        int len = depth(root);
        for(int i=1; i<=len; i++){
            printAtDistanceK(root, i, hash);
            hash_new.push_back(hash);
            hash.clear();
        }
        return hash_new;
    }
    
    vector<vector<int>> levelOrder(TreeNode* root) {
        return printAllLevel(root);
    }
};