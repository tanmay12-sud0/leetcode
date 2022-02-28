class Solution {
public:
    
  bool isPalindrome(string &s, int start, int end) {
        
        while(start < end) {
            
            if(s[start] != s[end]) return false;
            
            start += 1;
            end -= 1;
            
        }
        
        return true;
        
    }
    
    int part(string s, int i, int j, vector<vector<int>>&dp){
        if(i>=j){
            return dp[i][j] =  0;
        }
        if(isPalindrome(s, i, j)){
            return dp[i][j] =  0;
        }
        if(dp[i][j] != -1){
            return dp[i][j];
        }
        long ans = s.length()-1;
        for(int k=i; k<j; k++){
            if(isPalindrome(s,i,k)==false)
                continue;
            
            long temp = part(s, i, k, dp) + part(s, k+1, j, dp) + 1;
            ans = min(ans, temp);
        }
        return dp[i][j] = ans;
    }
    
    int minCut(string s) {
        int n = s.length();
        vector<vector<int>>dp(2001, vector<int>(2001, -1));
        return part(s, 0, s.length()-1, dp);
    }
};