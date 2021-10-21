class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int dp[300][300]={0};
        
        if(n == 0 and m==0){
            return 0;
        }
        
        dp[0][0] = grid[0][0];
        for(int i=0; i<n; i++){
            if(i!=0){
                dp[i][0] = dp[i-1][0] + grid[i][0];
            }
        }
        for(int i=0; i<m; i++){
            if(i!=0){
                dp[0][i] = dp[0][i-1] + grid[0][i];
            }
        }
        for(int i=1; i<n; i++){
            for(int j=1; j<m; j++){
                dp[i][j] = min(dp[i-1][j], dp[i][j-1]) + grid[i][j];
            }
        }
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                cout << dp[i][j] << ", ";
            }
            cout << endl;
        }
        return dp[n-1][m-1];
    }
};