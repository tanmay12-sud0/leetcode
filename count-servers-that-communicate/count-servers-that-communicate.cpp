class Solution {
public:
    
 
   
    int countServers(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int count = 0;
        vector<int>RowSum(n, 0);
        vector<int>ColSum(m, 0);
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j]==1){
                    RowSum[i]++;
                    ColSum[j]++;
                }
            }
        }
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j] and (RowSum[i]>1 || ColSum[j]>1)){
                    count++;
                }
            }
            cout << endl;
        }
        return count;
    }
};