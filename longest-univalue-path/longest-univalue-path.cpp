
class Solution {
public:
    int check(TreeNode* root, int target){
        if(root==NULL){
            return 0;
        }
        
        if(root->val != target){
            return 0;
        }
        
        int a = check(root->left, target);
        int b = check(root->right, target);
        return max(a,b)+1;
    }
    
    
    int longestUnivaluePath(TreeNode* root) {
        if(root==NULL){
            return 0;
        }
        int h1 = check(root->left, root->val);
        int h2 = check(root->right, root->val);
        int op1 = h1+h2;
        int op2 = longestUnivaluePath(root->left);
        int op3 = longestUnivaluePath(root->right);
        return max(op1, max(op2, op3));
    }
};