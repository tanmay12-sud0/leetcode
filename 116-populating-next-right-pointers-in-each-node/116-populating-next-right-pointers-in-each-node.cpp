class Solution {
public:
    
    void check(Node* root, int level, int &maxlevel){
        if(root == NULL){
            return;
        }
        if(root->left == NULL and root->right == NULL){
            return;
        }
        if(level > maxlevel){
            maxlevel = level;
            root->left->next = root->right;
        }else{
            root->left->next = root->right;
            root->right->next = root->next->left;
        }
        
        check(root->right, level+1, maxlevel);
        check(root->left, level+1, maxlevel);
        return;
    }
    
    
    Node* connect(Node* root) {
        int maxlevel = -1;
        check(root, 0, maxlevel);
        return root;
        
    }
};