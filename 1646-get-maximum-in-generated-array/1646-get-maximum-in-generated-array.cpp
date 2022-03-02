class Solution {
public:
    int getMaximumGenerated(int n) {
        vector<int>dp(n+1, 0);
        if(n <= 1){
            return n;
        }
        dp[0]=0;
        dp[1] =1;
        int max_so_far = 1;
        for(int i=2; i<=n; i++){
            if(i%2==0){
                dp[i] = dp[i/2];
            }else{
                dp[i] = dp[(i-1)/2] + dp[((i-1)/2)+1];
            }
            max_so_far = max(dp[i], max_so_far);
        }
        return max_so_far;
    }
};