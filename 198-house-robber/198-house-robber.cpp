class Solution {
public:
    int solve(vector<int>nums, int index, int n, vector<int>&dp){
        if(index >= n){
            return 0;
        }
        if(dp[index] != -1){
            return dp[index];
        }
        int ans;
        ans = max(solve(nums, index+1, n, dp), solve(nums, index+2, n, dp)+nums[index]);
        return dp[index] = ans;
    }
    
    
    
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int>dp(n, -1);
        return solve(nums, 0, n, dp);
    }
};