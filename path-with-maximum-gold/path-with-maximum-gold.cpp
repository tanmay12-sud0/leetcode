class Solution {
public:
    
    int dx[4] = {1, 0, -1, 0};
    int dy[4] = {0, 1, 0, -1}; 
    
    
    void dfs(vector<vector<bool>>&visited, int i, int j, int n, int m, int &sum,vector<vector<int>>&grid, int &max_so_far){
        visited[i][j] = true;
        
        for(int k=0; k<4; k++){
            int nx = i + dx[k];
            int ny = j + dy[k];
            
            if(nx>=0 and nx<n and ny>=0 and ny<m and !visited[nx][ny] and grid[nx][ny]!=0){
                sum += grid[nx][ny];
                max_so_far = max(max_so_far, sum);
                dfs(visited, nx, ny, n, m, sum, grid, max_so_far);
            }
        }
        max_so_far = max(max_so_far, sum);
        
        sum -= grid[i][j];
        visited[i][j] = false;
    }
    
    int getMaximumGold(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int maxxa = 0;
        vector<vector<bool>>visited(n, vector<bool>(m, false));
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j]!=0 and !visited[i][j]){
                    int sum = grid[i][j];
                    int max_so_far = INT_MIN;
                    dfs(visited, i, j, n, m, sum, grid, max_so_far);
                    cout <<i <<", " <<j<< max_so_far << endl;
                    maxxa = max(maxxa, max_so_far);
                }
            }
        }
        return maxxa;
    }
};