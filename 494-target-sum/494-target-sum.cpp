class Solution {
public:
    
    int countDekh(vector<int>&nums, int target, int idx, int sum, vector<vector<int>>&dp){
        if(idx == nums.size()){
           if(sum==target){
               return 1;
           }
            return 0;
        }
        
        if(dp[idx][sum+1000] != 0){
            return dp[idx][sum+1000];
        }
        
        int a = countDekh(nums, target, idx+1, sum+nums[idx], dp);
        int b = countDekh(nums, target, idx+1, sum+((nums[idx])*(-1)), dp);
        return dp[idx][sum+1000] =  a+b;
    }
    
    
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = 0;
        int sum = 0;
        vector<vector<int>>dp(22, vector<int>(10000, 0));
        return countDekh(nums, target, n, sum, dp);
    }
};