
class Solution {
public:
    
    int height(TreeNode* root){
        if(root==NULL){
            return 0;
        }
        int h1 = height(root->left);
        int h2 = height(root->right);
        return max(h1, h2)+1;
    }
    
    int width(TreeNode* root){
        if(root==NULL){
            return 0;
        }
        int h1 = width(root->left);
        int h2 = width(root->right);
        return max(h1, h2)*2+1;
    }
    
    void healper(vector<vector<string>>&s,TreeNode* root, int level, int start, int end){
        if(root==NULL){
            return;  
        }
        int mid = (start+end)/2;
        s[level][mid] = to_string(root->val);
        healper(s, root->left, level+1, start, mid);
        healper(s, root->right, level+1, mid+1, end);
        return;
    }
    
    
    
    vector<vector<string>> printTree(TreeNode* root) {
        int h = height(root);
        int w = width(root);
        vector<vector<string>>res(h, vector<string>(w, ""));
        healper(res, root, 0, 0, w);
        return res;
    }
};