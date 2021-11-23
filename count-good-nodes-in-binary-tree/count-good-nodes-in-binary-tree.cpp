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
    int count = 0;
    
    void checkKro(TreeNode* root, int curr){
        if(root==NULL){
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