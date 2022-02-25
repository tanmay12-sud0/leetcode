class Solution {
public:
    vector<int> replaceElements(vector<int>& arr) {
        int n = arr.size();
        vector<int>dp(n, 0);
        dp[n-1] = arr[n-1];
        for(int i=n-2; i>=0; i--){
            dp[i] = max(dp[i+1], arr[i]);
        }
        vector<int>hash(n, 0);
        for(int i=0; i<n-1; i++){
            hash[i] = dp[i+1];
        }
        hash[n-1] = -1;
        return hash;
    }
};