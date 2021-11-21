
class Solution {
public:
    
    int parent1;
    int parent2;
    int level1;
    int level2;
    
    void check(TreeNode* root, int x, int level, int parent){
        if(root==NULL){
            return;
        }
        if(root->val == x){
            level1 = level;
            parent1 = parent;
            return;
        }
        check(root->left, x, level+1, root->val);
        check(root->right, x, level+1, root->val);
        return;
    }
    
     void check1(TreeNode* root, int y, int level, int parent){
        if(root==NULL){
            return;
        }
        if(root->val == y){
            level2 = level;
            parent2 = parent;
            return;
        }
        check1(root->left, y, level+1, root->val);
        check1(root->right, y, level+1, root->val);
        return;
    }
    
    
    bool isCousins(TreeNode* root, int x, int y) {
        check(root, x, 0, -1);
        check1(root, y, 0, -1);
        // cout << level1 << ", " << parent1 << endl;
        // cout << level2 << ", " << parent2 << endl;
        if(level1==level2 and parent1!=parent2){
            return true;
        }
        return false;
    }
};