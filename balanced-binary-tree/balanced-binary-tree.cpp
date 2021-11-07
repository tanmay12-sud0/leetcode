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
    
    class HBPair{
        
        public:
	        int hei;
	        int balance;
    };

    
    
    HBPair balanceCheck(TreeNode* root){
	    HBPair p;
	    if(root == NULL){
		    p.hei = 0;
		    p.balance = true;
		    return p;
	    }

	    HBPair left = balanceCheck(root->left);
	    HBPair right = balanceCheck(root->right);

	    p.hei = max(left.hei, right.hei)+1;

	    if(abs(left.hei-right.hei)<=1 and left.balance and right.balance){
		    p.balance = true;
	    }else{
		    p.balance = false;
	    }
	    return p;

    }
    
    
    bool isBalanced(TreeNode* root) {
        HBPair pp = balanceCheck(root);
        return pp.balance;
    }
};