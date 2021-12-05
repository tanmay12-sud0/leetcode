class Solution {
public:
    int dx[4]= {0,0,1,-1};
    int dy[4]= {1,-1,0,0};
    
    void flood_fill(vector<vector<int>>grid, vector<vector<bool>>&visited, int row, int col, int i, int j, bool &flag){
          if(i==0 or i==row-1 or j==0 or j==col-1){
                flag = true;
            }
          
        visited[i][j] = true;
        for(int k=0; k<4; k++){
            int nx = i + dx[k];
            int ny = j + dy[k];

            if(nx>=0 and nx<row and ny>=0 and ny<col and grid[nx][ny]==0 and !visited[nx][ny]){
                flood_fill(grid, visited, row, col, nx, ny, flag);
            }
        }
    }
    
    
    
    
    int closedIsland(vector<vector<int>>& grid) {
        int row = grid.size();
        int col = grid[0].size();
        int count = 0;
        vector<vector<bool>>visited(row, vector<bool>(col, false));
        for(int i=0; i<row; i++){
            for(int j=0; j<col; j++){
                if(!visited[i][j] and grid[i][j]==0){
                    bool flag = false;
                    flood_fill(grid, visited,row, col, i, j, flag);
                        if(!flag){
                            count++;
                        }
                }
            }
        }
        
        for(int i=0; i<row; i++){
            for(int j=0; j<col; j++){
                cout << visited[i][j] << ", ";
            }
            cout << endl;
        }
        
        return count;
    }
};