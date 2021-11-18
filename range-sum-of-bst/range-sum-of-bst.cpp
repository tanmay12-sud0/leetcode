
class Solution {
public:
    int sum = 0;
    void rootSum(TreeNode* root, int low, int high){
        if(root==NULL){
            return;
        }
        if(root->val >= low and root->val <= high){
            sum += root->val;
        }
        rootSum(root->left, low, high);
        rootSum(root->right, low, high);
        return;
    }
    
    
    
    int rangeSumBST(TreeNode* root, int low, int high) {
        if(root==NULL){
            return 0;
        }
        rootSum(root, low, high);
        return sum;
    }
};