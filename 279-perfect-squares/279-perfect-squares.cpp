class Solution {
public:
    int numSquares(int n) {
        vector<int>dp(n+1);
        dp[0] = 0;
        for(int i=1; i<=n; i++){
            int ans = (1 << 30);
            for(int j=1; j*j <= (i); j++){
                ans = min(dp[i-(j*j)]+1, ans);
            }
            dp[i] = ans;
        }
        return dp[n];
    }
};