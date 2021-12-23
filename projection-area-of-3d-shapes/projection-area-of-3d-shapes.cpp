class Solution {
public:
    int projectionArea(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int sum1 = 0;
        int sum2 = 0, sum3=0;
        for(int i=0; i<n; i++){
            int maxa = INT_MIN;
            for(int j=0; j<m; j++){
                maxa = max(maxa, grid[i][j]);
            }
            sum2 += maxa;
        }
        
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j] != 0){
                    sum1++;
                }
            }
        }
        
        for(int i=0; i<m; i++){
            int maxaa = INT_MIN;
            for(int j=0; j<n; j++){
                maxaa = max(maxaa, grid[j][i]);
            }
            sum3 += maxaa;
        }
        return sum1+sum2+sum3;
    }
};