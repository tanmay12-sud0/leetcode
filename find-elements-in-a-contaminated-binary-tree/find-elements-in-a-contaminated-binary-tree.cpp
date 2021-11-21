
class FindElements {
    
    set<int>hash;
public:
    void recover(TreeNode* root, int value){
        if(root==NULL){
            return;
        }
        root->val = value;
        hash.insert(root->val);
        recover(root->left, 2*value+1);
        recover(root->right, 2*value+2);
        return;
    }
    
   
    FindElements(TreeNode* root) {
        recover(root, 0);
    }
    
    bool find(int target) {
        return hash.count(target);
    }
};

