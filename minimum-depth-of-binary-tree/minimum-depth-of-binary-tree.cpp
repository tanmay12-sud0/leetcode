
class Solution {
public:
    
    
    void minDis(TreeNode* root, int level, int &mindep){
        if(root == NULL){
            return;
        }
        if(root->left==NULL and root->right==NULL){
            if(level < mindep){
                mindep = level;
            }
            return;
        }
        
        minDis(root->left, level+1, mindep);
        minDis(root->right, level+1, mindep);
        return;
    }
    
    
    int minDepth(TreeNode* root) {
        if(root == NULL){
            return 0;
        }
        int mindep = INT_MAX;
        minDis(root, 1, mindep);
        return mindep;
    }
};