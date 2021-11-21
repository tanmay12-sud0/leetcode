
class Solution {
public:
    
    int min_so_far = INT_MAX;
    
    void minDiff(TreeNode* root){
        if(root == NULL){
            return;
        }
        if(root->left){
            
            TreeNode* replace = root->left;
            while(replace->right!=NULL){
                replace = replace->right;
            }
            
            min_so_far = min(min_so_far, abs(root->val- replace->val));
        }
        if(root->right){
             TreeNode* replace = root->right;
            while(replace->left!=NULL){
                replace = replace->left;
            }
            
            min_so_far = min(min_so_far, abs(root->val- replace->val));
        }
        
    
        minDiff(root->left);
        minDiff(root->right);
        return;
    }
    
    
    
    int minDiffInBST(TreeNode* root) {
        minDiff(root);
        return min_so_far;
    }
};



