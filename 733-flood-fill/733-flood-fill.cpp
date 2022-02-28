class Solution {
public:
    int dx[4] = {0,0,1,-1};
    int dy[4] = {1,-1,0,0};
    
    void dfs(vector<vector<int>>&grid, int row, int col, int i, int j, int newColor, int value, vector<vector<bool>>&visited){
        visited[i][j] = true;
	grid[i][j] = newColor;
	for(int k=0; k<4; k++){
		int xx = i + dx[k];
		int yy = j + dy[k];
		if(xx>=0 and xx<row and yy>=0 and yy<col and grid[xx][yy]==value and !visited[xx][yy]){
			dfs(grid, row, col, xx, yy, newColor, value, visited);
		}
	}
}
    
    
    vector<vector<int>> floodFill(vector<vector<int>>& grid, int sr, int sc, int newColor) {
        int row = grid.size();
	    int col = grid[0].size();
	
	    int value = grid[sr][sc];
	    vector<vector<bool>>visited(row, vector<bool>(col, false));
	    if(grid[sr][sc] == value){
		    dfs(grid, row, col, sr, sc, newColor, value, visited);
	    }
        return grid;
    }
};