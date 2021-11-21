
class Solution {
public:
    
    int count(TreeNode* root){
        if(root == NULL){
            return 0;
        }
        return count(root->left) + count(root->right) + 1;
    }
    
    bool check(TreeNode* root, int target, int idx){
        if(root==NULL){
            return true;
        }
        if(idx > target){
            return false;
        }
        return check(root->left, target, 2*idx) and check(root->right, target, 2*idx+1);
    }
    
    bool isCompleteTree(TreeNode* root) {
        int target = count(root);
        return check(root, target, 1);
    }
};