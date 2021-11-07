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
    int count = 0;
    void bfsQueue(TreeNode* root){
	if(root==NULL){
		return;
	}
	queue<TreeNode*>q;
	q.push(root);
	while(!q.empty()){
		TreeNode* f = q.front();
		q.pop();
		count++;
		if(f->left){
			q.push(f->left);
		}
		if(f->right){
			q.push(f->right);
		}
	}
	return;
}
    
    
    int countNodes(TreeNode* root) {
        bfsQueue(root);
        return count;
    }
};