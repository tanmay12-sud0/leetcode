
class Solution {
public:
    
//     bool left_to_root(TreeNode* root, int target, int curr){
//         if(root == NULL){
//             return false;
//         }
//         // if(root->left==NULL and root->right==NULL){
//         //     return false;
//         // }
//         if(curr == target and root->left==NULL and root->right==NULL){
//             cout << "hello";
//             return true;
//         }
//         cout << root->val <<", " << curr << endl;
//        if(root->left){
//             bool left = left_to_root(root->left, target, curr+root->left->val);
//        }
//        if(root->right){
//             bool right = left_to_root(root->right, target, curr+root->right->val);
//        }
//         return left or right;
//     }
    
    
    
    bool hasPathSum(TreeNode* root, int targetSum) {
        if(root == NULL)return false;
        if(targetSum-root->val == 0 and root->left==NULL and root->right == NULL)return true;
        return hasPathSum(root->left, targetSum-root->val) || hasPathSum(root->right, targetSum-root->val);
    }
};