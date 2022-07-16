
class Solution {
    int sum = 0;
    void leftsum(TreeNode* root, bool level){
        if(root==NULL){
            return;
        }
        if(level == true and root->left==NULL and root->right==NULL){
            sum += root->val;
            
        }
        leftsum(root->left, true);
        leftsum(root->right, false);
        return;
    }

    
public:
    int sumOfLeftLeaves(TreeNode* root) {
        if(root == NULL){
            return 0;
        }
        int maxLevel = -1;
        leftsum(root, false);
        return sum;
    }
};