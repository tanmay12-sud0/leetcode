
class Solution {
public:
    
    vector<int>hash;
    
    void inorder(TreeNode* root){
        if(root==NULL){
            return;
        }
        
        inorder(root->left);
        hash.push_back(root->val);
        inorder(root->right);
        return;
    }
    int i=0;
    void inorderchange(TreeNode* root){
        if(root==NULL){
            return;
        }
       
        inorderchange(root->left);
         root->val = hash[i++];
        
        inorderchange(root->right);
        return;
    }
    
    
    
    TreeNode* convertBST(TreeNode* root) {
        inorder(root);
        int n = hash.size();
        for(int i= hash.size()-2; i>=0; i--){
            hash[i] += hash[i+1];
        }
        for(auto x : hash){
            cout << x << "< ";
        }
        inorderchange(root);
        return root;
    }
};

