class Solution {
public:
    
    TreeNode* maxiTree(vector<int>& nums, int s, int e){
        if(s > e){
            return NULL;
        }
        
        int index = e;
        for(int i=s; i<=e; i++){
            if(nums[i] > nums[index]){
                index = i;
            }
        }
         TreeNode* root = new TreeNode(nums[index]);
         root->left = maxiTree(nums, s, index-1);
         root->right = maxiTree(nums, index+1, e);
        return root;
        
    }

    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        int s = 0;
        int e = nums.size()-1;
        return maxiTree(nums, s, e);
    }
};