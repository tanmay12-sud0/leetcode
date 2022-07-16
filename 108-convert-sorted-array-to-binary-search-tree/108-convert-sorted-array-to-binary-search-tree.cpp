
class Solution {
public:
    
    TreeNode* buildArrray(vector<int>&nums, int s, int e){
        if(s > e){
            return NULL;
        }
        int mid = (s+e)/2;
        TreeNode* root = new TreeNode(nums[mid]);
        root->left = buildArrray(nums, s, mid-1);
        root->right = buildArrray(nums, mid+1, e);
        return root;
    }
    
    
    
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        int len = nums.size();
        int s = 0;
        int e = len-1;
        return buildArrray(nums, s, e);
    }
};