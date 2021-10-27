class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
       
       
        int m = obstacleGrid.size() , n = obstacleGrid[0].size();
        vector<vector<int>> dp(m+1,vector<int>(n+1,0));
        dp[0][1] = 1;
        for(int i = 1 ; i <= m ; ++i)
            for(int j = 1 ; j <= n ; ++j)
                if(!obstacleGrid[i-1][j-1])
                    dp[i][j] = dp[i-1][j]+dp[i][j-1];
        return dp[m][n];
    }
};
    
    
    
     // int row = obstacleGrid.size();
        // int col = obstacleGrid[0].size();
        // int dp[101][101] = {0};
        // int flag = 0;
        // for(int i=0; i<row; i++){
        //     if(obstacleGrid[i][0] == 1 or flag){
        //         dp[i][0] = 0;
        //         flag = 1;
        //     }else{
        //         dp[i][0] = 1;
        //     }
        // }
        // flag = 0;
        // for(int i=0; i<col; i++){
        //     if(obstacleGrid[0][i] == 1 or flag){
        //         dp[0][i] = 0;
        //         flag = 1;
        //     }else{
        //         dp[0][i] = 1;
        //     }
        // }
        // for(int i=1; i<row; i++){
        //     for(int j=1; j<col; j++){
        //         if(obstacleGrid[i][j] == 1){
        //             dp[i][j] = 0;
        //         }else{
        //             dp[i][j] = dp[i-1][j] + dp[i][j-1];
        //         }
        //     }
        // }
        // return dp[row-1][col-1];