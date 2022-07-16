
class Solution {
public:
    int count = 0;
    
    void checkKro(TreeNode* root, int curr){
        if(root == NULL){
            return;
        }
        if(root->val >= curr){
            curr = root->val;
            count++;
        }
        checkKro(root->left, curr);
        checkKro(root->right, curr);
        return;
    }
    
    
    int goodNodes(TreeNode* root) {
        checkKro(root, root->val);
        return count;
    }
};