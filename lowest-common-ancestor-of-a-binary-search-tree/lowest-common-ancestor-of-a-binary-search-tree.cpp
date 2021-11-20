
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root == NULL){
		    return NULL;
	}  
        
	if(root->val == p->val or root->val == q->val){
		return root;
	}
        
    TreeNode* leftans = NULL;
    TreeNode* rightans = NULL;
	// if(root->val >= p->val or root->val >= q->val){
        leftans = lowestCommonAncestor(root->left, p, q);
    // }else{
        rightans = lowestCommonAncestor(root->right, p, q);
    // }
	

	if(leftans and rightans){
		return root;
	}
	if(leftans != NULL){
		return leftans;
	}
	return rightans;
    }
};