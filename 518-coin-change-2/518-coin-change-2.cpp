class Solution {
public:
        int change(int amount, vector<int>& coins) {
        if(amount == 0) return 1;
        if(coins.size() == 0) return 0;
        int n= coins.size();
        vector<vector<int>>t(n+1, vector<int>(amount+1, -1));
        return helper(coins, amount, n, t);
    }
    
    int helper(vector<int>& wt, int sum, int n,  vector<vector<int>>& t){
        if(sum == 0) return 1;
        if(n <= 0) return 0;
        
        //Check if answer exists
        if(t[n][sum] != -1) return t[n][sum];
        
        if(wt[n-1] <= sum){
            t[n][sum] = helper(wt, sum-wt[n-1], n, t) + helper(wt, sum, n-1, t);
            return t[n][sum];
        }else{
            t[n][sum] = helper(wt, sum, n-1, t);
            return t[n][sum];
        }
    }
//      int dp[10000 + 1][10000 + 1];
    
//     int minCoins(int amount, vector<int>coins, int idx, int sum){    
//         if(amount == sum){
//             return 1;
//         }
          
//         if(idx==coins.size() or amount < sum){
//             return 0;
//         }    
        
//         //  if(dp[idx][sum] != -1){
//         //     return dp[idx][sum];
//         // }  
        
//         return (minCoins(amount, coins, idx+1, sum) + minCoins(amount-coins[idx], coins, idx, sum));
//     }
    
//     int change(int amount, vector<int>& coins) {
//         int n = coins.size();
//         memset(dp, -1, sizeof(dp));  
//         int sum = 0;
//         return minCoins(amount, coins, 0, sum);
    
};