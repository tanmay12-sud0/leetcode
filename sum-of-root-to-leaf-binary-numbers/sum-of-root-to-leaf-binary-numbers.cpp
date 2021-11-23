/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    
    int binaryToDecimal(string n)
{
    string num = n;
    int dec_value = 0;
 
    // Initializing base value to 1, i.e 2^0
    int base = 1;
 
    int len = num.length();
    for (int i = len - 1; i >= 0; i--) {
        if (num[i] == '1')
            dec_value += base;
        base = base * 2;
    }
 
    return dec_value;
}
    int sum = 0;
    
    void checKSum(TreeNode* root, string curr){
        if(root == NULL){
            return;
        }
        if(root->left==NULL and root->right==NULL){
            curr += to_string(root->val);
            sum += binaryToDecimal(curr);
            return;
        }
        checKSum(root->left, curr+to_string(root->val));
        checKSum(root->right, curr+ to_string(root->val));
        curr.pop_back();
        return;
    }
    
    
    
    
    int sumRootToLeaf(TreeNode* root) {
        string curr;
        checKSum(root, curr);
        return sum;
    }
};