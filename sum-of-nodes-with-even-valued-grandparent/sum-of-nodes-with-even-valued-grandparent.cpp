
class Solution {
public:
    int sum = 0;
    
    void helloBoss(TreeNode* root){
        if(root==NULL)return;
        
        if(root->val%2==0){
            if(root->left){
                if(root->left->left){
                    sum += root->left->left->val;
                }
                if(root->left->right){
                    sum += root->left->right->val;
                }
            }
            if(root->right){
                if(root->right->left){
                    sum += root->right->left->val;
                }
                if(root->right->right){
                    sum += root->right->right->val;
                }
            }
        }
        
        
        helloBoss(root->left);
        helloBoss(root->right);
        return;
    }
    
    
    
    
    int sumEvenGrandparent(TreeNode* root) {
        if(root==NULL)return 0;
        helloBoss(root);
        return sum;
    }
};