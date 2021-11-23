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
    
    int max_so_far = INT_MIN;
    
    void findMax(TreeNode* root, int value){
        if(root==NULL){
            return;
        }
        
        max_so_far = max(max_so_far, abs(root->val-value));
        
        findMax(root->left, value);
        findMax(root->right, value);
        return;
    }
    
    void FindAll(TreeNode* root){
        if(root==NULL){
            return;
        }
        findMax(root, root->val);
        FindAll(root->left);
        FindAll(root->right);
        return;
    }
    
    
    int maxAncestorDiff(TreeNode* root) {
        if(root==NULL){
            return NULL;
        }
        FindAll(root);
        return max_so_far;
    }
};