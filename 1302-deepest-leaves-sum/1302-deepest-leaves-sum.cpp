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
    
    void solve(TreeNode* root, int &maxLevel, int level, int &sum){
        if(root == NULL){
            return;
        }
        if(level > maxLevel){
            maxLevel = level;
            sum = root->val;
        }
        else if(level == maxLevel){
            sum += root->val;
        }
        solve(root->left, maxLevel, level+1, sum);
        solve(root->right, maxLevel, level+1, sum);
        return;
    }
    
    
    
    int deepestLeavesSum(TreeNode* root) {
        int maxLevel = 0;
        int sum = 0;
        solve(root, maxLevel, 0, sum);
        return sum;
    }
};