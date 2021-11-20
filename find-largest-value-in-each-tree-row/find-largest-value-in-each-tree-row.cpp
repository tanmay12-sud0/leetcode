
class Solution {
public:
    
    int len(TreeNode* root){
        if(root==NULL){
            return NULL;
        }
        int h1 = len(root->left);
        int h2 = len(root->right);
        return max(h1, h2)+1;
    }
    
    void findRowMax(TreeNode* root, int level, vector<int>&hash){
        if(root==NULL){
            return;
        }
        
        if(hash[level] == INT_MIN){
            hash[level] = root->val;
        }else{
            if(hash[level] < root->val){
            
                hash[level] = root->val;
        }
        }
        
        findRowMax(root->left, level+1, hash);
        findRowMax(root->right, level+1, hash);
        return;
    }
    
    
    
    vector<int> largestValues(TreeNode* root) {
        // vector<int>new_hash;
        int lens = len(root);
        vector<int>hash(lens, INT_MIN);
        findRowMax(root, 0, hash);
        // for(auto x : hash){
        //     if(x > INT_MIN){
        //         new_hash.push_back(x);
        //     }else{
        //         break;
        //     }
        // }
        return hash;
    }
};