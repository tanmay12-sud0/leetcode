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
    
    void leftsum(TreeNode* root, string s){
        if(root == NULL)return;
        if(root->left==NULL and root->right == NULL){
            s += to_string(root->val);
            hash.push_back(s);
            return;
        }
        leftsum(root->left, s + to_string(root->val));
        leftsum(root->right, s + to_string(root->val));
        return;
    }
    
    int sumNumbers(TreeNode* root) {
        if(root == NULL){
            return NULL;
        }
        string s = "";
        leftsum(root, s);
        int value = 0;
        for(auto c : hash){
            value += stoi(c);
        }
        return value;
        
    }
};