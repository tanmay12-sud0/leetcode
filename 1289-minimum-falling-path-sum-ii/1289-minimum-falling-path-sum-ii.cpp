class Solution {
public:
    int dfs(vector<vector<int>>& arr,int i,int j,vector<vector<int>> &dp) {
        if(dp[i+1][j]!=INT_MAX)
            return dp[i+1][j];
        int s=INT_MAX;
        if(j==arr.size())
            return 0;
        for(int p=0;p<arr[j].size();p++){
            if(p==i)
                continue;
            else
                s=min(s,arr[j][p]+dfs(arr,p,j+1,dp));
        }
        return dp[i+1][j]=s;
    }
    int minFallingPathSum(vector<vector<int>>& arr) {
        vector<vector<int>>dp(202, vector<int>(202,INT_MAX));
        return dfs(arr,-1,0,dp);
    }
};













// class Solution {
// public:
    
//     void minCheck(vector<vector<int>>& grid, int i, int n, int &minSum, int sum, int prev, vector<vector<int>>&dp){
//         if(i==n){
//             minSum = min(minSum, sum);
//             return;
//         }
//         if(dp[i][])
//         for(int j=0; j<n; j++){
//             if(prev == j)continue;
//             minCheck(grid, i+1, n, minSum, sum+grid[i][j], j);
//         }
//         return;
//     }
    
    
    
//     int minFallingPathSum(vector<vector<int>>& grid) {
//         int minSum = INT_MAX;
//         int sum = 0;
//         int n = grid.size();
//         int m = grid[0].size();
//         vector<vector<int>>dp(n, vector<int>(m, 0));
//         minCheck(grid, 0, grid.size(), minSum, sum, -1, dp);
//         return minSum;
//     }
// };