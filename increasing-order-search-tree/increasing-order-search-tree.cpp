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
    TreeNode* insertIntoBST(TreeNode* &root, int d){
	if(root == NULL){
		return new TreeNode(d);
	}

	if(root->val >= d){
		root->left = insertIntoBST(root->left, d);
	}else{
		root->right = insertIntoBST(root->right, d);
	}
	return root;
}
    TreeNode* new_root = NULL;
    
    void inorder(TreeNode* root){
	if(root == NULL){
		return;
	}
	inorder(root->left);
	new_root = insertIntoBST(new_root, root->val);
	inorder(root->right);
	return;
}
    
    TreeNode* increasingBST(TreeNode* root) {
        if(root == NULL){
            return root;
        }
        inorder(root);
        return new_root;
        
    }
};