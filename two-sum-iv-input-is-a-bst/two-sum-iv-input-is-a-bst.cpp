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
    
    unordered_map<int, int>umap;
    
    bool checkValue(TreeNode* root, int k){
        if(root == NULL){
            return false;
        }
        if(umap.count(k-root->val)){
            return true;
        }else{
            umap[root->val]++;
        }
        bool leftans = checkValue(root->left, k);
        bool rightans = checkValue(root->right, k);
        if(leftans or rightans){
            return true;
        }
        return false;
    }

    
    bool findTarget(TreeNode* root, int k) {
        return checkValue(root, k);
    }
};