
class Solution {
public:
    
    class HBPair{
        
        public:
	        int hei;
	        int balance;
    };

    HBPair balanceCheck(TreeNode* root){
        HBPair pp;
	    if(root == NULL){
            pp.hei = 0;
            pp.balance = true;
            return pp;
        }
        HBPair left = balanceCheck(root->left);
        HBPair right = balanceCheck(root->right);
        if(left.balance and right.balance and abs(left.hei - right.hei) <= 1){
            pp.balance = true;
            pp.hei = max(left.hei, right.hei) + 1;
            return pp;
        }
        pp.balance = false;
        return pp;
    }
    
    
    bool isBalanced(TreeNode* root) {
        HBPair pp = balanceCheck(root);
        return pp.balance;
    }
};