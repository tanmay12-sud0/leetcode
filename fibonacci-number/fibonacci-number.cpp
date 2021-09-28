class Solution {
public:
    
    int fibo(int n, int *dp){
        if(n==0 or n==1){
            return n;
        }
        if(dp[n]!=0){
            return dp[n];
        }
        int ans = fibo(n-1, dp) + fibo(n-2, dp);
        dp[n] = ans;
        return ans;
    }
    
    
    
    int fib(int n) {
        int dp[100] ={0};
        return fibo(n, dp);
    }
};