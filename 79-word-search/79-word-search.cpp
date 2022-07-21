class Solution {
public:
    
    bool dfs(vector<vector<char>>&board, int row, int col, int i, int j, string word, int ii, vector<vector<bool>>&visited){
	visited[i][j] = true;


	if(ii == word.length()){
		return true;
	}
    
    int dx[] = {1, 0, -1, 0};
    int dy[] = {0, 1, 0, -1};
    
	for(int k=0; k<4; k++){
		int xx = i + dx[k];
		int yy = j + dy[k];

		if(xx>=0 and xx<row and yy>=0 and yy<col and !visited[xx][yy] and board[xx][yy] == (word[ii])){
			int mila = dfs(board, row, col, xx, yy, word, ii+1, visited);
			if(mila){
				return true;
			}
		}

	}
	visited[i][j] = false;
	return false;
}
    
    
    
    bool exist(vector<vector<char>>& board, string word) {
        int row = board.size();
		int col = board[0].size();
		vector<vector<bool>>visited(row, vector<bool> (col, 0));
		for(int i=0; i<row; i++){
			for(int j=0; j<col; j++){
				if(board[i][j] == (word[0])){
					if(dfs(board, row, col, i, j, word, 1, visited)){
						return true;
					}
				}
			}
		}
        return false;
    }
};