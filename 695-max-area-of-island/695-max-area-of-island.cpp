class Solution {
public:
    
    int dx[4] = {0,0,1,-1};
    int dy[4] = {1,-1,0,0};

    int total_cnt[10000]={0};

    void dfs(vector<vector<int>>&grid, int row, int col, int i, int j, int              color){
	    grid[i][j] = color;
	    total_cnt[color]++;
	    for(int k=0; k<4; k++){
		    int xx = i + dx[k];
		    int yy = j + dy[k];
		    if(xx>=0 and xx<row and yy>=0 and yy<col and grid[xx][yy]==1){
			    dfs(grid, row, col, xx, yy, color);
		}
	}
}
  
    
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int color = 1;
	    int row = grid.size();
	    int col = grid[0].size();
	for(int i=0; i<row; i++){
		for(int j=0; j<col; j++){
			if(grid[i][j] == 1){
				color++;
				dfs(grid, row, col, i, j, color);
			}
		}
	}
	int max_so_far=0;
		

	for(int i=0; i<10000; i++){
		max_so_far = max(max_so_far, total_cnt[i]);
	}
	    return max_so_far;
    }
};