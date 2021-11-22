class Solution {
public:
    int maxIncreaseKeepingSkyline(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<int>row(n, 0);
        vector<int>col(m, 0);
        
        for(int i=0; i<n; i++){
            row[i] = INT_MIN;
            for(int j=0; j<n; j++){
                row[i] = max(row[i], grid[j][i]);
            }
        }
         
        for(int i=0; i<n; i++){
            col[i] = INT_MIN;
            for(int j=0; j<n; j++){
                col[i] = max(col[i], grid[i][j]);
            }
        }
        // for(int i=0; i<n; i++){
        //     cout << row[i] <<", ";
        // }
        // cout << endl;
        // for(int i=0; i<n; i++){
        //     cout << col[i] <<", ";
        // }
        int sum = 0;
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                int x = min(col[j], row[i]);
                sum += (x-grid[i][j]);
                grid[i][j] = min(col[j], row[i]);
            }
        }
        
        return sum;
    }
};