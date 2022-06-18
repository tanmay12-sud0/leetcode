
class Solution {
public:
    class Pairs{
        public:
            int hei;
            int dia;
    };
    
    Pairs checkKro(TreeNode* root){
        Pairs pp;
        if(root == NULL){
            pp.hei = 0;
            pp.dia = 0;
            return pp;
        }
        
        Pairs left = checkKro(root->left);
        Pairs right = checkKro(root->right);
        pp.hei = max(left.hei, right.hei) + 1;
        pp.dia = max(left.hei+right.hei, max(left.dia, right.dia));
        return pp;
    }
    
    int diameterOfBinaryTree(TreeNode* root) {
        Pairs pp = checkKro(root);
        return pp.dia;
    }
};