class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int n = nums.size();
        int left = 0;
        int right = 0;
        int max_so_far= INT_MIN;
        int zero = 0;
        while(right < n){
            if(nums[right]==0){
                zero++;
            }
            if(zero > 1){
                while(zero > 1){
                    if(nums[left]==0){
                        zero--;
                    }
                    left++;
                }
            }
            max_so_far = max(max_so_far, right-left);
            right++;
        }
        return max_so_far;
    }
};