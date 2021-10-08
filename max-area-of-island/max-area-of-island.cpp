class Solution {
public:
    
    int dfs(vector<vector<int>>grid, vector<vector<bool>>&visited, int i, int j, int n, int m){
        visited[i][j] = true;
        int cs = 1;
        
        int dx[] = {1,-1,0,0};
        int dy[] = {0,0,1,-1};
        
        for(int k=0; k<4; k++){
            int nx = i + dx[k];
            int ny = j + dy[k];
            
            if(nx>=0 and nx < n and ny >=0 and ny < m and !visited[nx]                   [ny] and grid[nx][ny] == 1){
                int subcom = dfs(grid, visited, nx, ny, n, m) ;
                cs += subcom;
            }
        }
        return cs;
    }
  
    
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<bool>>visited(n, vector<bool>(m, false));
        int largest = 0;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                // cout << grid[i][j] <<" , " << endl;
                if(!visited[i][j] and grid[i][j] != 0){
                    int size = dfs(grid, visited, i, j, n, m);
                    
                    // cout << size <<"("<<i<<","<<j<<")"<< endl;
                    if(size > largest){
                        largest = size;
                    }
                }
            }
        }
        return largest;
      
    }
};