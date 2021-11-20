
class Solution {
public:
    
    int sum = 0;
    
    void sumD(TreeNode* root, int level, int &maxLevel){
        if(root==NULL){
            return;
        }
        if(maxLevel == level){
            sum += root->val;
        }else if(level>maxLevel){
            sum = root->val;
            maxLevel = level;
        }
        sumD(root->left, level+1, maxLevel);
        sumD(root->right, level+1, maxLevel);
        return;
        
    }

    
    int deepestLeavesSum(TreeNode* root) {
        int maxLevel = -1;
        sumD(root, 0, maxLevel);
        return sum;
    }
};