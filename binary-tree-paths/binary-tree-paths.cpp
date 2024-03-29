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
    vector<string>hash;
    
    void checkNode(TreeNode* root, string s){
        if(root==NULL){
            return;
        }
        if(root->left==NULL and root->right==NULL){
            s += to_string(root->val);
            hash.push_back(s);
           
        }
        
        checkNode(root->left, s+to_string(root->val)+"->");
        checkNode(root->right, s+to_string(root->val)+"->");
        s.pop_back();
        // s.pop_back();
        // s.pop_back();
        return;
        
    }

    vector<string> binaryTreePaths(TreeNode* root) {
        string s;
        checkNode(root, s);
        return hash;
    }
};