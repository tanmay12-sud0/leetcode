class Solution {
public:
    int coinChange(vector<int>& coins, int am) {
        int n=coins.size();
        long dp[n+1][am+1];
        for(int i=0;i<=n;i++) dp[i][0]=0;
        for(int i=0;i<=am;i++) dp[0][i]=INT_MAX;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=am;j++){
                if(j<coins[i-1]) dp[i][j]=dp[i-1][j];
                else dp[i][j]=min(dp[i-1][j],dp[i][j-coins[i-1]]+1);
            }
        }
        return (dp[n][am]==INT_MAX?-1:dp[n][am]);
    }
};














// class Solution {
// public:
//     int flag = 0;
//     int minCoins(int amount, vector<int>coins, vector<int>dp, int n){
//         if(amount == 0){
//             return 0;
//         }
//         // if (amount < 0) return INT_MIN+10;

//         if(dp[n]!= -1){
//             return dp[n];
//         }
        
//         int ans = INT_MAX;
//         for(int i=0; i<n; i++){
//             if(amount-coins[i]>=0){
//                     int subprob = minCoins(amount-coins[i], coins, dp, n);
//                     if(subprob == INT_MAX){
//                         flag = 2;
//                         ans = -1;
//                     }else{
//                         ans = min(ans, subprob+1);
//                     }
                    
//             }
//         }
        
//         return  dp[n] = ans;
//     }
    
    
    
//     int coinChange(vector<int>& coins, int amount) {
//         int n = coins.size();
//         vector<int>dp(amount+10, -1);
//         if(flag == 2){
//             return -1;
//         }
//         return minCoins(amount, coins, dp, n);
//     }
// };