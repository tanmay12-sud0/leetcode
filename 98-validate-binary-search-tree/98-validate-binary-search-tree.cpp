
class Solution {
public:
    
    bool checkBST(TreeNode* root, long a, long b){
        if(root == NULL){
            return true;
        }
        if(root->val <= a or root->val >= b){
            return false;
        }
        bool pp = checkBST(root->left, a, root->val);
        bool qq = checkBST(root->right, root->val, b);
        return pp and qq;
    }

    
    bool isValidBST(TreeNode* root) {
        return checkBST(root, LONG_MIN, LONG_MAX);
    }
};