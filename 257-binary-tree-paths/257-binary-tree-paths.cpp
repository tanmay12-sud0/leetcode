
class Solution {
public:
    vector<string>hash;
    void checkNode(TreeNode* root, string s){
        if(root == NULL){
            return;
        }
        if(root->left == NULL and root->right == NULL){
            s += to_string(root->val);
            hash.push_back(s);
            s.clear();
            return;
        }
        
        s += to_string(root->val);
        s += "->";
        checkNode(root->left, s);
        checkNode(root->right, s);
        s.pop_back();
        return;
        
    }

    vector<string> binaryTreePaths(TreeNode* root) {
        string s;
        checkNode(root, s);
        return hash;
    }
};