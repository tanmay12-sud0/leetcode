/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    
    bool checkBST(TreeNode* root, long a, long b){
        if(root == NULL){
            return true;
        }
        if(!(root->val > a and root->val < b)){
            return false;
        }
        
        bool h1 = checkBST(root->left, a, root->val);
        bool h2 = checkBST(root->right, root->val, b);
        if(!h1 or !h2){
            return false;
        }
        return true;
    }
    
    
    
    bool isValidBST(TreeNode* root) {
        return checkBST(root, LONG_MIN, LONG_MAX);
    }
};