
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
    
    void printAtDistanceKA(TreeNode* root, int k, vector<int>&hash){
        if(root == NULL){
            return;
        }
        if(k==1){
            hash.push_back(root->val);
            
        }
        printAtDistanceKA(root->left, k-1, hash);
        printAtDistanceKA(root->right, k-1, hash);
        return;
        
    }
    
    void printAtDistanceKB(TreeNode* root, int k, vector<int>&hash){
        if(root == NULL){
            return;
        }
        if(k==1){
            hash.push_back(root->val);
            
        }
        printAtDistanceKB(root->right, k-1, hash);
        printAtDistanceKB(root->left, k-1, hash);
        return;
        
    }
    
    vector<vector<int>> printAllLevel(TreeNode* root){
        vector<vector<int>>hash_new;
        vector<int>hash;
        int len = depth(root);
        for(int i=1; i<=len; i++){
           if(i%2==0){
                printAtDistanceKB(root, i, hash);
            hash_new.push_back(hash);
            hash.clear();
           }else{
                printAtDistanceKA(root, i, hash);
            hash_new.push_back(hash);
            hash.clear();
           }
        }
        return hash_new;
    }
    
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
         return printAllLevel(root);
    }
};




