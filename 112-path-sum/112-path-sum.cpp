
class Solution {
public:
        
    bool hasPathSum(TreeNode* root, int targetSum) {
        if(root == NULL)return false;
        if(targetSum-root->val == 0 and root->left==NULL and root->right == NULL)return true;
        return hasPathSum(root->left, targetSum-root->val) || hasPathSum(root->right, targetSum-root->val);
    }
};