
class Solution {
public:
    
    int height(TreeNode* root){
        if(root==NULL){
            return 0;
        }
        int a = height(root->left);
        int b = height(root->right);
        return max(a,b)+1;
    }
    
    void levelCheckKro(TreeNode* root,int level, vector<int>&umap){
        if(root==NULL){
            return;
        }
        umap[level] += root->val;
        levelCheckKro(root->left, level+1, umap);
        levelCheckKro(root->right, level+1, umap);
        return;
    }
    
    
    int maxLevelSum(TreeNode* root) {
        
        int h = height(root);
        vector<int>umap(h, 0);
        levelCheckKro(root, 0, umap);
        int maxa = INT_MIN;
        int index = -1;
        for(int i=0; i<h; i++){
            if(umap[i] > maxa){
                index = i;
                maxa = umap[i];
            }
        }
        return index+1;
    }
};