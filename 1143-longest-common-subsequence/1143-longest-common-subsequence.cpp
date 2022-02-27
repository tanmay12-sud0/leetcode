class Solution {
public:    
    int dp[1000 + 1][1000 + 1];
    
    int maxLen(string& s1, string& s2, int n, int m)
    {
        if (n == 0 || m == 0)
            return 0;
        
        if (dp[n][m] != -1)
            return dp[n][m];

        if (s1[n - 1] == s2[m - 1])
            return dp[n][m] = 1 + maxLen(s1, s2, n - 1, m - 1);
        else
            return dp[n][m] = max(0 + maxLen(s1, s2, n - 0, m - 1), 0 + maxLen(s1, s2, n - 1, m - 0));
    }
        
    int longestCommonSubsequence(string s1, string s2) 
    {
        memset(dp, -1, sizeof(dp));        
        return maxLen(s1, s2, s1.length(), s2.length());
    }
};


// class Solution {
// public:
//     int dp[100001][100001];
//     int check(string text1, string text2, int idx1, int idx2){
//         if(idx1 == 0 or idx2 == 0){
//             return 0;
//         }
//         if(dp[idx1][idx2] != -1){
//             return dp[idx1][idx2];
//         }
//         if(text1[idx1-1] == text2[idx2-1]){
//             return dp[idx1][idx2] = 1 + check(text1, text2, idx1-1, idx2-1);
//         }
//         return dp[idx1][idx2] = max(check(text1, text2, idx1-1, idx2) , check(text1, text2, idx1,idx2-1));
//     }
    
    
//     int longestCommonSubsequence(string text1, string text2) {
//          memset(dp, -1, sizeof(dp)); 
//         return check(text1, text2, text1.size(), text2.size());
//     }
// };