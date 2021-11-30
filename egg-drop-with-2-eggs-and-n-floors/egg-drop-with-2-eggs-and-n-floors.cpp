class Solution {
public:
    
    int findValue(int n, int e, vector<vector<int>>&dp){
        if(e == 1){
            return n;
        }
        if(n==0 or n==1){
            return n;
        }
        if(dp[e][n]!=-1){
            return dp[e][n];
        }
        int ans = INT_MAX;
        for(int x = 1; x<=n; x++){
            int mi = max(findValue(x-1, e-1, dp), findValue(n-x, e, dp));
            ans = min(ans, mi+1);
        }
        return dp[e][n] = ans;
    }

    
    int twoEggDrop(int n) {
        vector<vector<int>>dp(3, vector<int>(10000, -1));
        return findValue(n, 2, dp);
    }
};