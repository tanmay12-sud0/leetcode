
class Solution {
public:
    
    TreeNode* first = NULL;
    TreeNode* middle = NULL;
    TreeNode* last = NULL;
    TreeNode* prev = NULL;
    
    void check(TreeNode* root){
        if(root==NULL){
            return;
        }
        check(root->left);
        
        if(prev != NULL and root->val < prev->val){
            if(first == NULL){
                first = prev;
                middle = root;
            }else{
                last = root;
            }
        }
        
        prev = root;
        check(root->right);
    }
    
    
    
    void recoverTree(TreeNode* root) {
        if(root==NULL){
            return;
        }
        check(root);
        if(first!=NULL and last!=NULL){
            swap(first->val, last->val);
        }
        else if(first!=NULL and middle!=NULL){
            swap(first->val, middle->val);
        }
        return;
    }
};