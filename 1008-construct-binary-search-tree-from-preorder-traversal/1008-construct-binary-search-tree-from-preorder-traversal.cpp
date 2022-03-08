class Solution {
    map<int, int> dict;
public:
    TreeNode* BTreeFromPreIn(vector<int> &preorder, vector<int> &inorder, int &index, int low, int high){
        if(low > high){
            return NULL;
        }
        
        TreeNode* root = new TreeNode(preorder[index]);
        int idx = dict[preorder[index++]];
        
        root->left = BTreeFromPreIn(preorder, inorder, index, low, idx - 1);
        root->right = BTreeFromPreIn(preorder, inorder, index, idx + 1, high);
        return root;
    }
    
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        vector<int> inorder(preorder);
        sort(inorder.begin(), inorder.end());
        int n = inorder.size();
        for(int i = 0; i < n; i++){
            dict[inorder[i]] = i;
        }
        int index = 0;
        return BTreeFromPreIn(preorder, inorder, index, 0, n - 1);
    }
};