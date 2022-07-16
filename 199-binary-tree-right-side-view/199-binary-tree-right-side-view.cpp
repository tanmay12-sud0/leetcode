
class Solution {
public:
    
    void rightView(TreeNode* root, int level, int &maxlevel, vector<int>&hash){
	    if(root == NULL){
            return;
        }
        if(level > maxlevel){
            maxlevel = level;
            hash.push_back(root->val);
        }
        rightView(root->right, level+1, maxlevel, hash);
        rightView(root->left, level+1, maxlevel, hash);
        return;
    }
    
    
    
    vector<int> rightSideView(TreeNode* root) {
        vector<int>hash;
        int maxlevel = -1;
        rightView(root, 0,maxlevel, hash);
        return hash;
    }
};