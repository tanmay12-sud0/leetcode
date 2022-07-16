
class Solution {
public:
    
    bool check(TreeNode* rootA, TreeNode* rootB){
        if(rootA == NULL and rootB == NULL){
            return true;
        }
        if(rootA == NULL ^ rootB == NULL){
            return false;
        }
        if(rootA->val != rootB->val){
            return false;
        }
        bool left = check(rootA->left, rootB->right);
        bool right = check(rootA->right, rootB->left);
        return left and right;
    }
    
    
    bool isSymmetric(TreeNode* root) {
        return check(root, root);
    }
};