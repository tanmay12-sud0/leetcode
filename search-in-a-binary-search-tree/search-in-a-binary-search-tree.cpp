
class Solution {
public:
    TreeNode* searchBST(TreeNode* root, int key) {
        if(root == NULL){
		return NULL;
	}
	if(root->val == key){
		return root;
	}
	if(key <= root->val){
		return searchBST(root->left, key);
	}

	return searchBST(root->right, key);
    }
};