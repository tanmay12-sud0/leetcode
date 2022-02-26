class Solution {
public:
    bool isPossible(vector<int> &nums,vector<vector<bool> > &dp,vector<vector<bool> >& visited,int sum,int index){
        if(index<0 || sum<0)
            return false;
        if(sum==0)
            return dp[sum][index]=true;
        if(visited[sum][index])
            return dp[sum][index];
        visited[sum][index]=true;
        return dp[sum][index]=isPossible(nums,dp,visited,sum,index-1) || isPossible(nums,dp,visited,sum-nums[index],index-1);
        
    }
    bool canPartition(vector<int>& nums) {
        int sum=0;
        int n=nums.size();
        for(int i=0;i<n;i++){
            sum+=nums[i];
        }
        if(sum & 1)
            return false;
        
        sum=sum/2;
        vector<vector<bool> > dp(sum+1,vector<bool> (n,false));
        vector<vector<bool> > visited(sum+1,vector<bool> (n,false));
        return isPossible(nums,dp,visited,sum,n-1);
        
    }
};
















// class Solution {
// public:
//     bool checkKro(vector<int>nums, int sum, int n,vector<vector<int> > &umap){
//         if(n==0){
//             return false;
//         }
//         if(umap[n][sum] != 0){
//             return  umap[n][sum];
//         }
//         if(sum == 0){
//             return true;
//         }
//         if(nums[n-1] <= sum){
//             return umap[n][sum] = checkKro(nums, sum-nums[n-1], n-1, umap) or checkKro(nums, sum, n-1, umap);
//         }
//         return umap[n][sum] = checkKro(nums, sum, n-1, umap);
//     }
    
    
    
//     bool canPartition(vector<int>& nums) {
//         int n = nums.size();
//         long long sum = 0;
//         for(int i=0; i<n; i++){
//             sum += nums[i];
//         }
//         if(sum%2 != 0){
//             return false;
//         }
//         vector<vector<int>>umap(n+10, vector<int>(sum+10, 0));
//         return checkKro(nums, sum/2, n, umap);
//     }
// };