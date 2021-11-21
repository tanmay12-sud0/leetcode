
class Solution {
public:
    
    vector<int>hash;
    
    void check1(TreeNode* root1){
        if(root1 == NULL){
            return;
        }
        check1(root1->left);
        hash.push_back(root1->val);
        check1(root1->right);
        return;
    }
    void check2(TreeNode* root2){
        if(root2 == NULL){
            return;
        }
        check2(root2->left);
        hash.push_back(root2->val);
        check2(root2->right);
        return;
    }
    
    
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        check1(root1);
        check2(root2);
        sort(hash.begin(), hash.end());
        return hash;
    }
};