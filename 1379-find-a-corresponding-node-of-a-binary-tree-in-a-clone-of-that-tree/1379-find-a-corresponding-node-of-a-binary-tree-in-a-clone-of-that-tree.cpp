/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    
    TreeNode* copyKro(TreeNode* cloned, TreeNode* target){
        if(cloned==NULL){
            return NULL;
        }
        if(cloned->val == target->val){
            return cloned;
        }
        TreeNode* leftans = copyKro(cloned->left, target);
        TreeNode* rightans = copyKro(cloned->right, target);
        if(leftans){
            return leftans;
        }
        return rightans;
    }
    
    
    
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
        return copyKro(cloned, target);
    }
};