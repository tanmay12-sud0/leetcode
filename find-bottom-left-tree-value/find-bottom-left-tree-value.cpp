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
    int value;
    
    void leftMost(TreeNode* root, int level, int &maxLevel){
        if(root == NULL){
            return;
        }
        if(level > maxLevel){
            maxLevel = level;
            value = root->val;
        }
        
        leftMost(root->left, level+1, maxLevel);
        leftMost(root->right, level+1, maxLevel);
        return;
    }
    
    
    
    
    int findBottomLeftValue(TreeNode* root) {
        int maxLevel = -1;
        if(root == NULL)return NULL;
        leftMost(root, 0, maxLevel);
        return value;
    }
};