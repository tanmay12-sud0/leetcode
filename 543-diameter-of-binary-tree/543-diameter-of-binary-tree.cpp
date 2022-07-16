
class Solution {
public:
    
    class pairs{
        public:
            int height = 0;
            int diameter=0;
    };
    
    pairs check(TreeNode* root){
        pairs pp;
        
        if(root == NULL){
            pp.height = 0;
            pp.diameter = 0;
            return pp;
        }
        
        pairs left = check(root->left);
        pairs right = check(root->right);
        pp.height = max(left.height, right.height)+1;
        pp.diameter = max(left.height+right.height, max(left.diameter, right.diameter));
        return pp;
    }
    
    int diameterOfBinaryTree(TreeNode* root) {
        pairs pp = check(root);
        return pp.diameter;
    }
};