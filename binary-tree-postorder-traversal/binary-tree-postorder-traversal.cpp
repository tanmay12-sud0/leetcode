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
    
        void postorder(TreeNode* root, vector<int>&hash){
        if(root==NULL){
            return;
        }
        postorder(root->left, hash);
        postorder(root->right, hash);
        hash.push_back(root->val);

        return;
    }
    
    
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int>hash;
        postorder(root, hash);
        return hash;
    }
};




// class Solution {
// public:
    
    

    
    
    
    
//     vector<int> preorderTraversal(TreeNode* root) {
//         
//     }
// };