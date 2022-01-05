class Solution {
public:
    int dx[4] = {1,0,-1,0};
    int dy[4] = {0,1,0,-1};
    void dfs(vector<vector<char>>& grid, int row, int col, int i, int j){
        grid[i][j] = '0';
        for(int k=0; k<4; k++){
            int xx = i + dx[k];
            int yy = j + dy[k];
            if(xx>=0 and xx<row and yy>=0 and yy<col and grid[xx][yy] == '1'){
                dfs(grid, row, col, xx, yy);
            }
        }
    }

    int numIslands(vector<vector<char>>& grid) {
        int row = grid.size();
        int col = grid[0].size();
        int count = 0;
        for(int i=0; i<row; i++){
            for(int j=0; j<col; j++){
                if(grid[i][j] == '1'){
                    dfs(grid, row, col, i, j);
                    count++;
                }
            }
        }
        return count;
    }
};